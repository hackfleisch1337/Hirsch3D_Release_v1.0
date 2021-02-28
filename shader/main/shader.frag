#version 330 core

layout(location = 0) out vec4 color;


in vec2 v_uv;
in vec3 v_normal;
in vec3 v_position;
in mat4 v_model;
in vec3 v_vertex_pos;

uniform vec4 u_color;

uniform sampler2D u_texture;
uniform int isSamplerSet;

uniform sampler2D u_normalmap;
uniform int isNormalSet;

uniform sampler2D u_roughnessmap;
uniform int isRoughnessSet;

uniform float u_ambient;

uniform float u_shininess;
uniform float u_specIntensity;
uniform float u_kD;
uniform vec3 u_specColor;

// TBN Matrix

#define MAX_LIGHTS 10

struct DirectionalLight {
    vec3 color;
    vec3 direction;
    float brightness;
};

struct PointLight {
    vec3 color;
    vec3 position;
    float brightness;
    float linear;
    float quadratic;
};

struct SpotLight {
    vec3 color;
    vec3 position;
    vec3 direction;
    float brightness;
    float outerCone;
    float innerCone;
};

uniform int amountOfDlights;
uniform int amountOfPlights;
uniform int amountOfSlights;

uniform DirectionalLight dlights[MAX_LIGHTS];
uniform PointLight plights[MAX_LIGHTS];
uniform SpotLight slights[MAX_LIGHTS];

in vec3 gf_T;
in vec3 gf_B;
/*

in vec3 gf_Pos;
in vec2 gf_TexCoord;
in mat4 gf_model;
*/
// Light

void main() {
    
    vec4 f_color = vec4(0.0);
    mat3 tbn = mat3(gf_T, gf_B, v_normal);

    if(isSamplerSet != 1) {
        f_color = u_color;
    } else {
        vec4 tColor = texture(u_texture, v_uv);
        f_color = tColor;
    }
    
    // Scene ambient constant lightning
    vec3 ambient = vec3(f_color) * u_ambient;


    // Vectors

    vec3 view = normalize(-v_position);
    vec3 normal = normalize(v_normal);
    if(isNormalSet == 1) {
        vec3 uv_normal = vec3(texture(u_normalmap, v_uv));
        uv_normal = normalize(uv_normal * 2.0 - 1.0);
        normal =  normalize(mat3(v_model) * uv_normal + v_normal);
    }
    

    

    // Light Constants
    
    
    // Material Constants
    float shininess = u_shininess;
    vec3 specColor;

    float specIntensity = u_specIntensity;
    float Kd = u_kD;

    if(isRoughnessSet == 1) {
        shininess = 1 + shininess * max(log2(texture(u_roughnessmap, v_uv).x) + 1,0.0);
        specIntensity = max(specIntensity * max(log2(texture(u_roughnessmap, v_uv).x + 1),0.0), 0.1);
        specColor *= max(log2(texture(u_roughnessmap, v_uv).x) + 1, 0.0);
    }

    vec3 deffuse = vec3(0,0,0);
    vec3 specular = vec3(0,0,0);


    // Directional Light
    for(int i = 0; i < amountOfDlights; i++) {
        float brightness = dlights[i].brightness;
        vec3 light = normalize(dlights[i].direction);
        vec3 lightColor = dlights[i].color * brightness;

        
        
        if(u_specColor == vec3(-1,-1,-1)) {
            specColor = lightColor * vec3(f_color);
        } else {
            specColor = lightColor * u_specColor;
        }   

        vec3 reflection = reflect(-light, normal);
        vec3 c_deffuse = max(dot(normal, light), 0.0) * vec3(f_color);
        vec3 c_specular = pow(max(dot(reflection, view), 0.0), shininess) * specColor * abs(c_deffuse);

        c_deffuse.x *= lightColor.x;
        c_deffuse.y *= lightColor.y;
        c_deffuse.z *= lightColor.z;

        deffuse += c_deffuse;
        specular += c_specular;
    }

    // Point Light
    for(int i = 0; i < amountOfPlights; i++) {
        float brightness = plights[i].brightness;
        vec3 lightColor = plights[i].color * brightness;
        if(u_specColor == vec3(-1,-1,-1)) {
            specColor = lightColor * vec3(f_color);
        } else {
            specColor = lightColor * u_specColor;
        }  
        float quadratic = plights[i].quadratic;
        float linear = plights[i].linear;

        vec3 light = normalize(plights[i].position - v_vertex_pos);
        vec3 reflection = reflect(-light, normal);

        float dist = length(plights[i].position - v_vertex_pos);
        float attentuation = 1.0 / ((1.0) + (plights[i].linear*dist) + (plights[i].quadratic*dist*dist));
        
        vec3 c_deffuse = attentuation * plights[i].color * max(dot(normal, light), 0.0) * vec3(f_color);
        vec3 c_specular = attentuation * pow(max(dot(reflection, view), 0.0), shininess) * specColor * abs(c_deffuse);

        c_deffuse.x *= lightColor.x;
        c_deffuse.y *= lightColor.y;
        c_deffuse.z *= lightColor.z;

        deffuse += c_deffuse;
        specular += c_specular;
    }

    // Spotlight
    for(int i = 0; i < amountOfSlights; i++) {
        vec3 light = normalize(slights[i].position - v_position);
        vec3 lightColor = slights[i].color * slights[i].brightness;
        if(u_specColor == vec3(-1,-1,-1)) {
            specColor = lightColor * vec3(f_color);
        } else {
            specColor = lightColor * u_specColor;
        }  
        vec3 reflection = reflect(-light, normal);
        float theta = dot(light, slights[i].direction);
        float epsilon = slights[i].innerCone - slights[i].outerCone;
        float intensity = clamp((theta - slights[i].outerCone) / epsilon, 0.0f, 1.0f);
        vec3 c_deffuse = vec3(0);
        vec3 c_specular = vec3(0);
        if(theta > slights[i].outerCone) {
            c_deffuse += intensity * max(dot(normal, light), 0.0) * vec3(f_color);
            c_specular += intensity * pow(max(dot(reflection, view), 0.000001), shininess) * specColor * abs(deffuse);
        } else {
            ambient += u_ambient * slights[i].color * specColor;
        }
        c_deffuse.x *= slights[i].color.x;
        c_deffuse.y *= slights[i].color.y;
        c_deffuse.z *= slights[i].color.z;

        deffuse += c_deffuse;
        specular += c_specular;
    }

    // Lightcolor


    color = vec4(ambient + (deffuse * Kd) + (specular * specIntensity), 1.0);
    

    
    //else color = u_color;
}
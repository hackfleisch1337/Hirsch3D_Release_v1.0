#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 in_normal;


uniform vec3 u_position;
uniform vec3 c_position;

uniform mat4 u_model;
uniform mat4 u_view;

uniform mat4 u_modelViewProj; // = proj * view * model
uniform mat4 u_modelView; // = view * model
uniform mat4 u_invModelView;

out vec2 v_uv;
out vec3 v_normal;
out vec3 v_position;

void main() {

    /*
    vec3 absolutePosition = position + u_position;

    vec4 rotated = u_model * vec4(position, 1.0f);

    vec4 result = rotated + vec4(u_position, 1.0f);
    */


    gl_Position = u_modelViewProj * vec4(position, 1.0f);

    /*
    vec4 rotation = vec4( u_model * vec4(position + u_position, 1.0f) );
    gl_Position = rotation;*/
    v_uv = uv;
    v_normal = mat3(u_model) * in_normal;
    v_position = vec3(u_view  * vec4(position, 1.0f));
}
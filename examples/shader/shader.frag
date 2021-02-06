#version 330 core

layout(location = 0) out vec4 color;
in vec2 v_uv;
uniform sampler2D u_texture;

uniform vec4 u_color;

void main() {

    vec4 texColor = texture(u_texture, v_uv);
    vec4 uni_color = u_color;
    if(texColor == vec4(0.0f)) {
       texColor = vec4(1.0,1.0,1.0,1.0); 
    }
    if(u_color == vec4(0.0f)) {
        uni_color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    }

    color = texColor * uni_color;
}
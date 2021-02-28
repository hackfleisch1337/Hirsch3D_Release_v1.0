#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_color;
in vec2 v_uv;
uniform sampler2D u_texture;
uniform int isSamplerSet;

void main() {
    vec4 f_color = vec4(1);
    if(isSamplerSet != 1) {
        f_color = u_color;        
    } else {
        vec4 tColor = texture(u_texture, v_uv);
        
        
        f_color = tColor;
    }
    if(f_color.a < 0.5) {
        discard;
    } 
    color = f_color;
}
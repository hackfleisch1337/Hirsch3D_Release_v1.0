#version 330 core

in vec2 v_uv;

uniform u_color;
uniform sampler2D u_texture;


void main() {
    gl_FragColor = vec4(texture2D(u_texture, v_uv).a) * u_color;
}
#version 330 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec2 a_uv;

out vec2 v_uv;

uniform mat4 u_modelView;

void main() {
    gl_Position = u_modelView * vec4(vec2(a_position), 0.0f, 1.0f);
    v_uv = a_uv;
}
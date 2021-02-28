#version 330 core
layout(triangles) in;
layout(triangle_strip, max_vertices=3) out;


in vec3 vg_N[];
in vec3 vg_Pos[];
in vec2 vg_TexCoord[];
in mat4 vg_model[];
in vec3 vg_Vertex_Pos[];

out vec3 gf_T;
out vec3 gf_B;
out vec3 v_normal;
out vec3 v_position;
out vec2 v_uv;
out mat4 v_model;
out vec3 v_vertex_pos;

vec3 GetTangent(vec3 A, vec3 B, vec3 C,  vec2 Auv, vec2 Buv, vec2 Cuv)
{
  float Bv_Cv = Buv.y - Cuv.y;
  if(Bv_Cv == 0.0)
    return (B-C)/(Buv.x-Cuv.x);
  
  float Quotient = (Auv.y - Cuv.y)/(Bv_Cv);
  vec3 D   = C   + (B  -C)   * Quotient;
  vec2 Duv = Cuv + (Buv-Cuv) * Quotient;
  return (D-A)/(Duv.x - Auv.x);
}
vec3 GetBitangent(vec3 A, vec3 B, vec3 C,  vec2 Auv, vec2 Buv, vec2 Cuv)
{
  return GetTangent(A, C, B,  Auv.yx, Cuv.yx, Buv.yx);
}

void main(void)
{
    vec3 T = GetTangent(vg_Pos[0], vg_Pos[1], vg_Pos[2],
                      vg_TexCoord[0], vg_TexCoord[1], vg_TexCoord[2]);
    vec3 B = GetBitangent(vg_Pos[0], vg_Pos[1], vg_Pos[2],
                        vg_TexCoord[0], vg_TexCoord[1], vg_TexCoord[2]);

    for(int i=0; i<3; ++i) {
        gf_T = T;
        gf_B = B;
        v_uv = vg_TexCoord[i];
        v_normal = vg_N[i];
        v_position = vg_Pos[i];
        v_model = vg_model[i];
        v_vertex_pos = vg_Vertex_Pos[i];
        gl_Position = gl_in[i].gl_Position;
        EmitVertex();
    }

}
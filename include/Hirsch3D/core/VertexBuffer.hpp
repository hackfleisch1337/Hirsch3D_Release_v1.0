#ifndef HIRSCH3D_VERTEX_BUFFER
#define HIRSCH3D_VERTEX_BUFFER

#include "Vertex.hpp"
#include <iostream>
#include <vector>
#include <GL/glew.h>

namespace h3d
{
    class VertexBuffer {

    public:
        VertexBuffer(void* vertices, uint32_t amountOfVertices);
        void bind();
        void unbind();
        uint32_t getAmountOfVertices();
        virtual ~VertexBuffer();
        void changeVertex(uint32_t vertex, h3d::Vertex3 newVertex);
        h3d::Vertex3 getVertex(uint32_t vertex);
    private:
        uint32_t amountOfVertices;
        GLuint bufferId;
        GLuint vao;
    };
} // namespace h3d


#endif
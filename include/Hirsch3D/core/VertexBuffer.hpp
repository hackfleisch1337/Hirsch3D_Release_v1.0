/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/core/VertexBuffer.hpp
 * @ref Hirsch3d/core
 *
 * @author Emanuel Zache
 * @version 0.9.6
 * @copyright (C) 2021 Emanuel Zache
 *
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *
 */


#ifndef HIRSCH3D_VERTEX_BUFFER
#define HIRSCH3D_VERTEX_BUFFER

#include "Vertex.hpp"
#include <iostream>
#include <vector>
#include <GL/glew.h>

namespace h3d
{
    /**
     * Buffer for vertex data
     * 
     */
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
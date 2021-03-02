/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/core/IndexBuffer.hpp
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


#ifndef HIRSCH3D_INDEX_BUFFER_HPP
#define HIRSCH3D_INDEX_BUFFER_HPP
#include <iostream>
#include <GL/glew.h>

namespace h3d
{
    /**
     * Buffer for index data
     * 
     */
    class IndexBuffer {
        public:
        IndexBuffer(uint32_t* indices, uint32_t amountOfIndices);
        void bind();
        void unbind();
        uint32_t getAmountOfIndices();
        virtual ~IndexBuffer();
    private:
        uint32_t amountOfIndices;
        GLuint bufferId;
    };
} // namespace h3d


#endif
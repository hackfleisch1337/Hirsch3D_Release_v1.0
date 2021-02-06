#ifndef HIRSCH3D_INDEX_BUFFER_HPP
#define HIRSCH3D_INDEX_BUFFER_HPP
#include <iostream>
#include <GL/glew.h>

namespace h3d
{
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
/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/core/Shader.hpp
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


#ifndef HIRSCH3D_SHADER_HPP
#define HIRSCH3D_SHADER_HPP
#include <string>
#include <GL/glew.h>
namespace h3d
{
    #define HIRSCH3D_NO_GEOMETRY_SHADER "nogeometryshader"
    class Shader {
    public:
        /**
         * Loads the Shader
         * 
         * @param vertexShader path to the vertex shader source file
         * @param fragmentShader path to the fragment shader source file
         * @param geometryShader path to the geometry shader source file
         * 
         */
        bool load(std::string vertexShader, std::string fragmentShader, std::string geometryShader="nogeometryshader");
        void bind() const;
        void unbind() const;
        virtual ~Shader();
        /**
         * 
         * @returns the shader id
         */
        GLuint getShaderId() {return shaderId;}
        /**
         * 
         * @returns true if the shader is loaded
         */
        bool loaded() {return this->hasLoaded;}
    private:
        bool hasLoaded = false;
        bool useGeometryShader;
        GLuint compile(std::string shaderSrc, GLenum type);
        std::string parse(const char* filename);
        GLuint createShader(const char*, const char*, const char*);
        GLuint shaderId;
    };
} // namespace h3d



#endif
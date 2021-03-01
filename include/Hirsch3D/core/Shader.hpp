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
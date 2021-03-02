/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/core/Texture.hpp
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


#ifndef HIRSCH3D_TEXTURE_HPP
#define HIRSCH3D_TEXTURE_HPP
#include <string>
#include <cinttypes>
#include <GL/glew.h>

#ifndef YELLOW
#define YELLOW "\033[93m"
#define RED "\033[91m"
#define GREEN "\033[92m"
#define RESET_CLR "\x1B[0m"
#endif
#include <iostream>
namespace h3d
{
    /**
     * A texture for 3D Objects or Sprites
     * 
     */
    class Texture {
    public:
        /**
         * Loads a texture from a file
         * 
         * @param path The path and filename of the texture
         * 
         */
        void load(std::string path);
        void loadTtf(uint8_t* ttfBuffer);
        /**
         * Binds the texture
         * 
         */
        virtual void bind();

        /**
         * Unbinds the texture
         * 
         */
        virtual void unbind();

        virtual ~Texture(){
            std::cout << GREEN << "[OK] Deleted Texture Buffer Data" << RESET_CLR << std::endl;
            glDeleteTextures(1, &buffer);
        }

        /**
         * 
         * @returns the texture width in pixels
         */
        int32_t getWidth() {return width;}

        /**
         * 
         * @returns the texture height in pixels
         */
        int32_t getHeight() {return height;}

        /**
         * 
         * @returns the path of the texture
         */
        std::string getPath() {return this->path;}

        /**
         * 
         * @returns true if the texture is loaded
         */
        bool loaded() { return hasLoaded; }
    protected:
        GLuint buffer;
    private:
        std::string path;
        int32_t width;
        int32_t height;
        
        int32_t bitsPerPixel;
        bool hasLoaded = false;
    };
    /**
     * A map with normal vectors
     * 
     */
    class NormalMap: public Texture {
    public:
        void bind() override;
        void unbind() override;
    };

    /**
     * A grayscale picture wich defines
     * the intensity an roughness of the specular light
     * 
     */
    class RoughnessMap: public Texture {
    public: 
        void bind() override;
        void unbind() override;
    };

} // namespace h3d


#endif
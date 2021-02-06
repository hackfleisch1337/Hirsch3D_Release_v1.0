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
    
    class Texture {
    public:
        void load(std::string path);
        void loadTtf(uint8_t* ttfBuffer);
        void bind();
        void unbind();
        virtual ~Texture(){
            std::cout << GREEN << "[OK] Deleted Texture Buffer Data" << RESET_CLR << std::endl;
            glDeleteTextures(1, &buffer);
        }
        int32_t getWidth() {return width;}
        int32_t getHeight() {return height;}
        std::string getPath() {return this->path;}
        bool loaded() { return hasLoaded; }
    private:
        std::string path;
        int32_t width;
        int32_t height;
        GLuint buffer;
        int32_t bitsPerPixel;
        bool hasLoaded = false;
    };

} // namespace h3d


#endif
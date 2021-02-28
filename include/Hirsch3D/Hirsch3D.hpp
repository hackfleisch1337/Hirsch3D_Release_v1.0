/**
 * @file Hirsch3D/Hirsch3D.hpp
 * @ref Hirsch3d/core
 *
 * @author Emanuel Zache
 * @version 0.9.1
 * @copyright (C) 2021 Emanuel Zache
 *
 * @brief Hirsch3D is a 3D Renderengine based on OpenGl
 * 
 * Hirsch3D.hpp is the main file
 *
 *
 *
 */


#ifndef HIRSCH3D_HPP
#define HIRSCH3D_HPP

#include <iostream>
#include <string>
#include <vector>

#define HIRSCH3D_VERSION "0.9.1"
#define YELLOW "\033[93m"
#define RED "\033[91m"
#define GREEN "\033[92m"
#define RESET_CLR "\x1B[0m"

#include <pthread.h>
#include <string>
#define GLEW_STATIC
#include <GL/glew.h>
#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <ctime>

// Hirsch3D core
#include "core/Vertex.hpp"
#include "core/VertexBuffer.hpp"
#include "core/Texture.hpp"
#include "core/Light.hpp"
#include "core/Object.hpp"
#include "core/Scene.hpp"
#include "core/Camera.hpp"
#include "core/Text.hpp"



namespace h3d {


    class Renderer {
    public:
        void renderObject(const h3d::Object* o) const;
    };

    class Hirsch3D {

    protected:

        virtual void render(const h3d::Renderer&) = 0;
        virtual void setup() = 0;
        virtual void onClose() = 0;

        virtual void onMouseMoved(int relX, int relY, glm::vec2 mouse) {}
        virtual void onKeyDown(SDL_Keycode key) {}
        virtual void onKeyUp(SDL_Keycode key) {}

        void setTitle(std::string);
        void setSize(uint16_t, uint16_t);
    public:
        #define HIRSCH3D_NOFLAG     0b00000000
        #define HIRSCH3D_FULLSCREEN 0b00000001
        #define HIRSCH3D_BORDERLESS 0b00000010
        #define HIRSCH3D_MINIMIZED  0b00000100
        
        bool init(std::string title, uint16_t width, uint16_t height, uint8_t flags);
        bool start();
        bool load();

        virtual ~Hirsch3D();
        void setFps(uint16_t fps) {
            if(fps > 0) {
                this->fps = fps;
            }
        }

        uint32_t getCurrentTimeMillies();

    private:
        SDL_Window* window;
        SDL_GLContext glContext;
        Renderer renderer;
        std::string title;
        uint16_t width;
        uint16_t height;
        uint16_t fps = 60;
        GLuint tBuffer;
        h3d::Shader hirschShader;
        h3d::Object titleScreen;
        clock_t startTime;
        bool showTitle = true;
        bool loaded = false;
    };

    #include "core/Color.hpp"

}


#endif // Hirsch3D.hpp
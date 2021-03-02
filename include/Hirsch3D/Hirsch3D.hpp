/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/Hirsch3D.hpp
 * @ref Hirsch3d/.
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


#ifndef HIRSCH3D_HPP
#define HIRSCH3D_HPP

#include <iostream>
#include <string>
#include <vector>

#define HIRSCH3D_VERSION "0.9.6"
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

#include "error/Exception.hpp"

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

    /**
     * Renders the objects
     * 
     */
    class Renderer {
    public:
        /**
         * 
         * Renders an object. Shaders must be set before.
         *
         * @param o A pointer to the object to be rendered
         */
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

        /**
         * Sets the window title
         * @param s The title to be set
         * 
         */
        void setTitle(std::string s);
        /**
         * Sets the window size
         * @param width The width in pixels
         * @param height The height in pixels
         */
        void setSize(uint16_t width, uint16_t height);
    public:
        #define HIRSCH3D_NOFLAG     0b00000000
        #define HIRSCH3D_FULLSCREEN 0b00000001
        #define HIRSCH3D_BORDERLESS 0b00000010
        #define HIRSCH3D_MINIMIZED  0b00000100
        
        /**
         * Inits the Hirsch3D Programm
         * 
         * @returns true on success
         * 
         * @param title The window title
         * @param width The window with
         * @param height The window height
         * @param flags Flags
         * 
         */
        bool init(std::string title, uint16_t width, uint16_t height, uint8_t flags);
        /**
         * Starts the programm. Initialized and loaded requiered before.
         */
        void start();

        /**
         * Loads the programms resources.
         * Initialization requiered before.
         * @returns true on success
         * 
         */
        bool load();

        virtual ~Hirsch3D();

        /**
         * Sets the maximum framerate. Default framerate: 60 fps
         * 
         * @param fps the amount of maximal frames per second
         * 
         */
        void setFps(uint16_t fps) {
            if(fps > 0) {
                this->fps = fps;
            }
        }

        /**
         * Returns the amount of time since the start of the programm in millisecond.
         */
        uint32_t getCurrentTimeMillis();

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
/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/core/Scene.hpp
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


#ifndef HIRSCH3D_SCENE_HPP
#define HIRSCH3D_SCENE_HPP
#include <vector>
#include "Object.hpp"
#include "../Hirsch3D.hpp"
#include "Camera.hpp"


namespace h3d
{
    class Renderer;

    /**
     * Renderstate for 3D objects
     *
     *
     *
     *
     *
     *
     */
    class Scene {
    public:
        /**
         * Inititalizes the scene
         * 
         * @param vertexShaderSrc path to the vertex shader source file
         * @param fragmentShaderSrc path to the fragment shader source file
         * @param geometryShaderSrc path to the geometry shader source file
         * @param camera Pointer to the scenes camera
         * @param ambient intensity of the scenes ambient light (default=0.1f)
         * 
         */
        void load(std::string vertexShaderSrc, std::string fragmentShaderSrc, std::string geometryShaderSrc,h3d::Camera* camera, float ambient = 0.1f);
        
        /**
         * Inititalizes the scene with the default shader
         * 
         * @param camera Pointer to the scenes camera
         * @param ambient intensity of the scenes ambient light (default=0.1f)
         * 
         */
        void load(h3d::Camera* camera, float ambient = 0.1f);

        /**
         * Adds an object to the scene
         * 
         * @param o A pointer to the object
         * 
         */
        void addObject(h3d::Object* o);

        /**
         * Adds a directional light to the scene
         * 
         * @param l A pointer to the directional light
         * 
         */
        void addDirectionalLight(h3d::DirectionalLight* l);

        /**
         * Adds a point light to the scene
         * 
         * @param l A pointer to the point light
         * 
         */
        void addPointLight(h3d::PointLight* l);

        /**
         * Adds a spot light to the scene
         * 
         * @param l A pointer to the spot light
         * 
         */
        void addSpotLight(h3d::SpotLight* l);

        /**
         * Renders the scene
         * 
         * 
         * @param r The Hirsch3D Renderer
         */
        virtual void render(const h3d::Renderer &r);
        
        float ambient;
    protected:
        h3d::Shader shader;
        std::vector<h3d::Object*> objects;
        std::vector<h3d::DirectionalLight*> dlights;
        std::vector<h3d::PointLight*> plights;
        std::vector<h3d::SpotLight*> slights;
        h3d::Camera* camera;
        bool isLoaded = false;
    };

    /**
     * Renderstate to render 2D objects
     *
     *
     *
     */
    class Scene2D: public Scene {
    public:
        /**
         * Loads a 2D scene
         * 
         * @param width The width of the scene in pixels
         * @param height The height of the scene in pixels
         * 
         */
        void load2D(float width, float height);

        /**
         * Renders the scene
         * 
         * 
         * @param r The Hirsch3D Renderer
         */
        void render(const h3d::Renderer &r) override;
    private:

        h3d::Camera c2d;
    };

} // namespace h3d


#endif

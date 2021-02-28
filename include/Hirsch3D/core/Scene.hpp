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
     * Renderstate
     *
     *
     *
     *
     *
     *
     */

    class Scene {
    public:
        void load(std::string vertexShaderSrc, std::string fragmentShaderSrc, std::string geometryShaderSrc,h3d::Camera* camera, float ambient = 0.1f);
        void load(h3d::Camera* camera, float ambient = 0.1f);
        void addObject(h3d::Object* o);
        void addDirectionalLight(h3d::DirectionalLight* l);
        void addPointLight(h3d::PointLight* l);
        void addSpotLight(h3d::SpotLight* l);
        virtual void render(const h3d::Renderer &r);
        float ambient;

    protected:
        h3d::Shader shader;
        std::vector<h3d::Object*> objects;
        std::vector<h3d::DirectionalLight*> dlights;
        std::vector<h3d::PointLight*> plights;
        std::vector<h3d::SpotLight*> slights;
        h3d::Camera* camera;
    };

    /**
     * Renderstate to render 2D objects
     *
     *
     *
     */

    class Scene2D: public Scene {
    public:
        void load2D(float width, float height);
        void render(const h3d::Renderer &r) override;
    private:

        h3d::Camera c2d;
    };

} // namespace h3d


#endif

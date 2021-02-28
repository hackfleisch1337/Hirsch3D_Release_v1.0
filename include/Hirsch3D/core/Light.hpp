#ifndef HIRSCH3D_LIGHT_HPP
#define HIRSCH3D_LIGHT_HPP
#include "../../glm/glm/glm.hpp"
#define MAX_LIGHTS_ 10

namespace h3d
{
   
    struct DirectionalLight {
        glm::vec3 direction;
        glm::vec3 color;
        float brightness;
    };

    struct PointLight {
        glm::vec3 position;
        glm::vec3 color;
        float brightness;
        float linear;
        float quadratic;

    };

    struct SpotLight {
        glm::vec3 position;
        glm::vec3 direction;
        glm::vec3 color;
        float brightness;
        float innerCone;
        float outerCone;
    };


} // namespace h3d



#endif
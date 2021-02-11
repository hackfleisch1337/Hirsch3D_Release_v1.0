#ifndef HIRSCH3D_MATERIAL_HPP
#define HIRSCH3D_MATERIAL_HPP
#include "glm/glm/glm.hpp"
namespace h3d
{
    struct Material {

        float kS;
        float kD;
        float roughness;
        glm::vec3 specColor = {-1,-1,-1};
        
    };
} // namespace h3d



#endif
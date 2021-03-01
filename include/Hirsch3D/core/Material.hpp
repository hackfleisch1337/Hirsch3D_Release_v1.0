#ifndef HIRSCH3D_MATERIAL_HPP
#define HIRSCH3D_MATERIAL_HPP
#include "glm/glm/glm.hpp"
namespace h3d
{
    struct Material {

        // Specular intensity
        float kS;
        // Deffuse intensity
        float kD;
        // roughness
        float roughness;
        // Specular color ( {-1,-1,-1} = fragment color )
        glm::vec3 specColor = {-1,-1,-1};
        
    };
} // namespace h3d



#endif
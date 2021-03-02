/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/core/Material.hpp
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


#ifndef HIRSCH3D_MATERIAL_HPP
#define HIRSCH3D_MATERIAL_HPP
#include "glm/glm/glm.hpp"
namespace h3d
{
    /**
     * The material of an object
     * 
     */
    struct Material {

        // Specular intensity
        float kS;
        // Deffuse intensity
        float kD;
        // roughness
        float roughness;
        // Specular color ( {-1,-1,-1} = fragment color )
        glm::vec3 specColor = {-1,-1,-1};
        
        // Color the object emmits
        glm::vec3 emmisive = {0,0,0};
        
    };
} // namespace h3d



#endif
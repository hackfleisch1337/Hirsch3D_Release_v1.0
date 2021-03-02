/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/core/Vertex.hpp
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


#ifndef HIRSCH3D_VERTEX
#define HIRSCH3D_VERTEX



namespace h3d
{
    /**
     * Defines a vertex
     * 
     * 
     */
    struct Vertex3 {

        // Position
        float x;
        float y;
        float z;

        // Texture Coords
        float u;
        float v;

        // Normal
        float nx;
        float ny;
        float nz;
    };

    #define H3D_QUAD_VERTICES(width, height) { {-width, -height, 0.0,  0.0,  0.0,  0,0,0}, \
        {width, -height,  0.0,  1.0,  0.0,  0,0,1}, \
        {width,  height,  0.0,  1.0,  1.0,  0,0,1}, \
        {-width,  height, 0.0,  0.0,  1.0,  0,0,1}}

    #define H3D_QUAD_INDICES {0,1,2, 0,2,3}

    #define H3D_CUBE_VERTICES(x,y,z) {-x, -y, 0.0,  0.0,  0.0,  0,0,1}, \
        {x, -y,  0.0,  1.0,  0.0,  0,0,1}, \
        {x,  y,  0.0,  1.0,  1.0,  0,0,1}, \
        {-x,  y, 0.0,  0.0,  1.0,  0,0,1} \
        {-x, -y, z,  0.0,  0.0,  0,0,-1}, \
        {x, -y,  z,  1.0,  0.0,  0,0,-1}, \
        {x,  y,  z,  1.0,  1.0,  0,0,-1}, \
        {-x,  y, z,  0.0,  1.0,  0,0,-1}
    #define H3D_CUBE_INDICES {0,1,2,0,2,3}

} // namespace h3d




#endif
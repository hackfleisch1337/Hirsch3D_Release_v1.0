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
} // namespace h3d




#endif
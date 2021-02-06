#ifndef HIRSCH3D_TEXT_HPP
#define HIRSCH3D_TEXT_HPP
#include <string>
#include "../Include/stb/stb_truetype.h"
#include "Object.hpp"
namespace h3d
{
    
class Text: public Sprite {

public:

    void loadText(std::string text, std::string font, uint16_t fontsize, glm::vec4 color, float x, float y);
    

private:

    stbtt_bakedchar cdata[96];
    h3d::Texture fontTex;
};



} // namespace h3d



#endif
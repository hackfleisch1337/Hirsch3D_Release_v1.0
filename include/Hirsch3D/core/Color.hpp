#ifndef HIRSCH3D_COLOR_HPP
#define HIRSCH3D_COLOR_HPP
#include "glm/glm/glm.hpp"

namespace color {
        #define RGB_TO_OPENGL(r,g,b) glm::vec4((float)r/255,(float) g/255, (float)b/255, 1)

        // RED
        const glm::vec4 red(1.0f, 0.0f, 0.0f, 1.0f);
        const glm::vec4 outrageous_orange = RGB_TO_OPENGL(252.0f, 119.0f, 83.0f);
        const glm::vec4 english_red = RGB_TO_OPENGL(159.0f, 74.0f, 84.0f);
        const glm::vec4 english_violet = RGB_TO_OPENGL(89.0f, 63.0f, 98.0f);
        const glm::vec4 golden = RGB_TO_OPENGL(207.0f, 181.0f, 59.0f);

        // GREEN
        const glm::vec4 green(0.0f, 1.0f, 0.0f, 1.0f);
        const glm::vec4 yellow(1.0f, 1.0f, 0.0f, 1.0f);
        const glm::vec4 spring_green = RGB_TO_OPENGL(94.0f, 252.0f, 141.0f);
        const glm::vec4 celadon_green = RGB_TO_OPENGL(54.0f, 130.0f, 127.0f);
        const glm::vec4 magic_mint = RGB_TO_OPENGL(174.0f, 255.0f, 216.0f);
        const glm::vec4 army_green = RGB_TO_OPENGL(65.0f, 82.0f, 31.0f);
        const glm::vec4 yellow_green(0.8f, 0.61f, 0.5f, 1.0f);

        // BLUE
        const glm::vec4 blue(0.0f, 0.0f, 1.0f, 1.0f);
        const glm::vec4 cyan(0.0f, 1.0f, 0.0f, 1.0f);
        const glm::vec4 midnight_blue = RGB_TO_OPENGL(7.0f, 0.0f, 77.0f);
        const glm::vec4 cobalt_blue = RGB_TO_OPENGL(0.0f, 75.0f, 168.0f);

        // BLACK
        const glm::vec4 black(0.0f, 0.0f, 0.0f, 1.0f);
        const glm::vec4 dark_purple = RGB_TO_OPENGL(28.0f, 1.0f, 24.0f);

        // WHITE
        const glm::vec4 white(1.0f, 1.0f, 1.0f, 1.0f);
        const glm::vec4 snow = RGB_TO_OPENGL(255.0f, 250.0f, 250.0f);
        const glm::vec4 dim_gray = RGB_TO_OPENGL(113.0f, 105.0f, 105.0f);
        const glm::vec4 bone = RGB_TO_OPENGL(217.0f, 207.0f, 193.0f);     
        const glm::vec4 silver = RGB_TO_OPENGL(219.0f, 219.0f, 219.0f);     
    };

#endif
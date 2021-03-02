/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/core/Camera.hpp
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


#ifndef HIRSCH3D_CAMERA_HPP
#define HIRSCH3D_CAMERA_HPP

#include "glm/glm/glm.hpp"
#include "glm/glm/ext/matrix_transform.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

namespace h3d
{
    /**
     * A camera which rotates around the origin
     * 
     */
    class Camera {
    public:
        /**
         * Inititalizes a perspective camera
         * 
         * @param fov The fiels of view in degrees
         * @param width The width of the viewspace
         * @param height The height of the viewspace
         * 
         */
        void init(float fov, float width, float height);

        /**
         * Initializes a orthographic camera
         * 
         * @param viewSpaceWidth The width of the viewspace
         * @param viewSpaceHeight The height of the viewspace
         */
        void init(float viewSpaceWidth, float viewSpaceHeight) ;


        /**
         * @returns View Projection matrix (projection * view)
         * 
         */
        glm::mat4 getViewProj();

        /**
         * Updates the cameras position and viewing direction
         */
        virtual void update();

        /**
         * moves the camera
         */
        virtual void translate(glm::vec3 v);

        /**
         * Returns the camera around the origin
         */
        void rotate(float degree, glm::vec3 d);

        /**
         * @returns The view matrix
         * 
         */
        glm::mat4 getView();


        /**
         * 
         * @returns The cameras position
         */
        glm::vec3 getPosition();

protected:
        glm::vec3 pos;
        glm::mat4 projection;
        glm::mat4 view;
        glm::mat4 viewProj;
        bool initialized = false;
};
/**
 * A camera which rotates around its own center on the y and x axis
 * 
 */
class FpsCamera: public Camera {
public:
    /**
     * Initializes a first person camera
     * 
     * @param fov The fiels of view in degrees
     * @param width The width of the viewspace
     * @param height The height of the viewspace
     * 
     */
    void initFpsCamera(float fov, float width, float height);
    
    /**
     * Rotates the camera
     * 
     * @param xRel The angle to rotate around the x axis
     * @param yRel The angle to rotate around the y axis
     */
    void rotate(float xRel, float yRel);


    /**
     * Updated the cameras position and rotation
     * 
     */
    void update() override;

    /**
     * Moves the camera in their viewing direction
     * @param amount The amount the camera moves
     */
    void moveFront(float amount);

    /**
     * Moves the camera sideways relative to their viewing direction
     * @param amount The amount the camera moves
     * 
     */
    void moveSideways(float amount);

    /**
     * Moves the camera up relative to the viewspace
     * @param amount The amount the camera moves
     * 
     */
    void moveUp(float amount);

protected:

    float yaw;
    float pitch;
    glm::vec3 lookAt;
    const float mouseSensitivityX = 0.15f;
    const float mouseSensitivityY = 0.15f;
    glm::vec3 up;
};

} // namespace h3d




#endif
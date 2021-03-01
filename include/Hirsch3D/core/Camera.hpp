#ifndef HIRSCH3D_CAMERA_HPP
#define HIRSCH3D_CAMERA_HPP

#include "glm/glm/glm.hpp"
#include "glm/glm/ext/matrix_transform.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

namespace h3d
{
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
        void init(float fov, float width, float height) {
            projection = glm::perspective((float) glm::radians(fov)/2.0f, width/height, 0.01f, 1000.0f);
            view = glm::mat4(1.0f);
            pos = glm::vec3(0.0f);
            initialized = true;
            update();
        }

        /**
         * Initializes a orthographic camera
         * 
         * @param viewSpaceWidth The width of the viewspace
         * @param viewSpaceHeight The height of the viewspace
         */
        void init(float viewSpaceWidth, float viewSpaceHeight) {
            projection = glm::ortho(- (viewSpaceWidth/2), viewSpaceWidth/2, -(viewSpaceHeight/2), viewSpaceHeight/2);
            view = glm::mat4(1.0f);
            pos = glm::vec3(0.0f);
            initialized = true;
            update();
        }

        glm::mat4 getViewProj() {
            return this->viewProj;
        }

        /**
         * Updates the cameras position and viewing direction
         */
        virtual void update() {
            if(!initialized) return;
            viewProj = projection * view;
        }

        /**
         * moves the camera
         */
        virtual void translate(glm::vec3 v) {
            if(!initialized) return;
            pos += v;
            view = glm::translate(view, v * -1.0f);
        }

        /**
         * Returns the camera around the origin
         */
        void rotate(float degree, glm::vec3 d) {
            if(!initialized) return;
            this->view = glm::rotate(this->view, glm::radians(degree), d);
        }

        glm::mat4 getView() {
            return view;
        }

        glm::vec3 getPosition() {
            return pos;
        }

protected:
        glm::vec3 pos;
        glm::mat4 projection;
        glm::mat4 view;
        glm::mat4 viewProj;
        bool initialized = false;
};

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
    void initFpsCamera(float fov, float width, float height) {
        this->init(fov, width, height);
        up = glm::vec3(0.0f,1.0f,0.0f);
        yaw = -90.0f;
        pitch = 0.0f;
        initialized = true;
        rotate(0.0f, 0.0f);
        update();
    }
    
    /**
     * Rotates the camera
     */
    void rotate(float xRel, float yRel) {
        if(!initialized) return;
        yaw += xRel * mouseSensitivityX;
        pitch -= yRel * mouseSensitivityY;
        if(pitch > 89.0f)
            pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;
        glm::vec3 front;
        front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        front.y = sin(glm::radians(pitch));
        front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
        lookAt = glm::normalize(front);
        update();
    }

    void update() override {
        if(!initialized) return;
        view = glm::lookAt(pos, pos + lookAt, up);
        viewProj = projection * view;
    }

    void moveFront(float amount) {
        if(!initialized) return;
        translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f)*lookAt) * amount);
        update();
    }
    void moveSideways(float amount) {
        if(!initialized) return;
        translate(glm::normalize(glm::cross(lookAt, up)) * amount);
        update();
    }


    void moveUp(float amount) {
        if(!initialized) return;
        translate(glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f)) * amount);
        update();
    }

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
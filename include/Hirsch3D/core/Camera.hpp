#ifndef HIRSCH3D_CAMERA_HPP
#define HIRSCH3D_CAMERA_HPP

#include "glm/glm/glm.hpp"
#include "glm/glm/ext/matrix_transform.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

namespace h3d
{
    class Camera {
    public:
        // Perspective camera
        void init(float fov, float width, float height) {
            projection = glm::perspective((float) glm::radians(fov)/2.0f, width/height, 0.01f, 1000.0f);
            view = glm::mat4(1.0f);
            pos = glm::vec3(0.0f);
            update();
        }

        // Orthographic camera
        void init(float viewSpaceWidth, float viewSpaceHeight) {
            projection = glm::ortho(- (viewSpaceWidth/2), viewSpaceWidth/2, -(viewSpaceHeight/2), viewSpaceHeight/2);
            view = glm::mat4(1.0f);
            pos = glm::vec3(0.0f);
            update();
        }

        glm::mat4 getViewProj() {
            return this->viewProj;
        }

        virtual void update() {
            viewProj = projection * view;
        }

        virtual void translate(glm::vec3 v) {
            pos += v;
            view = glm::translate(view, v * -1.0f);
        }

        void rotate(float degree, glm::vec3 d) {
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

};

class FpsCamera: public Camera {
public:
    void initFpsCamera(float fov, float width, float height) {
        this->init(fov, width, height);
        up = glm::vec3(0.0f,1.0f,0.0f);
        yaw = -90.0f;
        pitch = 0.0f;
        rotate(0.0f, 0.0f);
        update();
    }

    void rotate(float xRel, float yRel) {
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
        view = glm::lookAt(pos, pos + lookAt, up);
        viewProj = projection * view;
    }

    void moveFront(float amount) {
        translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f)*lookAt) * amount);
        update();
    }
    void moveSideways(float amount) {
        translate(glm::normalize(glm::cross(lookAt, up)) * amount);
        update();
    }


    void moveUp(float amount) {
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
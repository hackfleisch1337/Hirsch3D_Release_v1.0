#ifndef HIRSCH3D_OBJECT
#define HIRSCH3D_OBJECT
#include <string>
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "glm/glm/glm.hpp"
#include "glm/glm/ext/matrix_transform.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "Material.hpp"
#include "Texture.hpp"
#include <fstream>



namespace h3d
{
    class Object {
    public:
        
        virtual ~Object();

        /**
         * Loads an object from the vertex and index data.
         * 
         * @param vertices A h3d::Vertex3 array of the vertices from the object
         * @param amountOfvertices The amount of vertices the object has
         * @param indices A uint32_t array of indices from the object
         * @param amountOfIndices The amount of indices the object has
         * @param color The color of the object if no texture is set or could be loaded
         * @param texure The texture for the object. nullptr = no texture
         * @param nmap The normalmap for the object. nullptr = no normalmap
         * @param r The roughnessmap for the object. nullptr = no roughnessmap
         * 
         * 
         */
        void load(void* vertices, uint32_t amountOfVertices, uint32_t* indices, uint32_t amountOfIndices, glm::vec4 color,
                    h3d::Texture *texture, h3d::NormalMap* nmap, h3d::RoughnessMap* r);

        /**
         * Loads an object from a .obj file
         * 
         * @param path The path to the .obj file
         * @param color The color of the object if no texture is set or could be loaded
         * @param texure The texture for the object. nullptr = no texture
         * @param nmap The normalmap for the object. nullptr = no normalmap
         * @param r The roughnessmap for the object. nullptr = no roughnessmap
         * 
         */
        void loadByPath(std::string path, glm::vec4 color, h3d::Texture* texture, h3d::NormalMap* nmap, h3d::RoughnessMap* r);

        /**
         * @returns the vertex buffer
         */
        VertexBuffer* getVertexBuffer() const {
            return this->vertices;
        }
        /**
         * 
         * @returns the index buffer
         */
        IndexBuffer* getIndexBuffer() const {
            return this->indices;
        }

        /**
         * @returns the model matrix
         */
        glm::mat4 getMatrix() {return modelMatrix;}

        /**
         * Rotates the object
         * 
         * @param degree the angle in degrees
         * @param direction the direction to rotate
         * 
         */
        void rotate(float degree, glm::vec3 direction);

        /**
         * Sets the rotation to an exact angle
         * 
         * @param r The vector of the angles in degree
         */
        void setRotation(glm::vec3 r);
        
        /**
         * @returns true if the object has loaded
         */
        bool loaded() const {return hasLoaded;}
        /**
         * moves the object
         * 
         * @param d The amount to move in every direction
         */
        void move(glm::vec3 d);

        /**
         * moves the object relativ to their viewing direction
         * @param d the amount to move in every direction
         */
        void moveInLineOfSight(glm::vec3 d);

        /**
         * Sets the material from the object
         * 
         * @param m The material
         */
        void setMaterial(h3d::Material m);

        /**
         * @returns the position
         */
        glm::vec3 getPosition();

        glm::vec3 position;
        glm::vec4 color;
        /**
         * @returns the texture
         */
        h3d::Texture* getTexture() {return texture;}
        
        /**
         * @returns the rotation
         */
        glm::vec3 getRotation() {return this->rotationVector;}
        h3d::NormalMap* getNormalMap() {return this->nmap;}
        h3d::RoughnessMap* getRoughnessMap() {return this->rm;}
        /**
         * @returns the material
         */
        h3d::Material getMaterial() {return this->material;}
    protected:
        glm::mat4 modelMatrix;
        glm::vec3 rotationVector;
        h3d::VertexBuffer* vertices;
        std::string objPath;
        uint32_t amountOfVertices;
        bool hasLoaded = false;
        h3d::IndexBuffer* indices;
        uint32_t amountOfIndices;
        h3d::Texture* texture;
        h3d::NormalMap* nmap;
        h3d::RoughnessMap* rm;
        h3d::Material material;
    };

    class Sprite: public h3d::Object {

    public:

        void load(h3d::Texture* t, float x, float y, float w = 0, float height = 0);
        void move(float x, float y);
        void rotate(float degree);
    };

} // namespace h3d



#endif
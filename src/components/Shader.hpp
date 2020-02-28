#ifndef shader_hpp
#define shader_hpp

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <string>

#include "Light.hpp"
#include "Transform.hpp"

// TODO: separate vertex and fragment shader
//       VertexShader provide interface to update model/view/projection
//       FragmentShader closely related with Material to Set visual effect
//       Shader organize VertexShader and FragmentShader

class Shader {
public:
    static Shader& DefaultShader();
    static Shader& TestShader();

    Shader(const GLchar *vertexPath,
           const GLchar *fragmentPath,
           const GLchar *geometryPath = nullptr);
    Shader();

    // "Activate" the shader
    void UseShaderProgram();

    // Uniform setting
    void Set(const std::string &name, bool value) const;
    void Set(const std::string &name, int value) const;
    void Set(const std::string &name, unsigned value) const;
    void Set(const std::string &name, float value) const;
    void Set(const std::string &name, const glm::vec2 &value) const;
    void Set(const std::string &name, float x, float y) const;
    void Set(const std::string &name, const glm::vec3 &value) const;
    void Set(const std::string &name, float x, float y, float z) const;
    void Set(const std::string &name, const glm::vec4 &value) const;
    void Set(const std::string &name, float x, float y, float z, float w) const;
    void Set(const std::string &name, const glm::mat2 &mat) const;
    void Set(const std::string &name, const glm::mat3 &mat) const;
    void Set(const std::string &name, const glm::mat4 &mat) const;

    // Specific Uniform Settings
    void SetLight(Light const& light);
    void SetTransform(Transform const& transform);
    void SetProjectionView(glm::mat4 projection, glm::mat4 view);

private:
    // The shader program id
    unsigned int id = 0;

    void checkCompileErrors(GLuint shader, const std::string &type,
                                           std::string path);
};

#endif /* shader_hpp */

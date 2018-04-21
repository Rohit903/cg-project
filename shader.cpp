/*
 * Copyright (C) 2018 shishirdongre
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include "shader.h"

Shader::Shader(const std::string& fileName) {
    program = glCreateProgram();
    shaders[0] = createShader(loadShader(fileName + ".vs"), GL_VERTEX_SHADER);
    shaders[1] = createShader(loadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

    for (unsigned int i = 0; i < NUM_SHADERS; i++)
        glAttachShader(program, shaders[i]);

    //Layout qualifier in GLSL wins if there is a conflict
    //    glBindAttribLocation(program, 0, "position");
    //    glBindAttribLocation(program, 1, "texCoord");
    //    glBindAttribLocation(program, 2, "normal");

    glLinkProgram(program);
    checkShaderError(program, GL_LINK_STATUS, true, "Error linking shader program");

    glValidateProgram(program);
    checkShaderError(program, GL_LINK_STATUS, true, "Invalid shader program");

    //    m_uniforms[0] = glGetUniformLocation(program, "MVP");
    //    m_uniforms[1] = glGetUniformLocation(program, "Normal");
    //    m_uniforms[2] = glGetUniformLocation(program, "lightDirection");
}

Shader::~Shader() {
    for (unsigned int i = 0; i < NUM_SHADERS; i++) {
        glDetachShader(program, shaders[i]);
        glDeleteShader(shaders[i]);
    }
    glDeleteProgram(program);
}



//void Shader::Update(const Transform& transform, const Camera& camera) {
//    glm::mat4 MVP = transform.GetMVP(camera);
//    glm::mat4 Normal = transform.GetModel();
//
//    glUniformMatrix4fv(m_uniforms[0], 1, GL_FALSE, &MVP[0][0]);
//    glUniformMatrix4fv(m_uniforms[1], 1, GL_FALSE, &Normal[0][0]);
//    glUniform3f(m_uniforms[2], 0.0f, 0.0f, 1.0f);
//}

std::string Shader::loadShader(const std::string& fileName) {
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            output.append(line + "\n");
        }
    } else {
        std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

GLuint Shader::createShader(const std::string& text, unsigned int type) {
    GLuint shader = glCreateShader(type);

    if (shader == 0)
        std::cerr << "Error creating a shader type " << type << std::endl;

    const GLchar * p;
    p = text.c_str();
    GLint length;
    length = text.length();

    glShaderSource(shader, 1, &p, &length);
    glCompileShader(shader);
    std::string message;
    
    if(type == GL_VERTEX_SHADER) {
        message = "Error compiling vertex shader";
    }
    
    if(type == GL_FRAGMENT_SHADER) {
        message = "Error compiling fragment shader";
    }
   
   
    checkShaderError(shader, GL_COMPILE_STATUS, false, message);

    return shader;
}

void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
    GLint success = 0;
    GLchar error[1024] = {0};

    if (isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if (success == GL_FALSE) {
        if (isProgram)
            glGetProgramInfoLog(shader, sizeof (error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof (error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

void Shader::bind() {
    glUseProgram(program);
}

void Shader::setUniform(float u) {
    int uniformLocation = glGetUniformLocation(shaders[0], "uniformColor");
    //Setting G of RGB in the uniform
    glUniform4f(uniformLocation, 0.0, u, 0.0, 1.0);
}

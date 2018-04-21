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

/* 
 * File:   shader.h
 * Author: shishirdongre
 *
 * Created on March 28, 2018, 2:38 PM
 */

#ifndef SHADER_H
#define SHADER_H

#include <string>
//#include "transform.h"

class Shader {
public:
    Shader(const std::string& fileName);

    void bind();
    void setUniform(float u);

    //void update(const Transform& transform, const Camera& camera);

    virtual ~Shader();
protected:
private:
    static const unsigned int NUM_SHADERS = 2;
    static const unsigned int NUM_UNIFORMS = 3;

    void operator=(const Shader& shader) {
    }

    //    Shader(const Shader& shader) {
    //    }

    std::string loadShader(const std::string& fileName);
    void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    GLuint createShader(const std::string& text, unsigned int type);

    GLuint program;
    GLuint shaders[NUM_SHADERS];
    GLuint m_uniforms[NUM_UNIFORMS];
};
#endif /* SHADER_H */


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
 * File:   mesh.h
 * Author: shishirdongre
 *
 * Created on April 12, 2018, 12:54 PM
 */

#ifndef MESH_H
#define MESH_H
#include "shader.h"
#include <glm/glm.hpp>  
#include <string>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};
//struct Vertex {
  //  GLfloat
//};

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh {
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    //Temporary constructor. Remove after implementing model loading
    Mesh(std::vector<float> vertices, std::vector<unsigned int> indices);
    void draw(Shader shader);
    virtual ~Mesh();
private:
    unsigned int VBO, VAO, EBO;
    std::vector<Mesh> meshes;
    std::string directory;
    void setupMesh();
    void loadModel(std::string path);
    //void processNode(aiNode *node, const aiScene *scene);
    //Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    //std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
//    unsigned int TextureFromFile(const char *path, const std::string* directory, bool gamma);
};

#endif /* MESH_H */


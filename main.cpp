#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<math.h>
#include<cstdlib>
#include <iostream>
#include <vector>
#include "shader.h"
#include "game.h"
#include "mesh.h"
#include "meshvertices.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    Game game(SCR_WIDTH, SCR_HEIGHT);

    if (game.initFailed) {
        std::cerr << "Failed to initialize the game" << std::endl;
        return -1;
    }
    GLFWwindow* window = game.window;

    Shader shader("game_shader");
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices = cube_indices;
    std::vector<Texture> textures;

    //Set up mesh from cube_vertices

    Vertex v;
    for (int i = 0; i < cube_vertices.size(); i += 3) {
        v.position.x = cube_vertices[i];
        v.position.y = cube_vertices[i + 1];
        v.position.z = cube_vertices[i + 2];
        vertices.push_back(v);
    }

    Mesh mesh(vertices, indices, textures);

    while (!glfwWindowShouldClose(window)) {
        //Draw mesh
        //glClear(GL_COLOR_BUFFER_BIT);
        shader.bind();
        //glEnable(GL_DEPTH_TEST);
        //glDepthFunc(GL_LESS);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        mesh.draw(shader);
        glfwSwapBuffers(window);
        //Event polling done after buffer swapping
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}


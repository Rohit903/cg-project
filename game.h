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
 * File:   game.h
 * Author: shishirdongre
 *
 * Created on April 11, 2018, 9:45 PM
 */

#ifndef GAME_H
#define GAME_H
#include<GLFW/glfw3.h>

enum GameState {
    GAME_FIRST_SCREEN,
    GAME_ACTIVE,
    GAME_END
};
class Game {
public:
    Game(GLuint width, GLuint height);
    //Register callbacks
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

    void update(GLfloat dt);
    void render();
    virtual ~Game();
    GLFWwindow* window;
    bool initFailed;
private:
    GameState state;
    GLboolean keys[1024];
    GLuint width, height;
};




#endif /* GAME_H */


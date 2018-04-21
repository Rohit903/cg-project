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
 * File:   meshvertices.h
 * Author: shishirdongre
 *
 * Created on April 19, 2018, 3:48 PM
 */

#ifndef MESHVERTICES_H
#define MESHVERTICES_H

#include<vector>

#define P 0.5

const std::vector<float> cube_vertices = {
    //Vertices in the top plane
    P, P, P,
    -P, P, P,
    -P, P, -P,
    P, P, -P,
    //Vertices in the bottom plane
    P, -P, P,
    -P, -P, P,
    -P, -P, -P,
    P, -P, -P,
};

const std::vector<unsigned int> cube_indices = {
    //Top
    0, 1, 2,
    0, 2, 3,
    //Right
    0, 3, 4,
    0, 4, 7,
    //Front
    0, 1, 5,
    0, 4, 5,
    //Left
    1, 5, 6,
    1, 2, 6,
    //Back
    2, 3, 7,
    2, 6, 7,
    //Bottom
    4, 5, 7,
    4, 6, 2,
};

#endif /* MESHVERTICES_H */


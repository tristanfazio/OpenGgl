/***********************************************
 * TITLE: trees.hpp
 * AUTHOR: Tristan Fazio
 * UNIT: Computer Graphics
 * DATE: 10/19
 * PURPOSE: header file for the trees object
 **********************************************/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "shaders/shader.h"

void drawTrees(unsigned int texture, glm::mat4 view, glm::mat4 projection);

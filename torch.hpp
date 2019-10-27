/***********************************************
 * TITLE: torchs.hpp
 * AUTHOR: Tristan Fazio
 * UNIT: Computer Graphics
 * DATE: 10/19
 * PURPOSE: header file for the torchs object
 **********************************************/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "shaders/shader.h"

void drawTorch(unsigned int tex_wood, glm::mat4 view, glm::mat4 projection, glm::vec3 cameraPos, bool torchEquipped);

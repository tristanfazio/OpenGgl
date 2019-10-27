/***********************************************
 * TITLE: watersheep.hpp
 * AUTHOR: Tristan Fazio
 * UNIT: Computer Graphics
 * DATE: 10/19
 * PURPOSE: header file for the watersheep object
 **********************************************/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <iostream>

#include "shaders/shader.h"


void drawWatersheep(unsigned int texture,glm::mat4 view, glm::mat4 projection, glm::vec3 cameraPos,float cameraSpeed, bool svenEquipped);

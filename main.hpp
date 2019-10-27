/***********************************************
 * TITLE: main.hpp
 * AUTHOR: Tristan Fazio
 * UNIT: Computer Graphics
 * DATE: 10/19
 * PURPOSE:
 **********************************************/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaders/shader.h"
#include "ground.hpp"
#include "trees.hpp"
#include "wall.hpp"
#include "sven.hpp"
#include "watersheep.hpp"
#include "torch.hpp"
#include "utils/textureloader.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
GLFWwindow* initWindow(int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void restart();
void toggleProj();
void toggle_sven_distance();
void toggle_torch_distance();

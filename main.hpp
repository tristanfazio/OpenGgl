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

#include "ground.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
GLFWwindow* initWindow(int width, int height);
void render(GLFWwindow* window);
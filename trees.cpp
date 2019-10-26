/***********************************************
 * TITLE: trees.cpp
 * AUTHOR: Tristan Fazio
 * UNIT: Computer Graphics
 * DATE: 10/19
 * PURPOSE: draw the green tree objects in the world scene
 **********************************************/

#include "trees.hpp"

void drawTrees(unsigned int texture, glm::mat4 view, glm::mat4 projection)
{
    //define vertices
    float vertices[] = 
    {
        // positions            // texture coords
        -0.5f, 0.0f, 0.0f,    0.0f,0.0f, //left
        0.5f, 0.0f, 0.0f,     1.0f,0.0f, //right
        0.0f, 2.0f, 0.0f,     0.5f,1.0f//top 
    };
    
    unsigned int VAO;//vertex array object
    unsigned int VBO; //vertex buffer object

    //use shader
    Shader shader("shaders/cmnShader.vs", "shaders/cmnShader.fs");
    shader.use();
    // pass them to the shaders
    shader.setMat4("projection", projection);
    shader.setMat4("view",view);

    //gen buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    //bind buffers
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //set vertex attributes
    //positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //texture maps
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //apply texture
    glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture);

    // create transformations
    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    model = glm::translate(model,glm::vec3(0.0f,0.0f,-5.0f));
    shader.setMat4("model",model);

    //draw leaves
    glDrawArrays(GL_TRIANGLES,0,3);

    model = glm::rotate(model,glm::radians(90.0f),glm::vec3(0.0f,1.0f,0.0f));
    shader.setMat4("model",model);
    //draw transformed leaves
    glDrawArrays(GL_TRIANGLES,0,3);
}
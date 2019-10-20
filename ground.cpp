/***********************************************
 * TITLE: ground.cpp
 * AUTHOR: Tristan Fazio
 * UNIT: Computer Graphics
 * DATE: 10/19
 * PURPOSE:
 **********************************************/

#include "ground.hpp"

void drawGround()
{
    //define vertices
    float vertices[] = 
    {
        1.0f,  0.5f, 0.0f,  // near top right 0
        1.0f, -0.5f, 0.0f,  // near bottom right 1
        -1.0f, -0.5f, 0.0f,  // near bottom left 2
        -1.0f,  0.5f, 0.0f,   // near top left  3
        1.0f,  0.5f, 1.0f,  // far top right
        1.0f, -0.5f, 1.0f,  // far bottom right
        -01.0f, -0.5f, 1.0f,  // far bottom left
        -1.0f,  0.5f, 1.0f   // far top left 
    };
    
    unsigned int indices[] = 
    {  
        //front
        0,1,2,   // first triangle
        0,2,3,    // second triangle
        //back
        4,5,6,  // first triangle
        4,6,7,  // second triangle
        //top
        0,3,4,  // first triangle
        0,4,7   // second triangle
    };  

    unsigned int VAO;//vertex array object
    unsigned int VBO; //vertex buffer object
    unsigned int EBO; //element buffer object

    Shader shader("shaders/ground.vs", "shaders/ground.fs");
    shader.use();
    shader.setVec3("ourColor",glm::vec3(0.545f, 0.271f, 0.075f));

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glDrawElements(GL_TRIANGLES,8,GL_UNSIGNED_INT,0);
}
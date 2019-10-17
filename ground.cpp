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
    //define vertex shader
    const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    //define fragment shader
    const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

    //create vertex shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);

    //create fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);

    //create shader program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    //delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  

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
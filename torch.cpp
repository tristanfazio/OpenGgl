/***********************************************
 * TITLE: torch.cpp
 * AUTHOR: Tristan Fazio
 * UNIT: Computer Graphics
 * DATE: 10/19
 * PURPOSE: draw the torch objects in the world scene
 **********************************************/

#include "torch.hpp"

void drawTorch(unsigned int tex_torch, glm::mat4 view, glm::mat4 projection, glm::vec3 cameraPos, bool torchEquipped)
{
    //define vertices
    float vertices[] = 
    {
        // positions          // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f,  0.0f,

        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f
    };
    
    unsigned int VAO;//vertex array object
    unsigned int VBO; //vertex buffer object
    float torchX,torchY,torchZ;
    //use shader
    Shader shader("shaders/cmnShader.vs", "shaders/treeShader.fs");
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //texture maps
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    if(!torchEquipped) {
        torchY = sin(glfwGetTime()*2);
        if(torchY > 0.75f )
        {
            torchY = 0.75f;
        }
        if(torchY < 0.35f)
        {
            torchY = 0.35f;
        }
        torchX = 2.5f;
        torchZ = 2.5f;
        std::cout << "not equip" << std::endl;
    }
    else if(torchEquipped) {
        torchX = cameraPos.x + 0.1f;
        torchZ = cameraPos.z - 0.1f;
        torchY = 0.3f;
        std::cout << "equip" << std::endl;
    }
    //torch
    //  wood
    //      create transformations
    glBindVertexArray(VAO);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model,glm::vec3(torchX,torchY,torchZ));
    model = glm::scale(model,glm::vec3(0.05f,0.12f,0.05f));
    model = glm::rotate(model,(float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
    
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.545f, 0.271f, 0.075f,1.0f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_torch);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);
    //  tip
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f);
    model = glm::translate(model,glm::vec3(torchX,torchY + 0.075f,torchZ));
    model = glm::scale(model,glm::vec3(0.05f,0.05f,0.05f));
    model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
    
    
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(1.0f, 0.647f, 0.0f,1.0f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_torch);
    //      draws
    glDrawArrays(GL_TRIANGLES,0,36);
}
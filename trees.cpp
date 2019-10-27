/***********************************************
 * TITLE: trees.cpp
 * AUTHOR: Tristan Fazio
 * UNIT: Computer Graphics
 * DATE: 10/19
 * PURPOSE: draw the green tree objects in the world scene
 **********************************************/

#include "trees.hpp"

void drawTrees(unsigned int tex_leaves, unsigned int tex_wood, glm::mat4 view, glm::mat4 projection)
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

    //tree 1
    //  leaves
    //      create transformations
    glBindVertexArray(VAO);
    glm::mat4 model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(0.0f,2.0f,-5.0f));
    model = glm::scale(model,glm::vec3(1.5f,1.5f,1.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.0f,0.392f,0.0f,1.0f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_leaves);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);
    //  stump
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(0.0f,0.5f,-5.0f));
    model = glm::scale(model,glm::vec3(0.5f,2.0f,0.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.51f, 0.271f, 0.075f,0.8f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_wood);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);

    //tree 2
    //  leaves
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(10.0f,2.0f,-5.0f));
    model = glm::scale(model,glm::vec3(1.5f,1.5f,1.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.0f,0.392f,0.0f,1.0f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_leaves);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);
    //  stump
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(10.0f,0.5f,-5.0f));
    model = glm::scale(model,glm::vec3(0.5f,2.0f,0.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.51f, 0.271f, 0.075f,0.8f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_wood);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);

    //tree 3
   //  leaves
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(5.0f,2.0f,-10.0f));
    model = glm::scale(model,glm::vec3(1.5f,1.5f,1.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.0f,0.392f,0.0f,1.0f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_leaves);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);
    //  stump
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(5.0f,0.5f,-10.0f));
    model = glm::scale(model,glm::vec3(0.5f,2.0f,0.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.51f, 0.271f, 0.075f,0.8f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_wood);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);

    //tree 4
    //  leaves
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(2.5f,2.0f,-7.5f));
    model = glm::scale(model,glm::vec3(1.5f,1.5f,1.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.0f,0.392f,0.0f,1.0f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_leaves);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);
    //  stump
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(2.5f,0.5f,-7.5f));
    model = glm::scale(model,glm::vec3(0.5f,2.0f,0.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.51f, 0.271f, 0.075f,0.8f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_wood);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);

    //tree 5
    //  leaves
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(7.5f,2.0f,-7.5f));
    model = glm::scale(model,glm::vec3(1.5f,1.5f,1.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.0f,0.392f,0.0f,1.0f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_leaves);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);
    //  stump
    //      create transformations
    glBindVertexArray(VAO);
    model = glm::mat4(1.0f); 
    model = glm::translate(model,glm::vec3(7.5f,0.5f,-7.5f));
    model = glm::scale(model,glm::vec3(0.5f,2.0f,0.5f));
    shader.setMat4("model",model);
    shader.setVec4("ourColor",glm::vec4(0.51f, 0.271f, 0.075f,0.8f));
    //      apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_wood);
    //      draw
    glDrawArrays(GL_TRIANGLES,0,36);
}
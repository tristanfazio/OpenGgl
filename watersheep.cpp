/***********************************************
 * TITLE: watersheep.cpp
 * AUTHOR: Tristan Fazio
 * UNIT: Computer Graphics
 * DATE: 10/19
 * PURPOSE: draw a series of box objects representing watersheep in the world scene
 **********************************************/

#include "watersheep.hpp"

void drawWatersheep(unsigned int texture, glm::mat4 view, glm::mat4 projection, glm::vec3 cameraPos,float cameraSpeed, bool svenEquipped)
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

    //apply texture
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
    glm::mat4 model;

    //body
    //(4 tall boxes for legs & body)
		glm::vec3 watersheep_scales[] = {
			glm::vec3( 0.25f,  0.25f,  0.5f),	//top
			glm::vec3( 0.05f,  0.25f,  0.05f),//near left
			glm::vec3( 0.05f,  0.25f,  0.05f),	//near right
			glm::vec3( 0.05f,  0.25f,  0.05f),//far left
			glm::vec3( 0.05f,  0.25f,  0.05f),	//far right
            glm::vec3( 0.05f,  0.05f,  0.05f),//ear
			glm::vec3( 0.05f,  0.05f,  0.05f),	//ear
			glm::vec3( 0.1f,  0.05f,  0.05f)	//snout
		};
		glm::vec3 watersheep_positions[] = {
			glm::vec3( 0.0f,  0.3f,  0.0f),		//top
			glm::vec3(-0.125f, 0.1f,  0.2f),	//near left
			glm::vec3( 0.125f, 0.1f,  0.2f),	//near right
			glm::vec3(-0.125f, 0.1f, -0.2f),	//far left
			glm::vec3( 0.125f, 0.1f, -0.2f),	//far right
            glm::vec3( 0.075f, 0.45f,  0.2f),	//ear
			glm::vec3(-0.075f, 0.45f,  0.2f),	//ear
			glm::vec3(0.0f, 0.3f,  0.25f)	//ear
		};

		glBindVertexArray(VAO);

		for(int tab = 0; tab < 8; tab++)
		{	
			model = glm::mat4(1.0f);
			model = glm::translate(model, watersheep_positions[tab]);
            if(svenEquipped) {
            model = glm::translate(model, glm::vec3(cameraPos.x, 0.2f, cameraPos.y)*cameraSpeed);
            }
            else {
            model = glm::translate(model, glm::vec3(7.5f, 0.2f, -10.0f));
            }
			model = glm::scale(model, watersheep_scales[tab]);
			
			shader.setMat4("model", model);
            shader.setVec4("ourColor",glm::vec4(0.5f, 0.5f, 0.5f, 0.1f));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

}
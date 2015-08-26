#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
#include <common/shader.hpp>
#include <common/texture.hpp>

int main( void )
{
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 2);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);

	if( !glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW ) )
	{
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		return -1;
    }
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
    glfwSetWindowTitle( "Tutorial 03" );
    glfwEnable( GLFW_STICKY_KEYS );
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LESS);
    //glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	GLuint programID = LoadShaders( "SimpleTransform.vertexshader", "SingleColor.fragmentshader" );

	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	GLuint vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
    GLuint vertexUVID = glGetAttribLocation(programID, "vertexUV");
    //GLuint vertexColorID = glGetAttribLocation(programID, "vertexColor");
    glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 View       = glm::lookAt(
                                glm::vec3(4,4,3), // Camera is at (4,3,3), in World Space
								glm::vec3(0,0,0), // and looks at the origin
                                glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
						   );
	// Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 Model      = glm::mat4(1.0f);\
	glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around

    GLuint Texture = loadBMP_custom("blackbuck.bmp");
    GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");

	static const GLfloat g_vertex_buffer_data[] = { 
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
         1.0f,-1.0f,-1.0f,
         1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
         1.0f,-1.0f,-1.0f,
        -0.25f,-0.25f, 1.0f,
        -0.25f, 0.25f, 1.0f,
         0.25f,-0.25f, 1.0f,
         0.25f, 0.25f, 1.0f,
        -0.25f, 0.25f, 1.0f,
         0.25f, -0.25f, 1.0f
	};

    /*static const GLfloat g_vertex_buffer_data2[] = {
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
         1.0f,-1.0f, 1.0f,
         1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
         1.0f, -1.0f, 1.0f
    };*/

    static const GLfloat g_color_buffer_data[] = {
        1.000f,  0.000f,  0.000f, 0.700f,
        1.000f,  0.000f,  0.000f, 0.700f,
        1.000f,  0.000f,  0.000f, 0.700f,
        1.000f,  0.000f,  0.000f, 0.700f,
        1.000f,  0.000f,  0.000f, 0.700f,
        1.000f,  0.000f,  0.000f, 0.700f,
        0.583f,  0.771f,  0.014f, 0.300f,
        0.583f,  0.771f,  0.014f, 0.300f,
        0.327f,  0.483f,  0.844f, 0.300f,
        0.327f,  0.483f,  0.844f, 0.300f,
        0.435f,  0.602f,  0.223f, 0.300f,
        0.435f,  0.602f,  0.223f, 0.300f
    };

    static const GLfloat g_uv_buffer_data[] = {
            0.000059f, 1.0f-0.000004f,
            0.000103f, 1.0f-0.336048f,
            0.335973f, 1.0f-0.335903f,
            1.000023f, 1.0f-0.000013f,
            0.667979f, 1.0f-0.335851f,
            0.999958f, 1.0f-0.336064f,
            0.335973f, 1.0f-0.335903f,
            0.336098f, 1.0f-0.000071f,
            0.667979f, 1.0f-0.335851f,
            0.335973f, 1.0f-0.335903f,
            0.336024f, 1.0f-0.671877f,
            1.000004f, 1.0f-0.671847f,
        };

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    GLuint colorbuffer;
    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
    /*GLuint vertexbuffer2;
    glGenBuffers(1, &vertexbuffer2);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data2), g_vertex_buffer_data2, GL_STATIC_DRAW);
*/
	do{
		glClear( GL_COLOR_BUFFER_BIT );
		// Use our shader
        glUseProgram(programID);
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glUniform1i(TextureID, 0);
		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(vertexPosition_modelspaceID);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			vertexPosition_modelspaceID, // The attribute we want to configure
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
        );
        // 2nd attribute buffer : colors
        /*glEnableVertexAttribArray(vertexColorID);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glVertexAttribPointer(
            vertexColorID,               // The attribute we want to configure
            4,                           // size
            GL_FLOAT,                    // type
            GL_FALSE,                    // normalized?
            0,                           // stride
            (void*)0                     // array buffer offset
        );*/

        glEnableVertexAttribArray(vertexUVID);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
            vertexUVID,                   // The attribute we want to configure
            2,                            // size : U+V => 2
            GL_FLOAT,                     // type
            GL_FALSE,                     // normalized?
            0,                            // stride
            (void*)0                      // array buffer offset
        );

       /* glEnableVertexAttribArray(vertexPosition_modelspaceID2);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
        glVertexAttribPointer(
            vertexPosition_modelspaceID2, // The attribute we want to configure
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );*/

		// Draw the triangle !
       glDrawArrays(GL_TRIANGLES, 0, 4*3); // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(vertexPosition_modelspaceID);
      //  glDisableVertexAttribArray(vertexColorID);
        glDisableVertexAttribArray(vertexUVID);
     //   glDisableVertexAttribArray(vertexPosition_modelspaceID2);
		// Swap buffers
		glfwSwapBuffers();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
		   glfwGetWindowParam( GLFW_OPENED ) );

	// Cleanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
    //glDeleteBuffers(1, &colorbuffer);
   // glDeleteBuffers(1, &vertexbuffer2);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteProgram(programID);
    glDeleteTextures(1, &TextureID);
	glfwTerminate();

	return 0;
}


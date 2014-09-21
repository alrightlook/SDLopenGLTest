#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <iostream>

using namespace std;

GLuint vbo;
void DrawSth()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0,0.0);
	glVertex3f(0.0,1.0, 0.0);
	glColor3f(0.0, 1.0,0.0);
	glVertex3f(-1.0,-1.0, 0.0);
	glColor3f(0.0, 0.0,1.0);
	glVertex3f(1.0,1.0, 0.0);

	glEnd();
}

void LoadData()
{
	GLfloat vertex[] = {0.0, 1.0, 0.0, -1.0, -1.0, 0.0, 1.0, -1.0, 0.0 };

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex)  , vertex, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,0);

}

void Draw()
{
	glDrawArrays(GL_TRIANGLES, 0,3);	
}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("Hello Mac Book", 100, 100, 640, 480, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetSwapInterval(1);
	glewInit();
	glColor3f(0.0, 0.0, 0.0);

	LoadData();
	bool quit = false;
	SDL_Event e;
	while(!quit)
	{
		if(SDL_PollEvent(&e)) {
			if(e.type == SDL_QUIT) {
				quit = true;
			}
		}
		else {
			Draw();
			//DrawSth();
			SDL_GL_SwapWindow(window);
		}
	}
	return 0;
}

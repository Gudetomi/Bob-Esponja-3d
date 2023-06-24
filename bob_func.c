#include "bob.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void DrawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC) {
	float tStep = (PI) / (float)uiSlices;
	float sStep = (PI) / (float)uiStacks;

	// Essa linha desenha em modo wireframe, caso queiram ver os polígonos criados pela função
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for (float t = -PI / 2; t <= (PI / 2) + .0001; t += tStep) {
		glBegin(GL_TRIANGLE_STRIP);
		for (float s = -PI; s <= PI + .0001; s += sStep) {
			glVertex3f(fA * cos(t) * cos(s), fB * cos(t) * sin(s), fC * sin(t));
			glVertex3f(fA * cos(t + tStep) * cos(s), fB * cos(t + tStep) * sin(s), fC * sin(t + tStep));
		}
		glEnd();
	}
}

// Cria paralelepípedos utilizando triângulos
void DrawParalelepidicrack(){
	// Definição dos vértices do paralelepípedo
	GLfloat vertices[] = {
		// Face frontal
		-0.5f, -0.5f, 0.5f,  // V0
		0.5f, -0.5f, 0.5f,   // V1
		0.5f, 0.5f, 0.5f,    // V2
		-0.5f, 0.5f, 0.5f,   // V3

		// Face traseira
		-0.5f, -0.5f, -0.5f, // V4
		0.5f, -0.5f, -0.5f,  // V5
		0.5f, 0.5f, -0.5f,   // V6
		-0.5f, 0.5f, -0.5f   // V7
	};

	// Definição dos índices para os triângulos
	GLubyte indices[] = {
		// Face frontal
		0, 1, 2,  // Triângulo 1
		2, 3, 0,  // Triângulo 2

		// Face traseira
		4, 5, 6,  // Triângulo 1
		6, 7, 4,  // Triângulo 2

		// Faces laterais
		1, 5, 6,  // Triângulo 1
		6, 2, 1,  // Triângulo 2
		0, 4, 7,  // Triângulo 1
		7, 3, 0,  // Triângulo 2
		0, 1, 5,  // Triângulo 1
		5, 4, 0,  // Triângulo 2
		2, 6, 7,  // Triângulo 1
		7, 3, 2   // Triângulo 2
	};
	// Renderização do paralelepípedo
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLubyte), GL_UNSIGNED_BYTE, indices);
	glDisableClientState(GL_VERTEX_ARRAY);
}

//Desenha um círculo de raio 1 centrado na origem
void drawCircle(float radius) {
    glBegin(GL_POLYGON);
        for (int i = 0; i < 60; i++) {
            glVertex2f(radius * cos(i), radius * sin(i));
        }
    glEnd();
}

//Desenha um triângulo equilátero de lado 1 centrado na origem
void drawTriangle() {
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(-0.5, -0.5);
        glVertex2d(0.5, -0.5);
    glEnd();
}

void init(void) {
	// Define a cor de fundo da janela de visualização como preto
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// Define o modo de rastreio de cor utilizado para misturar a cor do material nos pontos da face (smoothing)
	glShadeModel(GL_SMOOTH);
	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);

	// Parâmetros para a luz ambiente, difusa e especular, definindo também a posição da luz
	GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };

	// Passa os parâmetros definidos acima para a OpenGL
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// Habilita a luz ambiente, a luz zero e o depth buffer
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	// Primeira cor, para depois mudarmos com os eventos
	glColor3f(0.5, 1.0, 0.5);
}
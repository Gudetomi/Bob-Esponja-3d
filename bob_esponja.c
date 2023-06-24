#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "bob.h"

void display(void) {
	// Limpa a janela de visualização com a cor de fundo especificada, e limpa também o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Entra no modo de definição de matriz de visualização
	glMatrixMode(GL_MODELVIEW);
	// Carrega a matriz identidade
	glLoadIdentity();

	glClearColor(0.3f, 0.6f, 0.7f, 0.3f);

    gluLookAt(10.0f, 30.0f, 50.0f, 0.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Desenhar o Bob Esponja
    glTranslatef(-20.0, 0.0, 0.0);

	glPushMatrix();
		glTranslatef(0.0, 20.0, 0.0); // Transladar para a posição desejada
		draw_bob_esponja();
	glPopMatrix();

	// Desenhar o Gary
	glPushMatrix();
		glTranslatef(-10.0, 40.0, 0.0); // Transladar para a posição desejada
		draw_gary();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(45.0, 40.0, 0.0); // Transladar para a posição desejada
		draw_casa();
	glPopMatrix();
	// Executa os comandos OpenGL, e depois troca os buffers de vídeo
	glFlush();
}

void reshape(int w, int h) {
	// Define o viewport como o tamanho da janela
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	// Entra no modo de definição de matriz de projeção
	glMatrixMode(GL_PROJECTION);
	// Carrega a matriz identidade
	glLoadIdentity();
	// Define a projeção ortogonal
	if (w <= h)
		// Se a largura for menor que a altura, a projeção é feita para manter a proporção da janela
		glOrtho(-50, 50, -50 * (GLfloat)h / (GLfloat)w, 50 * (GLfloat)h / (GLfloat)w, -100.0, 100.0);
	else
		// Se a altura for menor que a largura, a projeção é feita para manter a proporção da janela
		glOrtho(-50 * (GLfloat)w / (GLfloat)h, 50 * (GLfloat)w / (GLfloat)h, -50, 50, -100.0, 100.0);
}

int main(int argc, char** argv) {
	// Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas
	glutInit(&argc, argv);
	// Inicializa o display, indicando que usará:
	// - um buffer de imagem (single buffer);
	// - buffer de profundidade;
	// - padrão de cores RGB)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
	// Especifica as dimensões da janela de exibição
	glutInitWindowSize(1000, 1000);
	// Especifica a posição inicial da janela de exibição
	glutInitWindowPosition(100, 100);
	// Cria a janela de exibição
	win_id = glutCreateWindow(argv[0]);
	// Chama a função init
	init();
	// Estabelece a função "display" como a função callback de exibição.
	glutDisplayFunc(display);
	// Estabelece a função "reshape" como a função callback de redimensionamento da janela de exibição.
	glutReshapeFunc(reshape);
	// Entra no loop de eventos, não retorna
	glutMainLoop();
	return 0;
}
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define PI 3.14159265358979323846

int win_id;
float ang_ombro = 0.0f, ang_cotovelo = 0.0f;


float cameraPosX = 0.0f;
float cameraPosY = 0.0f;
float cameraPosZ = 5.0f;
float cameraRotX = 0.0f;
float cameraRotY = 0.0f;

void updateCamera() {
	glLoadIdentity();
	glRotatef(-cameraRotX, 1.0f, 0.0f, 0.0f);
	glRotatef(-cameraRotY, 0.0f, 1.0f, 0.0f);
	glTranslatef(-cameraPosX, -cameraPosY, -cameraPosZ);
}


void keyboard(unsigned char key, int x, int y) {
	// Teclas de movimento da câmera
	switch (key) {
		case 'w':
			cameraPosZ -= 0.1f;
			break;
		case 's':
			cameraPosZ += 0.1f;
			break;
		case 'a':
			cameraPosX -= 0.1f;
			break;
		case 'd':
			cameraPosX += 0.1f;
			break;
		case 'q':
			cameraPosY -= 0.1f;
			break;
		case 'e':
			cameraPosY += 0.1f;
			break;
		case '1': 
			cameraPosX = -10.0f;
			cameraPosY = 0.0f;
			cameraPosZ = 0.0f;
			break;
		case '2': 
			cameraPosX = 0.0f;
			cameraPosY = 0.0f;
			cameraPosZ = 10.0f;
			break;
		case '3': 
			cameraPosX = 10.0f;
			cameraPosY = 0.0f;
			cameraPosZ = 0.0f;
			break;
		case '4': 
			cameraPosX = 0.0f;
			cameraPosY = 0.0f;
			cameraPosZ = -10.0f;
			break;
	}
	updateCamera();
	glutPostRedisplay();
}


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
void desenhaCirculo(float radius) {
    glBegin(GL_POLYGON);
        for (int i = 0; i < 60; i++) {
            glVertex2f(radius * cos(i), radius * sin(i));
        }
    glEnd();
}

//Desenha um quadrado de lado 1 centrado na origem
void desenhaQuadrado() {
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();
}


void draw_bob_esponja() {
	// Corpo
	glPushMatrix();
		glTranslatef(0, 0, 5.5);
		glScalef(26.0, 21.0, 10.0);
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		// glutSolidCube(1.0);
		DrawParalelepidicrack();
		glPopMatrix();
	glEnd();

	// Olho esquerdo
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Branco
		glTranslatef(-4.0, 4.0, 9.5);
		glutSolidSphere(4, 32, 3);
	glPopMatrix();

	// Iris esquerda
	glPushMatrix();
		glColor3f(0.2, 0.3, 0.6); // Azul
		glTranslatef(-4.0, 4.0, 13.0);
		// glutSolidSphere(2, 10, 2);
		desenhaCirculo(1.5);
	glPopMatrix();
	//pupila esquerda
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Preto
		glTranslatef(-4.0, 4.0, 13.5);
		// glutSolidSphere(1, 10, 2);
		desenhaCirculo(1.0);
	glPopMatrix();

	// Olho direito
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Branco
		glTranslatef(4.0, 4.0, 9.5);
		glutSolidSphere(4, 32, 3);
	glPopMatrix();
	// Iris direita
	glPushMatrix();
		glColor3f(0.2, 0.3, 0.6); // Azul
		glTranslatef(4.0, 4.0, 13.0);
		// glutSolidSphere(2, 10, 2);
		desenhaCirculo(1.5);
	glPopMatrix();
	//pupila direita
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Preto
		glTranslatef(4.0, 4.0, 13.5);
		// glutSolidSphere(2, 10, 2);
		desenhaCirculo(1.0);
	glPopMatrix();

	// Nariz
	glPushMatrix();
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glTranslatef(0.0, 0.0, 10.5);
		DrawEllipsoid(10, 10, 1.5, 1.5, 6);
		// glutSolidSphere(2, 10, 2);
	glPopMatrix();
	// Maça do rosto
	glPushMatrix();
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glTranslatef(-8.0, -2.5, 10.5);
		glutSolidSphere(2, 32, 2);
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glTranslatef(8.0, -2.5, 10.5);
		glutSolidSphere(2, 32, 2);
	glPopMatrix();

	glTranslatef(0.0, -0.5, 0.0);

	// Boca 
	glPushMatrix();
		glColor3f(0.6, 0.1, 0.1); // Vermelho
		glTranslatef(0.0, -3.5, 11.0);
		// glutSolidCube(3);
		glScalef(6, 4, 1);
		desenhaQuadrado();
	glPopMatrix();

	// Dente
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Amarelo
		glTranslatef(-1.0, -2.25, 11.0);
		glutSolidCube(1.5);
	glPopMatrix();
	// Dente
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Amarelo
		glTranslatef(1.0, -2.25, 11.0);
		glutSolidCube(1.5);
	glPopMatrix();

	glTranslatef(0.0, -12, 0.0);
	// Camisa
	glPushMatrix();
		glTranslatef(0, 0, 5.5);
		glColor3f(1.0, 1.0, 1.0); // Branco
		glScalef(25.0, 6.0, 10);
		DrawParalelepidicrack();
		// glutSolidCube(1.0);
	glPopMatrix();

	// Ombro esquerdo
	glPushMatrix();
		glTranslatef(15.0, 3.5, 5.0);
		glScalef(2.5, 2.5, 2.5);
		glutSolidSphere(1.0, 20, 6);
	glPopMatrix();
	// Braço esquerdo
	glPushMatrix();
		glTranslatef(17.0, 0.0, 5.0);
		glRotatef(20, 0.0, 0.0, 1.0);
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glScalef(2.5, 5.0, 3.5);
		glutSolidCube(1.0);
	glPopMatrix();
	// Cotovelo esquerdo
	glPushMatrix();
		glTranslatef(18.0, -2.5, 5.0);
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glScalef(2.0, 2.0, 2.0);
		glutSolidSphere(1.0, 20, 6);
	glPopMatrix();
	// Antebraço esquerdo
	glPushMatrix();
		glTranslatef(20.0, -3.0, 5.0);
		glRotatef(120, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.84, 0.0); // Amarelo
	glScalef(2.5, 5.0, 3.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//crucifixo
	// glPushMatrix();
	// 	glTranslatef(22.0, 3.0, 0.0);
	// 	glRotatef(0.0, 0.0, 0.0, 1.0);
	// 	glColor3f(0.4, 0.2, 1.0); // Marrom
	// 	glScalef(1.5, 20.0, 1.5);
	// 	glutSolidCube(1.0);
	// glPopMatrix();
	// glPushMatrix();
	// 	glTranslatef(22.0, -2.0, 0.0);
	// 	glRotatef(90.0, 0.0, 0.0, 1.0);
	// 	glColor3f(0.4, 0.2, 0.0); // Marrom
	// 	glScalef(1.5, 5.0, 1.5);
	// 	glutSolidCube(1.0);
	// glPopMatrix();

	// Ombro direito+
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Branco
		glTranslatef(-15.0, 1.5, 5.0);
		glScalef(2.5, 2.5, 2.5);
		glutSolidSphere(1.0, 20, 6);
	glPopMatrix();
	// Braço direito
	glPushMatrix();
		glTranslatef(-16.0, -3.0, 5.0);
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glScalef(2.5, 7.0, 3.5);
		glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(0.0, -5, 0.0);

	// Calça
	glPushMatrix();
		glTranslatef(0, 0, 5.5);
		glColor3f(0.4, 0.2, 0.0); // Marrom
		glScalef(25.0, 4.0, 10.0);
		DrawParalelepidicrack();
	glPopMatrix();

	glTranslatef(0.0, -8, 0.0);

	// Calça esquerdo
	glPushMatrix();
		glTranslatef(-4.0, 4.0, 5.0);
		glScalef(4.0, 4.5, 3.5);
		DrawParalelepidicrack();
	glPopMatrix();

	// Calça direito
	glPushMatrix();
		glTranslatef(4.0, 4.0, 5.0);
		glScalef(4.0, 4.5, 3.5);
		DrawParalelepidicrack();
	glPopMatrix();

	glTranslatef(0.0, -4.1, 0.0);
	glColor3f(1.0, 0.84, 0.0);

	// Perna esquerda
	glPushMatrix();
		glTranslatef(-4.0, 4.0, 5.0);
		glScalef(2.5, 5.0, 3.0);
		DrawParalelepidicrack();
	glPopMatrix();

	// Perna direita
	glPushMatrix();
		glTranslatef(4.0, 4.0, 5.0);
		glScalef(2.5, 5.0, 3.0);
		DrawParalelepidicrack();
	glPopMatrix();

	glTranslatef(0.0, -5, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	// Meia esquerda
	glPushMatrix();
		glTranslatef(-4.0, 4.0, 5.0);
		glScalef(2.5, 5.0, 3.0);
		DrawParalelepidicrack();
	glPopMatrix();

	// Meia direita
	glPushMatrix();
		glTranslatef(4.0, 4.0, 5.0);
		glScalef(2.5, 5.0, 3.0);
		DrawParalelepidicrack();
	glPopMatrix();

	// Sapato esquerdo
	glPushMatrix();
		glColor3f(0.3, 0.3, 0.4); // cinza
		glTranslatef(-4.0, 0.0, 6.0);
		glScalef(3.5, 3.0, 6.0);
		DrawParalelepidicrack();
	glPopMatrix();

	// Sapato direito
	glPushMatrix();
		glColor3f(0.3, 0.3, 0.4); // cinza
		glTranslatef(4.0, 0.0, 6.0);
		glScalef(3.5, 3.0, 6.0);
		DrawParalelepidicrack();
	glPopMatrix();
}

// Função para desenhar o Gary
void draw_gary() {
	//Concha
	glPushMatrix();
		glTranslatef(3.0, -8.0, 5.0);
		glColor3f(0.9, 0.4, 0.5);  // Rosa
		glutSolidSphere(6, 20, 6); // Desenha uma esfera sólida para representar o Gary
	glPopMatrix();

	//Corpo
	glPushMatrix();
		glColor3f(0.0, 1.0, 1.0); // Ciano
		glTranslatef(9.0, -8.0, 5.0);
		glRotatef(90, 0.0, 0.0, 1.0);
		DrawEllipsoid(10, 10, 3.0, 11.0, 3.0);
		// gluCylinder(gluNewQuadric(), 3, 3, 10, 40, 10); // Desenha uma esfera sólida para representar o Gary
	glPopMatrix();

	glPushMatrix();
		glTranslatef(15.0, -2.0, 5.0);
		glRotatef(15, 0.0, 0.0, 1.0);
		glColor3f(0.0, 1.0, 1.0); // Ciano
		glScalef(1.5, 10.0, 1.5);
		glutSolidCube(1.0);
	glPopMatrix();

	// Olho esquerdo
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Branco
		glTranslatef(14.0, 4.0, 5.0);
		glutSolidSphere(4, 32, 4);
	glPopMatrix();
	// Iris esquerda
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Preto
		glTranslatef(14.0, 4.0, 9.0);
		desenhaCirculo(1.0);
		// glutSolidSphere(1, 10, 2);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(20.0, -3.0, 5.0);
		glRotatef(-45, 0.0, 0.0, 1.0);
		glColor3f(0.0, 1.0, 1.0); // Ciano
		glScalef(1.5, 10.0, 1.5);
		glutSolidCube(1.0);
	glPopMatrix();
	// Olho direito
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Branco
		glTranslatef(26.0, 3.0, 5.0);
		glutSolidSphere(4, 32, 4);
	glPopMatrix();
	// Iris direita
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Preto
		glTranslatef(26.0, 3.0, 9.0);
		desenhaCirculo(1.0);
		// glutSolidSphere(1, 10, 2);
	glPopMatrix();

	

}

// Função para desenhar a casa do Bob Esponja (elipsoide)
void draw_casa() {
	glTranslatef(0, -30, -40.0);
	glColor3f(1.0, 0.65, 0.0); // Laranja
	DrawEllipsoid(10, 10, 20, 25, 15);
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

void display(void) {
	// Limpa a janela de visualização com a cor de fundo especificada, e limpa também o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Entra no modo de definição de matriz de visualização
	glMatrixMode(GL_MODELVIEW);
	// Carrega a matriz identidade
	glLoadIdentity();

	glClearColor(0.3f, 0.6f, 0.7f, 0.3f);
	// Define a posição da câmera, para onde ela aponta e qual o vetor UP
	gluLookAt(cameraPosX, cameraPosY, cameraPosZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Desenhar o Bob Esponja
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

	//movimentar a camera pelo teclado
	// 1 - Lateral esquerda 2 - Frontal 3 - Lateral direira 4 - Traseira
	glutKeyboardFunc(keyboard);

	// Estabelece a função "reshape" como a função callback de redimensionamento da janela de exibição.
	glutReshapeFunc(reshape);
	// Entra no loop de eventos, não retorna
	glutMainLoop();
	return 0;
}
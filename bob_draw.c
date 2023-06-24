#include "bob.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void draw_bob_esponja() {
	// Corpo
	glPushMatrix();
		glTranslatef(0, 0, 5.5);
		glScalef(26.0, 21.0, 10.0);
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		DrawParalelepidicrack();
		glPopMatrix();
	glEnd();

	// Olho direito
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Branco
		glTranslatef(-4.0, 4.0, 9.5);
		glutSolidSphere(4, 32, 3);
	glPopMatrix();

	// Iris direita
	glPushMatrix();
		glColor3f(0.2, 0.3, 0.6); // Azul
		glTranslatef(-4.0, 4.0, 13.0);
		drawCircle(1.5);
	glPopMatrix();
	//pupila direita
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Preto
		glTranslatef(-4.0, 4.0, 13.5);
		drawCircle(1.0);
	glPopMatrix();

	// Olho esquerdo
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Branco
		glTranslatef(4.0, 4.0, 9.5);
		glutSolidSphere(4, 32, 3);
	glPopMatrix();
	// Iris esquerda
	glPushMatrix();
		glColor3f(0.2, 0.3, 0.6); // Azul
		glTranslatef(4.0, 4.0, 13.0);
		drawCircle(1.5);
	glPopMatrix();
	//pupila esquerda
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Preto
		glTranslatef(4.0, 4.0, 13.5);
		drawCircle(1.0);
	glPopMatrix();

	// Nariz
	glPushMatrix();
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glTranslatef(0.0, 0.0, 10.5);
		DrawEllipsoid(10, 10, 1.5, 1.5, 6);
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
		glScalef(12, 4, 1);
        glRotatef(180, 1, 0, 0);
        drawTriangle();
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
		glScalef(26.5, 6.0, 10.5);
		DrawParalelepidicrack();
	glPopMatrix();

    //gola
    glPushMatrix();
		glTranslatef(-4, 1.5, 12);
		glColor3f(0.8, 0.75, 1.0); // Branco
		glScalef(5.0, 4.0, 1.0);
		glBegin(GL_TRIANGLES);
            glVertex2f(-0.5, 0.5);
            glVertex2f(0.5, 0.5);
            glVertex2f(0.0, 0.0);
        glEnd();
	glPopMatrix();

    //gola
    glPushMatrix();
		glTranslatef(4, 1.5, 12);
		glColor3f(0.8, 0.75, 1.0); // Branco
		glScalef(5.0, 4.0, 1.0);
		glBegin(GL_TRIANGLES);
            glVertex2f(-0.5, 0.5);
            glVertex2f(0.5, 0.5);
            glVertex2f(0.0, 0.0);
        glEnd();
	glPopMatrix();


    //gravata

    glPushMatrix();
        glTranslatef(0.0, 2.25, 12);
        glScalef(4.0, 4.0, 2.0);
		glColor3f(0.8, 0.2, 0.3); // Vermelho
		glBegin(GL_POLYGON);
            glVertex2f(-0.5, 0.25);
            glVertex2f(0.5, 0.25);
            glVertex2f(0.25, -0.25);
            glVertex2f(-0.25, -0.25);
        glEnd();
    glPopMatrix();
    
    glPushMatrix();
		glTranslatef(0.0, 0, 11);
        glScalef(4.0, 4.0, 2.0);
		glColor3f(0.8, 0.0, 0.0); // Vermelho
        glBegin(GL_POLYGON);
            glVertex2f(-0.25, 0.55);
            glVertex2f(0.25, 0.55);
            glVertex2f(0.25, -0.5);
            glVertex2f(0.0, -1.0);
            glVertex2f(-0.25, -0.5);
        glEnd();
		
	glPopMatrix();
    

	// Ombro esquerdo
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Branco
		glTranslatef(15.0, 3.5, 5.0);
		glScalef(1.5, 2.0, 1.5);
        DrawEllipsoid(10, 20, 1.0, 1.0, 1.0);
	glPopMatrix();
	// Braço esquerdo
	glPushMatrix();
		glTranslatef(17.0, -2.0, 5.0);
		glRotatef(20, 0.0, 0.0, 1.0);
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glScalef(1.0, 10.0, 1.0);
        DrawParalelepidicrack();
	glPopMatrix();
    //Mão esquerda
    glPushMatrix();
		glTranslatef(19.0, -7.0, 5.0);
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glutSolidSphere(2.0, 32, 6);
	glPopMatrix();

	//crucifixo
	glPushMatrix();
		glTranslatef(19.0, -7.0, 12.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glColor3f(0.6, 0.3, 0.2); // Marrom
		glScalef(0.5, 20.0, 0.5);
        DrawParalelepidicrack();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(19.0, -7.0, 27.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glColor3f(0.6, 0.3, 0.2); // Marrom
        glutSolidTorus(0.3, 5, 4, 32);
	glPopMatrix();

	// Ombro direito
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Branco
		glTranslatef(-15.0, 1.5, 5.0);
		glScalef(1.5, 2.0, 1.5);
        DrawEllipsoid(10, 20, 1.0, 1.0, 1.0);
	glPopMatrix();
	// Braço direito
	glPushMatrix();
		glTranslatef(-17.0, -3.0, 5.0);
		glRotatef(20, 0.0, 0.0, -1.0);
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glScalef(1.0, 10.0, 1.0);
        DrawParalelepidicrack();
	glPopMatrix();
    //Mão direita
    glPushMatrix();
		glTranslatef(-19.0, -7.0, 5.0);
		glColor3f(1.0, 0.84, 0.0); // Amarelo
		glutSolidSphere(2.0, 32, 6);
	glPopMatrix();

	glTranslatef(0.0, -5, 0.0);

	// Calça
	glPushMatrix();
		glTranslatef(0, 0, 5.5);
		glColor3f(0.4, 0.2, 0.0); // Marrom
		glScalef(26.5, 4.0, 10.5);
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
		glScalef(1.0, 5.0, 1.0);
		DrawParalelepidicrack();
	glPopMatrix();

	// Perna direita
	glPushMatrix();
		glTranslatef(4.0, 4.0, 5.0);
		glScalef(1.0, 5.0, 1.0);
		DrawParalelepidicrack();
	glPopMatrix();

	glTranslatef(0.0, -5, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	// Meia esquerda
	glPushMatrix();
		glTranslatef(-4.0, 4.0, 5.0);
		glScalef(1.0, 5.0, 1.0);
		DrawParalelepidicrack();
	glPopMatrix();

	// Meia direita
	glPushMatrix();
		glTranslatef(4.0, 4.0, 5.0);
		glScalef(1.0, 5.0, 1.0);
		DrawParalelepidicrack();
	glPopMatrix();

	// Sapato esquerdo
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Preto
		glTranslatef(-4.0, 0.0, 6.0);
		glScalef(1.5, 2.0, 3.0);
        DrawEllipsoid(10, 20, 1, 1, 2);
	glPopMatrix();

	// Sapato direito
	glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Preto
		glTranslatef(4.0, 0.0, 6.0);
		glScalef(1.5, 2.0, 3.0);
        DrawEllipsoid(10, 20, 1, 1, 2);
	glPopMatrix();

	// Chão
	glPushMatrix();
		glColor3f(0.9, 0.8, 0.7); // areia
		glTranslatef(4.0, -6.5, 6.0);
		glScalef(1000.0, 10.0, 1000.0);
		DrawParalelepidicrack();
	glPopMatrix();
}

// Função para desenhar o Gary
void draw_gary() {
	//Concha
	glPushMatrix();
		glTranslatef(3.0, -7.0, 5.0);
		glColor3f(0.9, 0.4, 0.5);  // Rosa
		glutSolidSphere(6, 32, 6); // Desenha uma esfera sólida para representar o Gary
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
		drawCircle(1.0);
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
		drawCircle(1.0);
	glPopMatrix();

}

// Função para desenhar a casa do Bob Esponja (e do Patrick e do Lula)
void draw_casa() {
    glPushMatrix();
        glTranslatef(30, -45.0, -50.0);
        glColor3f(1.0, 0.65, 0.0); // Laranja
        glScalef(1.1, 1.2, 1.1);
        DrawEllipsoid(10, 20, 20, 35, 15);
    glPopMatrix();

    //desenhar as folhas da coroa do abacaxi
    glPushMatrix();
        glTranslatef(30, 0.0, -50.0);
        glColor3f(0.2, 0.95, 0.2); // Verde
        DrawEllipsoid(10, 5, 5, 35, 1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(25, -2.0, -50.0);
        glRotatef(15, 0, 0, 1);
        glColor3f(0.2, 0.95, 0.2); // Verde
        DrawEllipsoid(10, 5, 5, 35, 1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(35, -2.0, -50.0);
        glRotatef(15, 0, 0, -1);
        glColor3f(0.2, 0.95, 0.2); // Verde
        DrawEllipsoid(10, 5, 5, 35, 1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(20, -6.0, -50.0);
        glRotatef(30, 0, 0, 1);
        glColor3f(0.2, 0.95, 0.2); // Verde
        DrawEllipsoid(10, 5, 5, 35, 1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(40, -6.0, -50.0);
        glRotatef(30, 0, 0, -1);
        glColor3f(0.2, 0.95, 0.2); // Verde
        DrawEllipsoid(10, 5, 5, 35, 1);
    glPopMatrix();

    //Casa do patrick
    glPushMatrix();
        glTranslatef(-40, -60.0, -50.0);
        glColor3f(0.4, 0.2, 0.0); // Marrom
        glScalef(1.5, 1.5, 1.5);
        DrawEllipsoid(10, 20, 20, 20, 20);
    glPopMatrix();

    //Casa do Lula
    glPushMatrix();
        glTranslatef(-100, -40.0, -30.0);
        glColor3f(0.3, 0.3, 0.5); // Cinza
        glScalef(20, 60, 20);
        DrawParalelepidicrack();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-100, -27.5, -20.0);
         glColor3f(0.35, 0.35, 0.55); // Cinza
        glScalef(5, 15, 5);
        DrawParalelepidicrack();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-100, -17.5, -20.0);
         glColor3f(0.35, 0.35, 0.55); // Cinza
        glScalef(15, 3, 5);
        DrawParalelepidicrack();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-90, -27.5, -30.0);
         glColor3f(0.3, 0.3, 0.5); // Cinza
        glScalef(5, 15, 5);
        DrawParalelepidicrack();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-110, -27.5, -30.0);
         glColor3f(0.3, 0.3, 0.5); // Cinza
        glScalef(5, 15, 5);
        DrawParalelepidicrack();
    glPopMatrix();
}
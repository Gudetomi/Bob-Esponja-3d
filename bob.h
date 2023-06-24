#ifndef __BOB_H__
#define __BOB_H__
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define PI 3.14159265358979323846
int win_id;

void DrawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC);

// Cria paralelepípedos utilizando triângulos
void DrawParalelepidicrack();

//Desenha um círculo de raio 1 centrado na origem
void drawCircle(float radius);

//Desenha um triângulo equilátero de lado 1 centrado na origem
void drawTriangle();

//Desenha o Bob Esponja
void draw_bob_esponja();

//Desenha o Gary
void draw_gary();

// Função para desenhar a casa do Bob Esponja (abacaxi)
void draw_casa();

void init(void);

void display(void);

void reshape(int w, int h);

int main(int argc, char** argv);

#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define Pi 3.14159265358979323846

int win_id;
float ang_ombro = 0.0f, ang_cotovelo = 0.0f;

void DrawEllipsoid(unsigned int uiStacks, unsigned int uiSlices, float fA, float fB, float fC)
{
  float tStep = (Pi) / (float)uiSlices;
  float sStep = (Pi) / (float)uiStacks;

  // Essa linha desenha em modo wireframe, caso queiram ver os polígonos criados pela função
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  for (float t = -Pi / 2; t <= (Pi / 2) + .0001; t += tStep)
  {
    glBegin(GL_TRIANGLE_STRIP);
    for (float s = -Pi; s <= Pi + .0001; s += sStep)
    {
      glVertex3f(fA * cos(t) * cos(s), fB * cos(t) * sin(s), fC * sin(t));
      glVertex3f(fA * cos(t + tStep) * cos(s), fB * cos(t + tStep) * sin(s), fC * sin(t + tStep));
    }
    glEnd();
  }
}

void draw_bob_esponja()
{
  // Corpo
  glPushMatrix();
  glColor3f(1.0, 0.84, 0.0); // Amarelo
  glScalef(26.0, 21.0, 21.0);
  glutSolidCube(1.0);
  glPopMatrix();
  glEnd();

  // Olho esquerdo
  glColor3f(1.0, 1.0, 1.0); // Branco
  glPushMatrix();
  glTranslatef(2.0, 8.0, 30.0);
  glutSolidSphere(4, 10, 4);
  glPopMatrix();

  // Olho direito
  glPushMatrix();
  glTranslatef(10.0, 8.0, 30.0);
  glutSolidSphere(4, 10, 4);
  glPopMatrix();

  // Iris
  glColor3f(0.0, 0.0, 0.0); // Preto
  glPushMatrix();
  glTranslatef(2.0, 8.0, 35.0);
  glutSolidSphere(2, 10, 2);
  glPopMatrix();

  // Iris
  glPushMatrix();
  glTranslatef(10.0, 8.0, 35.0);
  glutSolidSphere(2, 10, 2);
  glPopMatrix();
  // Nariz
  glPushMatrix();
  glColor3f(1.0, 0.84, 0.0); // Amarelo
  glTranslatef(10.0, 8.0, 60.0);
  glutSolidSphere(2, 10, 2);
  glPopMatrix();
  // Maça do rosto
  glPushMatrix();
  glColor3f(1.0, 0.84, 0.0); // Amarelo
  glTranslatef(0.0, -0.5, 30.0);
  glutSolidSphere(2, 10, 2);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1.0, 0.84, 0.0); // Amarelo
  glTranslatef(8.0, -0.5, 30.0);
  glutSolidSphere(2, 10, 2);
  glPopMatrix();

  glTranslatef(0.0, -0.5, 0.0);
  // Dente
  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0); // Amarelo
  glTranslatef(3.0, -2.5, 30.0);
  glutSolidCube(1.5);
  glPopMatrix();
  // Dente
  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0); // Amarelo
  glTranslatef(5, -2.5, 30.0);
  glutSolidCube(1.5);
  glPopMatrix();

  glTranslatef(0.0, -12, 0.0);
  // Blusa
  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0); // Branco
  glScalef(25.0, 6.0, 20.0);
  glutSolidCube(1.0);
  glPopMatrix();
  glEnd();

  // Ombro
  glPushMatrix();
  glTranslatef(15.0, 1.5, 0.0);
  glScalef(2.5, 2.5, 2.5);
  glutSolidSphere(1.0, 20, 6);
  glPopMatrix();
  glEnd();
  // Braço
  glPushMatrix();
  glTranslatef(17.0, -2.0, 0.0);
  glRotatef(20, 0.0, 0.0, 1.0);
  glColor3f(1.0, 0.84, 0.0); // Amarelo
  glScalef(2.5, 5.0, 3.5);
  glutSolidCube(1.0);
  glPopMatrix();
  // Cotovelo
  glPushMatrix();
  glTranslatef(18.0, -4.5, 0.0);
  glColor3f(1.0, 0.84, 0.0); // Amarelo
  glScalef(2.0, 2.0, 2.0);
  glutSolidSphere(1.0, 20, 6);
  glPopMatrix();
  glEnd();

  // Braço
  glPushMatrix();
  glTranslatef(20.0, -5.0, 0.0);
  glRotatef(120, 0.0, 0.0, 1.0);
  glColor3f(1.0, 0.84, 0.0); // Amarelo
  glScalef(2.5, 5.0, 3.5);
  glutSolidCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(22.0, 3.0, 0.0);
  glRotatef(0.0, 0.0, 0.0, 1.0);
  glColor3f(0.4, 0.2, 0.0); // Marrom
  glScalef(1.5, 20.0, 1.5);
  glutSolidCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(22.0, -2.0, 0.0);
  glRotatef(90.0, 0.0, 0.0, 1.0);
  glColor3f(0.4, 0.2, 0.0); // Marrom
  glScalef(1.5, 5.0, 1.5);
  glutSolidCube(1.0);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0); // Branco
  glTranslatef(-15.0, 1.5, 0.0);
  glScalef(2.5, 2.5, 2.5);
  glutSolidSphere(1.0, 20, 6);
  glPopMatrix();
  glEnd();

  glPushMatrix();
  glTranslatef(-16.0, -3.0, 0.0);
  glColor3f(1.0, 0.84, 0.0); // Amarelo
  glScalef(2.5, 7.0, 3.5);
  glutSolidCube(1.0);
  glPopMatrix();

  glTranslatef(0.0, -5, 0.0);

  glPushMatrix();
  glColor3f(0.4, 0.2, 0.0); // Marrom
  glScalef(25.0, 4.0, 20.0);
  glutSolidCube(1.0);
  glPopMatrix();
  glEnd();

  glTranslatef(0.0, -8, 0.0);

  // Calça esquerdo
  glPushMatrix();
  glTranslatef(-4.0, 4.0, 0.0);
  glScalef(3.0, 4.5, 10.0);
  glutSolidCube(1.0);
  glPopMatrix();

  // Calça direito
  glPushMatrix();
  glTranslatef(4.0, 4.0, 0.0);
  glScalef(3.0, 4.5, 10.0);
  glutSolidCube(1.0);
  glPopMatrix();

  glTranslatef(0.0, -4.1, 0.0);
  glColor3f(1.0, 0.84, 0.0);

  // Perna esquerda
  glPushMatrix();
  glTranslatef(-4.0, 4.0, 0.0);
  glScalef(2.5, 5.0, 8.0);
  glutSolidCube(1.0);
  glPopMatrix();

  // Perna direita
  glPushMatrix();
  glTranslatef(4.0, 4.0, 0.0);
  glScalef(2.5, 5.0, 8.0);
  glutSolidCube(1.0);
  glPopMatrix();

  glTranslatef(0.0, -5, 0.0);
  glColor3f(1.0, 1.0, 1.0);

  // Meia esquerda
  glPushMatrix();
  glTranslatef(-4.0, 4.0, 0.0);
  glScalef(2.5, 5.0, 8.0);
  glutSolidCube(1.0);
  glPopMatrix();

  // Meia direita
  glPushMatrix();
  glTranslatef(4.0, 4.0, 0.0);
  glScalef(2.5, 5.0, 8.0);
  glutSolidCube(1.0);
  glPopMatrix();

  // Sapato esquerdo
  glPushMatrix();
  glColor3f(0.4, 0.2, 0.0); // Marrom
  glTranslatef(-5.0, -1.0, 0.0);
  glScalef(2.5, 3.0, 20.0);
  glutSolidCube(1.0);
  glPopMatrix();

  // Sapato direito
  glPushMatrix();
  glColor3f(0.4, 0.2, 0.0); // Marrom
  glTranslatef(3.0, -1.0, 0.0);
  glScalef(2.5, 3.0, 20.0);
  glutSolidCube(1.0);
  glPopMatrix();
}

// Função para desenhar o Gary
void draw_gary()
{
  glPushMatrix();
  glTranslatef(3.0, -1.0, 30.0);
  glColor3f(1.0, 0.0, 1.0);  // Ciano
  glutSolidSphere(6, 20, 6); // Desenha uma esfera sólida para representar o Gary
  glPopMatrix();
  glEnd();

  glPushMatrix();

  glColor3f(0.0, 1.0, 1.0); // Ciano
  glTranslatef(5.0, -2.0, 30.0);
  glRotatef(90, 0.0, 90.0, 1.0);
  gluCylinder(gluNewQuadric(), 3, 3, 10, 40, 10); // Desenha uma esfera sólida para representar o Gary
  glPopMatrix();
  glEnd();

  glPushMatrix();
  glTranslatef(5.0, -10.0, -30.0);
  glRotatef(120, 0.0, 0.0, 1.0);
  glColor3f(0.0, 1.0, 1.0); // Ciano
  glScalef(1.5, 10.0, 1.5);
  glutSolidCube(1.0);
  glPopMatrix();
  
  // Olho esquerdo
  glColor3f(1.0, 1.0, 1.0); // Branco
  glPushMatrix();
  glTranslatef(17.0, 8.0, 30.0);
  glutSolidSphere(4, 10, 4);
  glPopMatrix();

  // Olho direito
  glPushMatrix();
  glTranslatef(23.0, 6.0, 30.0);
  glutSolidSphere(4, 10, 4);
  glPopMatrix();

  // Iris
  glColor3f(0.0, 0.0, 0.0); // Preto
  glPushMatrix();
  glTranslatef(17.0, 8.0, 35.0);
  glutSolidSphere(1, 10, 2);
  glPopMatrix();

  // Iris
  glPushMatrix();
  glTranslatef(23.0, 6.0, 35.0);
  glutSolidSphere(1, 10, 2);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.0, -10.0, -30.0);
  glRotatef(120, 0.0, 0.0, 1.0);
  glColor3f(0.0, 1.0, 1.0); // Ciano
  glScalef(1.5, 10.0, 1.5);
  glutSolidCube(1.0);
  glPopMatrix();
  
}

// Função para desenhar a casa do Bob Esponja (elipsoide)
void draw_casa()
{
  glColor3f(1.0, 0.65, 0.0); // Laranja
  DrawEllipsoid(10, 10, 20, 25, 15);
}

void init(void)
{
  // Define a cor de fundo da janela de visualização como preto
  glClearColor(0.0, 0.0, 0.0, 0.0);
  // Define o modo de rastreio de cor utilizado para misturar a cor do material nos pontos da face (smoothing)
  glShadeModel(GL_SMOOTH);
  // Habilita a definição da cor do material a partir da cor corrente
  glEnable(GL_COLOR_MATERIAL);

  // Parâmetros para a luz ambiente, difusa e especular, definindo também a posição da luz
  GLfloat light_ambient[] = {0.5, 0.5, 0.5, 1.0};
  GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat light_position[] = {10.0, 10.0, 10.0, 0.0};

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

void display(void)
{
  // Limpa a janela de visualização com a cor de fundo especificada, e limpa também o depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Entra no modo de definição de matriz de visualização
  glMatrixMode(GL_MODELVIEW);
  // Carrega a matriz identidade
  glLoadIdentity();
  // Define a posição da câmera, para onde ela aponta e qual o vetor UP
  gluLookAt(10.0f, 30.0f, 50.0f, 0.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f);

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

void reshape(int w, int h)
{
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

int main(int argc, char **argv)
{
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
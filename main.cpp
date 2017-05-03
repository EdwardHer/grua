#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
double rotate_y=-40;
double rotate_x=20;
double rotate_z=0;

GLfloat color=0.0f, color2=0.0f;
GLfloat X = 0.0f;
GLfloat zoom =0.1f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
GLfloat arriba = 0.0f;


void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
        if(rotate_y<=-10){
            rotate_y += 10;
        }
    if (key == GLUT_KEY_LEFT)
       if(rotate_y>=-180){
            rotate_y -= 10;
       }
    if (key == GLUT_KEY_UP)
        if (arriba <=0)
        {
            arriba+=10;
           // color=0;
        }
    if (key == GLUT_KEY_DOWN)
        if (arriba>=-10)
        {
            arriba-=10;


        }else{
            if(rotate_y==0){
                color=+0.5;

            }
            if (rotate_y==-60)
            {
                color2=+0.5;
                /* code */
            }
            //color=+1;
        }
       // arriba = arriba -10;
        //rotate_x -= 10;
    glutPostRedisplay();

}
void init(void)
{glShadeModel(GL_SMOOTH);

glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-200, 200, -200, 200, -200, 200);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}

// Aqui ponemos lo que queremos dibujar.
void display(void)
{glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Propiedades del material
    glLoadIdentity();
       glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex3f(200.f,0.0f,.0f);
    glVertex3f(-100.0f,0.f,-.0f);
    glColor3f(0,1,0);
    glVertex3f(0.f,200.00f,0.0f);
    glVertex3f(-0.0f,-100.f,0.0f);
    glColor3f(0,0,1);
    glVertex3f(0.f,-0.0f,200.0f);
    glColor3f(1,0,0);
    glVertex3f(-0.0f,0.f,-100.0f);
    glEnd();
    glFlush();

    glColor3f(0,0,1);
     glutSolidCube(30.0);
     glPushMatrix();

     glTranslatef(100,0,0);
     glColor3f(0,color,1);
     glutSolidCube(25.0);
     glPopMatrix();
     glPushMatrix();
     glColor3f(color2,color2,1);
     glTranslatef(50,-28,195);
     glutSolidCube(25.0);
     glPopMatrix();
     //glColor3f(0,0,1);
     //glutSolidCube(25.0);

     glColor3f(0,0,1);
     glutSolidCube(25.0);
     glColor3f(1,0,0);
    glRotatef( rotate_x, 5.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 10.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    // Otras transformaciones
    glScalef(scale, scale, scale);
    
     glBegin(GL_POLYGON);
    //*
    glVertex3f(-7,15,-7);
    glVertex3f(7,15,-7);
    glVertex3f(7,105,-7);
    glVertex3f(-7,105,-7);
    //izquierda
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-7,15,-7);
    glVertex3f(-7,15,7);
    glVertex3f(-7,105,7);
    glVertex3f(-7,105,-7);
    glEnd();
    glBegin(GL_POLYGON);
    //derecha
    glVertex3f(7,15,-7);
    glVertex3f(7,15,7);
    glVertex3f(7,105,7);
    glVertex3f(7,105,-7);
    glEnd();
    glBegin(GL_POLYGON);
    //delante
    glVertex3f(-7,15,7);
    glVertex3f(7,15,7);
    glVertex3f(7,105,7);
    glVertex3f(-7,105,7);
    glEnd();
   // */
//viga de encima
   glColor3f(1,1,0);
    //frente
   glBegin(GL_POLYGON);
    glVertex3f(7,90,7);
    glVertex3f(7,105,7);
    glVertex3f(100,105,7);
    glVertex3f(100,90,7);
    glEnd();
    //atras
    glBegin(GL_POLYGON);
    glVertex3f(7,90,-7);
    glVertex3f(7,105,-7);
    glVertex3f(100,105,-7);
    glVertex3f(100,90,- 7);
    glEnd();

    //arriba
    glBegin(GL_POLYGON);
    glVertex3f(7,105,-7);
    glVertex3f(7,105,7);
    glVertex3f(100,105,7);
    glVertex3f(100,105,- 7);
    glEnd(); 

    //abajo
    glBegin(GL_POLYGON);
    glVertex3f(7,90,-7);
    glVertex3f(7,90,7);
    glVertex3f(100,90,7);
    glVertex3f(100,90,- 7);
    glEnd(); 
//cable
    glBegin(GL_POLYGON);
    glVertex3f(100,105,7);
    glVertex3f(100,105,- 7);
    glVertex3f(100,55,-7);
    glVertex3f(100,55,7);
    glEnd(); 

    glBegin(GL_POLYGON);
    glVertex3f(100,105,7);
    glVertex3f(95,105, 7);
    glVertex3f(95,55,7);
    glVertex3f(100,55,7);
    glEnd();     
       //acero
     glBegin(GL_POLYGON);
    glVertex3f(99.5,55,3);
    glVertex3f(96.5,55, 3);
    glVertex3f(96.5,35+arriba,3);
    glVertex3f(99.5,35+arriba,3);
    glEnd(); 
    glPushMatrix();

     glTranslatef(99.2,35+arriba,5);
     glColor3f(1,1,1);
     glutSolidCube(9.0);
     glPopMatrix();


    glutSwapBuffers();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
}

// Main del programa.
int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);

// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);

// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (800, 600);

// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);

// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Teapot");

// Inicializamos el sistema
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
     glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}
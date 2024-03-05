
#include <stdio.h> 
#include <stdlib.h>
/*** freeglut***/
#include <freeglut.h>
 
void ChangeSize(int , int );					 
void RenderScene(void);							 
void ProcessMenu(int option);
void DrawPrism(void);


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Enable depth buffering
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(600, 80);
    glutCreateWindow("Simple Triangle");

    glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("Smooth Shading", 1);
    glutAddMenuEntry("Flat Shading", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glEnable(GL_DEPTH_TEST); // Enable depth testing

    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}
void ProcessMenu(int option)
{
    switch (option)
    {
    case 1:
        glShadeModel(GL_SMOOTH);
        break;
    case 2:
        glShadeModel(GL_FLAT);
        break;
    }
    glutPostRedisplay();
}

void ChangeSize(int w, int h) 
{ 
   printf("Window Size= %d X %d\n",w,h); 
   glViewport(0, 0, w, h);            
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   glOrtho(-10,10,-10,10,-10,10);      
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
} 

void DrawPrism() {
    /*Draw a Triangular Prism using multiple
triangles
 Each Rectangular face is formed by 2 triangles
 Assign a single color for each face as
shown in the picture
 The two triangles on the same rectangular
face has the same color*/
    //draw
    //use:
    //glColor3f( r, g, b);
    //glBegin(GL_LINE);
    //glVertex3f( -x, 0, 0);
    //glVertex3f( x, 0, 0);
    //glEnd();

    //perform transformation for the cube
    //use:
    //glRotatef(theta, x, y, z);

    //draw the prism top
    GLfloat x [] = {0, 5, 2.5};
    GLfloat y [] = {0, 0, 10};
    GLfloat z [] = {0, 0, 0};

    GLfloat df = 2.5;
    // button is plus z from the top
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    for (int i = 0; i < 3; i++) {
    	glVertex3f(x[i], y[i], z[i]);	
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 1, 0);
    for (int i = 0; i < 3; i++) {
		glVertex3f(x[i], y[i], z[i] + df);	
	}
    glEnd();

    // Side 1
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1);
    glVertex3f(x[0], y[0], z[0]);
    glVertex3f(x[1], y[1], z[1]);
    glVertex3f(x[1], y[1], z[1] + df);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 1);
    glVertex3f(x[0], y[0], z[0]);
    glVertex3f(x[1], y[1], z[1] + df);
    glVertex3f(x[0], y[0], z[0] + df);
    glEnd();

    // Side 2
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 0);
    glVertex3f(x[1], y[1], z[1]);
    glVertex3f(x[2], y[2], z[2]);
    glVertex3f(x[1], y[1], z[1] + df);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 0);
    glVertex3f(x[1], y[1], z[1] + df);
    glVertex3f(x[2], y[2], z[2]);
    glVertex3f(x[2], y[2], z[2] + df);
    glEnd();

    // Side 3
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 1);
    glVertex3f(x[2], y[2], z[2]);
    glVertex3f(x[0], y[0], z[0]);
    glVertex3f(x[2], y[2], z[2] + df);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 1);
    glVertex3f(x[2], y[2], z[2] + df);
    glVertex3f(x[0], y[0], z[0]);
    glVertex3f(x[0], y[0], z[0] + df);
    glEnd();

}




// Add the rest of your functions here

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10.0f, 0, 0, 0, 0, 1, 0);

    static float theta = 0;
    glRotatef(theta, 1.0f, 1.0f, 1.0f); // Corrected rotation

    DrawPrism();
    glutSwapBuffers();
    theta += 0.05; // Increment theta for continuous rotation

    glutPostRedisplay(); // Ensure the scene gets redrawn
}

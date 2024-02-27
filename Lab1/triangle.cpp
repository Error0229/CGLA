
#include <stdio.h> 
#include <stdlib.h>
/*** freeglut***/
#include <.\GL\freeglut.h>
 
void ChangeSize(int , int );					 
void RenderScene(void);							 
void ProcessMenu(int option);
int main(int argc, char** argv) 
{ 
   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
   glutInitWindowSize(400,400);				 
   glutInitWindowPosition(600,80);           
   glutCreateWindow("Simple Triangle");

   glutCreateMenu(ProcessMenu);
   glutAddMenuEntry("Smooth Shading", 1);
   glutAddMenuEntry("Flat Shading", 2);
   glutAttachMenu(GLUT_RIGHT_BUTTON);

    
   glutReshapeFunc(ChangeSize); 
   glutDisplayFunc(RenderScene); 
   glutMainLoop();	//http://www.programmer-club.com.tw/ShowSameTitleN/opengl/2288.html
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
void RenderScene(void) 
{ 
   glClearColor(1.0, 1.0, 1.0, 1.0);     
   glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
   gluLookAt(0,0,10.0f,0,0,0,0,1,0);   
   glBegin(GL_QUADS); 
      
      glColor3f( 0, 1, 1); glVertex3f(5, 0, 0);
      glColor3f( 1, 0, 0);glVertex3f( 5, 5, 0);
      glColor3f(0, 1, 0); glVertex3f(0, 5, 0);
	  glColor3f( 0, 0, 1);glVertex3f( 0, 0, 0); 
	
   glEnd();
   glutSwapBuffers(); 
}
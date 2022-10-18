#include <windows.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static int a1 = 0, a2 = 0,a3=0, tx = 150, ty = 150,tZ=-200;

void init() {

  glClearColor(1, 1, 1, 1.0);

  // Set up the viewing volume: 500 x 500 x 1 window with origin lower left.
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, 500.0);
}
 void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: (tx -= 5) %= 500; break;
    case GLUT_KEY_RIGHT: (tx += 5) %= 500; break;
    case GLUT_KEY_UP: (ty += 5) %= 500; break;
    case GLUT_KEY_DOWN: (ty -= 5) %= 500; break;
    case GLUT_KEY_F7: (tZ += 5) %= 500; break;
    case GLUT_KEY_F8: (tZ -= 5) %= 500; break;

    case GLUT_KEY_F1: (a1 = 5) %= 360; break;
    case GLUT_KEY_F2: (a1 = -5) %= 360; break;
    case GLUT_KEY_F3: (a2 = 5) %= 360; break;
    case GLUT_KEY_F4: (a2 =- 5) %= 360; break;
     case GLUT_KEY_F5: (a3 = 5) %= 360; break;
     case GLUT_KEY_F6: (a3 = -5) %= 360; break;
    default: return;
  }
  glutPostRedisplay();
}


// Clears the current window and draws a triangle.
void display() {

  // Set every pixel in the frame buffer to the current clear color.
  glClear(GL_COLOR_BUFFER_BIT);

  // Drawing is done by specifying a sequence of vertices.  The way these
  // vertices are connected (or not connected) depends on the argument to
  // glBegin.  GL_POLYGON constructs a filled polygon.

/*
    glBegin(GL_POLYGON);
        glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
        glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(0.9, 0, 0.6);glVertex3f(tx,100+ty,100+tZ);
        glColor3f(0, 0, 1);glVertex3f(100+tx,100+ty,tZ);
        glColor3f(0, 0, 1); glVertex3f(150+tx, 50+ty,50+tZ);
        glColor3f(0, 0, 1); glVertex3f(100+tx,ty,100+tZ);
    glEnd();
*/

    glBegin(GL_POLYGON);

     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.5, .75, .35);glVertex3f(tx+20,10+ty,tZ);
        glColor3f(.5, .75, .35);glVertex3f(90+tx,10+ty,tZ);
        glColor3f(.5, .75, .35); glVertex3f(90+tx, 57.5+ty,tZ);
        glColor3f(.5, .75, .35); glVertex3f(20+tx,ty+57.5,tZ);
    glEnd();

     glBegin(GL_POLYGON);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(0.9, 0, 0.6);glVertex3f(tx+20,10+ty,tZ+50);
        glColor3f(0.9, 0, .1);glVertex3f(90+tx,10+ty,tZ+50);
        glColor3f(0.9, 0, .6); glVertex3f(90+tx, 57.5+ty,tZ+50);
        glColor3f(0.9, 0, .6); glVertex3f(20+tx,ty+57.5,tZ+50);
    glEnd();

     glBegin(GL_POLYGON);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.75, 0.75, .25);glVertex3f(tx+20,10+ty,tZ+50);
        glColor3f(.75, 0.75, .25);glVertex3f(20+tx,10+ty,tZ);
        glColor3f(.75, 0.75, .25); glVertex3f(20+tx, 57.5+ty,tZ);
        glColor3f(.75, 0.75, .25); glVertex3f(20+tx, 57.5+ty,tZ+50);
    glEnd();

     glBegin(GL_POLYGON);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.75, 0.75, .25);glVertex3f(tx+90,10+ty,tZ+50);
        glColor3f(.75, 0.75, .25);glVertex3f(90+tx,10+ty,tZ);
        glColor3f(.75, 0.75, .25); glVertex3f(90+tx, 57.5+ty,tZ);
        glColor3f(.75, 0.75, .25); glVertex3f(90+tx, 57.5+ty,tZ+50);
    glEnd();


    glBegin(GL_TRIANGLES);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.5, 0.5, .25);glVertex3f (tx+90, 57.5+ty, tZ);
        glColor3f(.5, 0.5, .25);glVertex3f(tx+90, 57.5+ty, tZ+50);
        glColor3f(.5, 0.5, .25); glVertex3f(tx+90, 80+ty, tZ+25);
    glEnd();

    glBegin(GL_TRIANGLES);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.5, 0.5, .25);glVertex3f (tx+20, 57.5+ty, tZ);
        glColor3f(.5, 0.5, .25);glVertex3f(tx+20, 57.5+ty, tZ+50);
        glColor3f(.5, 0.5, .25); glVertex3f(tx+20, 80+ty, tZ+25);
    glEnd();

    glBegin(GL_POLYGON);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.55, 0.35, .2);glVertex3f(tx+20,57.5+ty,tZ);
        glColor3f(.55, 0.35, .2);glVertex3f(90+tx,57.5+ty,tZ);
        glColor3f(.55, 0.35, .2); glVertex3f(90+tx, 80+ty,tZ+25);
        glColor3f(.55, 0.35, .2); glVertex3f(20+tx, 80+ty,tZ+25);
    glEnd();

    glBegin(GL_POLYGON);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.55, 0.35, .2);glVertex3f(tx+20, 57.5+ty,tZ+50);
        glColor3f(.55, 0.35, .2);glVertex3f(90+tx, 57.5+ty,tZ+50);
        glColor3f(.55, 0.35, .2); glVertex3f(90+tx, 80+ty,tZ+25);
        glColor3f(.55, 0.35, .2); glVertex3f(20+tx, 80+ty,tZ+25);
    glEnd();

    glBegin(GL_POLYGON);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.15, 0.2, .3);glVertex3f(tx+47, 10+ty,tZ+50);
        glColor3f(.15, 0.2, .3);glVertex3f(65+tx, 10+ty,tZ+50);
        glColor3f(.15, 0.2, .3); glVertex3f(65+tx, 57.5+ty,tZ+50);
        glColor3f(.15, 0.2, .3); glVertex3f(47+tx, 57.5+ty,tZ+50);
    glEnd();

     glBegin(GL_POLYGON);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.3, 0.2, .1);glVertex3f(tx+27, 20+ty,tZ+50);
        glColor3f(.3, 0.2, .1);glVertex3f(38+tx, 20+ty,tZ+50);
        glColor3f(.3, 0.2, .1); glVertex3f(38+tx, 47.5+ty,tZ+50);
        glColor3f(.3, 0.2, .1); glVertex3f(27+tx, 47.5+ty,tZ+50);
    glEnd();

    glBegin(GL_POLYGON);
     //   glColor3f(1, 0.8, 0); glVertex3f(tx,ty,tZ);
   //     glColor3f(1, 0, 0);glVertex3f(-50+tx,50+ty,50+tZ);
        glColor3f(.3, 0.2, .1);glVertex3f(tx+74, 20+ty,tZ+50);
        glColor3f(.3, 0.2, .1);glVertex3f(85+tx, 20+ty,tZ+50);
        glColor3f(.3, 0.2, .1); glVertex3f(85+tx, 47.5+ty,tZ+50);
        glColor3f(.3, 0.2, .1); glVertex3f(74+tx, 47.5+ty,tZ+50);
    glEnd();







// glTranslatef(tx, ty, tZ);
 //glTranslatef(-tx, -ty,-tZ);
 glRotatef((GLfloat)a1, 0.0, 1.0, 1.0);
 a1 = 0;
 glRotatef((GLfloat)a2, 1.0, 0.0, 1.0);
 a2 = 0;
 glRotatef((GLfloat)a3, 1.0, 1.0, 0.0);
 a3 = 0;

  // Flush drawing command buffer to make drawing happen as soon as possible.
  glFlush();
  glPopMatrix();
    glutSwapBuffers();
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.
int main(int argc, char** argv) {

  // Use a single buffered window in RGB mode (as opposed to a double-buffered
  // window or color-index mode).
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Position window at (80,80)-(480,380) and give it a title.
 glutInitWindowPosition(50, 50);
  glutInitWindowSize(600, 500);
  glutCreateWindow("A Hexagon");

  // Tell GLUT that whenever the main window needs to be repainted that it
  // should call the function display().
  glutDisplayFunc(display);

  // Tell GLUT to start reading and processing events.  This function
  // never returns; the program only exits when the user closes the main
  // window or kills the process.
  glutSpecialFunc(special);
  init();
  glutMainLoop();
}

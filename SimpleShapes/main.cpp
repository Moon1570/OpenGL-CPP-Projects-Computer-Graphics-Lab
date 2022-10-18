
#include <GL/gl.h>
#include <GL/glut.h>   // freeglut.h might be a better alternative, if available.
#include <windows.h>

void initGL() {

    glClearColor(0.0, 0.0, 0.0, 1.0); // background color

    glEnable(GL_DEPTH_TEST);  // Required for 3D drawing, not usually for 2D.

    // TODO: Uncomment the following 4 lines to do some typical initialization for
    // lighting and materials.

    // glEnable(GL_LIGHTING);        // Enable lighting.
    // glEnable(GL_LIGHT0);          // Turn on a light.  By default, shines from direction of viewer.
    // glEnable(GL_NORMALIZE);       // OpenGL will make all normal vectors into unit normals
    // glEnable(GL_COLOR_MATERIAL);  // Material ambient and diffuse colors can be set by glColor*

}

void displayRectangle() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();

   glutSwapBuffers();  // Render now
}


void displayTriangle() {  // Display function will draw the image.

    glClearColor( 0, 0, 0, 1 );  // (In fact, this is the default.)
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f(1.0f, 0.0f, 0.0f); // red
    glBegin(GL_TRIANGLES);
 //   glColor3f( 1, 0, 0 ); // red
    glVertex2f( -0.8, -0.8 );
  //  glColor3f( 1, 0, 0 ); // green
    glVertex2f( 0.8, -0.8 );
  //  glColor3f( 1, 0, 0 ); // blue
    glVertex2f( 0, 0.9 );
    glEnd();

    glutSwapBuffers(); // Required to copy color buffer onto the screen.

}

void displayPolygon() {

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
      glColor3f(1.0f, 1.0f, 0.0f); // Yellow
      glVertex2f(0.4f, 0.2f);
      glVertex2f(0.6f, 0.2f);
      glVertex2f(0.7f, 0.4f);
      glVertex2f(0.6f, 0.6f);
      glVertex2f(0.4f, 0.6f);
      glVertex2f(0.3f, 0.4f);
   glEnd();


   glutSwapBuffers();
}

void display(){
  //  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearColor( 0, 0, 0, 1 );
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

   // Draw a Red 1x1 Square centered at origin



    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glVertex2f(-0.75f, -0.25f);    // x, y
      glVertex2f( -.25f, -0.25f);
      glVertex2f( -.25f,  0.25f);
      glVertex2f(-0.75f,  0.25f);
   glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f( 0, 0.4 );
        glVertex2f( 0, -.5);
        glVertex2f( .4, -0.5 );
    glEnd();

   glBegin(GL_POLYGON);            // These vertices form a closed polygon
 //     glColor3f(1.0f, 1.0f, 0.0f); // Yellow
      glVertex2f(0.4f, 0.2f);
      glVertex2f(0.6f, 0.2f);
      glVertex2f(0.7f, 0.4f);
      glVertex2f(0.6f, 0.6f);
      glVertex2f(0.4f, 0.6f);
      glVertex2f(0.3f, 0.4f);
   glEnd();


   glutSwapBuffers();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   // glutDisplayFunc(displayRectangle);
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<sstream>
#include <string>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
#include <unistd.h>
#include<stdio.h>

using namespace std;

static float xp=-.55;
int static crspeed = 60;
float crmove = 4;
float static y11= -3.3;
float static zp= 2;
float static tpx= .15;
int static carpos= 0;
float view = 10.0;
int static score= 0;
int static totalMeter = 0;
char quote[6][80];
int numberOfQuotes = 0, i;
int static carspeed= 45;
float static sky_red=0;
float static sky_green= .8;
float sky_blue= 1.0;
int roadlight = 50;
float rtri =0;
float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

double eyex = 1, eyey = 1, eyez = -4, posx = 8, posy = 6, posz = -75,  upx = 0, upy = 1, upz =0;
	//gluLookAt(0.0, 30.0, .0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

void sprint( float x, float y, string st)
{
    int l,i;
//    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i <  st.length(); i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }


}

void keyboardown(int key, int x, int y)
{
	switch (key){

	case GLUT_KEY_RIGHT:
	    xp=.55;
	    carpos=1;
      break;



	case GLUT_KEY_LEFT:
	    xp=-.55;
	    carpos=0;
	    break;


    case GLUT_KEY_UP:
        if (crspeed>5){
        crspeed-=5;
        carspeed+=5;
        }

        else
            crspeed=crspeed;
        break;


    case GLUT_KEY_DOWN:
       if (crspeed<60){
        crspeed+=5;
        carspeed-=5;
        }

        else
            crspeed=crspeed;
        break;

    case GLUT_KEY_END:
        crspeed=1000000;
        carspeed=-999995;

        usleep(5000000);

        crspeed=60;
        carspeed=-55;

        cout<<crspeed<<" "<<carspeed<<endl;

        break;

   case GLUT_KEY_F4: posx += 0.5; break;
    case GLUT_KEY_F5: posx -= 0.5; break;
    case GLUT_KEY_F6: posy += 0.5; break;
    case GLUT_KEY_F7: posy -= 0.5; break;
    case GLUT_KEY_F8: posz += 0.5; printf("posz = %lf", posz); break;
    case GLUT_KEY_F9: posz -= 0.5; break;


	default:
		break;

	}
}

//Extra Display Function
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 1.0, 3200);
	glMatrixMode(GL_MODELVIEW);
}

GLfloat UpwardsScrollVelocity = -1.0;

void timeTick(void)
{
	if (UpwardsScrollVelocity< -1)
		view -= 0.0011;
	if (view < 0) { view = 2; UpwardsScrollVelocity = -1.0; }
	//  exit(0);
	UpwardsScrollVelocity -= 0.2;
	glutPostRedisplay();
}


void RenderToDisplay()
{
	int l, lenghOfQuote, i;

	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(-20, 1.0, 0.0, 0.0);
	glScalef(0.05, 0.05, 0.05);

	for (l = 0; l<numberOfQuotes; l++)
	{
		lenghOfQuote = (int)strlen(quote[l]);
		glPushMatrix();
		glTranslatef(-(lenghOfQuote * 37), (l * 200), 0.0);
		for (i = 0; i < lenghOfQuote; i++)
		{
			glColor3f((UpwardsScrollVelocity / 10) + 300 + (l * 10), (UpwardsScrollVelocity / 10) + 300 + (l * 10), 0.0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, quote[l][i]);
		}
		glPopMatrix();
	}
}




void myDisplayFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	RenderToDisplay();
	glutSwapBuffers();
}

int winner(char a)
{


	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 500);
	glutCreateWindow("GAME OVER");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLineWidth(3);
	//char c=char(score);
	strcpy(quote[1], "Game Over");
	strcpy(quote[0], "Drive more carefully!");
	numberOfQuotes = 5;
	glutDisplayFunc(myDisplayFunction);
	glutReshapeFunc(reshape);
	glutIdleFunc(timeTick);
	glutMainLoop();

	return 0;
}

//Extra Display Function End

  void keyboard(unsigned char key, int x, int y)
{
    if(key=='n')
    {
        sky_red=0;
        sky_green=0.2;
        sky_blue=0.25;
        roadlight= 255;


    }

    else if(key=='d')
    {
        sky_red=0;
        sky_green=0.8;
        sky_blue=1.0;
        roadlight= 50;

    }

    else if(key=='e')
    {
        exit(1);
    }

}




bool collision()
{

	if (0 > (crmove-y11)&& -1 < (crmove-y11)&& carpos==1 )
	{
		return true;
	}

	else if (0 > (crmove-(y11-10))&& -1 < (crmove-(y11-10))&& carpos==0 )
	{
	    return true;
	}

    else if (0 > (crmove-(y11-20))&& -1 < (crmove-(y11-20))&& carpos==0 )
	{
	    return true;
	}

	 else if (0 > (crmove-(y11-30))&& -1 < (crmove-(y11-30))&& carpos==1 )
	{
	    return true;
	}


	 else if (0 > (crmove-(y11-30))&& -1 < (crmove-(y11-30))&& carpos==0 )
	{
	    y11-=40;
	    return false;
	}

	else
    {
        return false;
	}
}

    bool GameScore()
    {
    if (0 > (crmove-y11)&& -1 < (crmove-y11)&& carpos==0 )
	{
	    score++;
	}

	else if (0 > (crmove-(y11-10))&& -1 < (crmove-(y11-10))&& carpos==1 )
	{
	     score++;
	}

    else if (0 > (crmove-(y11-20))&& -1 < (crmove-(y11-20))&& carpos==1 )
	{

	     score++;
	}

	 else if (0 > (crmove-(y11-30))&& -1 < (crmove-(y11-30))&& carpos==0 )
	{
        //return false;
	     score+=10;
	}

	else if (0 > (crmove-(y11-35))&& -1 < (crmove-(y11-35))&& carpos==0 )
	{
        return true;
	     score+=10;
	}


    else{
        totalMeter++;
        //    cout<<totalMeter<<"Total Meter"<<endl;
        return false;
    }
    }
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


float home= 6;
void gamercar()
    {
        glPushMatrix();
            glTranslatef(xp, -1.0, 3.5);
            glPushMatrix();
            glRotatef(-10 , -1.0, 0.0, 0.0);
            glScalef(1.3, 0.8, 2.0);
			glColor3f(1, 1, 1);
            glutSolidCube(.3);
            glPopMatrix();
            glPushMatrix();
           glTranslatef(0.0, tpx, 0.0);
            glRotatef(-10 , -1.0, 0.0, 0.0);
            glScalef(1.0, .5, .5);
			glColor3f(0, 0, 0);
            glutSolidCube(.2);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.21, -0.12, 0.10);
            glRotatef(80 , 0.0, 1.2, 0.0);
            glScalef(.07, .14, .07);
			glColor3f(1, 0, 0);
            glutWireTorus(.2, .4, 20, 15);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.21, 0.0, -0.2);
            glRotatef(80 , 0.0, 1.2, 0.0);
            glScalef(.07, .14, .07);
			glColor3f(1, 0, 0);
            glutWireTorus(.2, .4, 20, 15);
            glPopMatrix();


            glPushMatrix();
            glTranslatef(-0.21, -0.12, 0.10);
            glRotatef(80 , 0.0, 1.2, 0.0);
            glScalef(.07, .14, .07);
			glColor3f(1, 0, 0);
            glutWireTorus(.2, .4, 20, 15);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.21, 0.0, -0.2);
            glRotatef(80 , 0.0, 1.2, 0.0);
            glScalef(.07, .14, .07);
			glColor3f(1, 0, 0);
            glutWireTorus(.2, .4, 20, 15);
            glPopMatrix();


            glPushMatrix();
            glTranslatef(-0.10, -0.10, 0.30);
            glRotatef(80 , 0.0, 1.2, 0.0);
            glScalef(.07, .03, .07);
			glColor3f(1, .5, 0);
            glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.10, -0.10, 0.30);
            glRotatef(80 , 0.0, 1.2, 0.0);
            glScalef(.07, .03, .07);
			glColor3f(1, .5, 0);
            glutSolidCube(1);
            glPopMatrix();

            glPopMatrix();

    }

 void sky()
        {
        glBegin(GL_QUADS);
            glColor3ub(sky_red, 0, sky_blue);
			glVertex3f(-4.0, 1.5, 0);
			glVertex3f(4.0, 1.5, 0);
			glVertex3f(8.0, 3, 0);
			glVertex3f(-8.0, 3, 0);
		glEnd();
        }


void roadside()
    {

	//tree
     for (float z = -38; z < 400; z +=4)
	{
		glPushMatrix();
            glColor3ub(200, 200, 200);
			glTranslatef(-1.20, z, .40);
			glScalef(.2, .2, 3);
            glutSolidCube(.4);
		glPopMatrix();
		glPushMatrix();
            glColor3ub(200, 200, 200);
			glTranslatef(-.84, z, 1.0);
			glScalef(2, .2, .2);
            glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
            glColor4ub(255, 255, 255, roadlight);
			glTranslatef(-.44, z, 0.70);
			//glScalef(2, .2, .2);
            glutSolidCone(.2,.3,15,20);
		glPopMatrix();



		//2d red Bar
/*
		glPushMatrix();
             glColor3ub(255, 0, 20);
			glTranslatef(-1.4, z+.2, .15);
			glScalef(.80, .30, .60);
            glutSolidCube(.8);
		glPopMatrix();
		glPushMatrix();
             glColor3ub(255, 255, 20);
			glTranslatef(0.0, 0.0, .40);
		glBegin(GL_QUADS);
			glVertex3f(-1.10, z, 0);
			glVertex3f(-.85, z, -.2);
			glVertex3f(-.85, z+.3, -.2);
			glVertex3f(-1.10, z+.3, 0);
		glEnd();
		glPopMatrix();
		glPushMatrix();
             glColor3ub(255, 0, 20);
			glTranslatef(-.7, z+.2, .10);
			glScalef(1.0, .60, .60);
		glutSolidCube(.4);
		glPopMatrix();
		*/
	}




        glBegin(GL_QUADS);
            glColor3ub(0, 155, 20);
			glVertex3f(-5.0, -10, 0);
			glVertex3f(-1.0, -10, 0);
			glVertex3f(-1.0, 400, 0);
			glVertex3f(-5.0, 400, 0);
		glEnd();
		glBegin(GL_QUADS);
            glColor3ub(0, 155, 20);
			glVertex3f(1.0, -10, 0);
			glVertex3f(5.0, -10, 0);
			glVertex3f(5.0, 400, 0);
			glVertex3f(1.0, 400, 0);
		glEnd();


    }

    void house(){
     for (float z = -40; z < 400; z +=4.8)
	{
		glPushMatrix();
		glScalef(1.0, 1.0, 1.0);
		glPushMatrix();
			glColor3ub(70, 61, 46);
			glTranslatef(-3.0, z, .30);
            glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(255, 255, 255);
			glTranslatef(-2.55, z, .40);
            glutSolidCube(.2);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(255, 255, 255);
			glTranslatef(-2.9, z-.5, .2);
			glScalef(.6, .2, 1);
            glutSolidCube(.5);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0, 1, 1);
			glRotatef(0, 0.0, 0.0, 0.0);
			glTranslatef(-3.0, z, .70);
				glutSolidCone(1, 1, 4, 6);
		glPopMatrix();
		glPopMatrix();

		//right side

		glPushMatrix();
		glPushMatrix();
			glColor3f(1, 1, 1);
			glTranslatef(3.0, z, .30);
            glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(2.55, z, .40);
            glutSolidCube(.2);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(2.9, z-.5, .2);
			glScalef(.6, .2, 1);
            glutSolidCube(.5);
		glPopMatrix();

		glPushMatrix();
			glColor3ub(70, 61, 46);
			glTranslatef(3.0, z, .60);
				glutSolidCone(1, .8, 4, 6);
		glPopMatrix();
		glPopMatrix();

	}
    }
    void tree(){
        for (float z = -40; z < 400; z +=4)
	{
		glPushMatrix();
		glPushMatrix();
			glColor3f(0, 1, 0);
			glTranslatef(-1.20, z, .45);
            glutSolidCone(.2, .4, 20, 10);
		glPopMatrix();
            glColor3ub(102, 51, 0);
			glTranslatef(-1.20, z, .25);
			glScalef(.2, .2, 1);
            glutSolidCube(.4);
		glPopMatrix();

		//right

		glPushMatrix();
		glPushMatrix();
			glColor3f(0, 1, 0);
			glTranslatef(1.20, z, .50);
            glutSolidCone(.2, .4, 20, 10);
		glPopMatrix();
            glColor3ub(102, 51, 0);
			glTranslatef(1.20, z, .30);
			glScalef(.2, .2, 1);
            glutSolidCube(.4);
		glPopMatrix();
	}

    }




void roadline(){
    for (float z = -4; z < 6; z +=1)
	{
		glPushMatrix();

			glColor3f(1, 1, 1);
				glBegin(GL_QUADS);
				glVertex3f(-.03, z, 0);
				glVertex3f(.03, z, 0);
				glVertex3f(.03, z+.5, 0);
				glVertex3f(-.03, z+.5, 0);
			glEnd();
		glPopMatrix();
	}
    }


    void objectcube()
    {
         for (float zp = -20; zp < 400; zp+=40)
	{
		//glPushMatrix();
		glPushMatrix();
			glColor3f(0, 1, 0);
			glTranslatef(-.50, zp, -.1);
            glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0, 1, 0);
			glTranslatef(.50, zp+10, -.1);
            glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0, 1, 0);
			glTranslatef(.50, zp+20, -.1);
            glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0, 1, 0);
			glTranslatef(-.50, zp+30, -.1);
            glutSolidCube(.4);
		glPopMatrix();

   }
    }


    void road(){
        for (float z = -10; z < 400; z +=1)
	{
		glPushMatrix();
			glColor3f(1, 1, 1);
				glBegin(GL_QUADS);
				glVertex3f(-.03, z, 0);
				glVertex3f(.03, z, 0);
				glVertex3f(.03, z+.5, 0);
				glVertex3f(-.03, z+.5, 0);
			glEnd();
		glPopMatrix();
	}
	glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(0.0, 0.0, -.50);
		glBegin(GL_QUADS);
			glVertex3f(-1.3, -10, 0);
			glVertex3f(1.3, -10, 0);
			glVertex3f(1.3, 400, 0);
			glVertex3f(-1.3, 400, 0);
		glEnd();


	glPopMatrix();


    }

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
//	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units
	gamercar();
	//sky();
    glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, 0.0, 0.0); //Move to the center of the triangle
	glRotatef(80 , -1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0.0, crmove, 0.0);
	glClearColor(0.0, 0.0, 0.0, 1.0);
    road();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(0.0, crmove, 0.0);
    tree();
    house();
    roadside();
    objectcube();
    GameScore();
    cout<<score<<endl;
    //cout<<crmove<<endl;
    //cout<<y11<<endl;
    glPopMatrix();

    glPushMatrix();
     glColor3ub(0,0,0);
     glTranslatef(5.52, 0.0, 2.0);

     ostringstream cnvrt;
     cnvrt << score;
     sprint(-4,-2.3,"Score: "+cnvrt.str());
     glPopMatrix();


      glPushMatrix();
     glColor3ub(0,0,0);
     glTranslatef(5.5, 0.0, 1.8);
     ostringstream cnvrt2;
     cnvrt2 << totalMeter;
     sprint(-4,-2.4,"Distance Travel: "+cnvrt2.str());
     glPopMatrix();

     glPushMatrix();
     glColor3ub(0,0,0);
     glTranslatef(5.5, 0.0, 1.6);
     ostringstream cnvrt3;

     if(carspeed<40){
        cnvrt3 << 40;
     } else{
        cnvrt3 << carspeed;
     }


     sprint(-4,-2.4,"Speed: "+cnvrt3.str());
     glPopMatrix();

    glPopMatrix();
    glClearColor(sky_red, sky_green, sky_blue, 1.0);

    if(collision())
    {
        winner('a');
    }
    //sky();

       glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      gluLookAt(eyex, eyey, eyez, posx, posy, posz,  upx, upy, upz);

	glutSwapBuffers();
}

void update(int value) {
    crmove-= 0.1f;
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;

	}
	_ang_tri += 0.7f;
	if (_ang_tri > 80) {
            _ang_tri=0;
		//crmove= 40;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(crspeed, update, 0);
}


int main(int argc, char** argv) {
	//Initialize GLUT

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Transformations");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
	//glClearColor(1.0, 1.0, 1.0, 0.0);
	initRendering();
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0); //Add a timer
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardown);
	glutMainLoop();
	return 0;
}

#include <GL/glut.h>
#include <vector>
#include <math.h>
#include <string.h>

GLdouble mModel[16];

int np = 0;

float px[10000];
float py[10000];
float pz[10000];
	

void tortuga3d(){

GLdouble cordx[] = { 0.0, 4.0, -8.0, 0.0, 8.0,-4.0};
GLdouble cordy[] = { -6.0, 2.0, 0.0, 8.0, 0.0,-4.0};
GLdouble r[] = { 6.0, 3.0, 2.0, 2.0, 2.0, 2.0};
GLint i;
glColor3f(1.0,0.0,1.0);

	for (i=0;i<6;i++){
	glutWireSphere(r[i], 15.0, 15.0);
	glTranslatef(cordx[i],cordy[i],0.0);
	}
}

void addPointToTrace() {

GLdouble m[16];
glGetDoublev (GL_MODELVIEW_MATRIX, m);

if (np == 0) { // add the first point
px [0] = 0;
py [0] = 0;
pz [0] = 0;
np++;
}

px [np] = m[0] * px [0] + m[4] * py [0] + m[8] * pz [0] + m[12];
py [np] = m[1] * px [0] + m[5] * py [0] + m[9] * pz [0] + m[13];
pz [np] = m[2] * px [0] + m[6] * py [0] + m[10] * pz [0] + m[14];

np++;

}

void displayTrace() {
int i;
glColor3f(255,255,255) ;
glBegin(GL_LINE_STRIP);
	for (i = 0; i < np; i++) {
	glVertex3f(px[i],py[i],pz[i]);
	}
glEnd();
}


void keyboard(unsigned char key,int x, int y)
{

/*glPushMatrix();
glLoadIdentity();
glMultMatrixd(mModel);
*/

	switch(key){

		case 'f':
		{
			glRotatef(-2.0,0.0,1.0,0.0);
			break;
		}

		case 'h':
		{
			glRotatef(2.0,0.0,1.0,0.0);
			break;
		}

		case 't':
		{
			glRotatef(2.0,1.0,0.0,0.);
			break;
		}

		case 'g':
		{
			glRotatef(-2.0,1.0,0.0,0.0);
			break;
		}

		case 'w':
		{
			glTranslatef(0.0, 0.1,0.0);
			addPointToTrace();
			break;
		}

		case 's':
		{
			glTranslatef(0.0,-0.1,0.0);
			addPointToTrace();
			break;
		}

		case 'a':
		{
			glTranslatef(-0.1,0.0,0.0);
			//addPointToTrace();
			break;
		}

		case 'd':
		{
			glTranslatef(0.1,0.0,0.0);
			//addPointToTrace();
			break;
		}

		case'=':
		{
			glScalef(2,2,2);
			break;
		}

		case'-':
		{
			glScalef(0.5,0.5,0.5);
			break;
		}
		
	}

/*glGetDoublev (GL_MODELVIEW_MATRIX, mModel);
glPopMatrix();*/
glutPostRedisplay();

}


void display(void) {

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//glPushMatrix();
//glMultMatrixd(mModel);
glColor3f(1.0,1.0,0.0) ;
tortuga3d();
glPopMatrix();
displayTrace();
glutSwapBuffers();

}

void reshape(int width, int height) {

glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(0.0, 1.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


int main(int argc, char **argv)
{
	
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glGetDoublev (GL_MODELVIEW_MATRIX, mModel);
	glPopMatrix();


	glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 640, 640 );
    glutCreateWindow("Turtle");
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
	
}
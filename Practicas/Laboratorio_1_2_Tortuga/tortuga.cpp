#include <GL/glut.h>
#include <vector>
#include <math.h>
#include <string.h>


void Tortuga(int sides,float radio,int x,int y)
{

	std::vector<float> puntox;
    std::vector<float> puntoy;

    float PI = 3.14159f;
    float step = (2 * PI )/sides;
    
    for (int i =0; i < sides; i++)
    {
     puntox.push_back(x+radio*cos(2*PI*i/sides));
     puntoy.push_back(y+radio*sin(2*PI*i/sides));
    }

    puntox.push_back(puntox[0]);
    puntoy.push_back(puntoy[0]);

    glBegin(GL_LINES);
    for(int  i= 0; i < puntox.size()-1; ++i)
    {
        glVertex2f(puntox[i],puntoy[i]);
        glVertex2f(puntox[i+1],puntoy[i+1]);
        
    }
    glEnd();




}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Tortuga(30,1,0,0);
	Tortuga(30,0.5,0,1);
	Tortuga(30,0.4,1,1);	
	Tortuga(30,0.4,1,-1);
	Tortuga(30,0.4,-1,1);
	Tortuga(30,0.4,-1,-1);


	glFlush();
}


void keyboard(unsigned char key,int x, int y)
{
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
			break;
		}

		case 's':
		{
			glTranslatef(0.0,-0.1,0.0);
			break;
		}

		case 'a':
		{
			glTranslatef(-0.1,0.0,0.0);
			break;
		}

		case 'd':
		{
			glTranslatef(0.1,0.0,0.0);
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

glutPostRedisplay();

}


void display(void) {
glClearColor(1.0, 1.0, 1.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
draw();
//glutWireTorus(0.25,0.75, 28, 28);
glutSwapBuffers();
}

void reshape(int width, int height) {
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


int main(int argc, char **argv)
{
	

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
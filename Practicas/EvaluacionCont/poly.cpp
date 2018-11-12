#include <GL/glut.h>
#include <vector>
#include <array>


int vp_width = 640;
int vp_height = 480;

std::array<int, 2> currentPt;
std::vector<std::array<int, 2>> pts;
bool closed = false;


void draw_polygon(int button, int state, int x, int y)
{
    currentPt = std::array<int, 2>{x, vp_height-y}; 

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if ( closed )
            pts.clear(); 
        closed = false;
        pts.push_back( currentPt );
    }
    if ( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
        closed = true;


}

void mouse_move(int x, int y)
{
    currentPt = std::array<int, 2>{x, vp_height-y};
    glutPostRedisplay();
}





void draw()
{

     if (!pts.empty() )
    {
        glBegin(GL_LINE_STRIP);
        for ( auto &pt : pts )
            glVertex2f( (float)pt[0], (float)pt[1] );
        auto &endPt = closed ? pts.front() : currentPt;
        glVertex2f((float)endPt[0], (float)endPt[1] );
        glEnd();
    }


   
    glFlush();

}





void keyboard(unsigned char key,int x, int y)
{
    switch(key){

        case 't':
        {
            glRotatef(2.0,0.0,0.0,1.0);
            break;
        }

        case 'g':
        {
            glRotatef(-2.0,0.0,0.0,1.0);
            break;
        }

        case 'w':
        {
            glTranslatef(0.0, 10.0,0.0);
            break;
        }

        case 's':
        {
            glTranslatef(0.0,-10.0,0.0);
            break;
        }

        case 'a':
        {
            glTranslatef(-10.0,0.0,0.0);
            break;
        }

        case 'd':
        {
            glTranslatef(10.0,0.0,0.0);
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




void display(void)
{   
    
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    draw();

    glutSwapBuffers();
}



int main(int argc, char **argv) 
{
    

    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow("Polygon");

        
    glutPassiveMotionFunc (mouse_move);
    glutMouseFunc(draw_polygon);

    

    glMatrixMode( GL_PROJECTION );
    glOrtho(0.0f, (float)vp_width, 0.0f, (float)vp_height, -1.0, 1.0);


    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
   
}
#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <iostream>


void Poligono(int sides,float radio)
{
    if( sides < 3 ) return;

    float PI = 3.14159f;
    float step = (2 * PI )/sides;

   
    std::vector<float> puntox;
    std::vector<float> puntoy;

    
    for (int i =0; i < sides; i++)
    {
     puntox.push_back(radio*cos(2*PI*i/sides));
     puntoy.push_back(radio*sin(2*PI*i/sides));
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

    //radio multiplicado por el seno y coseno son los puntos
    


}


void ponerPixel(GLint x,GLint y){
	glColor3f(255,255,255);
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}


void Incremental_basico(GLint x0,GLint y0, GLint xf, GLint yf){
	int x=0,y=0,valor;
	float m;
	m=(yf-y0)/(xf-x0);
	for(x=x0;x<=xf;x++){
		y=( y0 + m * ( x - x0) );
		ponerPixel(x,y);
	}
}
void Punto_medio(GLint x0,GLint y0, GLint xf, GLint yf){
	int dx,dy,incE,incNE,d,x,y;

	dx=xf-x0;
	dy=yf-y0;
	d=2*dy-dx; /* Valor inicial de d*/
	incE=2*dy; /*Incremento de E*/
	incNE=2*(dy-dx);/* Incremento de NE*/
	x=x0;
	y=y0;
	ponerPixel(x,y);
	while (x < xf){
		if(d <=0){
			d=d+incE;
			x=x+1;
		}else{
		   d=d+incNE;
		   x=x+1;
		   y=y+1;
		}
		ponerPixel(x,y);
	}
}



void display()
{
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-20,20,-20,20);

    // Para el segundo trabajo trabajar con GL_Points y el X y Y debe
    // coincidir con el tam de la ventana

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glColor3ub( 255, 255, 255 );
    Poligono(12,20);


    GLint x0=-5,y0=0,xf=10,yf=15;
    //Incremental_basico( x0, y0,  xf,  yf);
    Punto_medio( x0, y0,  xf,  yf);
    

    glutSwapBuffers();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow("Poligono");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
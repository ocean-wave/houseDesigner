#include "CameraPerspective.h"

CameraPerspective::CameraPerspective()
{
    // Initialize Modelview and Projection matrixes
    // (to set a clean state, even though this should be the default OpenGL values)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set default values for camera and projection
    R      = 2.5;
    angleh = 15;
    anglev = 35;
    Cnear   = .1f;
    Cfar    = 500;
}

CameraPerspective::~CameraPerspective()
{
}

void CameraPerspective::setProjection(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Projection will be adapted to inverse aspect ratios
	if (w>=h)
		gluPerspective(60.0,1.0*w/h,Cnear,Cfar);
	else
		gluPerspective(60.0*h/w,1.0*w/h,Cnear,Cfar);
}

void CameraPerspective::update()
{
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float anglex,angley;
	GLfloat cam[3],up[3];

	// Rad -> Deg
	anglex=angleh*PI/180;
	angley=anglev*PI/180;
		
	// Cam position and up-vector
	cam[0]=R*cos(anglex)*cos(angley);
	cam[1]=R*sin(anglex)*cos(angley);
	cam[2]=R*sin(angley);
	//up[0]=-cos(anglex)*sin(angley);
	//up[1]=-sin(anglex)*sin(angley);
	//up[2]=cos(angley);
	up[0] = 0;
	up[1] = 1;
	up[2] = 0;

	// Set camera in OpenGL
	gluLookAt(cam[0],cam[1],cam[2],
				0.0,0.0,0.0,
				up[0],up[1],up[2]);
}

void CameraPerspective::move(float ah, float av, bool)
{
    angleh += ah/2;
    anglev -= av/2;

    if(anglev>=360)	anglev=anglev-360;
    if(anglev<0)	anglev=anglev+360;
    if(angleh>=360)	angleh=angleh-360;
    if(angleh<0)	angleh=angleh+360;
}

void CameraPerspective::AddDistance(float d)
{
    R += d;
    if(R < 1.0)
        R = 1.0;
}
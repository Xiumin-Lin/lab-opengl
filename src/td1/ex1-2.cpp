#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

void Render()
{
    glEnable(GL_CULL_FACE);

    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    // 1er sommet
    glColor3ub(255, 0, 0);  // rouge
    glVertex2f(0.0f, 0.5f);
    
    // 2e sommet
    glColor3ub(0, 255, 0);  // blue
    glVertex2f(-0.5f, -0.5f);
    
    // 3e sommet
    glColor3ub(0, 0, 255);  // vert
    glVertex2f(0.5f, -0.5f);
    glEnd();
}

// la ‘callback’ executee par glutDisplayFunc()
void Display()
{
    Render();
    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(960,540);
    glutCreateWindow("Triangle");
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
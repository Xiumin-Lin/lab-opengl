#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <cmath>

const int WIDTH = 660;
const int HEIGHT = 660;
const float DEFAULT_INTENSITY = 0.3f;

void Render()
{
    glEnable(GL_SCISSOR_TEST);
    int scissorHeight = HEIGHT / 2;

    float secondsSinceStart = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    float sinValue = sin(secondsSinceStart);

    // scissor haut gauche
    glViewport(0, 0, WIDTH, scissorHeight);
    glScissor(0, 0, WIDTH, scissorHeight);
    glClearColor(0.f, 0.f, DEFAULT_INTENSITY, DEFAULT_INTENSITY);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix(); // Save current matrix state
    glRotatef(20 * secondsSinceStart, 1.f, 1.f, 1.f);
    glTranslatef(0, sinValue, 0);

        glBegin(GL_TRIANGLES);
        // 1er sommet
        glColor3ub(255, 0, 0);  // rouge
        glVertex2f(0.0f, 0.5f);
        
        // 2e sommet
        glColor3ub(0, 255, 0);  // blue
        glVertex2f(0.5f, -0.5f);
        
        // 3e sommet
        glColor3ub(0, 0, 255);  // vert
        glVertex2f(-0.5f, -0.5f);
        glEnd();
    glPopMatrix(); // Restore matrix state

    // scissor haut droit
    glViewport(0, scissorHeight, WIDTH, scissorHeight);
    glScissor(0, scissorHeight, WIDTH, scissorHeight);
    glClearColor(0.f, 0.f, 0.f, DEFAULT_INTENSITY);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix(); // Save current matrix state
    glRotatef(30 * secondsSinceStart, 1.f, 1.f, 0.f);

        glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex3f(-0.6f, -0.5f, 0.0f);

        glColor3f(0.3f, 0.3f, 0.3f); // Gray
        glVertex3f(0.6f, -0.5f, 0.0f);
        
        glColor3f(1.0f, 0.0f, 1.0f); // Purple
        glVertex3f(-0.5f, 0.2f, 0.0f);
        
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        glVertex3f(0.5f, 0.2f, 0.0f);
        
        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glVertex3f(0.0f, 0.8f, 0.0f);
        glEnd();

    glPopMatrix(); // Restore matrix state

    glDisable(GL_SCISSOR_TEST);
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
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("4 Objects");
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
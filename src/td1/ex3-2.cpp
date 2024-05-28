#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <cmath>

const int WIDTH = 960;
const int HEIGHT = 540;
const float DEFAULT_INTENSITY = 0.3f;

void Render()
{
    glEnable(GL_SCISSOR_TEST);
    int scissorWidth = WIDTH / 2;
    int scissorHeight = HEIGHT / 2;

    float secondsSinceStart = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    float sinValue = sin(secondsSinceStart);

    // scissor bas gauche
    glViewport(0, 0, scissorWidth, scissorHeight);
    glScissor(0, 0, scissorWidth, scissorHeight);
    glClearColor(DEFAULT_INTENSITY, 0.f, 0.f, DEFAULT_INTENSITY);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5.0f);

    // scale de 1.5
    glScalef(sinValue, sinValue, sinValue);
    
        glBegin(GL_LINES);
        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glVertex3f(-0.5f, -0.5f, 0.0f);

        glColor3f(1.0f, 0.0f, 1.0f); // Purple
        glVertex3f(0.5f, 0.5f, 0.0f);
        glEnd();

    glLoadIdentity();   // cancel any transformation and rotation
    
    // scissor bas droit
    glViewport(scissorWidth, 0, scissorWidth, scissorHeight);
    glScissor(scissorWidth, 0, scissorWidth, scissorHeight);
    glClearColor(0.f, DEFAULT_INTENSITY, 0.f, DEFAULT_INTENSITY);
    glClear(GL_COLOR_BUFFER_BIT);

    // translation de 10 unités par seconde
    glTranslatef(sinValue, 0, 0);
    
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glVertex2f(-0.5f, -0.5f);

        glColor3f(1.0f, 0.0f, 1.0f); // Purple
        glVertex2f(0.5f, -0.5f);
        
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        glVertex2f(0.5f, 0.5f);

        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glVertex2f(-0.5f, 0.5f);
        glEnd();

    glLoadIdentity();   // cancel any transformation and rotation

    // scissor haut gauche
    glViewport(0, scissorHeight, scissorWidth, scissorHeight);
    glScissor(0, scissorHeight, scissorWidth, scissorHeight);
    glClearColor(0.f, 0.f, DEFAULT_INTENSITY, DEFAULT_INTENSITY);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // rotation de 20° par seconde
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
    
    glLoadIdentity();   // cancel any transformation and rotation

    // scissor haut droit
    glViewport(scissorWidth, scissorHeight, scissorWidth, scissorHeight);
    glScissor(scissorWidth, scissorHeight, scissorWidth, scissorHeight);
    glClearColor(0.f, 0.f, 0.f, DEFAULT_INTENSITY);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // rotation de 20° par seconde
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

    glLoadIdentity();   // cancel any transformation and rotation

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
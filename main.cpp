#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0;
static int fingerBase1 = 0, fingerUp1 = 0;
static int fingerBase2 = 0, fingerUp2 = 0;
static int fingerBase3 = 0, fingerUp3 = 0;
static int fingerBase4 = 0, fingerUp4 = 0;
static int fingerBase5 = 0, fingerUp5 = 0;

int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    // Whole arm rotation
    // All of arm is rotating around x = -1
    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);


    // Draw the limb
    // The shoulder is centered in origin and has 1, 1, 1 dimensions
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glScalef (2.0, 0.8, 1.2);
    glutSolidCube (1.0);
    glPopMatrix();


    // Elbow and below rotation
    // When the elbow first drawn, it is rotated around x = -1
    // But then shifted in X by 1
    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);

    // Drawing the elbow
    glPushMatrix();
    glScalef (2.0, 0.4, 1.2);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidCube (1.0);
    glPopMatrix();



    // FINGER 1
    glPushMatrix();
    // Rotation of finger base 1
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase1, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger base 1
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.35);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCube(1);
    glPopMatrix();


    //Rotation of finger flang 1
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp1, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger flang 1
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.35);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(0.0, 0.0, 0.8);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();

    // FINGER 2
    glPushMatrix();
    // Rotation of finger base 2
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase2, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger base 2
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(0.0, 1.0, 1.0);
    glutSolidCube(1);
    glPopMatrix();


    //Rotation of finger flang 2
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp2, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger flang 2
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.15);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(0.0, 0.8, 0.8);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();


    // FINGER 3
    glPushMatrix();
    // Rotation of finger base 3
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase3, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger base 3
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.05);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(0.5, 0.5, 1.0);
    glutSolidCube(1);
    glPopMatrix();


    //Rotation of finger flang 3
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp3, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger flang 3
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.05);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(0.5, 0.5, 0.8);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();

    // FINGER 4
    glPushMatrix();
    // Rotation of finger base 4
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase4, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger base 4
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.25);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidCube(1);
    glPopMatrix();


    //Rotation of finger flang 4
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp4, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger flang 4
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.25);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(0.8, 0.8, 0.0);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();


    // FINGER 5
    glPushMatrix();
    // Rotation of finger base 5
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)fingerBase5, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger base 5
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.45);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(1.0, 0.0, 1.0);
    glutSolidCube(1);
    glPopMatrix();


    //Rotation of finger flang 5
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp5, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);

    // Draw finger flang 5
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.45);
    glScalef(0.3, 0.1, 0.1);
    glColor3f(0.8, 0.0, 0.8);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();



    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 's':
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':
            if (elbow < 150)
            {
                elbow = (elbow + 5);
                glutPostRedisplay();
            }
            break;

        case 'E':
            if (elbow > 0)
            {
                elbow = (elbow - 5);
                glutPostRedisplay();
            }
            break;

            // FINGER 1
        case 'f':
            if (fingerBase1 < 60) {
                fingerBase1 = (fingerBase1 + 5);
                glutPostRedisplay();
            }
            break;
        case 'F':
            if (fingerBase1 > -90) {
                fingerBase1 = (fingerBase1 - 5);
                glutPostRedisplay();
            }
            break;
        case 'r':
            if (fingerUp1 < 0) {
                fingerUp1 = (fingerUp1 + 5);
                glutPostRedisplay();
            }
            break;
        case 'R':
            if (fingerUp1 > -90) {
                fingerUp1 = (fingerUp1 - 5);
                glutPostRedisplay();
            }
            break;

            // FINGER 2
        case 'g':
            if (fingerBase2 < 60) {
                fingerBase2 = (fingerBase2 + 5);
                glutPostRedisplay();
            }
            break;
        case 'G':
            if (fingerBase2 > -90) {
                fingerBase2 = (fingerBase2 - 5);
                glutPostRedisplay();
            }
            break;
        case 't':
            if (fingerUp2 < 0) {
                fingerUp2 = (fingerUp2 + 5);
                glutPostRedisplay();
            }
            break;
        case 'T':
            if (fingerUp2 > -90) {
                fingerUp2 = (fingerUp2 - 5);
                glutPostRedisplay();
            }
            break;

            // FINGER 3
        case 'h':
            if (fingerBase3 < 60) {
                fingerBase3 = (fingerBase3 + 5);
                glutPostRedisplay();
            }
            break;
        case 'H':
            if (fingerBase3 > -90) {
                fingerBase3 = (fingerBase3 - 5);
                glutPostRedisplay();
            }
            break;
        case 'y':
            if (fingerUp3 < 0) {
                fingerUp3 = (fingerUp3 + 5);
                glutPostRedisplay();
            }
            break;
        case 'Y':
            if (fingerUp3 > -90) {
                fingerUp3 = (fingerUp3 - 5);
                glutPostRedisplay();
            }
            break;

            // FINGER 4
        case 'j':
            if (fingerBase4 < 60) {
                fingerBase4 = (fingerBase4 + 5);
                glutPostRedisplay();
            }
            break;
        case 'J':
            if (fingerBase4 > -90) {
                fingerBase4 = (fingerBase4 - 5);
                glutPostRedisplay();
            }
            break;
        case 'u':
            if (fingerUp4 < 0) {
                fingerUp4 = (fingerUp4 + 5);
                glutPostRedisplay();
            }
            break;
        case 'U':
            if (fingerUp4 > -90) {
                fingerUp4 = (fingerUp4 - 5);
                glutPostRedisplay();
            }
            break;

            // FINGER 5
        case 'k':
            if (fingerBase5 < 60) {
                fingerBase5 = (fingerBase5 + 5);
                glutPostRedisplay();
            }
            break;
        case 'K':
            if (fingerBase5 > -90) {
                fingerBase5= (fingerBase5 - 5);
                glutPostRedisplay();
            }
            break;
        case 'i':
            if (fingerUp5 < 0) {
                fingerUp5 = (fingerUp5 + 5);
                glutPostRedisplay();
            }
            break;
        case 'I':
            if (fingerUp5 > -90) {
                fingerUp5 = (fingerUp5 - 5);
                glutPostRedisplay();
            }
            break;


            // ESC CASE

        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
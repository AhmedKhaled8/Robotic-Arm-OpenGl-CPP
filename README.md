# SBE306B - Assignment 1 - Robot Arm
**Under the supervision of: [Eng. Ayman Anwar](https://github.com/A-M-Anwar) and [Eng. Eslam Adel](https://github.com/EslamAdel)**

In this assignment, we are asked to design using OpenGL - C++ a robot arm with the addition of animation repersented in rotations using keyboard.

### 1. The Arm:
Our robot arm consists of three main parts; shoulder, elbow, fingers. 

<center><img src="arm.png" alt="alt text" width="200" height="300"></center>

The shoulder have the ability to rotate freely 360&deg; around its joint. Elbow and its limb is rotating up to 150&deg; and down to 0&deg; in straight with the shoulder limb. For fingers, each consists of a metacarpal and a  phalange . The metacarpals rotate up to 60&deg; and down to -90&deg; and the distal phalanges only rotate internally down to -90&deg;. 


### 2. ```main``` function
Our main function is:
```cpp
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
```
* ```glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);``` activates the RGB and double buffering bits to use the RGB systems and the 2 buffers to make our animation smoother and faster.
* ```glutDisplayFunc(display);``` will show all of our drawings implemented in the ```display``` function.
* ```glutKeyboardFunc(keyboard);``` will allow the events triggered from keyboard buttons activated to do some actions, to rotate our objects, depending the cases implemented in ```keyboard``` function.
* ```glutMainLoop();``` leaves the control and looping of window displaying to GLUT.
  


### 3. Shoulder
<center><img src="shoulder.png" alt="alt text" width="500" height="250"></center>

* First we will create our cube "shoulder":
```cpp
void display(){
    // Another blocks of code will be added later here.
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0); // RED
    glScalef (2.0, 0.8, 1.2); // 2* X, 0.8* Y, 1.2* Z
    glutSolidCube (1.0); // Drawing Cube with 1 in all dimensions.
    // Dimensions will be modified in the glScalef
    // Now, L(x) = 2, W(z) = 1.2, H(y) = 0.8 
    glPopMatrix();
}
```
* Now, we want to rotate the shoulder around the most distant line x = -1 . (SHOWN IN FIG).
* So, we will translate our object 1 in  +x - direction and rotate the object with an angle ```shoulder``` the inverse the translation with 1 in -x - direction.
```cpp
static int shoulder = 0, elbow = 0;
// Remaining Variables
void display(){
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
}
```

* As mentioned above, our shoulder has the freedom of rotation around the joint (360&deg;). We will use `s` to rotate counter clockwise and `S` to to rotate clockwise.

```cpp
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

        // Other cases will be added later...
    }
}
```

### 4. Elbow:
<center><img src="elbow.png" alt="alt text" width="500" height="250"></center>

* The elbow will rotate around x = 1. Because the elbow is first drawn in the origin, we will translate it with 1 in +x - direction and rotate it with angle ```elbow``` and now we will translate it another 1 in +ve x - direction as the elbow axis of rotation is the nearest end of the shoulder cube. Of course, the rotation of the shoulder will also applied to the elbow and that's why the rotation of shoulder is being popped of the stack before drawing the elbow cube

```cpp
void display(){
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
}
```

* For the rotation of the elbow, we have limitations as the elbow will not rotate more than 150&deg; and won't rotate downwards. For flexion we will use `e` and for extension we will use `E`.
```cpp
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
                elbow = (elbow + 5) % 360;
                glutPostRedisplay();
            }
            break;

        case 'E':
            if (elbow > 0)
            {
                elbow = (elbow - 5) % 360;
                glutPostRedisplay();
            }
            break;
    }
}
```

### 4. Fingers
<center><img src="fingers.png" alt="alt text" width="500" height="250"></center>

* The above figure shows the coordinates of each finger of the 5 fingers. These corrdinates will be translated into when moving the fingers. For the rotation of the fingers , the metacarpals rotate with angle ```fingerBase[No.]``` up to 60° and down to -90° and the distal phalanges only rotate with angle ```fingerUp[No.]``` internally down to -90°
```cpp
// Our final display()
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
```


* For keyboard actions, the above figure shows the keys of the flexion of the phalanges and the uppercase of them cause the extension. And for the metacarpals, we will use the keys below those, displayed in the figure, on our keyboard.

```cpp
// Used variables
static int shoulder = 0, elbow = 0;
static int fingerBase1 = 0, fingerUp1 = 0;
static int fingerBase2 = 0, fingerUp2 = 0;
static int fingerBase3 = 0, fingerUp3 = 0;
static int fingerBase4 = 0, fingerUp4 = 0;
static int fingerBase5 = 0, fingerUp5 = 0;


// Our final keyboard function
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
```



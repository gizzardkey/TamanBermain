// ===================================================
//  T A M A N   B E R M A I N  -  K E L O M P O K  1
//  FPS CAMERA (FINAL VERSION)
// ===================================================

#include <GL/freeglut.h>
#include <cmath>
#include <iostream>

// ===================================================
//  KAMERA GLOBAL
// ===================================================
const float PI = 3.14159265f;
const float MOVE_SPEED = 0.05f;
const float MOUSE_SENSITIVITY = 0.15f;

float cameraPosX = 0.0f;
float cameraPosY = 3.0f;
float cameraPosZ = 8.0f;

float cameraYaw   = 0.0f;
float cameraPitch = -20.0f;

int windowWidth  = 1200;
int windowHeight = 800;

bool keys[256] = { false };

// ===================================================
//  ANIMASI JUNGKAT
// ===================================================
float rotPapan = 0.0f;
float rotateSpeed = 3.0f;
int arah = 1;

// ===================================================
//  UPDATE KAMERA (FPS)
// ===================================================
void updateCamera() {
    float yawRad   = cameraYaw * PI / 180.0f;
    float pitchRad = cameraPitch * PI / 180.0f;

    float forwardX = sin(yawRad) * cos(pitchRad);
    float forwardY = -sin(pitchRad);
    float forwardZ = -cos(yawRad) * cos(pitchRad);

    float rightX = sin(yawRad + PI / 2);
    float rightZ = -cos(yawRad + PI / 2);

    if (keys['w'] || keys['W']) {
        cameraPosX += forwardX * MOVE_SPEED;
        cameraPosY += forwardY * MOVE_SPEED;
        cameraPosZ += forwardZ * MOVE_SPEED;
    }
    if (keys['s'] || keys['S']) {
        cameraPosX -= forwardX * MOVE_SPEED;
        cameraPosY -= forwardY * MOVE_SPEED;
        cameraPosZ -= forwardZ * MOVE_SPEED;
    }
    if (keys['a'] || keys['A']) {
        cameraPosX -= rightX * MOVE_SPEED;
        cameraPosZ -= rightZ * MOVE_SPEED;
    }
    if (keys['d'] || keys['D']) {
        cameraPosX += rightX * MOVE_SPEED;
        cameraPosZ += rightZ * MOVE_SPEED;
    }
    if (keys[' ']) cameraPosY += MOVE_SPEED;
}

// ===================================================
//  MOUSE LOOK FPS
// ===================================================
void mouseMotion(int x, int y) {
    int cx = windowWidth / 2;
    int cy = windowHeight / 2;

    if (x == cx && y == cy) return;

    cameraYaw   += (x - cx) * MOUSE_SENSITIVITY;
    cameraPitch += (y - cy) * MOUSE_SENSITIVITY;

    if (cameraPitch >  89) cameraPitch =  89;
    if (cameraPitch < -89) cameraPitch = -89;

    glutWarpPointer(cx, cy);
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glutSetCursor(GLUT_CURSOR_NONE);
        glutWarpPointer(windowWidth / 2, windowHeight / 2);
    }
}

// ===================================================
//  INPUT
// ===================================================
void keyboard(unsigned char key, int x, int y) {
    keys[key] = true;

    if (key == 'p') {
        rotPapan += arah * rotateSpeed;
        if (rotPapan > 25) arah = -1;
        if (rotPapan < -25) arah = 1;
    }

    if (key == 27) exit(0);
}

void keyboardUp(unsigned char key, int x, int y) {
    keys[key] = false;
}

// ===================================================
//  IDLE (WAJIB UNTUK FPS)
// ===================================================
void idle() {
    updateCamera();
    glutPostRedisplay();
}

/// AKSESORIS

void pohon(){

    // ================= BATANG POHON =================
    glColor3f(0.45f, 0.24f, 0.10f); // coklat batang

    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glScalef(0.5f, 4.0f, 0.5f);

        glPushMatrix();
            glRotatef(-90, 1, 0, 0);
            glutSolidCylinder(1.0, 1.0, 32, 32);
        glPopMatrix();
    glPopMatrix();


    // ================= DAUN POHON BAWAH =================
    glColor3f(0.0f, 0.3f, 0.0f);

    glPushMatrix();
        glTranslatef(0.0f, 2.0f, 0.0f);
        glRotatef(-90, 1, 0, 0);
        glutSolidCone(1.8, 2.0, 32, 32);
    glPopMatrix();


    // ================= DAUN POHON TENGAH =================
    glPushMatrix();
        glTranslatef(0.0f, 3.0f, 0.0f);
        glRotatef(-90, 1, 0, 0);
        glutSolidCone(1.5, 2.0, 32, 32);
    glPopMatrix();


    // ================= DAUN POHON ATAS =================
    glColor3f(0.0f, 0.4f, 0.0f);

    glPushMatrix();
        glTranslatef(0.0f, 4.0f, 0.0f);
        glRotatef(-90, 1, 0, 0);
        glutSolidCone(1.2, 1.8, 32, 32);
    glPopMatrix();


    // ================= PUNCAK DAUN =================
    glColor3f(0.0f, 0.5f, 0.0f);

    glPushMatrix();
        glTranslatef(0.0f, 5.0f, 0.0f);
        glRotatef(-90, 1, 0, 0);
        glutSolidCone(0.8, 1.5, 32, 32);
    glPopMatrix();
}

void peletakan_pohon(){
    glPushMatrix();
        glTranslatef(11.0f, 0.0f, 11.3f);
        pohon();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(11.0f, 0.0f, -11.3f);
        pohon();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-11.0f, 0.0f, 11.3f);
        pohon();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-11.0f, 0.0f, -11.3f);
        pohon();
    glPopMatrix();
}

void kolam(){
    //Kiri
    glPushMatrix();
        glColor3f(0.741, 0.741, 0.741);
        glTranslatef(-3, 0, 0);
        glRotatef(90, 1, 0, 0);
        glScalef(1, 9, 1);
        glutSolidCube(1.0f); 
    glPopMatrix();

    //Kanan
    glPushMatrix();
        glColor3f(0.741, 0.741, 0.741);
        glTranslatef(3, 0, 0);
        glRotatef(90, 1, 0, 0);
        glScalef(1, 9, 1);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Atas
    glPushMatrix();
        glColor3f(0.741, 0.741, 0.741);
        glTranslatef(0, 0, -5);
        glRotatef(90, 1, 0, 0);
        glScalef(7, 1, 1);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Bawah
    glPushMatrix();
        glColor3f(0.741, 0.741, 0.741);
        glTranslatef(0, 0, 5);
        glRotatef(90, 1, 0, 0);
        glScalef(7, 1, 1);
        glutSolidCube(1.0f);
    glPopMatrix();

    //Air
    glPushMatrix();
        glColor3f(0, 0.765, 1);
        glTranslatef(0, 0, 0);
        glScalef(5, 0.1, 9);
        glutSolidCube(1.0f);
    glPopMatrix();
}

void peletakan_kolam(){
    glPushMatrix();
        glTranslatef(-7, 0.4, 0);
        kolam();
    glPopMatrix();
}

void rumput(){
    glPushMatrix();
        glScalef(10.0f, 0.1f, 10.0f);
        glutSolidCube(3);
    glPopMatrix();
}

void full_jalan(){
    // Jalan
    glPushMatrix();
        glColor3f(0.502, 0.502, 0.502);
        glTranslatef(0, 0.01f, 0);
        glScalef(1.8, 0.1, 8.35);
        glutSolidCube(3);
    glPopMatrix();

    // Strip Jalan Kiri
    glPushMatrix();
        glColor3f(0.259, 0.259, 0.259);
        glTranslatef(-2.5, 0.05f, 0);
        glScalef(0.2, 0.1, 8.35);
        glutSolidCube(3);
    glPopMatrix();

    // Strip Jalan Kanan
    glPushMatrix();
        glColor3f(0.259, 0.259, 0.259);
        glTranslatef(2.5, 0.05f, 0);
        glScalef(0.2, 0.1, 8.35);
        glutSolidCube(3);
    glPopMatrix();
}

void full_gapura() {

    // ================= TIANG KIRI =================
    glPushMatrix();
        glColor3f(1.0f, 0.0f, 0.0f);
        glTranslatef(-2.5f, 0.0f, 0.0f);   // kiri & naik setengah tinggi
        glRotatef(-90, 1, 0, 0);           // tegak
        glScalef(0.3f, 0.3f, 4.0f);        // tinggi tiang
        glutSolidCylinder(1.0, 1.0, 32, 32);
    glPopMatrix();

    // ================= TIANG KANAN =================
    glPushMatrix();
        glColor3f(1.0f, 0.0f, 0.0f);
        glTranslatef(2.5f, 0.0f, 0.0f);   // kanan
        glRotatef(-90, 1, 0, 0);
        glScalef(0.3f, 0.3f, 4.0f);
        glutSolidCylinder(1.0, 1.0, 32, 32);
    glPopMatrix();

    // ================= BALOK ATAS =================
    glPushMatrix();
        glColor3f(1.0f, 0.0f, 0.0f);
        glTranslatef(-2.95f, 4.0f, 0.0f);    // tepat di tengah
        glRotatef(90, 0, 1, 0);            // horizontal kiri-kanan
        glScalef(0.3f, 0.3f, 6.0f);        // panjang balok
        glutSolidCylinder(1.0, 1.0, 32, 32);
    glPopMatrix();
}

void peletakan_gapura(){
    glPushMatrix();
    glTranslatef(0, 0, 12);
        full_gapura();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -12);
        full_gapura();
    glPopMatrix();
}

void tanah(){
    glPushMatrix();
        glColor3f(0.1f, 0.6f, 0.1f);
        glTranslatef(0, -0.1f, 0);
        glScalef(25, 0.2, 25);
        glutSolidCube(1);
    glPopMatrix();
}

void semak() {

    // =================================================
    // ================= SEMAK DEPAN ===================
    // =================================================

    // kanan
    glPushMatrix(); glTranslatef(5,0,11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(4,0,11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(7,0,11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(6,0,11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(9,0,11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(8,0,11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(11,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(10,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    // kiri
    glPushMatrix(); glTranslatef(-5,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-4,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-7,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-6,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-9,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-8,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-11,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-10,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    // =================================================
    // ================= SEMAK BELAKANG ================
    // =================================================

    glPushMatrix(); glTranslatef(5,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(4,0,-11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(7,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(6,0,-11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(9,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(8,0,-11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(11,0,-11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(10,0,-11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,-11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    // =================================================
    // ================= SEMAK KANAN ===================
    // =================================================

    glPushMatrix(); glTranslatef(12,0,9.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,10.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,7.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,8.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,5.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,6.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,3.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,4.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,1.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,2.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,-0.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,0.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,-2.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,-1.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,-4.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,-3.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,-6.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,-5.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,-8.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,-7.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(12,0,-10.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,-9.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    // =================================================
    // ================= SEMAK KIRI ====================
    // =================================================

    glPushMatrix(); glTranslatef(-12,0,9.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,10.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,7.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,8.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,5.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,6.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,3.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,4.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,1.5);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,2.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,-0.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,0.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,-2.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,-1.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,-4.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,-3.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,-6.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,-5.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,-8.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,-7.5); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,-10.5); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-12,0,-9.5);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
}

// AKSESORIS (END)

// OBJEK UTAMA

// ================== 2406007 Sayyid Dzaky Farhan ================== //

void lampu(){
    // Bola Lampu
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(0, 5.1, 0);
        glutSolidSphere(1, 20, 20);
    glPopMatrix();

    // Kaki Lampu
    glPushMatrix();
        glColor3f(0.439, 0.439, 0.439);
        glScalef(0.7, 0.2, 0.7);
        glutSolidCube(2);
    glPopMatrix();

    // Tiang Lampu
    glPushMatrix();
        glColor3f(0.569, 0.569, 0.569);
        glTranslatef(0, 0.3, 0);
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.2, 5, 20, 20);
    glPopMatrix();
}

void peletakan_lampu(){
    glPushMatrix();
        glTranslatef(-3.7, 0.2, 8);
        lampu();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(3.7, 0.2, 0);
        lampu();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.7, 0.2, -7);
        lampu();
    glPopMatrix();
}

// ================== 2406007 Sayyid Dzaky Farhan ================== //

// ================== 2406000 Rizal Septiazi      ================== //

void jungkat_jungkit(){
    //Tiang 1
    glPushMatrix();
        glColor3f(0,0,1);
        glTranslatef(0, -12, 0);
        glRotatef(90, 0, 1, 0);
        glScalef(2, 0.3, 2);
        glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,0,0);
        glTranslatef(0, 3, 0);
        glRotatef(90, 1, 0, 0);
        glScalef(2, 2, 1);
        glutSolidCylinder(1.0, 15.0, 10, 10);
    glPopMatrix();

    // tiang 2
    glPushMatrix();
        glColor3f(0,0,1);
        glTranslatef(15, -12, 0);
        glRotatef(90, 0, 1, 0);
        glScalef(2, 0.3, 2);
        glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,0,0);
        glTranslatef(15, 3, 0);
        glRotatef(90, 1, 0, 0);
        glScalef(2, 2, 1);
        glutSolidCylinder(1.0, 15.0, 10, 10);
    glPopMatrix();

    // Tiang Tengah
    glPushMatrix();
        glColor3f(0,0,1);
        glTranslatef(17, 5, 0);
        glRotatef(-90, 0, 1, 0);
        glScalef(2, 2, 1.3);
        glutSolidCylinder(1.0, 15.0, 10, 10);
    glPopMatrix();

    // GRUP papan + pegangan 1 + pegangan 2 DALAM 1 TRANSFORM
    glPushMatrix();
        glColor3f(0,0,1);
        glTranslatef(7.3, 5, 0);
        glRotatef(rotPapan, 1, 0, 0);  // ROTASI DINAMIS !!!
        glTranslatef(-7.3, -5, 0);

        // Pegangan 1
        glPushMatrix();
            glColor3f(0,0,1);
            glTranslatef(8, 14, 18);
            glRotatef(90, 1, 0, 0);
            glScalef(1, 1, 0.6);
            glutSolidCylinder(1.0, 15.0, 10, 10);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1,0,0);
            glTranslatef(3.5, 15, -18);
            glRotatef(90, 0, 1, 0);
            glScalef(1, 1, 0.6);
            glutSolidCylinder(1.0, 15.0, 10, 10);
        glPopMatrix();

        // Pegangan 2
        glPushMatrix();
            glColor3f(0,0,1);
            glTranslatef(8, 14, -18);
            glRotatef(90, 1, 0, 0);
            glScalef(1, 1, 0.6);
            glutSolidCylinder(1.0, 15.0, 10, 10);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1,0,0);
            glTranslatef(3.5, 15, 18);
            glRotatef(90, 0, 1, 0);
            glScalef(1, 1, 0.6);
            glutSolidCylinder(1.0, 15.0, 10, 10);
        glPopMatrix();

        // Papan Kuning
        glPushMatrix();
            glColor3f(1,1,0);
            glTranslatef(7.3, 5, 0);
            glRotatef(90, 0, 1, 0);
            glScalef(25, 0.3, 6.5);
            glutSolidCube(3);
        glPopMatrix();

        // Baut
        glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(2, 5, 0);
            glRotatef(0, 1,0,0);
            glScalef(1,1,1);
            glutSolidSphere(1.5, 40, 40);
        glPopMatrix();

        glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(16.5, 5, 0);
            glRotatef(0, 1,0,0);
            glScalef(1,1,1);
            glutSolidSphere(1.5, 40, 40);
        glPopMatrix();
        glPopMatrix();

}

void peletakan_jungkat(){
    glPushMatrix();
        glTranslatef(7.5, 1.5, -3);     // atur posisi kalau perlu
        glScalef(0.1f, 0.1f, 0.1f);
        jungkat_jungkit();
    glPopMatrix();
}

// ================== 2406000 Rizal Septiazi      ================== //

// ================== 2406000 Hilma Putri         ================== //

void kursi() {

    glColor3f(0.55, 0.27, 0.07);

    // ================= DUDUKAN KURSI =================
    glPushMatrix();
        glTranslatef(0, 0, -2);

        // Dudukan Kursi 1
        glPushMatrix();
            glScalef(4.5, 0.3, 0.3);
            glutSolidCube(2);
        glPopMatrix();

        // Dudukan Kursi 2
        glPushMatrix();
            glTranslatef(0, 0, 1);
            glScalef(4.5, 0.3, 0.3);
            glutSolidCube(2);
        glPopMatrix();

        // Dudukan Kursi 3
        glPushMatrix();
            glTranslatef(0, 0, 2);
            glScalef(4.5, 0.3, 0.3);
            glutSolidCube(2);
        glPopMatrix();

        // Dudukan Kursi 4
        glPushMatrix();
            glTranslatef(0, 0, 3);
            glScalef(4.5, 0.3, 0.3);
            glutSolidCube(2);
        glPopMatrix();
    glPopMatrix();

    // ================= SAMBUNGAN KURSI =================
    glPushMatrix();
        glTranslatef(0, 0, -0.5);

        // Sambungan Kursi 1
        glPushMatrix();
            glTranslatef(-4, 0, 0);
            glScalef(0.3, 0.3, 1.8);
            glutSolidCube(2);
        glPopMatrix();

        // Sambungan Kursi 2
        glPushMatrix();
            glTranslatef(4, 0, 0);
            glScalef(0.3, 0.3, 1.8);
            glutSolidCube(2);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1, 0, -2.5);
        glRotatef(90, 1, 0, 0);

        // Sambungan Kursi 3
        glPushMatrix();
            glTranslatef(5, 0, -2);
            glScalef(0.3, 0.3, 1.8);
            glutSolidCube(2);
        glPopMatrix();

        // Sambungan Kursi 4
        glPushMatrix();
            glTranslatef(-3, 0, -2);
            glScalef(0.3, 0.3, 1.8);
            glutSolidCube(2);
        glPopMatrix();
    glPopMatrix();

    // ================= KAKI KURSI (SILINDER) =================
    glPushMatrix();
        glTranslatef(-4, -3, 1);
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.3, 3.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4, -3, 1);
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.3, 3.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-4, -3, -1.5);
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.3, 3.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4, -3, -1.5);
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.3, 3.0, 20, 20);
    glPopMatrix();

    // ================= BAWAHAN KAKI =================
    glPushMatrix();
        glTranslatef(-4, -3, 1);
        glutSolidSphere(0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4, -3, 1);
        glutSolidSphere(0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-4, -3, -1.5);
        glutSolidSphere(0.5, 40, 40);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4, -3, -1.5);
        glutSolidSphere(0.5, 40, 40);
    glPopMatrix();

    // ================= SANDARAN KURSI =================
    glPushMatrix();
        glTranslatef(0, 2, -2);
        glScalef(4.5, 0.3, 0.3);
        glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 3, -2);
        glScalef(4.5, 0.3, 0.3);
        glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 4, -2);
        glScalef(4.5, 0.3, 0.3);
        glutSolidCube(2);
    glPopMatrix();
}

void peletakan_kursi(){
    glPushMatrix();
        glTranslatef(3.7,1.3,7);
        glRotatef(-90, 0,1,0);
        glScalef(0.4,0.4,0.4);
        kursi();
    glPopMatrix();
}

// ================== 2406000 Hilma Putri         ================== //
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)windowWidth / windowHeight, 0.1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float yawRad   = cameraYaw * PI / 180.0f;
    float pitchRad = cameraPitch * PI / 180.0f;

    float lookX = cameraPosX + sin(yawRad) * cos(pitchRad);
    float lookY = cameraPosY - sin(pitchRad);
    float lookZ = cameraPosZ - cos(yawRad) * cos(pitchRad);

    gluLookAt(
        cameraPosX, cameraPosY, cameraPosZ,
        lookX, lookY, lookZ,
        0, 1, 0
    );

    // ===== GAMBAR SEMUA OBJEK =====
    semak();
    full_jalan();
    peletakan_lampu();
    tanah();
    peletakan_gapura();
    peletakan_kolam();
    peletakan_pohon();
    peletakan_jungkat();
    peletakan_kursi();

    glutSwapBuffers();
}

// ===================================================
//  INIT
// ===================================================
void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);

    float lightPos[] = { 10,10,10,1 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glClearColor(0.1f, 0.1f, 0.15f, 1);
}

// ===================================================
//  RESHAPE
// ===================================================
void reshape(int w, int h) {
    if (h == 0) h = 1;
    windowWidth = w;
    windowHeight = h;
    glViewport(0, 0, w, h);
}

// ===================================================
//  MAIN (FINAL)
// ===================================================
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Taman Bermain - Kelompok 1");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);

    glutPassiveMotionFunc(mouseMotion);
    glutMotionFunc(mouseMotion);
    glutMouseFunc(mouse);

    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}

#include <GL/freeglut.h>
#include <cmath>
#include <iostream>

// Variabel Kamera
float kameraX = 10.0f;
float kameraY = 10.0f;
float kameraZ = 10.0f;

void pohon() {

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


// =====================================================
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(
        kameraX, kameraY, kameraZ,
        0, 0, 0,
        0, 1, 0
    );

    pohon();

    glutSwapBuffers();
}

// =====================================================
void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(1, 1, 1, 1);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    float lightPos[] = {10, 10, 10, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

// =====================================================
void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)w / h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

// =====================================================
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Kursi Taman");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
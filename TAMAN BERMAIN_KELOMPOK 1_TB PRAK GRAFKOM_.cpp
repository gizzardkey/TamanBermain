// ---------------------------------- library
#include <GL/freeglut.h>
#include <cmath>
#include <iostream>

// Kamera 1
float kameraX = 0.0f;
float kameraY = 15.0f;
float kameraZ = 25.0f;

// Variabel rotasi papan
float rotPapan = 0.0f;
float rotateSpeed = 3.0f;
int arah = 1;

// Variabel Skalasi Awan
float sAwan = 1.0f;   // skala awal NORMAL
float bAwan = 0.06f;  // scaling

// Variabel Translasi Mobil
float tMobil = 10.8f;
float mMobil = 0.2f;

//Variabel Translasi Lauk
float tIkan = 0.0f;
float mIkan = 0.3f; // Kecepatan gerak ikan
float tIkanY = 0.0f;  // Posisi tinggi ikan
float mIkanY = 0.05f; // Kecepatan gerak ke atas

// Variabel Rotasi Ayunan
float rAyunan = 0.0;
float kAyunan = 1.5f;

// Variabel kincir angin
float rotKincir = 0.0f;
float speedKincir = 2.0f;

// CUACA

void cuaca_siang(){
    glClearColor(0.0297, 0.942, 0.990, 1.0f);

    glEnable(GL_LIGHTING); // Mengaktifkan Cahaya
    glEnable(GL_LIGHT0); // Cahaya Utama

    GLfloat ambient[]  = {0.35f, 0.35f, 0.35f, 1.0f};
    GLfloat diffuse[]  = {1.0f, 0.98f, 0.90f, 1.0f};
    GLfloat specular[] = {0.7f, 0.7f, 0.7f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT,  ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}

void cuaca_malam() {
    glClearColor(0.02f, 0.02f, 0.08f, 1.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    // Cahaya malam
    GLfloat ambient[]  = { 0.10f, 0.10f, 0.15f, 1.0f };
    GLfloat diffuse[]  = { 0.30f, 0.30f, 0.45f, 1.0f };
    GLfloat specular[] = { 0.40f, 0.40f, 0.50f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT,  ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}

void cuaca_sore() {
    glClearColor(0.96f, 0.58f, 0.28f, 1.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    // Cahaya sore
    GLfloat ambient[]  = { 0.25f, 0.22f, 0.20f, 1.0f };
    GLfloat diffuse[]  = { 1.0f, 0.55f, 0.30f, 1.0f };
    GLfloat specular[] = { 0.8f, 0.6f, 0.4f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT,  ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}

// KONTROL KAMERA
void kamera_1(){
    kameraX = 0.0f;
    kameraY = 15.0f;
    kameraZ = 25.0f;
}

void kamera_2(){
    // Kamera 2
    kameraX = -25.0f;
    kameraY = 15.0f;
    kameraZ = 0.0f;
}

void kamera_3(){
    // Kamera 3
    kameraX = 25.0f;
    kameraY = 15.0f;
    kameraZ = 0.0f;
}

void kamera_4(){
    // Kamera 4
    kameraX = 0.0f;
    kameraY = 15.0f;
    kameraZ = -25.0f;
}

// =========================== AKSESORIS ===========================
void kunang_kunang (){
	glDisable(GL_LIGHTING); 
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(4.0, 3, 8.4);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(8.0,5.0,11.7);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(-3.0, 5, -8.4);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(2.0, 3, 4.4);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(5.0,5.0, 6.7);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(3.0, 5, -8.4);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(4.0, 3, -8.4);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(8.0,5.0,11.7);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
      glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(-3.0, 5, -8.4);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(-5.0, 3, -8.4);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(-4.0,5.0,11.7);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    
      glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(-7.0, 5, -8.4);
        glutSolidSphere(0.09, 20, 20);
    glPopMatrix();
    glEnable(GL_LIGHTING);
}
void tempat_sampah() {
    glPushMatrix();
        glColor3f(0.7, 0.7, 0.7); 
        glTranslatef(4.0, 0.5, 8.4);
        glRotatef(-90, 1, 0, 0);  
        glutSolidCylinder(0.4, 0.8, 20, 2); 
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.7, 0.7, 0.7); 
        glTranslatef(4.0, 0.5, -8.4);
        glRotatef(-90, 1, 0, 0);  
        glutSolidCylinder(0.4, 0.8, 20, 2); 
    glPopMatrix();
}

void batu() {
//batu kangge dalem kolam
	
	//palih kanan
    glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(-5.0, 0.5, 4.0);
        glScalef(0.5f, 0.3f, 0.5f);   
        glRotatef(45, 1, 1, 0);      
        glutSolidDodecahedron();      
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(-5.0, 0.5, 3.0);
        glScalef(0.3f, 0.1f, 0.3f);    
        glRotatef(45, 1, 1, 0);      
        glutSolidDodecahedron();     
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(-6.0, 0.5, 4.3);
        glScalef(0.3f, 0.1f, 0.3f);    
        glRotatef(45, 1, 1, 0);     
        glutSolidDodecahedron();     
    glPopMatrix();
    
    //palih kiri
    glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(-9.0, 0.4, -4.0);
        glScalef(0.5f, 0.3f, 0.5f);    
        glRotatef(90, 1, 1, 0);     
        glutSolidDodecahedron();      
    glPopMatrix();
    
//batu kangge luar kolam
    //palih kanan
    glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(-11.0, 0.5, 6.0);
        glScalef(0.5f, 0.3f, 0.5f);   
        glRotatef(45, 1, 1, 0);      
        glutSolidDodecahedron();      
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(-10.0, 0.5, 6.0);
        glScalef(0.3f, 0.1f, 0.3f);   
        glRotatef(45, 1, 1, 0);      
        glutSolidDodecahedron();      
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(-11.0, 0.5, 5.0);
        glScalef(0.3f, 0.1f, 0.3f);   
        glRotatef(45, 1, 1, 0);      
        glutSolidDodecahedron();      
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(7.0, 0.5, 5.0);
        glScalef(0.3f, 0.1f, 0.3f);   
        glRotatef(45, 1, 1, 0);      
        glutSolidDodecahedron();      
    glPopMatrix();

	glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(5.0, 0.5, 10.0);
        glScalef(0.5f, 0.2f, 0.5f);   
        glRotatef(45, 1, 1, 0);      
        glutSolidDodecahedron();      
    glPopMatrix();
    
   	glPushMatrix();
        glColor3f(0.4f, 0.4f, 0.4);
        glTranslatef(8.0, 0.5, -10.0);
        glScalef(0.5f, 0.2f, 0.5f);   
        glRotatef(45, 1, 1, 0);      
        glutSolidDodecahedron();      
    glPopMatrix();

}
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

    // ================= SEMAK DEPAN ===================

    // kanan
    glPushMatrix(); glTranslatef(4,0,11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(5,0,11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(6,0,11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(7,0,11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(8,0,11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(9,0,11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(10,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(11,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    // kiri
    glPushMatrix(); glTranslatef(-4,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-5,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-6,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-7,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-8,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-9,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-10,0,11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-11,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    
    glPushMatrix(); glTranslatef(-12,0,11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    // ================= SEMAK BELAKANG ================

    // KANAN
    glPushMatrix(); glTranslatef(4,0,-11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(5,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(6,0,-11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(7,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(8,0,-11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(9,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(10,0,-11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(11,0,-11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,-11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    // KIRI
    glPushMatrix(); glTranslatef(-4,0,-11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-5,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-6,0,-11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-7,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-8,0,-11.7);  glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-9,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-10,0,-11.7); glScalef(0.9,0.9,0.9); glColor3f(0.24,0.53,0.24); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(-11,0,-11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();

    glPushMatrix(); glTranslatef(-12,0,-11.7); glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();
    glPushMatrix(); glTranslatef(12,0,-11.7);  glColor3f(0.13,0.37,0.13); glutSolidSphere(0.8,20,20); glPopMatrix();


    // ================= SEMAK KANAN ===================

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

    // ================= SEMAK KIRI ====================

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
// ======================== AKSESORIS (END) ========================

// ========================== OBJEK UTAMA ========================== //

// ================== 2406007 Sayyid Dzaky Farhan ================== //
void lampu(){
    // Bola Lampu
    glDisable(GL_LIGHTING);
    glPushMatrix();
        glColor3f(1, 0.984, 0);
        glTranslatef(0, 3, 0);
        glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    glEnable(GL_LIGHTING); 

    // Kaki Lampu
    glPushMatrix();
        glColor3f(0.439, 0.439, 0.439);
        glScalef(0.7, 0.2, 0.7);
        glutSolidCube(1);
    glPopMatrix();

    // Tiang Lampu
    glPushMatrix();
        glColor3f(0.569, 0.569, 0.569);
        glTranslatef(0, -1.5, 0);
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.1, 4, 20, 20);
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

void awan(){
    glPushMatrix();
        glColor3f(1,1,1);
        glTranslatef(1,0.8,0.7);
        glScalef(2,1,1);
        glutSolidSphere(2,32,32);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.89, 0.89, 0.89);
        glTranslatef(3,0,0);
        glScalef(2,1,1);
        glutSolidSphere(2,32,32);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.89, 0.89, 0.89);
        glTranslatef(-2,0,0);
        glScalef(2,1,1);
        glutSolidSphere(2,32,32);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.89, 0.89, 0.89);
        glTranslatef(0,-1.2,0);
        glScalef(2,1,1);
        glutSolidSphere(2,32,32);
    glPopMatrix();
}

void peletakan_awan(){
    glPushMatrix();
    glScalef(sAwan,1,1);
    glPushMatrix();
        glTranslatef(0,12,0);
        glScalef(0.5,0.5,0.5);
        awan();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-6,12,-4);
        glScalef(0.5,0.5,0.5);
        awan();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5,11,-5);
        glScalef(0.5,0.5,0.5);
        awan();
    glPopMatrix();
    glPopMatrix();
}

void mobil(){
    glPushMatrix();
        glPushMatrix();
            glColor3f(0.396, 0.4, 0.4);
            glTranslated(0,1.5,0);
            glScalef(1.5,1,3);
            glutSolidCube(3);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0, 0.827, 1);
            glTranslatef(0,2.7,1.7);
            glScalef(1.3,1.5,1.8);
            glutSolidCube(3);
        glPopMatrix();

        // Ban Belakang
        glPushMatrix();
            glColor3f(0.82, 0.82, 0.82);
            glTranslatef(2.7,0,2.3);
            glRotatef(-90,0,1,0);
            glutSolidCylinder(1.2,5.5,32,32);
        glPopMatrix();

        // Ban Depan
        glPushMatrix();
            glColor3f(0.82, 0.82, 0.82);
            glTranslatef(2.7,0,-2.3);
            glRotatef(-90,0,1,0);
            glutSolidCylinder(1.2,5.5,32,32);
        glPopMatrix();

        // Kerucut Mobil
        glPushMatrix();
            glColor3f(1,0,0);
            glTranslatef(0,6.5,2);
            glRotatef(90,1,0,0);
            glutSolidCone(1,5,32,32);
        glPopMatrix();
    glPopMatrix();
}

void peletakan_mobil(){
    // glPushMatrix();
    // glTranslatef(0,0,tMobil);
    glPushMatrix();
        glTranslatef(0,1,tMobil);
        glScalef(0.4,0.4,0.4);
        mobil();
    glPopMatrix();
    // glPopMatrix();
}
// ================== 2406007 Sayyid Dzaky Farhan ================== //

// ==================   2406034 Rizal Septiazi    ================== //
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
        glRotatef(rotPapan, 1, 0, 0);  // ROTASI si Papan
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
        glScalef(0.07f, 0.07f, 0.07f);
        jungkat_jungkit();
    glPopMatrix();
}

void lauk() {
    // Badan Ikan
    glPushMatrix();
        glColor3f(1.0f, 0.4f, 0.0f); 
        glScalef(1.5f, 0.8f, 0.5f); // biar lonjong
        glutSolidSphere(1.0, 20, 20);
    glPopMatrix();

    // Ekor
    glPushMatrix();
        glColor3f(1.0f, 0.2f, 0.0f); 
        glTranslatef(-1.2f, 0.0f, 0.0f);
        glRotatef(-90, 0, 1, 0);
        glutSolidCone(0.5, 1.0, 10, 10);
    glPopMatrix();
    
    //sirip
    glPushMatrix();
        glColor3f(1.0f, 0.2f, 0.0f); 
        glTranslatef(0.09f, 0.3f, 0.0f);
        glRotatef(-90, 1, 0, 0);
        glutSolidCone(0.5, 1.0, 5, 5);
    glPopMatrix();

    // Mata (Kiri & Kanan) 
    glDisable(GL_LIGHTING); 
    glColor3f(1.0f, 1.0f, 0.0f);
    glPushMatrix(); 
        glTranslatef(0.8f, 0.3f, 0.3f);
        glutSolidSphere(0.15, 10, 10);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.8f, 0.3f, -0.3f);
        glutSolidSphere(0.15, 10, 10); 
    glPopMatrix();

    glEnable(GL_LIGHTING); 
}

void peletakan_ikan() {
    glPushMatrix();
        glTranslatef(0.0, tIkanY,tIkan); 
        glPushMatrix();
            glTranslatef(-7.0f, 0.6f, 0.0f);
            // Logika supaya ikan berbalik arah, ketika nubruk tembok
            if (mIkan > 0) glRotatef(-90, 0, 1, 0);  // Biar Hadap depan
            else glRotatef(90, 0, 1, 0);  // Biar Hadap belakang
            glScalef(0.6f, 0.6f, 0.6f); 
            lauk();
        glPopMatrix();
    glPopMatrix();
}

// ==================   2406034 Rizal Septiazi    ================== //

// ==================    2406018 Hilma Putri      ================== //
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
        glTranslatef(3.7,1.3, 6);
        glRotatef(-90, 0,1,0);
        glScalef(0.3,0.3,0.3);
        kursi();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(3.7, 1.3, -6);
        glRotatef(-90, 0,1,0);
        glScalef(0.3,0.3,0.3);
        kursi();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-7.7, 1.3, -7);
        glRotatef(0, 0,1,0);
        glScalef(0.3,0.3,0.3);
        kursi();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-7.7, 1.3, 7);
        glRotatef(180, 0,1,0);
        glScalef(0.3,0.3,0.3);
        kursi();
    glPopMatrix();
}
void kincir_angin() {

    // Tiang Kincir
    glPushMatrix();
        glColor3f(0.3f, 0.6f, 1.0f);
        glTranslatef(0, -6, 0);
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.1, 2.0, 32, 1.0);
    glPopMatrix();

    // Kepala Kincir
    glPushMatrix();
        glColor3f(1.0f, 0.0f, 1.0f);
        glTranslatef(0, -4, 0);
        glutSolidSphere(0.2, 5.0, 5.0);
    glPopMatrix();

    // Baling-baling
	glPushMatrix();
    	glTranslatef(0, -4, 0);                // posisi pusat kincir
    	glRotatef(rotKincir, 0, 0, 1);        // rotasi animasi
    	glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
            glRotatef(i * 90, 0, 0, 1);   
            glTranslatef(0.4, 0, 0.1);      // geser dari pusat
            glScalef(0.6f, 0.2f, 0.1f);    // bentuk baling-baling
            glutSolidCube(1);
            rotKincir += 0.7f;   // kecepatan putaran
    		if (rotKincir >= 360) rotKincir -= 360;
    		glutPostRedisplay();
        glPopMatrix();
    }
	glPopMatrix();

}
// peletakan kincir
void peletakan1_kincir() {
    glPushMatrix();
        glTranslatef(8.0f, 4.0f, -8.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        kincir_angin();
    glPopMatrix();
}

void peletakan2_kincir() {
    glPushMatrix();
        glTranslatef(8.0f, 4.0f, 7.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        kincir_angin();
    glPopMatrix();
}

void peletakan3_kincir() {
    glPushMatrix();
        glTranslatef(9.0f, 4.0f, 9.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        kincir_angin();
    glPopMatrix();
}

void peletakan4_kincir() {
    glPushMatrix();
        glTranslatef(7.0f, 4.0f, 9.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        kincir_angin();
    glPopMatrix();
}

void peletakan5_kincir() {
    glPushMatrix();
        glTranslatef(9.0f, 4.0f, -10.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        kincir_angin();
    glPopMatrix();
}

void peletakan6_kincir() {
    glPushMatrix();
        glTranslatef(7.0f, 4.0f, -10.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        kincir_angin();
    glPopMatrix();
}
// ==================    2406018 Hilma Putri      ================== //

// ==================   2406011 Assyifa Ramdani   ================== //
void ayunan(){
    // Tiang Kiri
    glPushMatrix();
        glColor3f(0.6f, 0.35f, 0.1f);
        glTranslatef(-2, -3, 0);
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.15f, 5.0f,32,4);
    glPopMatrix();

    // Tiang Kanan
    glPushMatrix();
        glColor3f(0.6f, 0.35f, 0.1f);
        glTranslatef(2, -3, 0);
        glRotatef(-90, 1, 0, 0);
        glutSolidCylinder(0.15f, 5.0f,32,4);
    glPopMatrix();

    // Palang Atas
    glPushMatrix();
        glColor3f(0.6f, 0.35f, 0.1f);
        glTranslatef(-2, 2, 0);
        glRotatef(90, 0, 1, 0);
        glutSolidCylinder(0.15f, 4.0f,32,4);
    glPopMatrix();

    // Bola Sendi Kiri
    glPushMatrix();
        glColor3f(0.6f, 0.35f, 0.1f);
        glTranslatef(-2.0f, 2.0f, 0.0f);
        glutSolidSphere(0.16f, 20, 20);
    glPopMatrix();

    // Bola Sendi Kanan
    glPushMatrix();
        glColor3f(0.6f, 0.35f, 0.1f);
        glTranslatef(2.0f, 2.0f, 0.0f);
        glutSolidSphere(0.16f, 20, 20);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 2, 0);
        glRotatef(rAyunan, 1, 0, 0);

        // Tali
    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.8f);
        glTranslatef(-0.8f, 0, 0);
        glRotatef(90, 1, 0, 0);
        glutSolidCylinder(0.03f, 3.5f,32, 4);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.8f);
        glTranslatef(0.8f, 0, 0);
        glRotatef(90, 1, 0, 0);
        glutSolidCylinder(0.03f, 3.5f,32, 4);
    glPopMatrix();

        // Dudukan
    glPushMatrix();
        glColor3f(0.6f, 0.35f, 0.1f);
        glTranslatef(0, -3.5f, 0);
        glScalef(2.0f, 0.2f, 0.8f);
        glutSolidCube(1.0f);
    glPopMatrix();
    glPopMatrix();
}

void peletakan_ayunan(){
    glPushMatrix();
        glTranslatef(-6.5,3,10);
        glScalef(0.8,0.8,0.8);
        ayunan();
    glPopMatrix();
}
// ==================   2406011 Assyifa Ramdani   ================== //

// DISPLAY
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(
        kameraX, kameraY, kameraZ,
        0, 0, 0,
        0, 1, 0
    );
    // PEMANGGILAN FUNGSI OBJEK
    peletakan1_kincir(); peletakan2_kincir(); peletakan3_kincir(); peletakan4_kincir(); peletakan5_kincir(); peletakan6_kincir(); kunang_kunang(); tempat_sampah(); batu(); semak(); full_jalan(); peletakan_lampu(); tanah(); peletakan_gapura(); peletakan_kolam(); peletakan_pohon(); peletakan_jungkat();peletakan_kursi(); peletakan_awan(); peletakan_mobil(); peletakan_ayunan();peletakan_ikan();

    glutSwapBuffers();
}

// INIT
void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
}

//RESHAPE JENDELA
void reshape(int w, int h) {
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)w / h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

// FUNGSI KEYBOARD
void keyboard(unsigned char key, int x, int y) {

    switch (key) {
        case '1':
            cuaca_siang();
            break;
        case '2':
            cuaca_sore();
            break;
        case '3':
            cuaca_malam();
            break;
        case 'p':
            rotPapan += arah * rotateSpeed;
            if (rotPapan > 25) arah = -1;
            if (rotPapan < -25) arah = 1;
            break;
        case 'n': 
            tIkan += mIkan;
            // Batas Kolam (Agar tidak offside dari skala kolam 9)
            if (tIkan > 4.0f) mIkan = -0.3f;  // Jika mentok depan, balik arah
            if (tIkan < -4.0f) mIkan = 0.3f; // Jika mentok belakang, balik arah
            break;
        case 'u': // Kangge Gerak ke atas
    		tIkanY += mIkanY;
    		if (tIkanY > 2.0f) tIkanY = 2.0f; // Batas atas 
    		break;
		case 'j': // Kangge Gerak ke bawah
    		tIkanY -= mIkanY;
    		if (tIkanY < 0.0f) tIkanY = 0.0f; // Batas dasar kolam
    		break;
        case 'o':
            sAwan += bAwan;
            if (sAwan > 1.5f || sAwan < 0.8f) bAwan = -bAwan; // balik arah
            break;
        case 'm':
            tMobil += mMobil;
            if (tMobil > 11.0f || tMobil < -11.0f) mMobil = -mMobil;
            break;
        case 'k':
            rAyunan += kAyunan;
            if (rAyunan > 30.0f) kAyunan = -1.5;  // maksimal
            if (rAyunan < -30.0f) kAyunan = 1.5;   // minimal
            break;
        case 'a':
            kamera_2();
            break;
        case 's':
            kamera_1();
            break;
        case 'w':
            kamera_4();
            break;
        case 'd':
            kamera_3();
            break;
        case '=': // Zoom In
            kameraX -= 0.0f;
            kameraY -= 1.0f;
            kameraZ -= 1.0f;
            break;
        case '-': // Zoom Out
            kameraX += 0.0f;
            kameraY += 1.0f;
            kameraZ += 1.0f;
            break;
    }

    glutPostRedisplay();
}

// MAIN
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Taman Bermain - Kelompok 1");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}


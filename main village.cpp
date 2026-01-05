#include <GL/freeglut.h>
#include <cmath>
#include <iostream>

float kameraX = -14.0f;
float kameraY = 8.0f;
float kameraZ = 15.0f;
float camSpeed = 0.8f;

bool lampuNyala = true;

void setSpotlight(GLenum lightSource, float x, float y, float z) {
	if (lampuNyala) {
        glEnable(lightSource);
        float pos[] = { x, y, z, 1.0f };
        float diffuse[] = { 1.0f, 1.0f, 0.7f, 1.0f };
        float dir[] = { 0.0f, -1.0f, 0.0f };

        glLightfv(lightSource, GL_POSITION, pos);
        glLightfv(lightSource, GL_DIFFUSE, diffuse);
        glLightfv(lightSource, GL_SPOT_DIRECTION, dir);

        // --- PENGATURAN AGAR MENYEBAR LUAS ---
        glLightf(lightSource, GL_SPOT_CUTOFF, 95.0f);    
        glLightf(lightSource, GL_SPOT_EXPONENT, 1.0f);   // Perkecil fokus agar cahaya rata (tidak tajam di tengah)
        
        // --- PENGATURAN JARAK CAHAYA (ATTENUATION) ---
        glLightf(lightSource, GL_CONSTANT_ATTENUATION, 1.0f);
        glLightf(lightSource, GL_LINEAR_ATTENUATION, 0.01f);    // Makin kecil, makin jauh jangkauannya
        glLightf(lightSource, GL_QUADRATIC_ATTENUATION, 0.005f); 
    } else {
        glDisable(lightSource);
    }
}
// ---------------------------------- FUNGSI MODULAR KOTAK (CUSTOM)
// Fungsi ini memungkinkan kita mengatur posisi, rotasi, skala, dan warna dalam satu baris
void drawBox(float x, float y, float z,           // Posisi
             float rotX, float rotY, float rotZ,  // Rotasi (derajat)
             float sX, float sY, float sZ,        // Skala
             float r, float g, float b)           // Warna (RGB)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(rotX, 1, 0, 0);
        glRotatef(rotY, 0, 1, 0);
        glRotatef(rotZ, 0, 0, 1);
        glScalef(sX, sY, sZ);

        glColor3f(r, g, b);
        glutSolidCube(1.0f); 
    glPopMatrix();
}

void batang(float x, float y, float z,           // Posisi
             float rotX, float rotY, float rotZ, // Rotasi
             float sX, float sY, float sZ,       // Skala
             float r, float g, float b)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(rotX, 1, 0, 0);
        glRotatef(rotY, 0, 1, 0);
        glRotatef(rotZ, 0, 0, 1);
        glScalef(sX, sY, sZ);
        glColor3f(r, g, b);

        glPushMatrix();
            glRotatef(-90, 1, 0, 0); 
            glutSolidCylinder(1.0, 1.0, 32, 32); 
        glPopMatrix();
    glPopMatrix();
}
void air(float x, float y, float z,         
             float sX, float sY, float sZ)
{          
    glPushMatrix();
        glTranslatef(x, y, z);
        glScalef(sX, sY, sZ);
        glColor3f(0.0f, 0.0f, 1.0f);
        glutSolidCube(1.0f); 
    glPopMatrix();
}

void kolam(float x, float y, float z,           // Posisi
             float rotX, float rotY, float rotZ,  // Rotasi (derajat)
             float sX, float sY, float sZ,        // Skala
             float r, float g, float b)           // Warna (RGB)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(rotX, 1, 0, 0);
        glRotatef(rotY, 0, 1, 0);
        glRotatef(rotZ, 0, 0, 1);
        glScalef(sX, sY, sZ);

        glColor3f(1.0f, 1.0f, 1.0f);
        glutSolidCube(1.0f); 
    glPopMatrix();
}
// ---------------------------------- OBJEK TAMAN LAINNYA
void tanah(float scaleX, float scaleY, float scaleZ){
    glPushMatrix();
        glColor3f(0.1f, 0.6f, 0.1f);
        glTranslatef(0, -0.1f, 0);
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(1);
    glPopMatrix();
}

void jalan(float scaleX, float scaleY, float scaleZ){
    glPushMatrix();
        glColor3f(0.85f, 0.45f, 0.15f); 
        glTranslatef(0, 0.01f, 0);
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(3);
    glPopMatrix();
}

void trotoar(float x, float y, float z,         
             float sX, float sY, float sZ)
{          
    glPushMatrix();
        glTranslatef(x, y, z);
        glScalef(sX, sY, sZ);
        glColor3f(0.2f, 0.1f, 0.0f);
        glutSolidCube(1.0f); 
    glPopMatrix();
}

void daunpohon(float x, float y, float z, 
              float radius, float tinggi, 
              float r, float g, float b) 
{
    glPushMatrix();
        glTranslatef(x, y, z);
        glColor3f(r, g, b);
        glRotatef(-90, 1, 0, 0);
        glutSolidCone(radius, tinggi, 32, 32);
    glPopMatrix();
}

void Semak2(float x, float y, float z, float sX, float sY, float sZ)           // Warna (RGB)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        glScalef(sX, sY, sZ);

        glColor3f(0.13f, 0.37f, 0.13f);
        glutSolidSphere(0.8, 20, 20); 
    glPopMatrix();
}

void Semak1(float x, float y, float z, float sX, float sY, float sZ)           // Warna (RGB)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        glScalef(sX, sY, sZ);

        glColor3f(0.24f, 0.53f, 0.24f);
        glutSolidSphere(0.8, 20, 20); 
    glPopMatrix();
}


// ---lampu----KEY---
void full_lampu(float posX, float posY, float posZ, float scale){
    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glScalef(scale, scale, scale);
        
        // --- GAMBAR TIANG & KAKI (Terkena Lighting) ---
        glColor3f(0.05f, 0.05f, 0.05f); // Hitam gelap
        glPushMatrix(); 
            glScalef(3, 0.4, 3); 
            glutSolidCube(2); 
        glPopMatrix();
        
        glPushMatrix(); 
            glTranslatef(0, 1, 0); 
            glRotatef(-90, 1, 0, 0); 
            glutSolidCylinder(0.8, 30.0, 20, 20); 
        glPopMatrix();

        // --- GAMBAR BOLA LAMPU (Logika Menyala) ---
        glPushMatrix();
            glTranslatef(0, 30, 0); // Posisi di ujung tiang
            if (lampuNyala) {
                glDisable(GL_LIGHTING); // MATIKAN lighting agar warna kuningnya konstan (pijar)
                glColor3f(1.0f, 1.0f, 0.5f); // Kuning terang
                glutSolidSphere(3.7, 20, 20);
                glEnable(GL_LIGHTING); // HIDUPKAN kembali untuk objek lain
            } else {
                glColor3f(0.2f, 0.2f, 0.1f); // Kuning gelap/mati
                glutSolidSphere(3.7, 20, 20);
            }
        glPopMatrix();
    glPopMatrix();
}
//-----------------------------------------//

// ---------------------------------- DISPLAY
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(kameraX, kameraY, kameraZ, 0, 0, 0, 0, 1, 0);

    // Pastikan posisi Y (3.0f) sesuai dengan ketinggian bola lampu di koordinat dunia
    setSpotlight(GL_LIGHT1, -4.0f, 3.0f, 10.0f);
    setSpotlight(GL_LIGHT2,  4.0f, 3.0f, 0.0f);
    setSpotlight(GL_LIGHT3, -4.0f, 3.0f, -10.0f);
    
    tanah(25, 0.2, 25);
    jalan(2.0, 0.05, 8.35);
    
    //buat pohon cuy
    	//pohon 1
    		batang(11.0f, 0.0f, 11.3f, 0, 0, 0, 0.5f, 4.0f, 0.5f, 0.45f, 0.24f, 0.10f);
    		daunpohon(11.0f, 2.0f, 11.3f,  1.8, 2.0,  0.0, 0.3, 0.0);
    		daunpohon(11.0f, 3.0f, 11.3f,  1.5, 2.0,  0.0, 0.3, 0.0);
   			daunpohon(11.0f, 4.0f, 11.3f,  1.2, 1.8,  0.0, 0.4, 0.0);
    		daunpohon(11.0f, 5.0f, 11.3f,  0.8, 1.5,  0.0, 0.5, 0.0);
    	//pohon 2
    		batang(11.0f, 0.0f, -11.3f, 0, 0, 0, 0.5f, 4.0f, 0.5f, 0.45f, 0.24f, 0.10f);
    		daunpohon(11.0f, 2.0f, -11.3f,  1.8, 2.0,  0.0, 0.3, 0.0);
			daunpohon(11.0f, 3.0f, -11.3f,  1.5, 2.0,  0.0, 0.3, 0.0);
   			daunpohon(11.0f, 4.0f, -11.3f,  1.2, 1.8,  0.0, 0.4, 0.0);
    		daunpohon(11.0f, 5.0f, -11.3f,  0.8, 1.5,  0.0, 0.5, 0.0);
    	//pohon 3
    		batang(-11.0f, 0.0f, 11.3f, 0, 0, 0, 0.5f, 4.0f, 0.5f, 0.45f, 0.24f, 0.10f);
    		daunpohon(-11.0f, 2.0f, 11.3f,  1.8, 2.0,  0.0, 0.3, 0.0);
			daunpohon(-11.0f, 3.0f, 11.3f,  1.5, 2.0,  0.0, 0.3, 0.0);
   			daunpohon(-11.0f, 4.0f, 11.3f,  1.2, 1.8,  0.0, 0.4, 0.0);
    		daunpohon(-11.0f, 5.0f, 11.3f,  0.8, 1.5,  0.0, 0.5, 0.0);
    	//pohon 4
    		batang(-11.0f, 0.0f, -11.3f, 0, 0, 0, 0.5f, 4.0f, 0.5f, 0.45f, 0.24f, 0.10f);
    		daunpohon(-11.0f, 2.0f, -11.3f,  1.8, 2.0,  0.0, 0.3, 0.0);
			daunpohon(-11.0f, 3.0f, -11.3f,  1.5, 2.0,  0.0, 0.3, 0.0);
   			daunpohon(-11.0f, 4.0f, -11.3f,  1.2, 1.8,  0.0, 0.4, 0.0);
    		daunpohon(-11.0f, 5.0f, -11.3f,  0.8, 1.5,  0.0, 0.5, 0.0);
	//untuk gapura
		//depan
		batang(3.0f, 0.0f, 12.3f, 0, 0, 0, 0.3f, 4.0f, 0.3f, 1.0f, 0.0f, 0.0f);
		batang(-3.0f, 0.0f, 12.3f, 0, 0, 0, 0.3f, 4.0f, 0.3f, 1.0f, 0.0f, 0.0f);
		batang(4.0f, 4.0f, 12.3f, 0, 0, 90, 0.3f, 8.0f, 0.3f, 1.0f, 0.0f, 0.0f);
		
		//belakang
		batang(3.0f, 0.0f, -12.3f, 0, 0, 0, 0.3f, 4.0f, 0.3f, 1.0f, 0.0f, 0.0f);
		batang(-3.0f, 0.0f, -12.3f, 0, 0, 0, 0.3f, 4.0f, 0.3f, 1.0f, 0.0f, 0.0f);
		batang(4.0f, 4.0f, -12.3f, 0, 0, 90, 0.3f, 8.0f, 0.3f, 1.0f, 0.0f, 0.0f);

	
	//bangku 1
    drawBox(7.0f, 1.0f, 8.0f, 0, 0, 0, 3.0f, 0.2f, 2.0f, 0.5f, 0.35f, 0.05f); // yang kuning
    drawBox(7.0f, 0.5f, 8.0f, 0, 0, 0, 0.3f, 1.0f, 0.3f, 0.2f, 0.2f, 0.2f); //yang tengah tu
    drawBox(7.0f, 0.3f, 6.0f, 90, 0, 0, 2.0f, 0.5f, 0.8f, 0.6f, 0.6f, 0.6f); 
    drawBox(7.0f, 0.3f, 10.0f, 90, 0, 0, 2.0f, 0.5f, 0.8f, 0.6f, 0.6f, 0.6f); 
     
    //bangku2
    drawBox(-7.0f, 1.0f, 8.0f, 0, 0, 0, 3.0f, 0.2f, 2.0f, 0.5f, 0.35f, 0.05f); // yang kuning
    drawBox(-7.0f, 0.5f, 8.0f, 0, 0, 0, 0.3f, 1.0f, 0.3f, 0.2f, 0.2f, 0.2f);// yang tengah tu
    drawBox(-7.0f, 0.3f, 6.0f, 90, 0, 0, 2.0f, 0.5f, 0.8f, 0.6f, 0.6f, 0.6f); 
    drawBox(-7.0f, 0.3f, 10.0f, 90, 0, 0, 2.0f, 0.5f, 0.8f, 0.6f, 0.6f, 0.6f); 
	
	//bangku 3
    drawBox(7.0f, 1.0f, -8.0f, 0, 0, 0, 3.0f, 0.2f, 2.0f, 0.5f, 0.35f, 0.05f); // yang kuning
    drawBox(7.0f, 0.5f, -8.0f, 0, 0, 0, 0.3f, 1.0f, 0.3f, 0.2f, 0.2f, 0.2f); //yang tengah tu
    drawBox(7.0f, 0.3f, -6.0f, 90, 0, 0, 2.0f, 0.5f, 0.8f, 0.6f, 0.6f, 0.6f); 
    drawBox(7.0f, 0.3f, -10.0f, 90, 0, 0, 2.0f, 0.5f, 0.8f, 0.6f, 0.6f, 0.6f); 
     
    //bangku 4
    drawBox(-7.0f, 1.0f, -8.0f, 0, 0, 0, 3.0f, 0.2f, 2.0f, 0.5f, 0.35f, 0.05f); // yang kuning
    drawBox(-7.0f, 0.5f, -8.0f, 0, 0, 0, 0.3f, 1.0f, 0.3f, 0.2f, 0.2f, 0.2f);// yang tengah tu
    drawBox(-7.0f, 0.3f, -6.0f, 90, 0, 0, 2.0f, 0.5f, 0.8f, 0.6f, 0.6f, 0.6f); 
    drawBox(-7.0f, 0.3f, -10.0f, 90, 0, 0, 2.0f, 0.5f, 0.8f, 0.6f, 0.6f, 0.6f); 
    
    //kolam
    kolam(-9.0f, 0.0f, 0.0f, 0, 0, 0, 4.0f, 0.2f, 8.0f, 0.5f, 0.35f, 0.05f);
    kolam(-11.0f, 0.3f, 0.0f, 0, 0, 90, 0.5f, 0.2f, 8.0f, 0.5f, 0.35f, 0.05f); //kiri
    kolam(-7.0f, 0.3f, 0.0f, 0, 0, 90, 0.5f, 0.2f, 8.0f, 0.5f, 0.35f, 0.05f); //kanan
	kolam(-9.0f, 0.3f, -4.0f, 0, -90, 0, 0.5f, 0.5f, 4.0f, 0.5f, 0.35f, 0.05f); //belakang
    kolam(-9.0f, 0.3f, 4.0f, 0, -90, 0, 0.5f, 0.5f, 4.0f, 0.5f, 0.35f, 0.05f); //depan
    
    //air
    air(-9.0f, 0.2f, 0.0f, 4.0f, 0.2f, 8.0f);
    
    //trotoar
    trotoar(3.0f, 0.2f, 0.0f, 0.6f, 0.2f, 25.0f);
    trotoar(-3.0f, 0.2f, 0.0f, 0.6f, 0.2f, 25.0f);
    
    //lampu 
    full_lampu(-4, 0.0,  10, 0.1);
    full_lampu( 4, 0.0,  0, 0.1);
    full_lampu( -4, 0.0, -10, 0.1);
	
	//semak depan alamak
		//semak kanan
	Semak2(5.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(4.0f, 0.0f, 11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(7.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(6.0f, 0.0f, 11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(9.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(8.0f, 0.0f, 11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(11.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(10.0f, 0.0f, 11.7f, 0.9f, 0.9f, 0.9f);
	
		//kangge semak kiri
	Semak2(-5.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(-4.0f, 0.0f, 11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-7.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(-6.0f, 0.0f, 11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-9.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(-8.0f, 0.0f, 11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-11.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(-10.0f, 0.0f, 11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	Semak2(-12.0f, 0.0f, 11.7f, 1.0f, 1.0f, 1.0f);
	
	//semak belakang
		//semak kanan
	Semak2(5.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(4.0f, 0.0f, -11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(7.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(6.0f, 0.0f, -11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(9.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(8.0f, 0.0f, -11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(11.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(10.0f, 0.0f, -11.7f, 0.9f, 0.9f, 0.9f);
	
		//kangge semak kiri
	Semak2(-5.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(-4.0f, 0.0f, -11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-7.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(-6.0f, 0.0f, -11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-9.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(-8.0f, 0.0f, -11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-11.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	Semak1(-10.0f, 0.0f, -11.7f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	Semak2(-12.0f, 0.0f, -11.7f, 1.0f, 1.0f, 1.0f);
	
	//semak kanan
	Semak2(12.0f, 0.0f, 9.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, 10.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, 7.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, 8.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, 5.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, 6.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, 3.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, 4.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, 1.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, 2.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, -0.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, 0.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, -2.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, -1.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, -4.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, -3.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, -6.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, -5.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, -8.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, -7.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(12.0f, 0.0f, -10.5f, 1.0f, 1.0f, 1.0f);
	Semak1(12.0f, 0.0f, -9.5f, 0.9f, 0.9f, 0.9f);
	
	//semak kiri
	Semak2(-12.0f, 0.0f, 9.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, 10.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, 7.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, 8.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, 5.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, 6.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, 3.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, 4.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, 1.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, 2.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, -0.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, 0.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, -2.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, -1.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, -4.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, -3.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, -6.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, -5.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, -8.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, -7.5f, 0.9f, 0.9f, 0.9f);
	
	Semak2(-12.0f, 0.0f, -10.5f, 1.0f, 1.0f, 1.0f);
	Semak1(-12.0f, 0.0f, -9.5f, 0.9f, 0.9f, 0.9f);
    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);   
    glEnable(GL_NORMALIZE);  
    glShadeModel(GL_SMOOTH); 

    // Warna Langit Malam
    glClearColor(0.01f, 0.01f, 0.05f, 1.0f); 

    // Cahaya redup agar objek tidak hitam pekat saat lampu mati
    float ambientModel[] = { 0.1f, 0.1f, 0.15f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientModel);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}
//}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)w / h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'w': kameraZ -= camSpeed; break;
        case 's': kameraZ += camSpeed; break;
        case 'a': kameraX -= camSpeed; break;
        case 'd': kameraX += camSpeed; break;
        case 'q': kameraY += camSpeed; break;
        case 'e': kameraY -= camSpeed; break;
        case 'l':
        case 'L': 
            lampuNyala = !lampuNyala; // Membalikkan status (Toggle)
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Taman dengan drawBox Custom");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
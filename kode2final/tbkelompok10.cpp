#include <GL/glut.h>
#include <cmath> // Untuk sin dan cos dalam menggambar lingkaran/silinder atau fungsi matematika

// =========================== Variabel Global untuk Kamera dan Animasi (Opsional) ============ 
// ========================================= RISE KARTIKA UTAMI ===============================
float cameraAngleX = 20.0f;
float cameraAngleY = -45.0f;
float cameraDistance = 15.0f;

// ========================================= Status Lampu Jalan ============================================= 
// ========================================= RISE KARTIKA UTAMI =============================================
bool lampuNyala = true;
float tekoX = 0.0f;
float tekoY = 0.7f;
float tekoZ = 2.0f;
float tekoSize = 0.2f;
float tekoRot = 0.0f;

// ================================== Fungsi Pembantu: Menggambar Kubus ============================
void drawCube(float width, float height, float depth) {
    glPushMatrix();
    glScalef(width, height, depth);
    glutSolidCube(1.0f);
    glPopMatrix();
}

// ================================ Fungsi Pembantu: Menggambar Silinder =============================
void drawCylinder(float radius, float height, int slices, int stacks) {
    glPushMatrix();
    GLUquadric* quadric = gluNewQuadric();
    gluCylinder(quadric, radius, radius, height, slices, stacks);
    gluDisk(quadric, 0.0, radius, slices, stacks); // Tutup bawah
    glTranslatef(0.0f, 0.0f, height);
    gluDisk(quadric, 0.0, radius, slices, stacks); // Tutup atas
    gluDeleteQuadric(quadric);
    glPopMatrix();
}

// ================================== Fungsi Menggambar Pohon ===========================
// ================================ Cecep Faiasl Ahmad 2406033 ==========================
void drawPohon() {
    glPushMatrix();
    
    // --- Batang Pohon ---
    glColor3f(0.4f, 0.26f, 0.13f); // Warna coklat kayu
    glPushMatrix();
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Putar agar berdiri tegak
        drawCylinder(0.2f, 1.5f, 16, 1);     
    glPopMatrix();

    // --- Daun Pohon (Menggunakan 2 tumpukan Kerucut/Cone) ---
    glColor3f(0.0f, 0.4f, 0.0f); // Warna hijau daun
    
    // Daun bagian bawah (lebih lebar)
    glPushMatrix();
        glTranslatef(0.0f, 1.0f, 0.0f);      
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 
        glutSolidCone(1.0, 1.5, 20, 20);     
    glPopMatrix();
    
    // Daun bagian atas (lebih kecil/runcing)
    glPushMatrix();
        glTranslatef(0.0f, 1.8f, 0.0f);      
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        glutSolidCone(0.7, 1.2, 20, 20);
    glPopMatrix();

    glPopMatrix();
}

// ========================= Fungsi Menggambar Gerobak Angkringan ====================== 
// ========================= HAIKAL MUHAMAD SABQI - 2406020 ============================
void drawGerobak() {
    glPushMatrix();
    glTranslatef(0.0f, 0.75f, 0.0f); // Posisi gerobak agak naik dari lantai

    // Badan Gerobak
    glColor3f(0.45f, 0.0f, 0.0f); // merah tua
    drawCube(2.0f, 1.0f, 1.0f);

    // Tiang Penopang Atap
    glColor3f(0.7f, 0.7f, 0.7f); // warna chrome
    glPushMatrix();
    glTranslatef(0.9f, 0.9f, 0.4f);
    drawCube(0.05f, 1.7f, 0.05f);
    glTranslatef(-1.8f, 0.0f, 0.0f);
    drawCube(0.05f, 1.7f, 0.05f);
    glTranslatef(0.0f, 0.0f, -0.8f);
    drawCube(0.05f, 1.7f, 0.05f);
    glTranslatef(1.8f, 0.0f, 0.0f);
    drawCube(0.05f, 1.7f, 0.05f);
    glPopMatrix();

    // Atap Gerobak (Biru)
    glColor3f(0.0f, 0.0f, 0.0f); // Hitam
    glPushMatrix();
    glTranslatef(0.0f, 1.8f, 0.0f);
    drawCube(2.2f, 0.1f, 1.2f); // Atap datar
    glPopMatrix();

    // Roda (Hitam)
    glColor3f(0.1f, 0.1f, 0.1f);
    glPushMatrix();
    glTranslatef(-0.8f, -0.45f, 0.45f); // Roda kanan
    glRotatef(360.0f, 0.0f, 1.0f, 0.0f); // Putar agar silinder horizontal
    drawCylinder(0.3f, 0.1f, 16, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8f, -0.45f, -0.55f); // Roda kiri
    glRotatef(360.0f, 0.0f, 1.0f, 0.0f);
    drawCylinder(0.3f, 0.1f, 16, 1);
    glPopMatrix();

    // Gagang Gerobak 
    glColor3f(0.7f, 0.7f, 0.7f); // warna chrome
    glPushMatrix();
    glTranslatef(1.1f, 0.4f, -0.4f); // gagang kanan
    drawCube(0.5f, 0.05f, 0.05f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.1f, 0.4f, 0.4f); // gagang kiri
    drawCube(0.5f, 0.05f, 0.05f);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f);  // warna chrome
    glTranslatef(0.95f, -0.6f, 0.0f); //penyangga depan
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    drawCube(0.2f, 0.05f, 0.05f);
    glPopMatrix();

    glPopMatrix();
}

// ================================= Rak Kayu Sederhana =============================================
// ================================ Haikal Muhamad Sabqi ===============================================
void drawRakKayu() {
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f); // warna chrome (Silver)

    // Tiang kiri
    glPushMatrix();
    glTranslatef(-0.3f, 0.5f, 0.0f);
    drawCube(0.05f, 1.0f, 0.05f);
    glPopMatrix();

    // Tiang kanan
    glPushMatrix();
    glTranslatef(0.3f, 0.5f, 0.0f);
    drawCube(0.05f, 1.0f, 0.05f);
    glPopMatrix();

    // Rak bawah
    glPushMatrix();
    glTranslatef(0.0f, 0.2f, 0.0f);
    drawCube(0.7f, 0.05f, 0.3f);
    glPopMatrix();

    // Rak atas
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    drawCube(0.7f, 0.05f, 0.3f);
    glPopMatrix();

    glPopMatrix();
}

// ================================== Spanduk Angkringan ===========================
// =========================== HAIKAL MUHAMAD SABQI - 2406020 =======================
void drawSpanduk1() {
    glPushMatrix();
    glColor3f(0.06f, 0.06f, 0.06f); // abu-abu (KARBON)
    drawCube(1.8f, 0.3f, 0.05f);
    glPopMatrix();
}

void drawSpanduk2() {
    glPushMatrix();
    glColor3f(0.06f, 0.06f, 0.06f); // abu-abu (KARBON)
    drawCube(0.8f, 0.3f, 0.05f);
    glPopMatrix();
}

// ========================= Fungsi Menggambar Kursi ========================
// ===================== CECEP FAISAL AHMAD - 2406033 ===================
void drawKursi() {
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glColor3f(0.6f, 0.4f, 0.2f); // Warna kayu

    // Dudukan
    drawCube(0.5f, 0.05f, 0.5f);

    // Kaki-kaki
    glPushMatrix();
    glTranslatef(0.2f, -0.25f, 0.2f);
    drawCube(0.05f, 0.5f, 0.05f);
    glTranslatef(-0.4f, 0.0f, 0.0f);
    drawCube(0.05f, 0.5f, 0.05f);
    glTranslatef(0.0f, 0.0f, -0.4f);
    drawCube(0.05f, 0.5f, 0.05f);
    glTranslatef(0.4f, 0.0f, 0.0f);
    drawCube(0.05f, 0.5f, 0.05f);
    glPopMatrix();

    // Sandaran
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, -0.2f);
    drawCube(0.5f, 0.5f, 0.05f);
    glPopMatrix();

    glPopMatrix();
}

// ================================= Fungsi Menggambar Meja ================================
void drawMeja() {
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glColor3f(0.6f, 0.4f, 0.2f); // Warna kayu

    // Permukaan Meja
    drawCube(1.0f, 0.05f, 1.0f);

    // Kaki-kaki Meja
    glPushMatrix();
    glTranslatef(0.4f, -0.3f, 0.4f);
    drawCube(0.05f, 0.6f, 0.05f);
    glTranslatef(-0.8f, 0.0f, 0.0f);
    drawCube(0.05f, 0.6f, 0.05f);
    glTranslatef(0.0f, 0.0f, -0.8f);
    drawCube(0.05f, 0.6f, 0.05f);
    glTranslatef(0.8f, 0.0f, 0.0f);
    drawCube(0.05f, 0.6f, 0.05f);
    glPopMatrix();

    glPopMatrix();
}

// ========================= Fungsi Menggambar Lampu Jalan ===========================
// ========================= RISE KARTIKA UTAMI - 2406--- ============================
void drawLampuJalan() {
    glPushMatrix();
    
    glColor3f(0.0f, 0.0f, 0.0f); // warna hitam
    glPushMatrix();
    glTranslatef(-1.0f, -3.0f, 3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawCube(1.0f, 0.1f, 1.0f); 
    glPopMatrix();

    // Tiang Lampu
    glColor3f(0.2f, 0.2f, 0.2f);
    glPushMatrix();
    glTranslatef(-1.0f, -0.04f, 3.0f); 
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f); 
    drawCylinder(0.1f, 3.0f, 16, 1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.60f, 0.0f, 3.0f); 
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f); 
    drawCylinder(0.1f, 0.7f, 16, 1);
    glPopMatrix();
    
    // Bagian Atas Lampu (Rumah Lampu)
    glPushMatrix();
    glTranslatef(-1.55f, -0.3f, 3.0f);
    glRotatef(50.0f, 0.0f, 1.0f, 0.0f);
    
    if (lampuNyala) {
        glColor3f(1.0f, 1.0f, 0.8f); // Kuning terang
        glutSolidSphere(0.2f, 20, 20);
    } else {
        glColor3f(0.2f, 0.2f, 0.2f); // Abu gelap
        glutSolidSphere(0.2f, 20, 20);
    }
    glPopMatrix();

    glPopMatrix();
}

// ===================== Inisialisasi Pencahayaan ===========================
// ======================= RISE KARTIKA UTAMI ================================
void initLighting() {
    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0);   

    GLfloat global_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    GLfloat light_diffuse[] = { 1.0f, 1.0f, 0.8f, 1.0f }; 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    GLfloat material_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat material_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat material_specular[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    GLfloat material_shininess = 30.0f; 

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);

    glEnable(GL_COLOR_MATERIAL); 
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); 
}

// =========================== Fungsi Utama untuk Menggambar Scene =============================================
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // --- Mengatur Kamera ---
    glTranslatef(0.0f, 0.0f, -cameraDistance);
    glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

    glEnable(GL_DEPTH_TEST); 

    // --- Mengatur Lampu ---
    GLfloat light_position[] = { 3.0f, 3.5f, -2.0f, 1.0f }; 
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    if (lampuNyala) glEnable(GL_LIGHT0);
    else glDisable(GL_LIGHT0);

    // ========================== Lantai & Jalan ===============================
	// ================= HAIKAL MUHAMAD SABQI - 2406020 ==========================
    glColor3f(0.0f, 0.5f, 0.0f); // Rumput - hijau - lantai
    glPushMatrix();
    glTranslatef(0.0f, -0.05f, 0.0f);
    drawCube(10.0f, 0.1f, 10.0f);
    glPopMatrix();
    
    glColor3f(0.0f, 0.0f, 0.0f); // Jalan Raya - hitam
    glPushMatrix();
    glTranslatef(0.0f, 0.01f, -2.6f);
    drawCube(10.0f, 0.1f, 2.0f);
    glPopMatrix();
    
    glColor3f(1.0f, 1.0f, 1.0f); // garis putih (trotoar jalan)
    glPushMatrix();
    glTranslatef(0.0f, 0.01f, -3.6f);
    drawCube(10.0f, 0.2f, 0.1f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 0.01f, -1.6f);
    drawCube(10.0f, 0.2f, 0.1f);
    glPopMatrix();

    // ============================== Menyusun Objek ==============================================
    
    // Lampu Jalan ================ RISE KARTIKA UTAMI ============================================
    glPushMatrix();
    glTranslatef(light_position[0], light_position[1] - 0.5f, light_position[2]); 
    drawLampuJalan();
    glPopMatrix();

    // Gerobak =================== HAIKAL MUHAMAD SABQI =============================================
    glPushMatrix();
    drawGerobak();
    glPopMatrix();
    
	// Rak Kayu
    glPushMatrix();
    glTranslatef(0.8f, 0.0f, -1.2f);
    drawRakKayu();
    glPopMatrix();
    
    // Spanduk Depan
    glPushMatrix();
    glTranslatef(0.0f, 2.4f, 0.4f);
    drawSpanduk1();
    glPopMatrix();
    
    // Spanduk Kanan
    glPushMatrix();
    glTranslatef(0.9f, 2.4f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawSpanduk2();
    glPopMatrix();
    
    // Spanduk Kiri
    glPushMatrix();
    glTranslatef(-0.9f, 2.4f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawSpanduk2();
    glPopMatrix();

    // Meja & Teapot ===== CECEP FAISAL AHMAD - 2406033 ====================================
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 2.0f); 
    drawMeja();
    glPopMatrix();
    
    glPushMatrix(); //teko
    glTranslatef(tekoX, tekoY, tekoZ);     // Menggunakan variabel kontrol
    glScalef(tekoSize, tekoSize, tekoSize); // Menggunakan variabel kontrol
    glRotatef(tekoRot, 0.0f, 1.0f, 0.0f);   // Rotasi pada sumbu Y (berputar di tempat)
    glColor3f(0.9f, 0.9f, 0.9f);  
    glutSolidTeapot(1.0);
    glPopMatrix();

    // Kursi-kursi
    glPushMatrix(); //1
    glTranslatef(-1.0f, 0.0f, 2.0f); 
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawKursi();
    glPopMatrix();

    glPushMatrix(); //2
    glTranslatef(1.0f, 0.0f, 2.0f); 
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    drawKursi();
    glPopMatrix();
    
    glPushMatrix(); //3
    glTranslatef(0.0f, 0.0f, 3.0f); 
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    drawKursi();
    glPopMatrix();

    // ===== MEMANGGIL POHON (BARU) ===== Cecep Faisal Ahmad 2406033 ==============================
    glPushMatrix();
        glTranslatef(-4.0f, 0.0f, -4.0f); // Pohon kiri belakang
        drawPohon(); 
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.0f, 0.0f, -4.0f);  // Pohon kanan belakang
        drawPohon(); 
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-4.0f, 0.0f, -1.0f);  // Pohon samping kiri
        glScalef(0.8f, 0.8f, 0.8f);       
        drawPohon();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(4.0f, 0.0f, -1.0f);  // Pohon samping kiri depan
        glScalef(0.8f, 0.8f, 0.8f);       
        drawPohon();
    glPopMatrix();

    glutSwapBuffers();
}

// --- Fungsi Reshape ---
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// ======= Mouse Interaction ============================= RISE KARTIKA UTAMI ====================================
// ===============================================================================================================
int lastMouseX, lastMouseY;
int mouseButton;

void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        lastMouseX = x;
        lastMouseY = y;
        mouseButton = button;
    }
}

void motion(int x, int y) {
    if (mouseButton == GLUT_LEFT_BUTTON) { 
        cameraAngleY += (x - lastMouseX) * 0.5f;
        cameraAngleX += (y - lastMouseY) * 0.5f;
    } else if (mouseButton == GLUT_RIGHT_BUTTON) { 
        cameraDistance -= (y - lastMouseY) * 0.1f;
        if (cameraDistance < 1.0f) cameraDistance = 1.0f;
    }
    lastMouseX = x;
    lastMouseY = y;
    glutPostRedisplay(); 
}

// ==== Keyboard Interaction --- Cecep Faisal Ahmad 2406033 =================================================
// ==========================================================================================================
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'l': case 'L': lampuNyala = !lampuNyala; break;
        case 'r': case 'R': cameraAngleX = 20.0f; cameraAngleY = -45.0f; cameraDistance = 15.0f; break;
        
        case 'w': case 'W': tekoZ -= 0.1f; break;
        case 's': case 'S': tekoZ += 0.1f; break;
        case 'a': case 'A': tekoX -= 0.1f; break;
        case 'd': case 'D': tekoX += 0.1f; break;
        case 'q': case 'Q': tekoY += 0.1f; break;
        case 'e': case 'E': tekoY -= 0.1f; break;
        
        // Kontrol Ukuran Teko (+ / -)
        case '+': case '=': tekoSize += 0.02f; break;
        case '-': case '_': tekoSize -= 0.02f; break;
        
        // Kontrol Rotasi Teko (F)
        case 'f': case 'F': tekoRot += 5.0f; break;
    }
    glutPostRedisplay();
}

// ============================ RISE KARTIKA UTAMI ===========================================================
// ===========================================================================================================
void initGL() {
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f); 
    glShadeModel(GL_SMOOTH); 
    glEnable(GL_NORMALIZE);  
    initLighting();          
}

// ========================== RISE KARTIKA UTAMI ===========================================================
// =========================================================================================================
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("TB kelompok 10 - Angkringan Racing --");
    initGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

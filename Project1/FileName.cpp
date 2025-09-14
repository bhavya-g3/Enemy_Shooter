#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

//void display1() {
//
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
//
//    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
//
//
//    glBegin(GL_LINES);
//    glVertex2f(100, 100);
//    glVertex2f(150, 150);
//
//    glVertex2f(100, 100);
//    glVertex2f(200, 100);
//
//    glVertex2f(200, 100);
//    glVertex2f(150, 150);
//
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glVertex2f(100, 10);
//    glVertex2f(200, 10);
//
//    glVertex2f(200, 100);
//    glVertex2f(200, 10);
//
//    glVertex2f(100, 100);
//    glVertex2f(100, 10);
//
//    glVertex2f(400, 100);
//    glVertex2f(400, 10);
//
//    glVertex2f(400, 100);
//    glVertex2f(200, 100);
//
//    glVertex2f(400, 10);
//    glVertex2f(200, 10);
//
//    glVertex2f(350, 150);
//    glVertex2f(400, 100);
//
//    glVertex2f(350, 150);
//    glVertex2f(150, 150);
//
//    glVertex2f(125, 10);
//    glVertex2f(125, 50);
//
//    glVertex2f(175, 10);
//    glVertex2f(175, 50);
//
//    glVertex2f(125, 50);
//    glVertex2f(175, 50);
//
//    glVertex2f(250, 25);
//    glVertex2f(350, 25);
//
//    glVertex2f(250, 25);
//    glVertex2f(250, 75);
//
//    glVertex2f(250, 75);
//    glVertex2f(350, 75);
//
//    glVertex2f(350, 25);
//    glVertex2f(350, 75);
//
//
//    glEnd();
//    glFlush();
//
//
//}
//
//void line(float x1, float y1, float x2, float y2) {
//    glBegin(GL_POINTS);
//
//    float y, m, c;
//    float dx = x2 - x1;
//    float dy = y2 - y1;
//
//    if (abs(dx) < 1e-6) {  // Handle vertical lines safely
//        float s = (y2 > y1) ? 1 : -1;
//        for (float y = y1; y != y2; y += s) {
//            glVertex2f(x1, y);  // X remains constant
//        }
//    }
//
//    m = dy / dx;
//    c = y1 - m * x1;
//    float s = (x2 > x1) ? 1 : -1;
//    for (float x = x1; x != x2; x += s){
//        y = m * x + c;
//        glVertex2f(x, y);
//    }
//
//    glEnd();
//    glFlush();
//}
//
//void ddaline(float x1, float y1, float x2, float y2) {
//    glBegin(GL_POINTS);
//
//    float y, m, c;
//    float dx = x2 - x1;
//    float dy = y2 - y1;
//
//    m = dy / dx;
//    
//    if(abs(m) <= 1) {  // Case when slope is gentle (|m| ≤ 1)
//        float y = y1;
//        float s = (x2 > x1) ? 1 : -1;
//        for(float x = x1; x != x2; x+=s) {
//            glVertex2f(x,y);
//            y = y + m*s;  // Update y based on the slope
//        }
//    } 
//    else {  // Case when slope is steep (|m| > 1)
//        float x = x1;
//        float s = (y2 > y1) ? 1 : -1;
//        for(float y = y1; y != y2; y+=s) {
//            glVertex2f(x,y);
//            x = x + (1.0 / m)*s;  // Update x based on the inverse slope
//        }
//    }
//
//    glEnd();
//    glFlush();
//}
//
//
//
//void drawHouse(float x1, float y1, float x2, float y2, float x3, float y3,
//    float x4, float y4, float x5, float y5, float x6, float y6) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0, 1, 0);
//    glBegin(GL_LINES);
//    float k = (x6 - x1)/3;
//    float l = (y2 - y1)/2;
//    float m = (x6 - x1 - k) / 4;
// 
//    /*glVertex2f(x1,y1);
//    glVertex2f(x1 + k, y1);*/
//
//    //// Base rectangle
//    //line(x1, y1, x1 + k, y1);
//    //line(x1 + k, y2, x1 + k, y1);
//    //line(x2, y2, x1, y1);
//    //line(x5, y5, x6, y6);
//    //line(x5, y5, x2, y2);
//    //line(x6, y6, x1 + k, y1);
//
//    //// Roof
//    //line(x4, y4, x5, y5);
//    //line(x4, y4, x3, y3);
//    //line(x3, y3, x2, y2);
//
//    //// Door
//    //line(x1 + k / 4, y1, x1 + k / 4, y1 + l);
//    //line(x1 + 3 * k / 4, y1, x1 + 3 * k / 4, y1 + l);
//    //line(x1 + k / 4, y1 + l, x1 + 3 * k / 4, y1 + l);
//
//    //// Window
//    //line(x1 + k + m, y1 + l / 2, x1 + k + 3 * m, y1 + l / 2);
//    //line(x1 + k + m, y1 + l / 2, x1 + k + m, y1 + 3 * l / 2);
//    //line(x1 + k + m, y1 + 3 * l / 2, x1 + k + 3 * m, y1 + 3 * l / 2);
//    //line(x1 + k + 3 * m, y1 + l / 2, x1 + k + 3 * m, y1 + 3 * l / 2);
//
//    // Base rectangle
//    ddaline(x1, y1, x1 + k, y1);
//    ddaline(x1 + k, y2, x1 + k, y1);
//    ddaline(x2, y2, x1, y1);
//    ddaline(x5, y5, x6, y6);
//    ddaline(x5, y5, x2, y2);
//    ddaline(x6, y6, x1 + k, y1);
//
//    // Roof
//    ddaline(x4, y4, x5, y5);
//    ddaline(x4, y4, x3, y3);
//    ddaline(x3, y3, x2, y2);
//
//    // Door
//    ddaline(x1 + k / 4, y1, x1 + k / 4, y1 + l);
//    ddaline(x1 + 3 * k / 4, y1, x1 + 3 * k / 4, y1 + l);
//    ddaline(x1 + k / 4, y1 + l, x1 + 3 * k / 4, y1 + l);
//
//    // Window
//    ddaline(x1 + k + m, y1 + l / 2, x1 + k + 3 * m, y1 + l / 2);
//    ddaline(x1 + k + m, y1 + l / 2, x1 + k + m, y1 + 3 * l / 2);
//    ddaline(x1 + k + m, y1 + 3 * l / 2, x1 + k + 3 * m, y1 + 3 * l / 2);
//    ddaline(x1 + k + 3 * m, y1 + l / 2, x1 + k + 3 * m, y1 + 3 * l / 2);
//
//    glEnd();
//    glFlush();
//}
//void display() {
//    drawHouse(100,10,    100,100,   150,150,   350,150,   400,100,    400,10);
//}
//void myinit() {
//
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//
//    glColor3f(1.0, 0.0, 0.0);
//
//    glPointSize(5.0);
//
//    glMatrixMode(GL_PROJECTION);
//
//    glLoadIdentity();
//
//    gluOrtho2D(0.0, 639.0, 0.0, 319.0);
//
//    //gluOrtho2D(-780, 780, -420, 420);
//
//}
//
///* Main function: GLUT runs as a console application starting at main()  */
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);                 // Initialize GLUT initalise graphics system
//
//    glutCreateWindow("Bhavya"); // Create a window with the given title
//
//    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); // Use to initalise the colour system
//
//    glutInitWindowSize(640, 320);   // Set the window's initial width & height (resolution=no of pixels in horizontal*no of pixels in vertical)
//
//    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner shitfted the origin
//
//    myinit();
//
//    glutDisplayFunc(display); // passed in the openGL we cannot pass directly so we use function as glutDisplayFunc
//
//    glutMainLoop();
//
//    return 0;
//
//}// Register display callback handler for window re-paint
using namespace std;
#define GL_SILENCE_DEPRECATION
#define SZ 100000
#define FOR(I,J,K) for (I = J; I < K; I++)
double enemy = 0.1f;
double enemy_x[SZ];
double enemy_y[SZ];
double enemy_vel[SZ];
double enemy_stat[SZ] = { 0 };
double enemy_col[SZ];
double shooter_x = 0.0f;
double shooter_y = -1.9f;
double shooter_min_x = -1.9f;
double shooter_max_x = 1.9f;
double angle = 0.0f;
double bullet_x[SZ];
double bullet_y[SZ];
double bullet_vel = 0.05f;
int bullet_stat[SZ] = { 0 };
double bullet_vel_x[SZ];
double bullet_vel_y[SZ];
double tip_x[SZ];
double tip_y[SZ];
int bullet = 0;
int points = 0;
int on = 1000;
int frontCount = -1, cnt = 0, high = -1;
int game_over = 0;
int game_play = 0;
int level = 1;
int game_level = 0;
double mousex;
double mousey;
int mainmenu = 1;
int high_score = 0;
int howtoplay = 0;
int about = 0;
int life = 3;
int flag = 0;
int a = 0;
void renderBitmapString(float x, float y, void* font, const char* string) {
	const char* c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}
void MainMenu() {
	glLineWidth(4);
	glClearColor(0.20f, 0.24f, 0.30f, 1.0f);
	glColor3f(1.0, 1.0, 1.0);
	renderBitmapString(-0.50f,1.3f, GLUT_BITMAP_TIMES_ROMAN_24, "ENEMY RUSH");
	renderBitmapString(-0.2f, 0.8f, GLUT_BITMAP_HELVETICA_18, "By -");
	renderBitmapString(-0.6f, 0.6f, GLUT_BITMAP_HELVETICA_18, "Bhavya (102203638)");
	renderBitmapString(-0.6f, 0.4f, GLUT_BITMAP_HELVETICA_18, "Shambhavi (102383058)");
	renderBitmapString(-0.6f, 0.2f, GLUT_BITMAP_HELVETICA_18, "Shreyansh (102203642)");
	glBegin(GL_LINES);
	glVertex2f(-0.4f, -0.2f);
	glVertex2f(0.4f, -0.2f);
	glVertex2f(-0.4f, -0.5f);
	glVertex2f(0.4f, -0.5f);
	glVertex2f(-0.4f, -0.2f);
	glVertex2f(-0.4f, -0.5f);
	glVertex2f(0.4f, -0.2f);
	glVertex2f(0.4f, -0.5f);
	glEnd();
	renderBitmapString(-0.33f, -0.38f, GLUT_BITMAP_TIMES_ROMAN_24, "NEW GAME");
	glBegin(GL_LINES);
	glVertex2f(-0.4f, -0.7f);
	glVertex2f(0.4f, -0.7f);
	glVertex2f(-0.4f, -1.0f);
	glVertex2f(0.4f, -1.0f);
	glVertex2f(-0.4f, -0.7f);
	glVertex2f(-0.4f, -1.0f);
	glVertex2f(0.4f, -0.7f);
	glVertex2f(0.4f, -1.0f);
	glEnd();
	renderBitmapString(-0.42f, -0.88f, GLUT_BITMAP_TIMES_ROMAN_24, "HOW TO PLAY");
	
	
}
void drawBullet() {
	glPushMatrix();
	glTranslatef(-170 / 1200, 220 / 800, 0);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();
}
void drawenemy() {
	int i;
	if (frontCount == -1) {
		cnt = 0;
	}
	if (frontCount == 0) {
		cnt = 1;
	}
	if (frontCount < 100000) {
		for (i = 0;cnt <= 2;i++) {
			if (i > frontCount || enemy_y[i] <= -5.0f) {
				enemy_x[i] = ((rand() % 100) * 1.0f / 100.0) + ((rand() % 4) * 1.0f) - 2;
				enemy_y[i] = 2.3f;
				enemy_vel[i] = .003f + 3 * ((rand() % 10 * 1.0f) / 10000);
				enemy_stat[i] = 0;
				enemy_col[i] = rand() % 3;
				frontCount++;
				cnt++;
			}
		}
	}
}
void drawenemy(int i) {
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.07, 0.0);
	glutSolidSphere(0.04, 50, 50);
	glPopMatrix();
	glLineWidth(5);
	glColor3f(0.9, 0.0, 0.7);
	glBegin(GL_LINES);
	glVertex2f(-0.02, -0.05);
	glVertex2f(-0.09, -0.14);
	glVertex2f(0.02, -0.05);
	glVertex2f(0.09, -0.14);
	glEnd();
	glColor3f(0.9, 0.3, 0.7);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(-0.04, 0.01);
	glVertex2f(-0.1, -0.04);
	glVertex2f(0.04, 0.01);
	glVertex2f(0.1, -0.04);
	glEnd();
	glColor3f(0.0, 1.0, 0.7);
	glPointSize(15.0);
	glBegin(GL_POINTS);
	glVertex2f(-0.000, -0.01);
	glEnd();
}
void gameOver() {
	renderBitmapString(-0.5f, 0.7f, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");
	renderBitmapString(-0.5f, 0.5f, GLUT_BITMAP_TIMES_ROMAN_24, "SCORE : ");
	char str[80];
	sprintf_s(str, "%d", points);
	for (int i = 0;i < (int)(strlen(str));i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	glBegin(GL_LINES);
	glVertex2f(-0.6f, -0.5f);
	glVertex2f(-0.6f, -0.2f);
	glVertex2f(-0.6f, -0.5f);
	glVertex2f(0.6f, -0.5f);
	glVertex2f(-0.6f, -0.2f);
	glVertex2f(0.6f, -0.2f);
	glVertex2f(0.6f, -0.5f);
	glVertex2f(0.6f, -0.2f);
	glEnd();
	renderBitmapString(-0.2f, -0.4f, GLUT_BITMAP_TIMES_ROMAN_24, "MENU");
	frontCount = -1;
	cnt = 0;
	high = -1;
}
void drawShooter() {
	glColor3f(0.0, 0.5, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2f, -0.2f);
	glVertex2f(0.2f, -0.2f);
	glVertex2f(0.2f, -0.15f);
	glVertex2f(-0.2f, -0.15f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.1f, -0.5f);
	glVertex2f(0.1f, -0.5f);
	glVertex2f(0.1f, 0.16f);
	glVertex2f(-0.1f, 0.16f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0.1f, -0.15f);
	glVertex2f(0.4f, -0.15f);
	glVertex2f(0.4f, -0.05f);
	glVertex2f(0.1f, -0.05f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.1f, -0.15f);
	glVertex2f(-0.4f, -0.15f);
	glVertex2f(-0.4f, -0.05f);
	glVertex2f(-0.1f, -0.05f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.3f, -0.07f);
	glVertex2f(-0.4f, -0.07f);
	glVertex2f(-0.4f, 0.15f);
	glVertex2f(-0.3f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0.3f, -0.07f);
	glVertex2f(0.4f, -0.07f);
	glVertex2f(0.4f, 0.15f);
	glVertex2f(0.3f, 0.1f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.1f, 0.16f);
	glVertex2f(0.1f, 0.16f);
	glVertex2f(0.005f, 0.22f);
	glEnd();
}
void new_update(int value) {
	for (int i = 0;i <= frontCount;i++) {
		if (enemy_y[i] <= -1.6f) {
			enemy_vel[i] = 0;
			enemy_y[i] = -5.0f;
			enemy_stat[i] = 0;
			frontCount--;
			points--;
		}
		if (shooter_x > enemy_x[i] - 0.46f && shooter_x < enemy_x[i] + 0.46f &&
			enemy_y[i] - 0.05f <= -1.7f) {
			life--;
		}
		if (life == 0) {
			game_over = 1;
			game_play = 0;
			mainmenu = 0;
		}
	}
	for (int i = 0;i <= high;i++) {
		if (bullet_stat[i] == 1) {
			bullet_x[i] -= bullet_vel_x[i];
			bullet_y[i] += bullet_vel_y[i];
			tip_x[i] -= bullet_vel_x[i];
			tip_y[i] += bullet_vel_y[i];
			if (bullet_y[i] >= 2.0f) {
				bullet_stat[i] = 0;
			}
		}
	}
	for (int i = 0;i <= frontCount;i++) {
		for (int j = 0;j <= high;j++) {
			if (tip_x[j] > enemy_x[i] - 0.05f && tip_x[j]<enemy_x[i] + 0.05f &&
				tip_y[j]>enemy_y[i] - 0.05f && tip_y[j] < enemy_y[i] + 0.05f && bullet_stat[j] == 1) {
				enemy_vel[i] = 0;
				enemy_y[i] = -5.0f;
				enemy_stat[i] = 0;
				frontCount--;
				bullet_stat[j] = 0;
				points++;
			}
		}
	}
	for (int i = 0;i <= frontCount;i++) {
		if (enemy_y[i] < 0.0f && enemy_stat[i] == 0) {
			cnt--;
			enemy_stat[i] = 1;
		}
		if (enemy_y[i] >= -1.85f) {
			enemy_y[i] -= enemy_vel[i];
		}
	}
	on += 100;
	game_level += 10;
	if (game_level >= 10000) {
		level++;
		game_level = 1;
	}
	glutTimerFunc(10, new_update, 0);
}
void score() {
	glColor3f(1.0f, 1.0f, 1.0f);
	renderBitmapString(2.2f, 1.8f, GLUT_BITMAP_HELVETICA_18, "SCORE : ");
	char str[80];
	sprintf_s(str, "%d", points);
	for (int i = 0;i < (int)(strlen(str));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
}
void showLife() {
	glColor3f(1.0f, 1.0f, 1.0f);
	renderBitmapString(-2.6f, 1.8f, GLUT_BITMAP_HELVETICA_18, "LIFE : ");
	char str[80];
	sprintf_s(str, "%d", life);
	for (int i = 0;i < (int)(strlen(str));i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
}

void howToPlay() {
    glColor3f(1.0f, 1.0f, 1.0f);

    renderBitmapString(-0.3f, 1.5f, GLUT_BITMAP_TIMES_ROMAN_24, "HOW TO PLAY");

    renderBitmapString(-1.8f, 1.2f, GLUT_BITMAP_HELVETICA_18, "1. Use Left arrow key to move the shooter Left");
    renderBitmapString(-1.8f, 1.0f, GLUT_BITMAP_HELVETICA_18, "2. Use Right arrow key to move the shooter Right");
    renderBitmapString(-1.8f, 0.8f, GLUT_BITMAP_HELVETICA_18, "3. Press Space key to Shoot");
    renderBitmapString(-1.8f, 0.6f, GLUT_BITMAP_HELVETICA_18, "4. Kill the object to earn 1 point");
    renderBitmapString(-1.8f, 0.4f, GLUT_BITMAP_HELVETICA_18, "5. If objects are missed and cross the shooter, 1 life is lost");
    renderBitmapString(-1.8f, 0.2f, GLUT_BITMAP_HELVETICA_18, "6. Press ESC to exit the game");

    glBegin(GL_LINES);
    glVertex2f(-0.4f, -1.2f);
    glVertex2f(0.4f, -1.2f);
    glVertex2f(-0.4f, -1.5f);
    glVertex2f(0.4f, -1.5f);
    glVertex2f(-0.4f, -1.2f);
    glVertex2f(-0.4f, -1.5f);
    glVertex2f(0.4f, -1.2f);
    glVertex2f(0.4f, -1.5f);
    glEnd();
    renderBitmapString(-0.1f, -1.38f, GLUT_BITMAP_TIMES_ROMAN_24, "BACK");
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (double)w / (double)h, 0.1f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void handleKeypress1(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(0);
	}
	else if (key == ' ' && on >= 1000) {
		int i;
		for (i = 0;i < high;i++) {
			if (bullet_stat[i] == 0) {
				bullet_x[i] = shooter_x;
				bullet_y[i] = shooter_y;
				tip_x[i] = bullet_x[i];
				tip_y[i] = bullet_y[i] + 0.2;
				bullet_vel_x[i] = 0;
				bullet_vel_y[i] = bullet_vel;
				bullet_stat[i] = 1;
				bullet = 1;
				break;
			}
		}
		if (bullet == 0) {
			high++;
			bullet_x[high] = shooter_x;
			bullet_y[high] = shooter_y;
			tip_x[high] = shooter_x;
			tip_y[high] = shooter_y + 0.2;
			bullet_vel_x[high] = 0;
			bullet_vel_y[high] = bullet_vel;
			bullet_stat[high] = 1;
		}
		on = 0;
		bullet = 0;
	}
}
void getCoord(int x, int y) {
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;
	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	winZ = 0;
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY,
		&posZ);
	mousex = posX * 100 / 2;
	mousey = (posY * 100) / 2;
	glutPostRedisplay();
}
void handleKeypress2(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) {
		if (shooter_x > shooter_min_x) {
			shooter_x -= 0.05;
		}
	}
	else if (key == GLUT_KEY_RIGHT) {
		if (shooter_x < shooter_max_x) {
			shooter_x += 0.05;
		}
	}
}
void handleMouseclick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && game_play == 0 && mainmenu == 1) {
        getCoord(x, y);

        if (mousex >= -0.4f && mousex <= 0.4f && mousey >= -0.5f && mousey <= -0.2f) {
            if (game_over == 0) {
                game_play = 1;
                game_over = 0;
            }
        }
        else if (mousex >= -0.4f && mousex <= 0.4f && mousey >= -1.0f && mousey <= -0.7f) {
            mainmenu = 0;
            howtoplay = 1;
        }
    }

    else if (button == GLUT_LEFT_BUTTON && game_play == 0 && mainmenu == 0 && howtoplay == 1) {
        getCoord(x, y);
        if (mousex >= -0.4f && mousex <= 0.4f && mousey >= -1.5f && mousey <= -1.2f) {
            mainmenu = 1;
            howtoplay = 0;
        }
    }

    else if (button == GLUT_LEFT_BUTTON && game_play == 0 && mainmenu == 0 && game_over == 1) {
        getCoord(x, y);
        if (mousex >= -0.4f && mousex <= 0.4f && mousey >= -0.5f && mousey <= -0.2f) {
            mainmenu = 1;
            game_over = 0;
            life = 3;       
            points = 0;     
        }
    }
}


void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (game_play == 0 && mainmenu == 1) {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -5.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		MainMenu();
		glPopMatrix();
	}
	else if (game_play == 0 && mainmenu == 0 && game_over == 1) {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -5.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		gameOver();
		glPopMatrix();
	}
	else if (mainmenu == 0 && howtoplay == 1 && game_play == 0) {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -5.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		howToPlay();
		glPopMatrix();
	}
	else if (mainmenu == 0 && game_play == 0 && game_over == 1) {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -5.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		gameOver();
		glPopMatrix();
	}
	else if (game_over == 0 && game_play == 1) {
		drawenemy();
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -5.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		for (int i = 0;i <= high;i++) {
			if (bullet_stat[i] == 1) {
				glPushMatrix();
				glTranslatef(bullet_x[i], bullet_y[i], 0.0f);
				glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
				glColor3f(0.0f, 0.0f, 0.0f);
				drawBullet();
				glPopMatrix();
			}
		}
		glPushMatrix();
		glTranslatef(shooter_x, shooter_y, 0.0f);
		drawShooter();
		glPopMatrix();
		for (int i = 0;i <= frontCount;i++) {
			glPushMatrix();
			glTranslatef(enemy_x[i], enemy_y[i], 0.0f);
			if (enemy_vel[i] != 0)
				drawenemy(i);
			glPopMatrix();
		}
		glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		score();
		showLife();
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -5.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glPushMatrix();
		glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		glPopMatrix();
	}
	glPopMatrix();
	glutSwapBuffers();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(220, 50);
	glutCreateWindow("Shooting Game");
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutKeyboardFunc(handleKeypress1);
	glutSpecialFunc(handleKeypress2);
	glutMouseFunc(handleMouseclick);
	glutReshapeFunc(handleResize);
	glutTimerFunc(5, new_update, 0);
	glutMainLoop();
	return 0;
}
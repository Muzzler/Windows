/*#include <stdio.h>
#include <windows.h>	   // Standard header for MS Windows applications
#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header

#define KEY_ESCAPE 27

void display(void)
{
 
	glClear(GL_COLOR_BUFFER_BIT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
 
	HBITMAP hBmp = (HBITMAP) ::LoadImage (NULL,(LPCTSTR) "t_24_bit_bmp.bmp", 
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE |LR_CREATEDIBSECTION);
	if (hBmp == NULL) {
	printf("Nie znaleziono bitmapy\n");
	}
	else printf("Znaleziono bitmape!\n");
 
	BITMAP BM;
	::GetObject (hBmp, sizeof (BM), &BM);
	  if (BM.bmBitsPixel != 24){
	   printf("Zla paleta kolorow!\n");
	  }
	   else
	   printf("Dobra paleta kolorow!\n");
		printf("Wysokosc:%d\n",BM.bmHeight);
		printf("Szerokosc:%d\n",BM.bmWidth);
 
//GLwidth=BM.bmWidth;
//GLheight=BM.bmHeight;
 
	glDrawPixels( BM.bmWidth, BM.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, BM.bmBits );
	glEnd();
	glFlush();
}
 
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
 
 
int main(int argc, char **argv)
{
 
argc = 1;
//argv[1] = {{""}};
//int g=(int)pvParam;
 
glutInit(&argc, argv);	
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(560,640);
	//glutInitWindowPosition(1400,100);
	glutCreateWindow("Instrukcja sterowania Q0");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
 
 
 return 0;
}
*/
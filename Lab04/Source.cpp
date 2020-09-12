#include<stdio.h>
#include<windows.h>
#include<conio.h> 
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("      ");
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
}
int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a'&& x>0) { 
				if (x <= 0) {
					x = 0;
				}
				draw_ship(--x, y); }
			if (ch == 'd') { 
				if (x >= 73) {
					x = 73;
				}
				draw_ship(++x, y); }
			if (ch == 'w'&&y>0) { 
				erase_ship(x, y);
				draw_ship(x, --y); }
			if (ch == 's') { 
				erase_ship(x, y);
				draw_ship(x, ++y); }
			fflush(stdin);
		}
		Sleep(500);
	} while (ch != 'x');
	return 0;
}
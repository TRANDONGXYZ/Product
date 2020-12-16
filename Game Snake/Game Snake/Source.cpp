#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

const int consolewidth = 30;
const int consolehight = 30;

int j = 1;

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

enum trang_thai
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct toa_do
{
	int x;
	int y;
};

struct Snake
{
	toa_do dot[31];
	int n;
	trang_thai tt;
} snake;

struct hoa_qua
{
	toa_do td;
} hq;

void khoi_tao(Snake& snake);
void hien_thi(Snake snake);
void gotoxy(short x, short y);
void dieu_khien_di_chuyen(Snake& snake);
int xu_ly(Snake& snake, hoa_qua& hq, int& thoi_gian_sleep);

void khoi_tao(Snake& snake, hoa_qua& hq)
{
	snake.n = 1;
	snake.dot[0].x = 1;
	snake.dot[0].y = 1;
	hq.td.x = 20;
	hq.td.y = 20;

	//snake.n = 3;
	//snake.dot[0].x = 2;
	//snake.dot[0].y = 2;
	//snake.dot[1].x = 1;
	//snake.dot[1].y = 1;
	//snake.dot[2].x = 0;
	//snake.dot[2].y = 0;

	snake.tt = RIGHT;
}

void hien_thi(Snake snake, hoa_qua hq)
{
	int i, row, in, m, s;
	system("cls");

	for (row = 1; row <= consolehight; row++)
	{
		if (row == 1)
		{
			for (in = 1; in <= consolewidth; in++)
			{
				if (in == 1)
					cout << char(201);
				else if (in == consolewidth)
					cout << char(187);
				else
					cout << char(205);
			}
			cout << endl;
		}
		else if (row == consolehight)
		{
			for (in = 1; in <= consolewidth; in++)
			{
				if (in == 1)
					cout << char(200);
				else if (in == consolewidth)
					cout << char(188);
				else
					cout << char(205);
			}
			cout << endl;
		}
		else
		{
			for (s = 1; s <= consolewidth; s++)
			{
				if (s == 1 || s == consolewidth)
					cout << char(186);
				else
					cout << " ";
			}
			cout << endl;
		}
	}

	gotoxy(hq.td.x, hq.td.y);
	cout << j;
	gotoxy(snake.dot[0].x, snake.dot[0].y);
	cout << char(2);

	for (i = 1; i < snake.n; i++)
	{
		gotoxy(snake.dot[i].x, snake.dot[i].y);
		cout << "*";
	}
}

void dieu_khien_di_chuyen(Snake& snake)
{
	int i;
	for (i = snake.n - 1; i > 0; i--)
	{
		snake.dot[i] = snake.dot[i - 1];
	}

	if (_kbhit())
	{
		int key;
		key = _getch();

		if (key == 'A' || key == 'a')
			snake.tt = LEFT;
		if (key == 'S' || key == 's')
			snake.tt = DOWN;
		if (key == 'W' || key == 'w')
			snake.tt = UP;
		if (key == 'D' || key == 'd')
			snake.tt = RIGHT;
	}

	if (snake.tt == LEFT)
		snake.dot[0].x--;
	else if (snake.tt == DOWN)
		snake.dot[0].y++;
	else if (snake.tt == UP)
		snake.dot[0].y--;
	else if (snake.tt == RIGHT)
		snake.dot[0].x++;
}

int xu_ly(Snake& snake, hoa_qua& hq, int& thoi_gian_sleep)
{
	if (snake.dot[0].x < 0 || snake.dot[0].x >= consolewidth || snake.dot[0].y < 0 || snake.dot[0].y >= consolewidth)
		return -1;


	for (int i = 1; i <= snake.n; i++)
	{
		if (snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y)
			return -1;
	}


	if (snake.dot[0].x == hq.td.x && snake.dot[0].y == hq.td.y)
	{
		snake.n++;
		if (snake.tt == RIGHT)
		{
			snake.dot[0].x++;
		}
		else if (snake.tt == LEFT)
		{
			snake.dot[0].x--;
		}
		else if (snake.tt == UP)
		{
			snake.dot[0].y--;
		}
		else if (snake.tt == DOWN)
		{
			snake.dot[0].y++;
		}

		hq.td.x = rand() % (consolewidth - 1);
		hq.td.x = rand() % (consolehight - 1);

		if (thoi_gian_sleep > 30)
			thoi_gian_sleep -= 20;

		j++;
	}
}

int main()
{
	int ma = 0, thoi_gian_sleep = 200;
	srand(time(NULL));

	khoi_tao(snake, hq);

	while (1)
	{
		//hiển thị

		hien_thi(snake, hq);

		//điều khiển

		dieu_khien_di_chuyen(snake);

		//Xử lý

		ma = xu_ly(snake, hq, thoi_gian_sleep);

		//kết quả

		if (ma == -1)
		{
			gotoxy(consolewidth + 1, 10);
			cout << "Ban da thua game.";
			_getch();
			break;
		}

		Sleep(thoi_gian_sleep);
	}
}
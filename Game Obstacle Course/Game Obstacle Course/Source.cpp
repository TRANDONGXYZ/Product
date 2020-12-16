#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

const int consolewidth = 80;
const int consoleheight = 25;
const int roadwidth = 25;

struct toa_do
{
	int x, y;
};

struct hinh_dang
{
	char a[3][3];
};

struct Xe
{
	toa_do td;		//tọa độ tại vị trí hd.a[1][1]
	hinh_dang hd;
	int diem;
};

struct vat_can
{
	toa_do td;
	hinh_dang hd;
};

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void khoi_tao(Xe& xe, vat_can& vc)
{
#define pHD xe.hd.a		//#define có thể thay thể cho cả phần thực thể
	//------------------------------------------------------------------------------------
	//tọa độ khi xe xuất hiện

	xe.td.y = consoleheight - 2;
	xe.td.x = roadwidth / 2;

	//-------------------------------------------------------------------------------------

	//hình dạng của xe

	pHD[0][0] = pHD[0][2] = pHD[2][0] = pHD[2][2] = 'o';		//khởi tạo bánh xe
	pHD[0][1] = '^';		//khởi tạo đầu xe
	pHD[2][1] = '-';		//khởi tạo đuôi xe
	pHD[1][0] = pHD[1][2] = '|';		//khởi tạo thân xe
	pHD[1][1] = ' ';		//khởi tạo phần trung tâm

	//---------------------------------------------------------------------------------------
	//vật cản
	vc.td.x = 1 + rand() % (roadwidth - 1);
	vc.td.y = 0;

	xe.diem = 0;
}

void hien_thi(Xe xe, vat_can& vc)
{
	system("cls");

	//-------------------------------------------------------------------------------------
	//đường biên

	for (int i = 0; i < consoleheight; i++)
	{
		cout << char(186) << endl;
	}

	for (int i = 0; i < consoleheight; i++)
	{
		gotoxy(roadwidth, i);
		cout << char(186);
	}

	//--------------------------------------------------------------------------------------
	//hình dạng của xe

	for (int kDong = -1; kDong <= 1; kDong++)
	{
		for (int kCot = -1; kCot <= 1; kCot++)
		{
			int x = kCot + xe.td.x;
			int y = kDong + xe.td.y;

			gotoxy(x, y);
			cout << xe.hd.a[kDong + 1][kCot + 1];
		}
	}

	//------------------------------------------------------------------------------------
	//vật cản

	if (vc.td.y <= consoleheight - 1)
	{
		gotoxy(vc.td.x, vc.td.y);
		cout << char(178);
	}
	else if (vc.td.y > consoleheight - 1)
	{
		vc.td.y = 0;
		vc.td.x = 1 + rand() % (roadwidth - 1);
	}

	//------------------------------------------------------------------------------------
	//điểm
	gotoxy(0, consoleheight + 2);
	cout << xe.diem;
}

void dieu_khien(Xe& xe)
{
	if (_kbhit())
	{
		char key = _getch();
		if (key == 'A' || key == 'a' && xe.td.x >= 3)
			xe.td.x--;
		if (key == 'D' || key == 'd' && xe.td.x <= roadwidth - 3)
			xe.td.x++;
	}
}

int xu_ly(Xe& xe, vat_can& vc, int& thoi_gian)
{
	//-------------------------------------------------------------------------------------------
	//xử lý thua game do va chạm

	if ((xe.td.x - 1 == vc.td.x && xe.td.y - 1 == vc.td.y) || (xe.td.x == vc.td.x && xe.td.y - 1 == vc.td.y) || (xe.td.x + 1 == vc.td.x && xe.td.y - 1 == vc.td.y) || (xe.td.x + 1 == vc.td.x && xe.td.y == vc.td.y) || (xe.td.x - 1 == vc.td.x && xe.td.y == vc.td.y) || (xe.td.x + 1 == vc.td.x && xe.td.y + 1 == vc.td.y) || (xe.td.x - 1 == vc.td.x && vc.td.y - 1 == vc.td.y))
		return -1;


	//---------------------------------------------------------------------------------------------
	//Xử lý điểm

	if (vc.td.y > consoleheight - 2)
		xe.diem++;

	if (thoi_gian > 30)
		thoi_gian -= 20;

	//--------------------------------------------------------------------------------------------
	//vật cản di chuyển

	vc.td.y++;

	//-------------------------------------------------------------------------------------------
	//tăng độ khó cho game


}

int main()
{
	Xe xe;
	vat_can vc;
	int thoi_gian = 200, a;
	srand(time(NULL));

	khoi_tao(xe, vc);

	while (1)
	{
		//hiển thị
		hien_thi(xe, vc);

		//điều khiển
		dieu_khien(xe);

		//xử lý
		a = xu_ly(xe, vc, thoi_gian);

		//game over
		if (a == -1)
		{
			gotoxy(0, consoleheight + 10);
			cout << "Ban da thua game :(" << endl;
			while (_getch() != 13);
			break;
		}

		Sleep(thoi_gian);
	}
}
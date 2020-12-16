#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>

#include "function.h"

using namespace std;

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void gotoxy1(short x, short y)
{
	system("cls");
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//----------------------------------------------------------------------------------------------------------------
//Giao diện

//Giao dien Huong dan
int Guide(void)
{
	int a = 12, b = 6, d = 65;
	char c;

	gotoxy(5, 2);
	cout << "<--  Back (B)" << endl;
	gotoxy(102, 2);
	cout << "Play (P)  -->" << endl;
	gotoxy(20, b);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "1.SYMBOL:   Player 1 |X|     Player 2 |O|." << endl;
	gotoxy(20, b + 1);
	cout << "2.CONTROL:  Use W A S D to move. Press ENTER to mark your move." << endl;
	gotoxy(20, b + 2);
	cout << "3.RULE :    The first one create five in a row without being blocked is a winner." << endl;
	gotoxy(a + 4, b + 4);
	cout << "                  ^                  " << endl;
	gotoxy(a + 4, b + 5);
	cout << "                  |                  " << endl;
	gotoxy(a + 4, b + 6);
	cout << "               -------                " << endl;
	gotoxy(a + 4, b + 7);
	cout << "              |   W   |               " << endl;
	gotoxy(a + 4, b + 8);
	cout << "       -----------------------         " << endl;
	gotoxy(a + 4, b + 9);
	cout << "<---- |   A   |   S   |   D   | ---->  " << endl;
	gotoxy(a + 4, b + 10);
	cout << "       -----------------------        " << endl;
	gotoxy(a + 4, b + 11);
	cout << "                  |                  " << endl;
	gotoxy(a + 4, b + 12);
	cout << "                  V                  " << endl;

	gotoxy(a + 4, b + 14);
	cout << "       -----------------------         " << endl;
	gotoxy(a + 4, b + 15);
	cout << "      |         SPACE         |        " << endl;
	gotoxy(a + 4, b + 16);
	cout << "       -----------------------        " << endl;

	gotoxy(d + 4, b + 4);
	cout << "                  ^                  " << endl;
	gotoxy(d + 4, b + 5);
	cout << "                  |                  " << endl;
	gotoxy(d + 4, b + 6);
	cout << "               -------                     " << endl;
	gotoxy(d + 4, b + 7);
	cout << "              |   UP  |                     " << endl;
	gotoxy(d + 4, b + 8);
	cout << "       -----------------------        " << endl;
	gotoxy(d + 4, b + 9);
	cout << "<---- |  LEFT |  DOWN | RIGHT | ---->   " << endl;
	gotoxy(d + 4, b + 10);
	cout << "       -----------------------         " << endl;
	gotoxy(d + 4, b + 11);
	cout << "                  |                  " << endl;
	gotoxy(d + 4, b + 12);
	cout << "                  V                  " << endl;

	gotoxy(d + 4, b + 14);
	cout << "       -----------------------         " << endl;
	gotoxy(d + 4, b + 15);
	cout << "      |         ENTER         |        " << endl;
	gotoxy(d + 4, b + 16);
	cout << "       -----------------------        " << endl;

	gotoxy(a + 17, b + 19);
	cout << "Player 1: X";
	gotoxy(d + 17, b + 19);
	cout << "Player 2: O";

	gotoxy(0, b + 22);

	c = _getch();
	while (1)
	{
		if (c == 'B' || c == 'b')
			return 1;
		else if (c == 'P' || c == 'p')
			return 2;
		else
			c = _getch();
	}
}

//Giao diện khung phân cách
void Display_khung(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	//Đường nằm dọc
	for (int i = 0; i < 30; i++)
	{
		gotoxy(60, i);
		if (i == 15)
			cout << char(204);
		else
			cout << char(186);
	}

	//Đường nằm ngang
	for (int i = 61; i < 122; i++)
	{
		gotoxy(i, 15);
		cout << char(205);
	}
}

//Thiết kế giao diện màn hình hiện các tùy chọn khi mới mở game
void Display_new_game(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int y = 36;
	gotoxy1(y, 1);
	cout << "VIETNAM NATIONAL UNIVERSITY HO CHI MINH CITY";
	Sleep(100);
	gotoxy1(y + 13, 2);
	cout << "UNIVERSITY OF SCIENCE";
	Sleep(100);
	gotoxy1(y + 7, 3);
	cout << "FACULTY OF INFORMATION TECHNOLOGY";
	Sleep(100);


	int x = (120 - 25) / 2;
	gotoxy1(x + 1, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "*" << "*" << "*";
	gotoxy(x, 6);
	cout << "*";
	gotoxy(x, 7);
	cout << "*";
	gotoxy(x, 8);
	cout << "*";
	gotoxy(x + 1, 9);
	cout << "*" << "*" << "*";
	Sleep(100);
	// Chu C

	// Chu A
	gotoxy1(x + 8, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "*" << "*";
	gotoxy(x + 7, 6);
	cout << "*" << "  " << "*";
	gotoxy(x + 7, 7);
	cout << "*" << "*" << "*" << "*";
	gotoxy(x + 7, 8);
	cout << "*" << "  " << "*";
	gotoxy(x + 7, 9);
	cout << "*" << "  " << "*";
	Sleep(100);

	//Chu R
	gotoxy1(x + 14, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "*" << "*" << "*";
	gotoxy(x + 14, 6);
	cout << "*" << "  " << "*";
	gotoxy(x + 14, 7);
	cout << "*" << "*";
	gotoxy(x + 14, 8);
	cout << "*" << "  " << "*";
	gotoxy(x + 14, 9);
	cout << "*" << "   " << "*";
	Sleep(100);


	//Chu 0
	gotoxy1(x + 21, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "*" << "*" << "*";
	gotoxy(x + 20, 6);
	cout << "*" << "   " << "*";
	gotoxy(x + 20, 7);
	cout << "*" << "   " << "*";
	gotoxy(x + 20, 8);
	cout << "*" << "   " << "*";
	gotoxy(x + 21, 9);
	cout << "*" << "*" << "*";
	Sleep(100);

	gotoxy1((120 - 36) / 2, 11);
	cout << "Instructors: Master. Truong Toan Thinh";
	Sleep(100);

	system("cls");

	//========================================================================================

	system("cls");

	int b = (120 - 38) / 2;
	int c = 36;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(c, 1);
	cout << "VIETNAM NATIONAL UNIVERSITY HO CHI MINH CITY";
	gotoxy(c + 13, 2);
	cout << "UNIVERSITY OF SCIENCE";
	gotoxy(c + 7, 3);
	cout << "FACULTY OF INFORMATION TECHNOLOGY";


	int a = (120 - 25) / 2;
	gotoxy(a + 1, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "*" << "*" << "*";
	gotoxy(a, 6);
	cout << "*";
	gotoxy(a, 7);
	cout << "*";
	gotoxy(a, 8);
	cout << "*";
	gotoxy(a + 1, 9);
	cout << "*" << "*" << "*";
	// Chu C

	// Chu A
	gotoxy(a + 8, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "*" << "*";
	gotoxy(a + 7, 6);
	cout << "*" << "  " << "*";
	gotoxy(a + 7, 7);
	cout << "*" << "*" << "*" << "*";
	gotoxy(a + 7, 8);
	cout << "*" << "  " << "*";
	gotoxy(a + 7, 9);
	cout << "*" << "  " << "*";

	//Chu R
	gotoxy(a + 14, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "*" << "*" << "*";
	gotoxy(a + 14, 6);
	cout << "*" << "  " << "*";
	gotoxy(a + 14, 7);
	cout << "*" << "*";
	gotoxy(a + 14, 8);
	cout << "*" << "  " << "*";
	gotoxy(a + 14, 9);
	cout << "*" << "   " << "*";


	//Chu 0
	gotoxy(a + 21, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "*" << "*" << "*";
	gotoxy(a + 20, 6);
	cout << "*" << "   " << "*";
	gotoxy(a + 20, 7);
	cout << "*" << "   " << "*";
	gotoxy(a + 20, 8);
	cout << "*" << "   " << "*";
	gotoxy(a + 21, 9);
	cout << "*" << "*" << "*";


	gotoxy((120 - 36) / 2, 11);
	cout << "Instructors: Master. Truong Toan Thinh";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	gotoxy(80, 13);
	cout << "Play Game";
	gotoxy(80, 14);
	cout << "Exit";
	gotoxy(80, 15);
	cout << "Guide";
	gotoxy(80, 16);
	cout << "Load Game";


	gotoxy(29, 13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Information member: " << endl;
	gotoxy(23, 14);
	cout << " Le Van Dong      - 19127363" << endl;
	gotoxy(23, 15);
	cout << " Tran Dong Ba     - 19127334" << endl;
	gotoxy(23, 16);
	cout << " Phan Manh Truong - 19127309" << endl;
	gotoxy(23, 17);
	cout << " Pham Thanh Dang  - 19127114" << endl;
	cout << endl;
}

//Giao diện bàn cờ trong game
void Display_table(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(77, 19);
	cout << "Save Game(L)";
	gotoxy(96, 19);

	cout << "Quit Game(Q)";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int k = 1, h = 3;
	for (int i = 0; i < 25; i++)
	{
		h = 3;
		for (int j = 0; j < 13; j++)
			if (i % 2 == 0 && j < 12)
			{
				gotoxy(h += 4, k);
				cout << char(197) << char(196) << char(196) << char(196);
			}
			else if (i % 2 == 0)
			{
				gotoxy(h += 4, k);
				cout << char(197);
			}
			else
			{
				gotoxy(h += 4, k);
				cout << char(179) << "   ";
			}
		k++;
	}
}

//Giao diện X thắng game
void X_win(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	int a = 62;
	int b = 4;
	gotoxy(a, b);
	cout << "xx      xx      xx        xxxx        xx  xx  xx        xx";
	gotoxy(a, b + 1);
	cout << "  xx  xx        xx        xxxx        xx  xx  xxxx      xx";
	gotoxy(a, b + 2);
	cout << "    xx            xx    xx    xx    xx    xx  xx   xx   xx";
	gotoxy(a, b + 3);
	cout << "  xx  xx          xx    xx    xx    xx    xx  xx      xxxx";
	gotoxy(a, b + 4);
	cout << "xx      xx           xx          xx       xx  xx        xx";
}

//Giao diện O thắng game
void O_win(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	int a = 62;
	int b = 4;
	gotoxy(a, b);
	cout << " OOOOOOOO       OO        OOOO        OO  OO  OO        OO";
	gotoxy(a, b + 1);
	cout << "OO      OO      OO        OOOO        OO  OO  OOOO      OO";
	gotoxy(a, b + 2);
	cout << "OO      OO        OO    OO    OO    OO    OO  OO   OO   OO";
	gotoxy(a, b + 3);
	cout << "OO      OO        OO    OO    OO    OO    OO  OO      OOOO";
	gotoxy(a, b + 4);
	cout << " OOOOOOOO            OO          OO       OO  OO        OO";
}

//Hoà nhau
void Draw()
{
	int a = 62;
	int b = 4;
	gotoxy(a, b);
	cout << "=======    =======           ===     ==      ==     ==   ";
	gotoxy(a, b + 1);
	cout << "==     ==  ==      ==       == ==     ==    ====   ==   ";
	gotoxy(a, b + 2);
	cout << "==     ==  =======         =======     ==  ==  == ==      ";
	gotoxy(a, b + 3);
	cout << "==     ==  ==     ==      ==      ==    ===     ===       ";
	gotoxy(a, b + 4);
	cout << "======     ==       ==   ==        ==    =       =        ";
}

//Hỏi người dùng có muốn chơi lại không
int AskContinue()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	char c;

	gotoxy(77, 22);
	cout << "Continue? Yes (Y) - No (N)";

	c = _getch();

	while (1)
	{
		if (c == 'Y' || c == 'y')
			return 1;
		else if (c == 'N' || c == 'n')
			return 0;
		else
			c = _getch();
	}
}

//Xác nhận thoát game
int Quit()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	char c;
	gotoxy(77, 22);
	cout << "EXIT:  Yes |Y|    No |N| ?  ";

	c = _getch();

	while (1)
	{
		if (c == 'Y' || c == 'y')
			return 1;
		else if (c == 'N' || c == 'n') {
			gotoxy(77, 22);
			cout << "                                       ";
			return 0;
		}
		else
			c = _getch();
	}
}

//Tải lại game
void Load_game()
{
	int a = 30;

	system("cls");

	gotoxy(50, 9);
	cout << "LOADING ...";
	for (int i = 0; i < 20; i++)
	{
		gotoxy(a += 2, 10);
		cout << char(175) << " " << char(175) << " " << char(175) << " " << char(175) << " " << char(175);
		gotoxy(a, 10);
		cout << " ";
		gotoxy(a + 10, 10);
		cout << char(175);
		Sleep(50);
	}

	system("cls");
}

//Dấu mũi tên trong lượt đánh
void Dau_mui_ten()
{
	gotoxy(70, 6);
	for (int i = 1; i <= 5; i++)
		cout << char(175) << " ";
}

//Dấu mũi tên trong menu
void Dau_mui_ten_menu(int h, int k)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(h, k);
	for (int i = 0; i < 2; i++)
		cout << char(175) << " ";
}

//Xóa dấu mũi tên trong menu
void Xoa_dau_mui_ten_menu(int h, int k)
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(h + i, k);
		cout << " ";
	}
}

//Xóa màu xanh
void Tra_mau(int k)
{
	switch (k)
	{
	case 13:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		gotoxy(80, 13);
		cout << "Play Game";
		break;
	case 14:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		gotoxy(80, 14);
		cout << "Exit";
		break;
	case 15:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		gotoxy(80, 15);
		cout << "Guide";
		break;
	case 16:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		gotoxy(80, 16);
		cout << "Load Game";
		break;

	}
}

//Nổi lựa chọn
void Lua_chon(int h, int k)
{
	switch (k)
	{
	case 13:
		Dau_mui_ten_menu(h, k);
		gotoxy(80, 13);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Play Game";
		break;
	case 14:
		Dau_mui_ten_menu(h, k);
		gotoxy(80, 14);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Exit";
		break;
	case 15:
		Dau_mui_ten_menu(h, k);
		gotoxy(80, 15);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Guide";
		break;
	case 16:
		Dau_mui_ten_menu(h, k);
		gotoxy(80, 16);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Load Game";
		break;

	}
}

//Giao diện tới lượt "O" đánh
void Display_innings_O()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Dau_mui_ten();
	int a = 88, b = 4;
	gotoxy(a, b);
	cout << "OOOOOOOOOO";
	gotoxy(a, b + 1);
	cout << "OO      OO";
	gotoxy(a, b + 2);
	cout << "OO      OO";
	gotoxy(a, b + 3);
	cout << "OO      OO";
	gotoxy(a, b + 4);
	cout << "OOOOOOOOOO";
}

//Giao diện tới lượt "X" đánh
void Display_innings_X()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	Dau_mui_ten();
	int a = 88, b = 4;
	gotoxy(a, b);
	cout << "xx      xx";
	gotoxy(a, b + 1);
	cout << "  xx  xx  ";
	gotoxy(a, b + 2);
	cout << "    xx    ";
	gotoxy(a, b + 3);
	cout << "  xx  xx  ";
	gotoxy(a, b + 4);
	cout << "xx      xx";
}

//Đếm số nước đã đánh của X và O
void Times_X_O(TIMES times)
{
	gotoxy(87, 11);
	cout << "X = " << times.X << ", O = " << times.O;
}

//Giao diện tỉ số
void Display_score(SCORE score)
{
	gotoxy(77, 13);
	cout << "SCORE:";
	gotoxy(81, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "|X|:  " << score.X;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(93, 14);
	cout << "|O|:  " << score.O;

}

//Giao diện lưu game
string Display_save_game()
{
	string address, name;
	gotoxy(93, 27);
	cout << "Input file name: ";
	getline(cin, name);
	gotoxy(93, 27);
	cout << "                            ";
	address = "D:/" + name + ".txt";
	return address;
}

//Giao diện yêu cầu nhập tên để mở tập tin
string Display_play_continue(void)
{
	string name, address;
	cout << "Input file name: ";
	getline(cin, name);
	address = "D:/" + name + ".txt";
	return address;
}

//Đánh lại các nước đã đánh
void Danh_lai(char mang[][25], TIMES times, POSITION position, P p)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	for (int i = 0; i < times.X; i++)
	{
		gotoxy(position.X[i].x, position.X[i].y);
		cout << "X";
		mang[position.X[i].x][position.X[i].y] = 'X';
		/*gotoxy(70, 12);
		cout << mang[position.X[i].x][position.X[i].y];*/
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 0; i < times.O; i++)
	{
		gotoxy(position.O[i].x, position.O[i].y);
		cout << "O";
		mang[position.O[i].x][position.O[i].y] = 'O';
		/*gotoxy(70, 12);
		cout << mang[position.O[i].x][position.O[i].y];*/
	}

	gotoxy(p.x, p.y);
}

//----------------------------------------------------------------------------------------------------------------
//Xử lý

//------------------------------------------------------------------------------
//Xử lý nhập lựa chọn

//Nhập lựa chọn vào "Setting" hoặc "Play"
int Selection_1(void)
{
	int h = 75, k = 13;
	char c;

	Dau_mui_ten_menu(h, k);
	Lua_chon(h, k);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	while (1)
	{
		gotoxy(0, 20);	//Để đưa con trỏ về vị trí ít thấy ở góc dưới màn hình

		c = _getch();

		Xoa_dau_mui_ten_menu(h, k);

		if (c == -32)
		{
			c = _getch();
			if (c == 72)	//Di chuyển lên
			{
				Tra_mau(k);
				k--;
			}
			else if (c == 80)	//Di chuyển xuống
			{
				Tra_mau(k);
				k++;
			}
		}
		else if (c == 13)
		{
			gotoxy(0, 20);
			switch (k)
			{
			case 13:
				system("cls");
				return 1;
			case 14:
				exit(1);
			case 15:
				return 2;
			case 16:
				return 3;
				/*case 17:
					return 4;*/
			}
		}

		if (k > 16)
			k = 13;
		else if (k < 13)
			k = 16;

		Lua_chon(h, k);
	}
}

//------------------------------------------------------------------------------
//Xử lý thao tác

//Di chuyển để đánh
int Move(POSITION& position, char mang[][25], P& p, TIMES& times, int& kq, int& d, int& kt)
{
	int Xac_nhan = 0;
	enum class STATUS
	{
		UNKNOWN,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	char c;

	if (d == 1)
	{
		STATUS status = STATUS::UNKNOWN;

		gotoxy(p.x, p.y);
		c = _getch();

		if (c == 'W' || c == 'w')
			status = STATUS::UP;
		else if (c == 'S' || c == 's')
			status = STATUS::DOWN;
		else if (c == 'A' || c == 'a')
			status = STATUS::LEFT;
		else if (c == 'D' || c == 'd')
			status = STATUS::RIGHT;
		else if (c == 'Q' || c == 'q')
		{
			Xac_nhan = Quit();
			if (Xac_nhan == 1);
			else
				for (int i = 61; i < 61 * 2; i++)
				{
					gotoxy(i, 17);
					cout << " ";
				}
		}
		else if (c == char(32))
		{
			if (Kiem_tra(position, p, times) == 0)
			{
				Danh_dau(position, mang, p, times, d);
				kq = WhoWin(mang, p, kt, times);
				if (d == 1)
					d = 0;
				else
					d = 1;
			}
			status = STATUS::UNKNOWN;
		}
		else if (c == 'L' || c == 'l')
			return 3;

		if (status == STATUS::UP || status == STATUS::DOWN || status == STATUS::LEFT || status == STATUS::RIGHT)
		{
			if (status == STATUS::UP)
				if (p.y > 2)
					p.y -= 2;
				else
					c = _getch();
			else if (status == STATUS::DOWN)
				if (p.y < 24)
					p.y += 2;
				else
					c = _getch();
			else if (status == STATUS::LEFT)
				if (p.x > 9)
					p.x -= 4;
				else
					c = _getch();
			else if (status == STATUS::RIGHT)
				if (p.x < 50)
					p.x += 4;
		}
	}
	else
	{
		STATUS status = STATUS::UNKNOWN;

		gotoxy(p.x, p.y);
		c = _getch();

		if (c == -32)
		{
			c = _getch();
			if (c == 72)
				status = STATUS::UP;
			else if (c == 80)
				status = STATUS::DOWN;
			else if (c == 75)
				status = STATUS::LEFT;
			else if (c == 77)
				status = STATUS::RIGHT;
		}
		else if (c == char(13))
		{
			if (Kiem_tra(position, p, times) == 0)
			{
				Danh_dau(position, mang, p, times, d);
				kq = WhoWin(mang, p, kt, times);
				if (d == 1)
					d = 0;
				else
					d = 1;
			}
		}
		else if (c == 'Q' || c == 'q')
		{
			Xac_nhan = Quit();
			if (Xac_nhan == 1);
			else
				for (int i = 61; i < 61 * 2; i++)
				{
					gotoxy(i, 17);
					cout << " ";
				}
		}
		else if (c == 'L' || c == 'l')
			return 3;

		if (status == STATUS::UP || status == STATUS::DOWN || status == STATUS::LEFT || status == STATUS::RIGHT)
		{
			if (status == STATUS::UP)
				if (p.y > 2)
					p.y -= 2;
				else
					c = _getch();
			else if (status == STATUS::DOWN)
				if (p.y < 24)
					p.y += 2;
				else
					c = _getch();
			else if (status == STATUS::LEFT)
				if (p.x > 9)
					p.x -= 4;
				else
					c = _getch();
			else if (status == STATUS::RIGHT)
				if (p.x < 50)
					p.x += 4;
		}
		/*else if (kq == 1 || kq == 0 || kq == -2 || kq == 2);*/

	}

	if (Xac_nhan == 1)
		return -1;
	if (kq == 1)
		return 1;
	if (kq == -2)
		return -2;
	if (kq == 2)
		return 2;
	if (kq == 0)
		return 0;
}

//Đánh dấu "X" hoặc "O"
void Danh_dau(POSITION& position, char mang[][25], P p, TIMES& times, int d)
{
	gotoxy(p.x, p.y);
	if (d == 1)
	{

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "X";
		mang[p.x][p.y] = 'X';
		Display_innings_O();
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "O";
		mang[p.x][p.y] = 'O';
		Display_innings_X();
	}

	if (d == 1)
	{
		position.X[times.X].x = p.x;
		position.X[times.X++].y = p.y;
	}
	else
	{
		position.O[times.O].x = p.x;
		position.O[times.O++].y = p.y;
	}

	Times_X_O(times);
}

//Xử lý thắng - thua - hòa
int WhoWin(char mang[][25], P p, int& kt, TIMES times)
{
	int count, m, n, q, r, v, x, y, w, z, t, u;

	//Xét "X" thắng
	if (mang[p.x][p.y] == 'X')
	{
		//Xét theo chiều ngang
		for (int i = 9; i < 38; i += 4)
		{
			count = 0;
			for (int j = i; j <= i + 4 * 4; j += 4)
				if (mang[j][p.y] == 'X')
				{
					count++;
					if (count == 5)
					{
						X_win();
						kt = 1;
					}
				}
		}

		//Xét theo chiều dọc
		for (int i = 2; i < 40; i += 2)
		{
			count = 0;
			for (int j = i; j <= i + 2 * 4; j += 2)
				if (mang[p.x][j] == 'X')
				{
					count++;
					if (count == 5)
					{
						X_win();
						kt = 1;
					}
				}
		}

		//Xét theo chiều xiên xuống dưới
		Vi_tri_goc_trai_xien_duoi(u, v, p);

		Vi_tri_goc_tren_xien_duoi(x, y, p);

		m = u, n = v, q = v;

		for (int i = u; i <= x - 4 * 4; i += 4)
		{
			count = 0;
			for (int p = i; p <= i + 4 * 4; p += 4)
			{
				if (mang[p][n] == 'X')
				{
					count++;
					if (count == 5)
					{
						X_win();
						kt = 1;
					}
				}
				n += 2;
			}

			q += 2;
			n = q;
		}

		//Xét theo chiều xiên lên trên
		Vi_tri_goc_trai_xien_len(r, t, p);

		Vi_tri_goc_tren_xien_len(w, z, p);

		m = r, n = t, q = t;

		for (int i = r; i <= w - 4 * 4; i += 4)
		{
			count = 0;
			for (int p = i; p <= i + 4 * 4; p += 4)
			{
				if (mang[p][n] == 'X')
				{
					count++;
					if (count == 5)
					{
						X_win();
						kt = 1;
					}
				}
				n -= 2;
			}

			q -= 2;
			n = q;
		}

		//Xét trường hợp hòa
		if (times.X == 72 && times.O == 72)
		{
			Draw();
			kt = -2;
		}
	}
	else			//Xét "O" thắng
	{
		//Xét theo chiều ngang
		for (int i = 9; i < 38; i += 4)
		{
			count = 0;
			for (int j = i; j <= i + 4 * 4; j += 4)
				if (mang[j][p.y] == 'O')
				{
					count++;
					if (count == 5)
					{
						O_win();
						kt = 2;
					}
				}
		}

		//Xét theo chiều dọc
		for (int i = 2; i < 40; i += 2)
		{
			count = 0;
			for (int j = i; j <= i + 2 * 4; j += 2)
				if (mang[p.x][j] == 'O')
				{
					count++;
					if (count == 5)
					{
						O_win();
						kt = 2;
					}
				}
		}

		//Xét theo chiều xiên xuống dưới
		Vi_tri_goc_trai_xien_duoi(u, v, p);

		Vi_tri_goc_tren_xien_duoi(x, y, p);

		m = u, n = v, q = v;

		for (int i = u; i <= x - 4 * 4; i += 4)
		{
			count = 0;
			for (int p = i; p <= i + 4 * 4; p += 4)
			{
				if (mang[p][n] == 'O')
				{
					count++;
					if (count == 5)
					{
						O_win();
						kt = 2;
					}
				}
				n += 2;
			}

			q += 2;
			n = q;
		}

		//Xét theo chiều xiên lên trên
		Vi_tri_goc_trai_xien_len(r, t, p);

		Vi_tri_goc_tren_xien_len(w, z, p);

		m = r, n = t, q = t;

		for (int i = r; i <= w - 4 * 4; i += 4)
		{
			count = 0;
			for (int p = i; p <= i + 4 * 4; p += 4)
			{
				if (mang[p][n] == 'O')
				{
					count++;
					if (count == 5)
					{
						O_win();
						kt = 2;
					}
				}
				n -= 2;
			}

			q -= 2;
			n = q;
		}

		//Xét trường hợp hòa
		if (times.X == 72 && times.O == 72)
		{
			Draw();
			kt = -2;
		}
	}
	return kt;
}

//Tìm vị trí gốc bên trái xiên xuống - phần trái
void Vi_tri_goc_trai_xien_duoi(int& u, int& v, P p)
{
	u = p.x;
	v = p.y;
	for (; u > 9 && v > 2; u -= 4)
		v -= 2;
	/*cout << "u = " << u << ", v = " << v << endl;*/
}

//Tìm vị trí gốc bên trái xiên xuống - phần trên
void Vi_tri_goc_tren_xien_duoi(int& x, int& y, P p)
{
	x = p.x;
	y = p.y;
	for (; y < 24 && x < 53; y += 2)
		x += 4;
	/*cout << "x = " << x << ", y = " << y << endl;*/
}

//Tìm vị trí gốc bên trái xiên lên - phần trái
void Vi_tri_goc_trai_xien_len(int& r, int& t, P p)
{
	r = p.x;
	t = p.y;
	for (; r > 9 && t < 24; r -= 4)
		t += 2;
	/*cout << "r = " << r << ", t = " << t << endl;*/
}

//Tìm vị trí gốc bên trái xiên lên - phần trên
void Vi_tri_goc_tren_xien_len(int& w, int& z, P p)
{
	w = p.x;
	z = p.y;
	for (; w < 53 && z > 2; w += 4)
		z -= 2;
	/*cout << "w = " << w << ", z = " << z << endl;*/
}

//Kiểm tra đã đánh dấu vào vị trí h, k chưa
int Kiem_tra(POSITION position, P p, TIMES times)
{
	int max = times.X > times.O ? times.X : times.O;
	for (int i = 0; i < max; i++)
	{
		if ((p.x == position.X[i].x && p.y == position.X[i].y) || (p.x == position.O[i].x && p.y == position.O[i].y))
			return 1;
	}
	return 0;
}

//--------------------------------------------------------------------------------------------------------------
//Đặt lại dữ liệu

void Reset_Data(char mang[][25], POSITION& position, TIMES& times, int& kq, int& kt, int& d, int& a5, P& p)
{
	for (int i = 9; i <= 53; i += 4)
		for (int j = 2; j <= 24; j += 2)
			mang[i][j] = 'N';

	for (int i = 0; i < 72; i++)
	{
		position.X[i].x = position.X[i].y = position.O[i].x = position.O[i].y = 0;
	}

	times.X = times.O = 0;
	kq = 0;
	if (kt == 1)
		d = 0;
	else if (kt == 2)
		d = 1;
	kt = 0;
	a5 = 0;
	p.x = 9;
	p.y = 2;
}

void Reset_All_Data(char mang[][25], POSITION& position, TIMES& times, int& kq, int& kt, int& d, int& a5, SCORE& score, P& p)
{
	for (int i = 9; i <= 53; i += 4)
		for (int j = 2; j <= 24; j += 2)
			mang[i][j] = 'N';

	for (int i = 0; i < 200; i++)
	{
		position.X[i].x = position.X[i].y = position.O[i].x = position.O[i].y = 0;
	}

	times.X = times.O = 0;
	kq = 0;
	d = 1;
	kt = 0;
	a5 = 0;
	score.X = 0;
	score.O = 0;
	p.x = 9;
	p.y = 2;
}

//--------------------------------------------------------------------------------------------------------------
//Lưu game

void Save(TIMES times, POSITION position, SCORE score, int d, P p)
{
	fstream f;
	string address;

	while (1)
	{
		address = Display_save_game();
		f.open(address, ios::out);
		if (f.fail())
		{
			cout << "File doesn't exitst !" << endl;
			cout << "Input file name: ";
			cin.ignore();
		}
		else
			break;
	}

	//Lưu số lần đánh của X và của O
	f << times.X << " " << times.O;

	f << "\n\n";

	//Lưu các tọa độ đã đánh của X
	for (int i = 0; i < times.X; i++)
	{
		f << position.X[i].x << " " << position.X[i].y << endl;
	}

	f << "\n\n";

	//Lưu các tọa độ đã đánh của O
	for (int i = 0; i < times.O; i++)
	{
		f << position.O[i].x << " " << position.O[i].y << endl;
	}

	f << "\n\n";

	//Lưu tới lượt X hoặc O
	f << d;

	f << "\n\n";

	//Lưu tỉ số X - O
	f << score.X << " " << score.O;

	f << "\n\n";

	//Lấy vị trí cuối cùng

	f << p.x << " " << p.y;
}

void Play_continue(char mang[][25], TIMES& times, POSITION& position, SCORE& score, int& d, P& p)
{
	fstream f;
	string address;

	while (1)
	{
		address = Display_play_continue();
		f.open(address, ios::in);
		if (f.fail())
		{
			cout << "File doesn't exitst !" << endl;
			cout << "Input file name: ";
			_flushall();
		}
		else
			break;
	}

	//Lấy tống số nước của X - O
	f >> times.X >> times.O;

	/*Lấy các vị trí của X*/
	for (int i = 0; i < times.X; i++)
		f >> position.X[i].x >> position.X[i].y;

	//Lấy các vị trí của o
	for (int i = 0; i < times.O; i++)
		f >> position.O[i].x >> position.O[i].y;

	//Lấy lượt của X hoặc O
	f >> d;

	//Lấy tỉ số X - O
	f >> score.X >> score.O;

	//Lấy vị trí cuối cùng
	f >> p.x >> p.y;
}
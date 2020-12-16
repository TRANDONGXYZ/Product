#include "function.h"

//Tính toán ngày tháng năm-------------------------------------------------------------------------------------------------

//Khởi tạo bộ lịch
int*** Alloc()
{
	int*** Calander = new int** [n_Month];
	for (int i = 0; i < n_Month; i++)
		Calander[i] = new int* [n_Row];
	for (int i = 0; i < n_Month; i++)
		for (int j = 0; j < n_Row; j++)
			Calander[i][j] = new int[n_Col];

	for (int i = 0; i < n_Month; i++)
		for (int j = 0; j < n_Row; j++)
			memset(Calander[i][j], 0, n_Col * sizeof(int));

	return Calander;
}

//Tính toán số ngày trong tháng
int Day_of_month(int month, int year)
{
	int n_Day_of_month = 0;

	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		n_Day_of_month = 31;
		break;
	case 4: case 6: case 9: case 11:
		n_Day_of_month = 30;
		break;
	case 2:
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
			n_Day_of_month = 29;
		else
			n_Day_of_month = 28;

		break;
	}

	return n_Day_of_month;
}

//Tính toán thứ
void XepLich(int***& Calander, int year, int day, int month)
{
	int JMD, start_pos, n_Day_of_month = 0;

	for (int r = 0; r < n_Month; r++)
	{
		if (month > 1)
		{
			if (day - 1 < n_Day_of_month)
			{
				start_pos = 0;

				JMD = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
					(365 * (year + 4800 - ((14 - month) / 12))) +
					((year + 4800 - ((14 - month) / 12)) / 4) -
					((year + 4800 - ((14 - month) / 12)) / 100) +
					((year + 4800 - ((14 - month) / 12)) / 400) - 32045) % 7 + 2;

				for (int k = start_pos; day <= n_Day_of_month; k++)
				{
					Calander[r][0][k] = day;
					day++;
				}
			}
		}

		day = 1;
		n_Day_of_month = Day_of_month(month, year);

		JMD = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
			(365 * (year + 4800 - ((14 - month) / 12))) +
			((year + 4800 - ((14 - month) / 12)) / 4) -
			((year + 4800 - ((14 - month) / 12)) / 100) +
			((year + 4800 - ((14 - month) / 12)) / 400) - 32045) % 7 + 2;

		start_pos = JMD - 1;
		if (start_pos == 7)
			start_pos = 0;

		for (int j = start_pos; j < n_Col; j++)
		{
			Calander[r][0][j] = day;
			day++;
		}

		for (int i = 1; i < n_Row && day <= n_Day_of_month; i++)
		{
			for (int j = 0; j < n_Col && day <= n_Day_of_month; j++)
			{
				Calander[r][i][j] = day;
				day++;
			}
		}

		month++;
	}
}

//Chạy bộ lịch
void Lich()
{
	system("cls");

	int*** Calander;
	int year = 2020;

	Calander = Alloc();
	XepLich(Calander, year);
	WeekDay(Calander);
	Delete(Calander);
	cout << endl << endl;
}

//Xóa không gian lưu trữ bộ lịch sau khi xuất
void Delete(int***& Calander)
{
	for (int i = 0; i < n_Month; i++)
		for (int j = 0; j < n_Row; j++)
			delete[] Calander[i][j];

	delete[] Calander;
	Calander = NULL;
}

//Di chuyển----------------------------------------------------------------------------------------------------------------

//Di chuyển con trỏ vị trí
void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//Xử lý nhập lựa chọn----------------------------------------------------------------------------------------------------------

int Selection()
{
	char c;
	int x = 1, y = 2;

	while (1)
	{
		c = _getch();

		if (c == -32)
		{
			c = _getch();

			if (c == 72)	//Di chuyển lên
			{
				Xoa_dau_mui_ten_menu(x, y);
				TraMauMenu(y);
				y--;
				if (y == 1)
					y = 4;
				Dau_mui_ten_menu(x, y);
				GhiLaiMenu(y);
			}
			else if (c == 80)	//Di chuyển xuống
			{
				Xoa_dau_mui_ten_menu(x, y);
				TraMauMenu(y);
				y++;
				if (y == 5)
					y = 2;
				Dau_mui_ten_menu(x, y);
				GhiLaiMenu(y);
			}
		}
		else if (c == 13)
			break;
	}

	return y;
}

int SelectionOut()
{
	char c;
	int x = 5;

	Xoa_dau_mui_ten_menu(1, 4);
	while (1)
	{
		c = _getch();

		if (c == -32)
		{
			c = _getch();

			if (c == 75)
			{
				if (x == 15)
					x = 5;
				TraMauOut(15);
				GhiLaiOut(x);
			}
			else if (c == 77)
			{
				if (x == 5)
					x = 15;
				TraMauOut(5);
				GhiLaiOut(x);
			}
		}
		else if (c == 13)
			break;
	}

	return x;
}

int Selection_Calander()
{
	char c;

	while (1)
	{
		c = _getch();

		if (c == 'B' || c == 'b')
			return 1;
		else if (c == 'C' || c == 'c')
			return 2;
	}
}

//Giao diện--------------------------------------------------------------------------------------------------------------------

//In bộ lịch
void WeekDay(int*** Calander)
{
	string months[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	cout << endl << "   <--- Back" << endl;
	gotoxy(107, 1);
	cout << "Clock --->" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 0; i < 4; i++)
		cout << endl;

	for (int i = 0; i < n_Month; i++)
	{
		for (int i = 0; i < 56; i++)
			cout << " ";

		cout << "   " << months[i + 1] << endl << endl;
		cout << "           Sun             Mon             Tue             Wes             Thu             Fri             Sat" << endl;
		for (int j = 0; j < n_Row; j++)
		{
			for (int r = 0; r < n_Col; r++)
				if (Calander[i][j][r] != 0)
					cout << right << setw(13) << Calander[i][j][r] << "   ";
				else
					for (int i = 0; i < 16; i++)
						cout << " ";

			cout << endl << endl;
		}
		cout << endl << endl;
	}
}

void TraMauOut(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(x, 8);

	switch (x)
	{
	case 5:
		cout << "Yes" << endl;
		break;
	case 15:
		cout << "No" << endl;
	}
}

void TraMauMenu(int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(5, y);

	switch (y)
	{
	case 2:
		cout << "Watch" << endl;
		break;
	case 3:
		cout << "Calander" << endl;
		break;
	case 4:
		cout << "Exit" << endl;
	}
}

void GhiLaiMenu(int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	gotoxy(5, y);

	switch (y)
	{
	case 2:
		cout << "Watch" << endl;
		break;
	case 3:
		cout << "Calander" << endl;
		break;
	case 4:
		cout << "Exit" << endl;
	}
}

void GhiLaiOut(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	gotoxy(x, 8);

	switch (x)
	{
	case 5:
		cout << "Yes" << endl;
		break;
	case 15:
		cout << "No" << endl;
	}
}

//Giao diện màn hình chính
int Display()
{
	system("cls");
	int x = 5, y = 1, selection;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(x, y);
	cout << "TIME" << endl;
	gotoxy(x, y + 1);
	Dau_mui_ten_menu(x - 4, y + 1);
	cout << "Watch" << endl;
	gotoxy(x, y + 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Calander" << endl;
	gotoxy(x, y + 3);
	cout << "Exit" << endl;

	//Nhap lua chon
	selection = Selection();
	return selection;
}

//Dấu mũi tên trong menu
void Dau_mui_ten_menu(int h, int k)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED/*_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY*/);
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

void DeleteNumber(int x, int y)
{
	int Y = y + 10, X = x + 11;
	for (int i = y; i < Y; i++)
		for (int j = x; j < X; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
}

void So(int n, int x, int y)
{
	switch (n)
	{
	case 0:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "===========" << endl;
		gotoxy(x, y + 1);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 2);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 3);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 4);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 5);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 6);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 7);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 8);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 9);
		cout << "===========" << endl;
		break;
	case 1:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "          =" << endl;
		gotoxy(x, y + 1);
		cout << "        = =" << endl;
		gotoxy(x, y + 2);
		cout << "      = = =" << endl;
		gotoxy(x, y + 3);
		cout << "    = = = =" << endl;
		gotoxy(x, y + 4);
		cout << "  = =   = =" << endl;
		gotoxy(x, y + 5);
		cout << "        = =" << endl;
		gotoxy(x, y + 6);
		cout << "        = =" << endl;
		gotoxy(x, y + 7);
		cout << "        = =" << endl;
		gotoxy(x, y + 8);
		cout << "        = =" << endl;
		gotoxy(x, y + 9);
		cout << "        = =" << endl;
		break;
	case 2:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "===========" << endl;
		gotoxy(x, y + 1);
		cout << "========= =" << endl;
		gotoxy(x, y + 2);
		cout << "        = =" << endl;
		gotoxy(x, y + 3);
		cout << "        = =" << endl;
		gotoxy(x, y + 4);
		cout << "========= =" << endl;
		gotoxy(x, y + 5);
		cout << "= =========" << endl;
		gotoxy(x, y + 6);
		cout << "= =" << endl;
		gotoxy(x, y + 7);
		cout << "= =" << endl;
		gotoxy(x, y + 8);
		cout << "= =========" << endl;
		gotoxy(x, y + 9);
		cout << "===========" << endl;
		break;
	case 3:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "===========" << endl;
		gotoxy(x, y + 1);
		cout << "========= =" << endl;
		gotoxy(x, y + 2);
		cout << "        = =" << endl;
		gotoxy(x, y + 3);
		cout << "        = =" << endl;
		gotoxy(x, y + 4);
		cout << "========= =" << endl;
		gotoxy(x, y + 5);
		cout << "========= =" << endl;
		gotoxy(x, y + 6);
		cout << "        = =" << endl;
		gotoxy(x, y + 7);
		cout << "        = =" << endl;
		gotoxy(x, y + 8);
		cout << "========= =" << endl;
		gotoxy(x, y + 9);
		cout << "===========" << endl;
		break;
	case 4:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "= =        " << endl;
		gotoxy(x, y + 1);
		cout << "= =        " << endl;
		gotoxy(x, y + 2);
		cout << "= =        " << endl;
		gotoxy(x, y + 3);
		cout << "= =        " << endl;
		gotoxy(x, y + 4);
		cout << "= =    = = " << endl;
		gotoxy(x, y + 5);
		cout << "= =    = = " << endl;
		gotoxy(x, y + 6);
		cout << "= =========" << endl;
		gotoxy(x, y + 7);
		cout << "===========" << endl;
		gotoxy(x, y + 8);
		cout << "       = = " << endl;
		gotoxy(x, y + 9);
		cout << "       = = " << endl;
		break;
	case 5:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "===========" << endl;
		gotoxy(x, y + 1);
		cout << "= =========" << endl;
		gotoxy(x, y + 2);
		cout << "= =" << endl;
		gotoxy(x, y + 3);
		cout << "= =" << endl;
		gotoxy(x, y + 4);
		cout << "= =========" << endl;
		gotoxy(x, y + 5);
		cout << "= ====== ==" << endl;
		gotoxy(x, y + 6);
		cout << "        = =" << endl;
		gotoxy(x, y + 7);
		cout << "        = =" << endl;
		gotoxy(x, y + 8);
		cout << "========= =" << endl;
		gotoxy(x, y + 9);
		cout << "===========" << endl;
		break;
	case 6:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "===========" << endl;
		gotoxy(x, y + 1);
		cout << "= =========" << endl;
		gotoxy(x, y + 2);
		cout << "= =" << endl;
		gotoxy(x, y + 3);
		cout << "= =" << endl;
		gotoxy(x, y + 4);
		cout << "= =========" << endl;
		gotoxy(x, y + 5);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 6);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 7);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 8);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 9);
		cout << "===========" << endl;
		break;
	case 7:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "===========" << endl;
		gotoxy(x, y + 1);
		cout << "========= =" << endl;
		gotoxy(x, y + 2);
		cout << "        = =" << endl;
		gotoxy(x, y + 3);
		cout << "        = =" << endl;
		gotoxy(x, y + 4);
		cout << "        = =" << endl;
		gotoxy(x, y + 5);
		cout << "        = =" << endl;
		gotoxy(x, y + 6);
		cout << "        = =" << endl;
		gotoxy(x, y + 7);
		cout << "        = =" << endl;
		gotoxy(x, y + 8);
		cout << "        = =" << endl;
		gotoxy(x, y + 9);
		cout << "        = =" << endl;
		break;
	case 8:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "===========" << endl;
		gotoxy(x, y + 1);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 2);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 3);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 4);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 5);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 6);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 7);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 8);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 9);
		cout << "===========" << endl;
		break;
	case 9:
		DeleteNumber(x, y);
		gotoxy(x, y);
		cout << "===========" << endl;
		gotoxy(x, y + 1);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 2);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 3);
		cout << "= =     = =" << endl;
		gotoxy(x, y + 4);
		cout << "= ======= =" << endl;
		gotoxy(x, y + 5);
		cout << "========= =" << endl;
		gotoxy(x, y + 6);
		cout << "        = =" << endl;
		gotoxy(x, y + 7);
		cout << "        = =" << endl;
		gotoxy(x, y + 8);
		cout << "========= =" << endl;
		gotoxy(x, y + 9);
		cout << "===========" << endl;
	}
}

void Dau_hai_cham(int x, int y)
{
	gotoxy(x, y);
	cout << "O" << endl;
	gotoxy(x, y + 3);
	cout << "O" << endl;
}

int Number(string weekday_month, int date, int year, int hour, int minute, int second)
{
	int giay_truoc, giay_sau, phut_truoc, phut_sau, gio_truoc, gio_sau, x = 89, y = 6;
	char c;

	giay_truoc = second / 10;
	giay_sau = second % 10;

	phut_truoc = minute / 10;
	phut_sau = minute % 10;

	gio_truoc = hour / 10;
	gio_sau = hour % 10;

	So(gio_truoc, 9, 6);
	So(gio_sau, 23, 6);
	Dau_hai_cham(41, 9);
	So(phut_truoc, 49, 6);
	So(phut_sau, 63, 6);
	Dau_hai_cham(81, 9);
	So(giay_truoc, x, y);

	gotoxy(55, 18);
	cout << weekday_month << " " << date << " " << year;

	x = 103;

	for (int i = giay_sau; i < 10; i++)
	{
		if (_kbhit())
		{
			c = _getch();
			if (c == 'B' || c == 'b')
				return 1;
			else if (c == 'C' || c == 'c')
				return 2;
		}
		So(i, x, y);
		Sleep(1000);
	}

	return 0;
}

int Watch()
{
	system("cls");

	cout << endl << "   <--- Back" << endl;
	gotoxy(104, 1);
	cout << "Calander --->" << endl;

	string weekday_month = "";
	time_t thoi_gian;
	tm* t;
	char* c;
	int i;

	while (1)
	{
		thoi_gian = time(NULL);
		t = localtime(&thoi_gian);
		for (int i = 0; i < 7; i++)
			weekday_month = chtostr(asctime(t));

		i = Number(weekday_month, t->tm_mday, 1900 + t->tm_year, t->tm_hour, t->tm_min, t->tm_sec);

		if (i != 0)
			break;
	}

	return i;
}

//Cố định cửa sổ Console
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

//Ẩn con trỏ chuột trong màn hình Console
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

int Ask()
{
	int x = 5, y = 7, selection;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(x, y);
	cout << "Do you want to exit?" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	gotoxy(x, y + 1);
	cout << "Yes";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(x + 10, y + 1);
	cout << "No" << endl;

	selection = SelectionOut();

	if (selection == 5)
		return 5;
	else
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 15; j++)
			{
				gotoxy(j + 5, i + 7);
				cout << " ";
			}
		return 10;
	}
}

//Trích xuất thông tin-----------------------------------------------------------------------------------------------------

//Trích xuất năm trong chuỗi thời gian
int ExtractYear(string time)
{
	int nam;
	string year = time.substr(time.length() - 5, 4);
	nam = atoi(year.c_str());
	return nam;
}

//Chuyển đổi kiểu dữ liệu--------------------------------------------------------------------------------------------------
string chtostr(char* time)
{
	string thoi_gian = "";
	int n = 0;

	while (n < 8)
	{
		thoi_gian += time[n];
		n++;
	}

	return thoi_gian;
}
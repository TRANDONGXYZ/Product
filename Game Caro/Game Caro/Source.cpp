#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <windows.h>
#include <conio.h>

#include "function.h"

using namespace std;

//Width Console = 122
//Height Console = 30

int main()
{
	int kt = 0, kq = 0, d = 1;

	P p;
	SCORE score;
	POSITION position;
	TIMES times;
	char mang[54][25];

	p.x = 9;
	p.y = 2;

	score.X = score.O = 0;
	times.X = times.O = 0;

	position.X[0].x = 9;
	position.X[0].y = 2;

	SetConsoleTitleA("DAI HOC KHOA HOC TU NHIEN - 19CLC8 - NHOM 1");
	FixConsoleWindow();

	int a1, a2, a3, a4, a5 = 0;

New_game:;
	Display_new_game();
	goto Selection;
Selection:;
	a1 = Selection_1();

	if (a1 == 1)
		goto Load;
	else if (a1 == 2)
		goto Guide;
	else if (a1 == 3)
		goto Load_continue;
Save:;
	Save(times, position, score, d, p);
	goto Play_game;
Display:;
	Display_table();
	Display_khung();
	Display_score(score);
	if (d == 1)
		Display_innings_X();
	else
		Display_innings_O();
	Times_X_O(times);
	goto Play_game;
Load_continue:;
	Play_continue(mang, times, position, score, d, p);
	system("cls");
	Display_table();
	Display_khung();
	Display_score(score);
	if (d == 1)
		Display_innings_X();
	else
		Display_innings_O();
	Danh_lai(mang, times, position, p);
	Times_X_O(times);
	goto Play_game;
Guide:;
	system("cls");
	a3 = Guide();
	if (a3 == 1)
		goto New_game;
	else
	{
		system("cls");
		goto Load;
	}
Play_game:;
	while (a5 == 0 || a5 == 3)
	{
		a5 = Move(position, mang, p, times, kq, d, kt);
		if (a5 == 3)
			break;
	}
	if (a5 == 3)
		goto Save;
	if (a5 == -1)
		goto End;
	if (a5 == 1)
	{
		score.X++;
		Display_score(score);
	}
	if (a5 == 2)
	{
		score.O++;
		Display_score(score);
	}
	goto Play_again;
Play_again:;
	a4 = AskContinue();
	if (a4 == 1) {
		goto Reset;
	}
	else {
		goto End;
	}
Reset:;
	Reset_Data(mang, position, times, kq, kt, d, a5, p);
	goto Load;
Load:;
	Load_game();
	goto Display;
End:;
	system("cls");
	Reset_All_Data(mang, position, times, kq, kt, d, a5, score, p);
	goto New_game;
}
#pragma once

#include <iostream>
#include <iomanip>
#include <memory.h>
#include <string>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

#define n_Month 12
#define n_Col 7
#define n_Row 5

//int*** Alloc();
//void WeekDay(int*** Calander);
//void XepLich(int***& Calander, int year, int day = 1, int month = 1);
//void Lich(int***& Calander, int& year);
//string chtostr(char* time);
//int ExtractYear(string time);
//void Delete(int***& Calander);

//Tính toán ngày tháng năm-------------------------------------------------------------------------------------------------

//Khởi tạo bộ lịch
int*** Alloc();

//Tính toán số ngày trong tháng
int Day_of_month(int month, int year);

//Tính toán thứ
void XepLich(int***& Calander, int year, int day = 1, int month = 1);

//Chạy bộ lịch
void Lich();

//Xóa không gian lưu trữ bộ lịch sau khi xuất
void Delete(int***& Calander);

//Xử lý nhập lựa chọn----------------------------------------------------------------------------------------------------------

int Selection();
int SelectionOut();
int Selection_Calander();

//Di chuyển----------------------------------------------------------------------------------------------------------------

//Di chuyển con trỏ vị trí
void gotoxy(short x, short y);

//Giao diện----------------------------------------------------------------------------------------------------------------

//In bộ lịch
void WeekDay(int*** Calander);

//Giao diện màn hình chính
int Display();

//Dấu mũi tên trong menu
void Dau_mui_ten_menu(int h, int k);

//Xóa dấu mũi tên trong menu
void Xoa_dau_mui_ten_menu(int h, int k);

void TraMauMenu(int y);
void TraMauOut(int x);
void GhiLaiMenu(int y);
void GhiLaiOut(int x);
int Watch();
void So(int n, int x, int y);
void Dau_hai_cham(int x, int y);
int Number(string weekday_month, int date, int year, int hour, int minute, int second);

//Cố định cửa sổ Console
void FixConsoleWindow();
void Nocursortype();

int Ask();

//Trích xuất thông tin-----------------------------------------------------------------------------------------------------

//Trích xuất năm trong chuỗi thời gian
int ExtractYear(string time);

//Chuyển đổi kiểu dữ liệu--------------------------------------------------------------------------------------------------

//Chuyển đổi kiểu char* sang kiểu string
string chtostr(char* time);
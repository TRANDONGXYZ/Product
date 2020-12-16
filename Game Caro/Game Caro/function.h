#pragma once

#pragma comment(lib, "winmm.lib")

using namespace std;

struct P
{
	int x, y;
};

struct POSITION
{
	P X[72];
	P O[72];
};

struct SCORE
{
	int X, O;
};

struct TIMES
{
	int X, O;
};

//FIX WINDOW
void FixConsoleWindow();

//----------------------------------------------------------------------------------------------------------------------
//Function: gotoxy

void gotoxy(short x, short y);
void gotoxy1(short x, short y);

//----------------------------------------------------------------------------------------------------------------------
//Giao diện

//Hướng dẫn
int Guide(void);

//Màn hình khi mới mở game
void Display_new_game(void);

//Màn hình giao diện bàn cờ
void Display_table(void);

//Màn hình giao diện khung phân cách
void Display_khung(void);

//Giao diện chỉnh âm lượng
void Display_volumn();

//Giao diện X thắng game
void X_win(void);

//Giao diện O thắng game
void O_win(void);

//Giao diện hoà nhau
void Draw();

//Hỏi người dùng có muốn chơi lại không
int AskContinue();

//Xác nhận thoát game
int Quit();

//Tải lại game
void Load_game();

//Dấu mũi tên
void Dau_mui_ten();

//Dấu mũi tên trong menu
void Dau_mui_ten_menu(P p);

//Xóa dấu mũi tên trong menu
void Xoa_dau_mui_ten_menu(P p);

//Xóa màu xanh
void Tra_mau(P p);

//Nổi lựa chọn
void Lua_chon(P p);

//Giao diện tới lượt "O" đánh
void Display_innings_O();

//Giao diện tới lượt "X" đánh
void Display_innings_X();

//Giao diện tỉ số
void Display_score(SCORE score);

//Giao diện lưu game
string Display_save_game();

//Giao diện yêu cầu nhập tên để mở tập tin
string Display_play_continue(void);

//Đánh lại các nước đã đánh
void Danh_lai(char mang[][25], TIMES times, POSITION position, P p);

//Đếm số nước đã đánh của X và O
void Times_X_O(TIMES times);

//----------------------------------------------------------------------------------------------------------------------
//Xử lý nhập lựa chọn

//Xử lý nhập lựa chọn Setting hoặc Play
int Selection_1(void);

//Xử lý nhập lựa chọn trong phần cài đặt

//----------------------------------------------------------------------------------------------------------------------
//Xử lý khi vào chơi game

//Xử lý di chuyển
int Move(POSITION& position, char mang[][25], P& p, TIMES& times, int& kq, int& d, int& kt);

//Xử lý đánh dấu "X" hoặc "O"
void Danh_dau(POSITION& position, char mang[][25], P p, TIMES& times, int d);

//Kiểm tra ô h, k đã được đánh hay chưa
int Kiem_tra(POSITION position, P p, TIMES times);

//Tìm vị trí gốc bên trái xiên xuống - phần trái
void Vi_tri_goc_trai_xien_duoi(int& u, int& v, P p);

//Tìm vị trí gốc bên trái xiên xuống - phần trên
void Vi_tri_goc_tren_xien_duoi(int& x, int& y, P p);

//Tìm vị trí gốc bên trái xiên lên - phần trái
void Vi_tri_goc_trai_xien_len(int& w, int& z, P p);

//Tìm vị trí gốc bên trái xiên lên - phần trên
void Vi_tri_goc_tren_xien_len(int& w, int& z, P p);

//Xử lý thắng - thua - hòa
int WhoWin(char mang[][25], P p, int& kt, TIMES times);

//----------------------------------------------------------------------------------------------------------------------
//Đặt lại dữ liệu

void Reset_Data(char mang[][25], POSITION& position, TIMES& times, int& kq, int& kt, int& d, int& a5, P& p);

void Reset_All_Data(char mang[][25], POSITION& position, TIMES& times, int& kq, int& kt, int& d, int& a5, SCORE& score, P& p);

//----------------------------------------------------------------------------------------------------------------------
//Lưu dữ liệu

void Save(TIMES times, POSITION position, SCORE score, int d, P p);

void Play_continue(char mang[][25], TIMES& times, POSITION& position, SCORE& score, int& d, P& p);
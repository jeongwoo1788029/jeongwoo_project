#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//커서 좌표 함수
void xy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서 정보(상태) 관리 함수
void Cursor(bool flag)//일시정지 시 커서 깜빡임
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = flag;//true : 깜빡임, false : 안깜빡임
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//일시정지 함수
void Pause(int x, int y) {
    if (_kbhit() && _getch() == 32) {//스페이스바 아스키코드 값 : 32
        xy(x, y);
        Cursor(true);
        if (_getch() == 32) {
            Cursor(false);
        }
        else {
            _getch();
        }
    }
}

// **커서가 움직이는 부분**
void Loop(int width, int length, int speed) {
    int x = 0;//x좌표
    int y = 0;//y좌표
    int num = 0;//switch문 제어
    int count = 0;//방향 관리 및 이동
    int sign = 1;//부호 관리 및 이동

    //커서 off
    Cursor(false);

    //루프 부분
    while (length > 0 && width > 0) {

        Pause(x, y);//일시정지
        Sleep(1000 / speed);//스피드

        //커서 움직임
        switch (num) {
        case 1://세로
            y += sign;
            xy(x, y);
            cout << "1";

            count += 1;
            if (count == length) {
                num = 0;//default로 이동
                width -= 1;
                sign *= -1;//부호 변환
                count = 0;
            }
            break;
        default://가로 
            x += sign;
            xy(x, y);
            cout << "1";

            count += 1;
            if (count == width) {
                num = 1;//case 1로 이동
                length -= 1;
                count = 0;
            }
        }
    }

    //마지막에서 정지!
    xy(x, y);
    Cursor(true);
    _getch();
}

//메인 함수
int main() {
    int width = 0;//가로 길이
    int length = 0;//세로 세로
    int speed = 0;//속도

    //입력
    cin >> width >> length >> speed;

    //콘솔창 지우기
    system("cls");

    //루프(커서가 움직이는 부분)
    Loop(width, length, speed);

    return 0;
}
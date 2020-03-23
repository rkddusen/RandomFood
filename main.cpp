#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<climits>

#define SIZE 100
#define UP 0
#define DOWN 1
#define SPACE 2

using namespace std;

int text_stor(string* text);
int menu();
int keyControl();
void gotoxy(int, int);
void menu_random(string* text, int num);
void menu_change(string* text);
void menu_add(string* text, int count);
void menu_sub(string* text, int count);


void CursorView(char show)//커서숨기기
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int main() {
    CursorView(0);
    ////배열 크기를 정하기 위한 파일 열기
    //ifstream readFile;

    //readFile.open("food.txt");//food.txt open
    //int line = 0;
    //if (readFile.is_open()) {
    //   while (!readFile.eof()) {
    //      string line_str;
    //      getline(readFile, line_str);//한줄씩받아 line_str에 저장
    //      line++;
    //   }

    //   readFile.close();//파일 닫기
    //}
    //else
    //   cout << "파일 없음" << endl;

    //cout << line;
    //
    //string* text = new string[line];
    ////string text[line];//메뉴 저장할 배열

    cout << endl;
    cout << "   ※메뉴 랜덤 프로그램※" << endl;
    cout << endl;
    cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
    cout << "▒                        ▒" << endl;
    cout << "▒     ▶  Start!  ◀     ▒" << endl;
    cout << "▒                        ▒" << endl;
    cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
    if (cin.get() != '\n') {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    system("cls");

    string text[SIZE];//메뉴 저장할 배열
    int num = text_stor(text);//메모장에 저장되어있는 개수
    //int num = 0;
    /*cout << "현재 저장된 메뉴" << endl;
    cout << "====================" << endl;
    for (int i = 0; i < SIZE; i++) {//현재 저장된 메뉴 출력
       cout << i + 1 << " ) " << text[i];
       if (i % 6 == 5) {
          cout << endl;
       }
       else if (text[i] != "\0")
          cout << ", ";

       if (text[i] == "\0") {
          printf("\b\b\b\b\b\b\b      ");
          break;
       }
    }*/

    /*for (int i = 0; i < SIZE; i++) {//현재 저장된 메뉴 출력

       cout << i + 1 << " ) " << text[i];
       if (i % 6 == 5) {
          cout << endl;
       }
       else if (text[i] != "\0")
          cout << ", ";

       if (text[i] == "\0") {
          printf("\b\b\b\b\b\b\b      ");
          break;
       }
    }*/
    int food_num = 0;
    for (int i = 0; i < SIZE; i++) {//현재 저장된 메뉴 출력
        food_num++;
        cout << i + 1 << " ) " << text[i] << endl;
        if (text[i + 1] == "\0") {
            break;
        }

    }

    cout << endl;
    cout << "Press Enter key" << endl;
    if (cin.get() != '\n') {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }

    //cin.get();
    system("cls");

    int menu_num = menu();


    if (menu_num == 1) {
        menu_random(text, food_num);
    }
    else if (menu_num == 2) {
        menu_change(text);
    }

    else if (menu_num == 3) {
        return 0;
    }


    return 0;
}

int text_stor(string* text) {//txt파일에 있는 내용 text배열에 저장
    ifstream readFile;

    readFile.open("food.txt");//food.txt open
    int num = 0;
    if (readFile.is_open()) {
        while (!readFile.eof()) {
            string str;
            getline(readFile, str);//한줄씩받아 str에 저장
            //cout << str << endl;

            text[num] = str;//text배열에 하나씩 저장
            num++;
        }

        readFile.close();//파일 닫기
    }
    text[num] = "\0";

    return num;
}

int keyControl() {
    int temp = _getch();
    //cout << temp;
    if (temp == 72) {//72
        return UP;
    }
    else if (temp == 80) {//80
        return DOWN;
    }
    else if (temp == '\r') {
        return SPACE;
    }
}

void gotoxy(int x, int y) {
    COORD posXY = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}

int menu() {
    system("cls");

    cout << "※목록을 선택하세요." << endl;
    cout << "> 1. 메뉴 랜덤 선택" << endl;
    cout << "  2. 메뉴 수정" << endl;
    cout << "  3. 종료" << endl;
    gotoxy(0, 1);

    //menu선택 숫자로 할 때
    /*int menu_sel;
    cin >> menu_sel;
    cout << menu_sel;
    if (menu_sel != 1 && menu_sel != 2 && menu_sel != 3) {
       cout << "재입력" << endl;
       menu();
    }
    switch (menu_sel)
    {
    case 1:
       menu_random();
       break;
    case 2:
       menu_change();
       break;
    case 3:
       exit;
       break;
    default:
       break;
    }*/
    int x = 0;
    int y = 1;
    int key;
    do {
        key = keyControl();
        switch (key) {
        case UP://화살표 위 눌렀을 때
            if (y > 1) {
                gotoxy(x, y);//그 자리
                cout << " ";//먼저 지우고
                gotoxy(x, --y);//한 칸 위에 올라가기
                cout << ">";
            }
            break;

        case DOWN://화살표 아래 눌렀을 때
            if (y < 3) {
                gotoxy(x, y);//그 자리
                cout << " ";//먼저 지우고
                gotoxy(x, ++y);//한 칸 아래 내려가기
                cout << ">";
            }
            break;

        case SPACE:

            //if (y==1) {//space입력 됐는데 y가 1이었을 때
            //   return 1;
            //}
            //else if (y == 2) {//space입력 됐는데 y가 2이었을 때
            //   return 2;
            //}
            //else if (y == 3) {//space입력 됐는데 y가 3이었을 때
            //   
            //   break;//종료
            //}

            return y;
        }
    } while (key != SPACE);
}

void menu_random(string* text, int num) {//메뉴 선택해주는 함수
    system("cls");
    srand((unsigned int)time(NULL));
    int food_menu = rand() % (num);
    //cout << num << endl;
    //cout << food_menu << endl;

    cout << "    ＊" << endl;
    cout << "   ＊＊" << endl;
    cout << "  ＊＊＊" << endl;
    cout << " ＊＊＊＊" << endl;
    cout << "＊＊＊＊＊" << endl;
    Sleep(700);
    gotoxy(0, 0);
    cout << "    ※";
    Sleep(700);
    gotoxy(0, 1);
    cout << "   ※※";
    Sleep(700);
    gotoxy(0, 2);
    cout << "  ※※※";
    Sleep(700);
    gotoxy(0, 3);
    cout << " ※※※※";
    Sleep(700);
    gotoxy(0, 4);
    cout << "※※※※※";
    Sleep(1000);

    cout << endl;
    cout << endl;
    cout << "오늘의 메뉴는!!" << text[food_menu] << "입니다~~!!!!!!" << endl;
    cout << endl;
    cout << "Press Enter key" << endl;
    if (cin.get() != '\n') {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    system("cls");
    main();
}

void menu_change(string* text) {//메뉴 수정하는 함수
    /*system("cls");

    cout << "현재 저장된 메뉴" << endl;
    cout << "====================" << endl;
    int count = 0;
    for (int i = 0; i < SIZE; i++) {//현재 저장된 메뉴 출력
        count++;
        cout << i + 1 << " ) " << text[i] << endl;
        if (text[i + 1] == "\0") {
            break;
        }

    }
    cout << endl;
    cout << "Press Enter key" << endl;

    if (cin.get() != '\n') {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }*/
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        count++;
        if (text[i + 1] == "\0") {
            break;
        }
    }
    system("cls");
    cout << "※목록을 선택하세요." << endl;
    cout << "> 1. 메뉴 추가" << endl;
    cout << "  2. 메뉴 삭제" << endl;
    cout << "  3. 메인 화면" << endl;
    int x2 = 0;
    int y2 = 1;
    int key2;
    do {
        key2 = keyControl();
        switch (key2) {
        case UP://화살표 위 눌렀을 때
            if (y2 > 1) {
                gotoxy(x2, y2);//그 자리
                cout << " ";//먼저 지우고
                gotoxy(x2, --y2);//한 칸 위에 올라가기
                cout << ">";
            }
            break;

        case DOWN://화살표 아래 눌렀을 때
            if (y2 < 3) {
                gotoxy(x2, y2);//그 자리
                cout << " ";//먼저 지우고
                gotoxy(x2, ++y2);//한 칸 아래 내려가기
                cout << ">";
            }
            break;

        case SPACE:

            if (y2 == 1) {//space입력 됐는데 y가 1이었을 때
               //menu_add(text);
                if (count <= SIZE) {
                    menu_add(text, count);
                }
                else {
                    system("cls");
                    cout << "메뉴의 개수는 50개를 넘길 수 없습니다." << endl;
                    /*cout << "Press Enter key" << endl;
                    cin.get();*/
                    menu_change(text);
                }
            }
            else if (y2 == 2) {//space입력 됐는데 y가 2이었을 때
                menu_sub(text, count);
            }
            else if (y2 == 3) {//space입력 됐는데 y가 3이었을 때
                system("cls");
                main();
            }
        }
    } while (key2 != SPACE);
}

void menu_add(string* text, int count) {

    string admenu;
    system("cls");
    cout << "추가할 메뉴를 입력하세요(뒤로 가기 -> q)" << endl;
    cin >> admenu;

    if (!admenu.compare("q") || !admenu.compare("Q")) {//뒤로가기
        if (cin.get() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        menu_change(text);
    }

    ofstream out("food.txt");
    for (int i = 0; i < count; i++) {
        out << text[i] << endl;
    }
    out << admenu << endl;
    out.close();
    text[count] = admenu;
    cout << "추가 되었습니다" << endl;
    cout << "Press Enter key" << endl;
    cin.get();
    menu_change(text);
}
void menu_sub(string* text, int count) {
    system("cls");
    cout << "현재 저장된 메뉴" << endl;
    cout << "====================" << endl;
    for (int i = 0; i < SIZE; i++) {//현재 저장된 메뉴 출력

        cout << i + 1 << " ) " << text[i] << endl;
        if (text[i + 1] == "\0") {
            break;
        }
    }
    cout << endl;
    //cout << "삭제할 메뉴의 번호를 입력하세요" << endl;
    //int del;
    //cin >> del;
    //if (1 <= del && del <= count) {
    //   for (int i = del - 1; i < count; i++) {
    //      text[i] = text[i + 1];
    //   }
    //   text[count - 1] = "\0";
    //   /*string text_sub[SIZE];
    //   for (int i = 0; i < count - 1; i++) {
    //      text_sub[i] = text[i];
    //   }*/
    //}
    string del_s;
    string del_s2;
    cout << "삭제할 메뉴의 번호를 입력하세요.(뒤로 가기 -> q)" << endl;
    cin >> del_s;

    if (!del_s.compare("q") || !del_s.compare("Q")) {//뒤로가기
        if (cin.get() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        menu_change(text);
    }

    int del = atoi(del_s.c_str());
    del_s2 = to_string(del);
    while (1 > del || del > count || (del_s.size() != del_s2.size())) {
        cout << "다시 입력하세요." << endl;
        cout << "삭제할 메뉴의 번호를 입력하세요." << endl;
        cin >> del_s;
        del = atoi(del_s.c_str());
    }
    for (int i = del - 1; i < count; i++) {
        text[i] = text[i + 1];
    }
    text[count - 1] = "\0";

    ofstream out("food.txt");
    for (int i = 0; i < count; i++) {
        out << text[i] << endl;
    }

    cout << "Press Enter key" << endl;
    cin.get();
    menu_change(text);
}
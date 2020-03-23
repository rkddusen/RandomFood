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


void CursorView(char show)//Ŀ�������
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
    ////�迭 ũ�⸦ ���ϱ� ���� ���� ����
    //ifstream readFile;

    //readFile.open("food.txt");//food.txt open
    //int line = 0;
    //if (readFile.is_open()) {
    //   while (!readFile.eof()) {
    //      string line_str;
    //      getline(readFile, line_str);//���پ��޾� line_str�� ����
    //      line++;
    //   }

    //   readFile.close();//���� �ݱ�
    //}
    //else
    //   cout << "���� ����" << endl;

    //cout << line;
    //
    //string* text = new string[line];
    ////string text[line];//�޴� ������ �迭

    cout << endl;
    cout << "   �ظ޴� ���� ���α׷���" << endl;
    cout << endl;
    cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
    cout << "��                        ��" << endl;
    cout << "��     ��  Start!  ��     ��" << endl;
    cout << "��                        ��" << endl;
    cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
    if (cin.get() != '\n') {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    system("cls");

    string text[SIZE];//�޴� ������ �迭
    int num = text_stor(text);//�޸��忡 ����Ǿ��ִ� ����
    //int num = 0;
    /*cout << "���� ����� �޴�" << endl;
    cout << "====================" << endl;
    for (int i = 0; i < SIZE; i++) {//���� ����� �޴� ���
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

    /*for (int i = 0; i < SIZE; i++) {//���� ����� �޴� ���

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
    for (int i = 0; i < SIZE; i++) {//���� ����� �޴� ���
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

int text_stor(string* text) {//txt���Ͽ� �ִ� ���� text�迭�� ����
    ifstream readFile;

    readFile.open("food.txt");//food.txt open
    int num = 0;
    if (readFile.is_open()) {
        while (!readFile.eof()) {
            string str;
            getline(readFile, str);//���پ��޾� str�� ����
            //cout << str << endl;

            text[num] = str;//text�迭�� �ϳ��� ����
            num++;
        }

        readFile.close();//���� �ݱ�
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

    cout << "�ظ���� �����ϼ���." << endl;
    cout << "> 1. �޴� ���� ����" << endl;
    cout << "  2. �޴� ����" << endl;
    cout << "  3. ����" << endl;
    gotoxy(0, 1);

    //menu���� ���ڷ� �� ��
    /*int menu_sel;
    cin >> menu_sel;
    cout << menu_sel;
    if (menu_sel != 1 && menu_sel != 2 && menu_sel != 3) {
       cout << "���Է�" << endl;
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
        case UP://ȭ��ǥ �� ������ ��
            if (y > 1) {
                gotoxy(x, y);//�� �ڸ�
                cout << " ";//���� �����
                gotoxy(x, --y);//�� ĭ ���� �ö󰡱�
                cout << ">";
            }
            break;

        case DOWN://ȭ��ǥ �Ʒ� ������ ��
            if (y < 3) {
                gotoxy(x, y);//�� �ڸ�
                cout << " ";//���� �����
                gotoxy(x, ++y);//�� ĭ �Ʒ� ��������
                cout << ">";
            }
            break;

        case SPACE:

            //if (y==1) {//space�Է� �ƴµ� y�� 1�̾��� ��
            //   return 1;
            //}
            //else if (y == 2) {//space�Է� �ƴµ� y�� 2�̾��� ��
            //   return 2;
            //}
            //else if (y == 3) {//space�Է� �ƴµ� y�� 3�̾��� ��
            //   
            //   break;//����
            //}

            return y;
        }
    } while (key != SPACE);
}

void menu_random(string* text, int num) {//�޴� �������ִ� �Լ�
    system("cls");
    srand((unsigned int)time(NULL));
    int food_menu = rand() % (num);
    //cout << num << endl;
    //cout << food_menu << endl;

    cout << "    ��" << endl;
    cout << "   ����" << endl;
    cout << "  ������" << endl;
    cout << " ��������" << endl;
    cout << "����������" << endl;
    Sleep(700);
    gotoxy(0, 0);
    cout << "    ��";
    Sleep(700);
    gotoxy(0, 1);
    cout << "   �ء�";
    Sleep(700);
    gotoxy(0, 2);
    cout << "  �ءء�";
    Sleep(700);
    gotoxy(0, 3);
    cout << " �ءءء�";
    Sleep(700);
    gotoxy(0, 4);
    cout << "�ءءءء�";
    Sleep(1000);

    cout << endl;
    cout << endl;
    cout << "������ �޴���!!" << text[food_menu] << "�Դϴ�~~!!!!!!" << endl;
    cout << endl;
    cout << "Press Enter key" << endl;
    if (cin.get() != '\n') {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    system("cls");
    main();
}

void menu_change(string* text) {//�޴� �����ϴ� �Լ�
    /*system("cls");

    cout << "���� ����� �޴�" << endl;
    cout << "====================" << endl;
    int count = 0;
    for (int i = 0; i < SIZE; i++) {//���� ����� �޴� ���
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
    cout << "�ظ���� �����ϼ���." << endl;
    cout << "> 1. �޴� �߰�" << endl;
    cout << "  2. �޴� ����" << endl;
    cout << "  3. ���� ȭ��" << endl;
    int x2 = 0;
    int y2 = 1;
    int key2;
    do {
        key2 = keyControl();
        switch (key2) {
        case UP://ȭ��ǥ �� ������ ��
            if (y2 > 1) {
                gotoxy(x2, y2);//�� �ڸ�
                cout << " ";//���� �����
                gotoxy(x2, --y2);//�� ĭ ���� �ö󰡱�
                cout << ">";
            }
            break;

        case DOWN://ȭ��ǥ �Ʒ� ������ ��
            if (y2 < 3) {
                gotoxy(x2, y2);//�� �ڸ�
                cout << " ";//���� �����
                gotoxy(x2, ++y2);//�� ĭ �Ʒ� ��������
                cout << ">";
            }
            break;

        case SPACE:

            if (y2 == 1) {//space�Է� �ƴµ� y�� 1�̾��� ��
               //menu_add(text);
                if (count <= SIZE) {
                    menu_add(text, count);
                }
                else {
                    system("cls");
                    cout << "�޴��� ������ 50���� �ѱ� �� �����ϴ�." << endl;
                    /*cout << "Press Enter key" << endl;
                    cin.get();*/
                    menu_change(text);
                }
            }
            else if (y2 == 2) {//space�Է� �ƴµ� y�� 2�̾��� ��
                menu_sub(text, count);
            }
            else if (y2 == 3) {//space�Է� �ƴµ� y�� 3�̾��� ��
                system("cls");
                main();
            }
        }
    } while (key2 != SPACE);
}

void menu_add(string* text, int count) {

    string admenu;
    system("cls");
    cout << "�߰��� �޴��� �Է��ϼ���(�ڷ� ���� -> q)" << endl;
    cin >> admenu;

    if (!admenu.compare("q") || !admenu.compare("Q")) {//�ڷΰ���
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
    cout << "�߰� �Ǿ����ϴ�" << endl;
    cout << "Press Enter key" << endl;
    cin.get();
    menu_change(text);
}
void menu_sub(string* text, int count) {
    system("cls");
    cout << "���� ����� �޴�" << endl;
    cout << "====================" << endl;
    for (int i = 0; i < SIZE; i++) {//���� ����� �޴� ���

        cout << i + 1 << " ) " << text[i] << endl;
        if (text[i + 1] == "\0") {
            break;
        }
    }
    cout << endl;
    //cout << "������ �޴��� ��ȣ�� �Է��ϼ���" << endl;
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
    cout << "������ �޴��� ��ȣ�� �Է��ϼ���.(�ڷ� ���� -> q)" << endl;
    cin >> del_s;

    if (!del_s.compare("q") || !del_s.compare("Q")) {//�ڷΰ���
        if (cin.get() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        menu_change(text);
    }

    int del = atoi(del_s.c_str());
    del_s2 = to_string(del);
    while (1 > del || del > count || (del_s.size() != del_s2.size())) {
        cout << "�ٽ� �Է��ϼ���." << endl;
        cout << "������ �޴��� ��ȣ�� �Է��ϼ���." << endl;
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
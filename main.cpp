#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<vector>

#define SIZE 100
#define UP 0
#define DOWN 1
#define SPACE 2

using namespace std;

void Start();
//void text_stor(string text[SIZE]);
int* text_stor(vector <vector<string> >& text);
int menu();
int sub_menu();
int keyControl();
void gotoxy(int, int);
void menu_random(vector <vector<string> >& text, int* num);
void menu_check(vector <vector<string> >& text, int* num);
void menu_check2(vector <vector<string> >& text, int* num);
void menu_change(vector <vector<string> >& text);
void menu_add(vector <vector<string> >& text, int* count);
void menu_sub(vector <vector<string> >& text, int* count);

string text_name[6] = { "KoreanFood.txt", "ChineseFood.txt", "JapaneseFood.txt", "WesternFood.txt", "etc.txt", "food.txt" };

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

	//string text[5][SIZE];//�޴� ������ �迭
	//text_stor(*text);

	Start();

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


	return 0;
}

//�����ϴ� �޴�
void Start() {
	vector< vector<string> >text(6, vector<string>(SIZE, "\0"));
	int* number;
	number = text_stor(text);

	int menu_num = menu();


	if (menu_num == 1)
		menu_random(text, number);
	else if (menu_num == 2)
		menu_check(text, number);
	else if (menu_num == 3)
		menu_change(text);
	//else if (menu_num == 4)
}

//txt���Ͽ��� text���Ϳ� ����
int* text_stor(vector <vector<string> >& text) {
	static int result[6];

	ifstream readFile;

	//KoreanFood
	readFile.open(text_name[0]);//food.txt open
	int num_k = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//���پ��޾� str�� ����
			//cout << str << endl;

			if (str == "\0")
				break;
			text[0][num_k] = str;


			num_k++;
		}

		readFile.close();//���� �ݱ�
	}
	text[0][num_k] = "\0";
	result[0] = num_k;

	//ChineseFood
	readFile.open(text_name[1]);//food.txt open
	int num_c = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//���پ��޾� str�� ����
			//cout << str << endl;

			if (str == "\0")
				break;
			text[1][num_c] = str;//text�迭�� �ϳ��� ����
			num_c++;
		}

		readFile.close();//���� �ݱ�
	}
	text[1][num_c] = "\0";
	result[1] = num_c;

	//JapaneseFood
	readFile.open(text_name[2]);//food.txt open
	int num_j = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//���پ��޾� str�� ����
			//cout << str << endl;

			if (str == "\0")
				break;
			text[2][num_j] = str;//text�迭�� �ϳ��� ����
			num_j++;
		}

		readFile.close();//���� �ݱ�
	}
	text[2][num_j] = "\0";
	result[2] = num_j;

	//WesternFood
	readFile.open(text_name[3]);//food.txt open
	int num_w = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//���پ��޾� str�� ����
			//cout << str << endl;

			if (str == "\0")
				break;
			text[3][num_w] = str;//text�迭�� �ϳ��� ����
			num_w++;
		}

		readFile.close();//���� �ݱ�
	}
	text[3][num_w] = "\0";
	result[3] = num_w;

	//etc
	readFile.open(text_name[4]);//food.txt open
	int num_e = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//���پ��޾� str�� ����
			//cout << str << endl;

			if (str == "\0")
				break;
			text[4][num_e] = str;//text�迭�� �ϳ��� ����
			num_e++;
		}

		readFile.close();//���� �ݱ�
	}
	text[4][num_e] = "\0";
	result[4] = num_e;

	//total
	readFile.open(text_name[5]);//food.txt open
	int num_t = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//���پ��޾� str�� ����
			//cout << str << endl;

			if (str == "\0")
				break;
			text[5][num_t] = str;//text�迭�� �ϳ��� ����
			num_t++;
		}

		readFile.close();//���� �ݱ�
	}
	text[5][num_t] = "\0";
	result[5] = num_t;

	return result;
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
	else
		return 3;
	
}

void gotoxy(int x, int y) {
	COORD posXY = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}

//ù��° �޴� ���� ȭ��
int menu() {
	system("cls");

	cout << "�ظ���� �����ϼ���." << endl;
	cout << "> 1. �޴� ���� ����" << endl;
	cout << "  2. �޴� Ȯ��" << endl;
	cout << "  3. �޴� ����" << endl;
	cout << "  4. ����" << endl;
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
			else if (y == 1) {
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, 4);
				cout << ">";
				y = 4;
			}
			break;

		case DOWN://ȭ��ǥ �Ʒ� ������ ��
			if (y < 4) {
				gotoxy(x, y);//�� �ڸ�
				cout << " ";//���� �����
				gotoxy(x, ++y);//�� ĭ �Ʒ� ��������
				cout << ">";
			}
			else if (y == 4) {
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, 1);
				cout << ">";
				y = 1;
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
		case 3:
			continue;
		}
	} while (key != SPACE);
}

//�ι�° �޴� ���� ȭ��
int sub_menu() {
	system("cls");
	cout << "�ظ���� �����ϼ���." << endl;
	cout << "> 1. �ѽ�" << endl;
	cout << "  2. �߽�" << endl;
	cout << "  3. �Ͻ�" << endl;
	cout << "  4. ���" << endl;
	cout << "  5. ��Ÿ" << endl;
	cout << "  6. ��ü" << endl;
	cout << "  7. �ڷ� ����" << endl;
	gotoxy(0, 1);

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
			else if (y == 1) {
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, 7);
				cout << ">";
				y = 7;
			}
			break;

		case DOWN://ȭ��ǥ �Ʒ� ������ ��
			if (y < 7) {
				gotoxy(x, y);//�� �ڸ�
				cout << " ";//���� �����
				gotoxy(x, ++y);//�� ĭ �Ʒ� ��������
				cout << ">";
			}
			else if (y == 7) {
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, 1);
				cout << ">";
				y = 1;
			}
			break;

		case SPACE:
			return y;
		}
	} while (key != SPACE);
}

void menu_random(vector <vector<string> >& text, int* num) {//�޴� �������ִ� �Լ�
	int sub_menu_num = sub_menu();
	system("cls");
	if (sub_menu_num == 7) {
		Start();
	}
	else {
		srand((unsigned int)time(NULL));
		int food_menu = rand() % (num[sub_menu_num-1]);
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
		cout << "������ �޴���!!" << text[sub_menu_num-1][food_menu] << "�Դϴ�~~!!!!!!" << endl;
		cout << endl;
		cout << "Press Enter key" << endl;
		if (cin.get() != '\n') {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");

		main();
	}
}

void menu_check(vector <vector<string> >& text, int* num) {
	//���
	int menu_check_num = sub_menu();
	system("cls");
	switch (menu_check_num) {
	case 1:
		cout << num[0] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  �ѽ�  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 2:
		cout << num[1] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  �߽�  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 3:
		cout << num[2] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  �Ͻ�  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 4:
		cout << num[3] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  ���  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 5:
		cout << num[4] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  ��Ÿ  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 6:
		cout << num[5] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  ��ü  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 7:
		Start();
		break;
	}
	for (int j = 0; j < SIZE; j++) {
		cout << j + 1 << ")" << text[menu_check_num-1][j] << endl;
		if (text[menu_check_num-1][j + 1] == "\0") {
			break;
		}
	}
	cout << endl;
	cout << "Press Enter key" << endl;
	if (cin.get() != '\n') {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	system("cls");
	Start();
}

void menu_check2(vector <vector<string> >& text, int* num) {
	//���
	int menu_check_num = sub_menu();
	system("cls");
	switch (menu_check_num) {
	case 1:
		cout << num[0] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  �ѽ�  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 2:
		cout << num[1] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  �߽�  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 3:
		cout << num[2] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  �Ͻ�  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 4:
		cout << num[3] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  ���  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 5:
		cout << num[4] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  ��Ÿ  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 6:
		cout << num[5] << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		cout << "��  ��ü  ��" << endl;
		cout << "�ƢƢƢƢƢ�" << endl;
		break;
	case 7:
		menu_change(text);
		break;
	}
	for (int j = 0; j < SIZE; j++) {
		cout << j + 1 << ")" << text[menu_check_num - 1][j] << endl;
		if (text[menu_check_num - 1][j + 1] == "\0") {
			break;
		}
	}
	cout << endl;
	cout << "Press Enter key" << endl;
	if (cin.get() != '\n') {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	system("cls");
	menu_change(text);
}

void menu_change(vector <vector<string> >& text) {//�޴� �����ϴ� �Լ�
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

	int count[6] = { 0, };//�� �޸��庰�� �޴� ���� ��� ����(->�޴� �߰�, ���� �� �ʿ�)
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < SIZE; j++) {
			count[i]++;
			if (text[i][j + 1] == "\0")
				break;
		}
	}

	system("cls");
	cout << "�ظ���� �����ϼ���." << endl;
	cout << "> 1. �޴� �߰�" << endl;
	cout << "  2. �޴� ����" << endl;
	cout << "  3. �޴� Ȯ��" << endl;
	cout << "  4. ���� ȭ��" << endl;
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
			else if (y2 == 1) {
				gotoxy(x2, y2);//�� �ڸ�
				cout << " ";//���� �����
				gotoxy(x2, 4);
				cout << ">";
				y2 = 4;
			}
			break;

		case DOWN://ȭ��ǥ �Ʒ� ������ ��
			if (y2 < 4) {
				gotoxy(x2, y2);//�� �ڸ�
				cout << " ";//���� �����
				gotoxy(x2, ++y2);//�� ĭ �Ʒ� ��������
				cout << ">";
			}
			else if (y2 == 4) {
				gotoxy(x2, y2);//�� �ڸ�
				cout << " ";//���� �����
				gotoxy(x2, 1);//�� ĭ ���� �ö󰡱�
				cout << ">";
				y2 = 1;
			}
			break;

		case SPACE:

			if (y2 == 1) {//space�Է� �ƴµ� y�� 1�̾��� ��
			   //menu_add(text);
				if (count[5] < SIZE) {
					menu_add(text, count);
				}
				else {
					system("cls");
					cout << "�޴��� ������ �̹� �ִ��Դϴ�." << endl;
					/*cout << "Press Enter key" << endl;
					cin.get();*/
					menu_change(text);
				}
			}
			else if (y2 == 2) {//space�Է� �ƴµ� y�� 2�̾��� ��
				menu_sub(text, count);
			}
			else if (y2 == 3) {//space�Է� �ƴµ� y�� 3�̾��� ��
				menu_check2(text, count);
			}
			else if (y2 == 4) {//space�Է� �ƴµ� y�� 3�̾��� ��
				system("cls");
				Start();
			}
		}
	} while (key2 != SPACE);
}

void menu_add(vector <vector<string> >& text, int* count) {
	int menu_add_num = sub_menu();//������ ���� ��ȣ
	if (menu_add_num == 7) {
		menu_change(text);
	}
	string admenu;
	system("cls");
	//cout << count[menu_add_num - 1] << endl;
	cout << "�߰��� �޴��� �Է��ϼ���(�ڷ� ���� -> q)" << endl;
	cin >> admenu;

	if (!admenu.compare("q") || !admenu.compare("Q")) {//�ڷΰ���
		if (cin.get() != '\n') {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		menu_change(text);
	}
	ofstream out(text_name[menu_add_num - 1]);
	for (int i = 0; i < count[menu_add_num-1]; i++) {
		out << text[menu_add_num-1][i] << endl;
	}
	out << admenu << endl;
	out.close();
	text[menu_add_num-1][count[menu_add_num-1]] = admenu;

	cout << "�߰� �Ǿ����ϴ�" << endl;
	cout << "Press Enter key" << endl;
	cin.get();
	menu_change(text);
}

void menu_sub(vector <vector<string> >& text, int* count) {
	system("cls");
	int menu_sub_num = sub_menu();
	if (menu_sub_num == 7) {
		menu_change(text);
	}
	system("cls");
	cout << "���� ����� �޴�" << endl;
	cout << "====================" << endl;
	for (int i = 0; i < SIZE; i++) {//���� ����� �޴� ���
		cout << i + 1 << " ) " << text[menu_sub_num-1][i] << endl;
		if (text[menu_sub_num-1][i + 1] == "\0")
			break;
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
		menu_sub(text, count);
	}

	int del = atoi(del_s.c_str());
	del_s2 = to_string(del);
	while (1 > del || del > count[menu_sub_num - 1] || (del_s.size() != del_s2.size())) {
		cout << "�ٽ� �Է��ϼ���." << endl;
		cout << "������ �޴��� ��ȣ�� �Է��ϼ���." << endl;
		cin >> del_s;
		del = atoi(del_s.c_str());
	}
	for (int i = del - 1; i < count[menu_sub_num - 1]; i++) {
		text[menu_sub_num - 1][i] = text[menu_sub_num - 1][i + 1];
	}
	text[menu_sub_num - 1][count[menu_sub_num - 1] - 1] = "\0";

	ofstream out(text_name[menu_sub_num - 1]);
	for (int i = 0; i < count[menu_sub_num - 1]; i++) {
		out << text[menu_sub_num - 1][i] << endl;
	}

	cout << "Press Enter key" << endl;
	cin.get();
	menu_change(text);
}
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

	//string text[5][SIZE];//메뉴 저장할 배열
	//text_stor(*text);

	Start();

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


	return 0;
}

//시작하는 메뉴
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

//txt파일에서 text벡터에 저장
int* text_stor(vector <vector<string> >& text) {
	static int result[6];

	ifstream readFile;

	//KoreanFood
	readFile.open(text_name[0]);//food.txt open
	int num_k = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//한줄씩받아 str에 저장
			//cout << str << endl;

			if (str == "\0")
				break;
			text[0][num_k] = str;


			num_k++;
		}

		readFile.close();//파일 닫기
	}
	text[0][num_k] = "\0";
	result[0] = num_k;

	//ChineseFood
	readFile.open(text_name[1]);//food.txt open
	int num_c = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//한줄씩받아 str에 저장
			//cout << str << endl;

			if (str == "\0")
				break;
			text[1][num_c] = str;//text배열에 하나씩 저장
			num_c++;
		}

		readFile.close();//파일 닫기
	}
	text[1][num_c] = "\0";
	result[1] = num_c;

	//JapaneseFood
	readFile.open(text_name[2]);//food.txt open
	int num_j = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//한줄씩받아 str에 저장
			//cout << str << endl;

			if (str == "\0")
				break;
			text[2][num_j] = str;//text배열에 하나씩 저장
			num_j++;
		}

		readFile.close();//파일 닫기
	}
	text[2][num_j] = "\0";
	result[2] = num_j;

	//WesternFood
	readFile.open(text_name[3]);//food.txt open
	int num_w = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//한줄씩받아 str에 저장
			//cout << str << endl;

			if (str == "\0")
				break;
			text[3][num_w] = str;//text배열에 하나씩 저장
			num_w++;
		}

		readFile.close();//파일 닫기
	}
	text[3][num_w] = "\0";
	result[3] = num_w;

	//etc
	readFile.open(text_name[4]);//food.txt open
	int num_e = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//한줄씩받아 str에 저장
			//cout << str << endl;

			if (str == "\0")
				break;
			text[4][num_e] = str;//text배열에 하나씩 저장
			num_e++;
		}

		readFile.close();//파일 닫기
	}
	text[4][num_e] = "\0";
	result[4] = num_e;

	//total
	readFile.open(text_name[5]);//food.txt open
	int num_t = 0;
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			string str;
			getline(readFile, str);//한줄씩받아 str에 저장
			//cout << str << endl;

			if (str == "\0")
				break;
			text[5][num_t] = str;//text배열에 하나씩 저장
			num_t++;
		}

		readFile.close();//파일 닫기
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

//첫번째 메뉴 선택 화면
int menu() {
	system("cls");

	cout << "※목록을 선택하세요." << endl;
	cout << "> 1. 메뉴 랜덤 선택" << endl;
	cout << "  2. 메뉴 확인" << endl;
	cout << "  3. 메뉴 수정" << endl;
	cout << "  4. 종료" << endl;
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
			else if (y == 1) {
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, 4);
				cout << ">";
				y = 4;
			}
			break;

		case DOWN://화살표 아래 눌렀을 때
			if (y < 4) {
				gotoxy(x, y);//그 자리
				cout << " ";//먼저 지우고
				gotoxy(x, ++y);//한 칸 아래 내려가기
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
		case 3:
			continue;
		}
	} while (key != SPACE);
}

//두번째 메뉴 선택 화면
int sub_menu() {
	system("cls");
	cout << "※목록을 선택하세요." << endl;
	cout << "> 1. 한식" << endl;
	cout << "  2. 중식" << endl;
	cout << "  3. 일식" << endl;
	cout << "  4. 양식" << endl;
	cout << "  5. 기타" << endl;
	cout << "  6. 전체" << endl;
	cout << "  7. 뒤로 가기" << endl;
	gotoxy(0, 1);

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
			else if (y == 1) {
				gotoxy(x, y);
				cout << " ";
				gotoxy(x, 7);
				cout << ">";
				y = 7;
			}
			break;

		case DOWN://화살표 아래 눌렀을 때
			if (y < 7) {
				gotoxy(x, y);//그 자리
				cout << " ";//먼저 지우고
				gotoxy(x, ++y);//한 칸 아래 내려가기
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

void menu_random(vector <vector<string> >& text, int* num) {//메뉴 선택해주는 함수
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
		cout << "오늘의 메뉴는!!" << text[sub_menu_num-1][food_menu] << "입니다~~!!!!!!" << endl;
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
	//출력
	int menu_check_num = sub_menu();
	system("cls");
	switch (menu_check_num) {
	case 1:
		cout << num[0] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  한식  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 2:
		cout << num[1] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  중식  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 3:
		cout << num[2] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  일식  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 4:
		cout << num[3] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  양식  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 5:
		cout << num[4] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  기타  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 6:
		cout << num[5] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  전체  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
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
	//출력
	int menu_check_num = sub_menu();
	system("cls");
	switch (menu_check_num) {
	case 1:
		cout << num[0] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  한식  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 2:
		cout << num[1] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  중식  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 3:
		cout << num[2] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  일식  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 4:
		cout << num[3] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  양식  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 5:
		cout << num[4] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  기타  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
		break;
	case 6:
		cout << num[5] << endl;
		cout << "▒▒▒▒▒▒" << endl;
		cout << "▒  전체  ▒" << endl;
		cout << "▒▒▒▒▒▒" << endl;
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

void menu_change(vector <vector<string> >& text) {//메뉴 수정하는 함수
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

	int count[6] = { 0, };//각 메모장별로 메뉴 개수 담는 변수(->메뉴 추가, 삭제 시 필요)
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < SIZE; j++) {
			count[i]++;
			if (text[i][j + 1] == "\0")
				break;
		}
	}

	system("cls");
	cout << "※목록을 선택하세요." << endl;
	cout << "> 1. 메뉴 추가" << endl;
	cout << "  2. 메뉴 삭제" << endl;
	cout << "  3. 메뉴 확인" << endl;
	cout << "  4. 메인 화면" << endl;
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
			else if (y2 == 1) {
				gotoxy(x2, y2);//그 자리
				cout << " ";//먼저 지우고
				gotoxy(x2, 4);
				cout << ">";
				y2 = 4;
			}
			break;

		case DOWN://화살표 아래 눌렀을 때
			if (y2 < 4) {
				gotoxy(x2, y2);//그 자리
				cout << " ";//먼저 지우고
				gotoxy(x2, ++y2);//한 칸 아래 내려가기
				cout << ">";
			}
			else if (y2 == 4) {
				gotoxy(x2, y2);//그 자리
				cout << " ";//먼저 지우고
				gotoxy(x2, 1);//한 칸 위에 올라가기
				cout << ">";
				y2 = 1;
			}
			break;

		case SPACE:

			if (y2 == 1) {//space입력 됐는데 y가 1이었을 때
			   //menu_add(text);
				if (count[5] < SIZE) {
					menu_add(text, count);
				}
				else {
					system("cls");
					cout << "메뉴의 개수가 이미 최대입니다." << endl;
					/*cout << "Press Enter key" << endl;
					cin.get();*/
					menu_change(text);
				}
			}
			else if (y2 == 2) {//space입력 됐는데 y가 2이었을 때
				menu_sub(text, count);
			}
			else if (y2 == 3) {//space입력 됐는데 y가 3이었을 때
				menu_check2(text, count);
			}
			else if (y2 == 4) {//space입력 됐는데 y가 3이었을 때
				system("cls");
				Start();
			}
		}
	} while (key2 != SPACE);
}

void menu_add(vector <vector<string> >& text, int* count) {
	int menu_add_num = sub_menu();//수정할 파일 번호
	if (menu_add_num == 7) {
		menu_change(text);
	}
	string admenu;
	system("cls");
	//cout << count[menu_add_num - 1] << endl;
	cout << "추가할 메뉴를 입력하세요(뒤로 가기 -> q)" << endl;
	cin >> admenu;

	if (!admenu.compare("q") || !admenu.compare("Q")) {//뒤로가기
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

	cout << "추가 되었습니다" << endl;
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
	cout << "현재 저장된 메뉴" << endl;
	cout << "====================" << endl;
	for (int i = 0; i < SIZE; i++) {//현재 저장된 메뉴 출력
		cout << i + 1 << " ) " << text[menu_sub_num-1][i] << endl;
		if (text[menu_sub_num-1][i + 1] == "\0")
			break;
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
		menu_sub(text, count);
	}

	int del = atoi(del_s.c_str());
	del_s2 = to_string(del);
	while (1 > del || del > count[menu_sub_num - 1] || (del_s.size() != del_s2.size())) {
		cout << "다시 입력하세요." << endl;
		cout << "삭제할 메뉴의 번호를 입력하세요." << endl;
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
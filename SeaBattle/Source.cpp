#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <time.h>
#include <windows.h>
using namespace std;

//void enterFireUser(char field1[10][10], char field2[10][10], char field3[10][10]);
void enterFireUserAuto(char field1[10][10], char field2[10][10], char field3[10][10]);                  //атака машины авто бой
void enterCoordinate(char field1[10][10], char field2[10][10], char field3[10][10], int a, int b, int counter, int c);  //ввод координат
void enterCoordinateAuto(char field[10][10], int a, int b);                                             //ввод координат авто
void printFields(char field1[10][10], char field2[10][10], char field3[10][10]);                        //печать полей
void enterFireManual(char field1[10][10], char field2[10][10], char field3[10][10]);                    //атака пользователя ручной бой
void checkField(char field[10][10], int a, int b);                                                      //проверка поля
void checkField2(char field[10][10], int a, int b);                                                     //проверка поля
void enterFireMachineManual(char field1[10][10], char field2[10][10], char field3[10][10]);             //атака машины ручной бой
void enterFireMachine(char field1[10][10], char field2[10][10], char field3[10][10]);                   //атака машины автобой
void startGame(char field1[10][10], char field2[10][10], char field3[10][10]);                          //инициализация полей

int main() {

	char field1[10][10];
	char field2[10][10];
	char field3[10][10];

	startGame(field1, field2, field3);

	int a = 0, b = 0, counter = 0, f, p, next, q;

	cout << "Hello, welcome to battleship\n\n" << endl;

	cout << "Press 0 to autofight Machine vs Machine" << endl;                   //расстановка кораблей
	cout << "Press 1 to fight User vs Machine" << endl;
	cin >> f;
	switch (f) {
	case 0:
		enterCoordinateAuto(field3, a, b);
		Sleep(100);
		enterCoordinateAuto(field1, a, b);
		printFields(field1, field2, field3);
		enterFireUserAuto(field1, field2, field3);
		break;
	case 1:
		cout << "Press 0 to auto arrangement of ships " << endl;
		cout << "Press 1 to manual arrangement of ships" << endl;
		cin >> p;
		switch (p) {
		case 0:
			enterCoordinateAuto(field3, a, b);
			Sleep(100);
			enterCoordinateAuto(field1, a, b);
			cout << "Battle begin >>>" << endl;
			break;
		case 1:
			enterCoordinateAuto(field3, a, b);
			enterCoordinate(field1, field2, field3, a, b, counter, 1);
			enterCoordinate(field1, field2, field3, a, b, counter, 2);
			enterCoordinate(field1, field2, field3, a, b, counter, 3);
			enterCoordinate(field1, field2, field3, a, b, counter, 4);
			break;
		}


	}
	cout << "Press 0 to auto battle " << endl;                                           //бой
	cout << "Press 1 to manual battle" << endl;
	cin >> q;
	switch (q) {
	case 0:
		enterFireUserAuto(field1, field2, field3);
		break;
	case 1:
		enterFireManual(field1, field2, field3);
		break;
	}
	
}

void startGame(char field1[10][10], char field2[10][10], char field3[10][10]) {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			field1[i][j] = '.';
			field2[i][j] = '.';
			field3[i][j] = '.';
		}
	}
}

void printFields(char field1[10][10], char field2[10][10], char field3[10][10]) {                 //печать игровых полей
	cout << "\n  Your Battle Field  \t      Machine field   \t     Machine's ships\n";
	cout << "\n  0 1 2 3 4 5 6 7 8 9\t   0 1 2 3 4 5 6 7 8 9\t    0 1 2 3 4 5 6 7 8 9\n";
	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << field1[i][j] << " ";
		}

		cout << "   ";
		cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << field2[i][j] << " ";
		}

		cout << "   ";
		cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << field3[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
};
void enterCoordinate(char field1[10][10], char field2[10][10], char field3[10][10], int a, int b, int counter, int c) {     //ввод координат кораблей
			cout << "Enter " << c << "-pointed ship a (horizontal): "; cin >> a;
			cout << "Enter " << c << "-pointed ship b (vertical): "; cin >> b;
			if (field1[a + 1][b] != '#' && field1[a + 1][b + 1] != '#' && field1[a + 1][b - 1] != '#'
				&& field1[a - 1][b - 1] != '#' && field1[a - 1][b + 1] != '#' && field1[a - 1][b] != '#'
				&& field1[a][b - 1] != '#' && field1[a][b + 1] != '#' && field1[a][b] != '#' && counter == 0) {
				field1[a][b] = '#';
			}
			else if (counter != 0 && (field1[a + 1][b] == '#' || field1[a][b - 1] == '#' || field1[a][b + 1] == '#'
				|| field1[a - 1][b - 1] == '#') && (field1[a + 1][b + 1] != '#' || field1[a + 1][b - 1] != '#' || field1[a - 1][b + 1] != '#'
					|| field1[a - 1][b - 1] != '#')) {
				int temp = 0;
				if (field1[a + 1][b] == '#') temp++;
				if (field1[a - 1][b] == '#') temp++;
				if (field1[a][b + 1] == '#') temp++;
				if (field1[a][b - 1] == '#') temp++;
				if (temp == 1)	field1[a][b] = '#';
			}
			else cout << "Error Check Field, illegal number or field, retry " << endl;
			counter++;
			if (field1[a][b] == '#') {
				cout << "Your " << c << "-pointed ship: [" << a << "][" << b << "]" << endl;
				printFields(field1, field2, field3);
				if ((counter == c) && (counter != 4)) cout << "Good, next ship " << endl;
				else if (counter == 4) cout << "Ok, lets play ! " << endl;
				else enterCoordinate(field1, field2, field3, a, b, counter, c);
			}
			else {
				cout << "Error, illegal number or field, retry " << endl;
				counter--;
				enterCoordinate(field1, field2, field3, a, b, counter, c);
			}
		};
void enterCoordinateAuto(char field[10][10], int  a, int b)
{
	srand(time(NULL));
	int l = rand() % 2;
	switch (l) {
	case 0:
		a = rand() % 7;
		b = rand() % 10;
		while (field[a][b] == 'X' || field[a + 1][b] == 'X' || field[a + 2][b] == 'X' || field[a + 3][b] == 'X' ||
			field[a - 1][b - 1] == 'X' || field[a - 1][b] == 'X' || field[a - 1][b + 1] == 'X' || field[a][b - 1] == 'X' ||
			field[a][b + 1] == 'X' || field[a + 1][b - 1] == 'X' || field[a + 1][b + 1] == 'X' || field[a + 2][b - 1] == 'X' ||
			field[a + 2][b + 1] == 'X' || field[a + 3][b - 1] == 'X' || field[a + 3][b + 1] == 'X' || field[a + 4][b - 1] == 'X' ||
			field[a + 4][b] == 'X' || field[a + 4][b + 1] == 'X')
		{
			a = rand() % 7;
			b = rand() % 10;
		}
		field[a][b] = '#';
		field[a + 1][b] = '#';
		field[a + 2][b] = '#';
		field[a + 3][b] = '#';
		break;
	case 1:
		a = rand() % 10;
		b = rand() % 7;
		while (field[a][b] == 'X' || field[a][b + 1] == 'X' || field[a][b + 2] == 'X' || field[a][b + 3] == 'X' ||
			field[a - 1][b - 1] == 'X' || field[a - 1][b] == 'X' || field[a - 1][b + 1] == 'X' || field[a - 1][b + 2] == 'X' ||
			field[a - 1][b + 3] == 'X' || field[a - 1][b + 4] == 'X' || field[a][b - 1] == 'X' || field[a][b + 4] == 'X' ||
			field[a + 1][b - 1] == 'X' || field[a + 1][b] == 'X' || field[a + 1][b + 1] == 'X' || field[a + 1][b + 2] == 'X' ||
			field[a + 1][b + 3] == 'X' || field[a + 1][b + 4] == 'X')
		{
			a = rand() % 10;
			b = rand() % 7;
		}
		field[a][b] = '#';
		field[a][b + 1] = '#';
		field[a][b + 2] = '#';
		field[a][b + 3] = '#';
		break;
	}
	int n = rand() % 2;
	switch (n) {
	case 0:
		a = rand() % 8;
		b = rand() % 10;
		while (field[a][b] == '#' || field[a + 1][b] == '#' || field[a + 2][b] == '#' || field[a - 1][b - 1] == '#' ||
			field[a - 1][b] == '#' || field[a - 1][b + 1] == '#' || field[a][b - 1] == '#' || field[a][b + 1] == '#' ||
			field[a + 1][b - 1] == '#' || field[a + 1][b + 1] == '#' || field[a + 2][b - 1] == '#' || field[a + 2][b + 1] == '#' ||
			field[a + 3][b - 1] == '#' || field[a + 3][b] == '#' || field[a + 3][b + 1] == '#')
		{
			a = rand() % 8;
			b = rand() % 10;
		}
		field[a][b] = '#';
		field[a + 1][b] = '#';
		field[a + 2][b] = '#';
		break;
	case 1:
		a = rand() % 10;
		b = rand() % 8;
		while (field[a][b] == '#' || field[a][b + 1] == '#' || field[a][b + 2] == '#' || field[a - 1][b - 1] == '#' ||
			field[a - 1][b] == '#' || field[a - 1][b + 1] == '#' || field[a - 1][b + 2] == '#' || field[a - 1][b + 3] == '#' ||
			field[a][b - 1] == '#' || field[a][b + 3] == '#' || field[a + 1][b - 1] == '#' || field[a + 1][b] == '#' ||
			field[a + 1][b + 1] == '#' || field[a + 1][b + 2] == '#' || field[a + 1][b + 3] == '#')
		{
			a = rand() % 10;
			b = rand() % 8;
		}
		field[a][b] = '#';
		field[a][b + 1] = '#';
		field[a][b + 2] = '#';
		break;
	}
	int k = rand() % 2;
	switch (k) {
	case 0:
		a = rand() % 9;
		b = rand() % 10;
		while (field[a][b] == '#' || field[a - 1][b - 1] == '#' || field[a - 1][b] == '#' || field[a - 1][b + 1] == '#' ||
			field[a][b - 1] == '#' || field[a][b + 1] == '#' || field[a + 1][b - 1] == '#' || field[a + 1][b] == '#' ||
			field[a + 1][b + 1] == '#' || field[a + 2][b - 1] == '#' || field[a + 2][b] == '#' || field[a + 2][b + 1] == '#')
		{
			a = rand() % 9;
			b = rand() % 10;
		}
		field[a][b] = '#';
		field[a + 1][b] = '#';
		break;
	case 1:
		a = rand() % 10;
		b = rand() % 9;
		while (field[a][b] == '#' || field[a][b + 1] == '#' || field[a - 1][b - 1] == '#' || field[a - 1][b] == '#' ||
			field[a - 1][b + 1] == '#' || field[a - 1][b + 2] == '#' || field[a][b - 1] == '#' || field[a][b + 2] == '#' ||
			field[a + 1][b - 1] == '#' || field[a + 1][b] == '#' || field[a + 1][b + 1] == '#' || field[a + 1][b + 2] == '#')
		{
			a = rand() % 10;
			b = rand() % 9;
		}
		field[a][b] = '#';
		field[a][b + 1] = '#';
		break;
	}
	a = rand() % 10;
	b = rand() % 10;
	while (field[a][b] == '#' || field[a][b + 1] == '#' || field[a][b - 1] == '#' || field[a + 1][b] == '#' || field[a - 1][b] == '#'
		|| field[a + 1][b + 1] == '#' || field[a + 1][b - 1] == '#' || field[a - 1][b + 1] == '#' || field[a - 1][b - 1] == '#')
	{
		a = rand() % 10;
		b = rand() % 10;
	}
	field[a][b] = '#';
}
void checkFieldAuto(char field1[10][10], char field2[10][10], char field3[10][10], int a, int b, int counter, int c) {    //проверка поля для авто установки
	if (field2[a + 1][b] != '#' && field2[a + 1][b + 1] != '#' && field2[a + 1][b - 1] != '#'
		&& field2[a - 1][b - 1] != '#' && field2[a - 1][b + 1] != '#' && field2[a - 1][b] != '#'
		&& field2[a][b - 1] != '#' && field2[a][b + 1] != '#' && counter == 0) field2[a][b] = '#';
	else if (counter != 0 && (field2[a + 1][b] == '#' || field2[a][b - 1] == '#' || field2[a][b + 1] == '#'
		|| field2[a - 1][b] == '#')) {
		int temp = 0;
		if (field2[a + 1][b] == '#') temp++;
		if (field2[a - 1][b] == '#') temp++;
		if (field2[a][b + 1] == '#') temp++;
		if (field2[a][b - 1] == '#') temp++;
		if (temp == 1)	field2[a][b] = '#';
	}
	else cout << "Error Check Field, illegal number or field, retry " << endl;
}
void checkField2(char field[10][10], int a, int b) {
	int temp = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j] == '$') temp++;
		}
	}
	if (temp == 10) {
		cout << "Great! Machine hit the ALL ship! Machine WIN.\n\n" << endl;
		system("pause");
	}
}
void checkField(char field[10][10], int a, int b) {
	int temp = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (field[i][j] == '$') temp++;
		}
	}
	if (temp == 10) {
		cout << "Great! You are hit the ALL ship! You are WIN.\n\n" << endl;
		system("pause");
	}
}

void enterFireManual(char field1[10][10], char field2[10][10], char field3[10][10]) {
	int a, b;
	cout << "Enter fire coordinate (horizontal):" << endl;
	cin >> a;
	cout << "Enter fire coordinate (vertical):" << endl;
	cin >> b;
	if (field3[a][b] == '#' && field2[a][b] != '$') {
		field2[a][b] = '$';
		if (field2[a + 1][b + 1] == '.')  field2[a + 1][b + 1] = '*';
		if (field2[a + 1][b - 1] == '.')  field2[a + 1][b - 1] = '*';
		if (field2[a + 1][b] == '.')      field2[a + 1][b] = '*';
		if (field2[a - 1][b + 1] == '.')  field2[a - 1][b + 1] = '*';
		if (field2[a - 1][b - 1] == '.')  field2[a - 1][b - 1] = '*';
		if (field2[a - 1][b] == '.')      field2[a - 1][b] = '*';
		if (field2[a][b + 1] == '.')      field2[a][b + 1] = '*';
		if (field2[a][b - 1] == '.')      field2[a][b - 1] = '*';
		cout << "Great! You are hit the ship! Shoot again.." << endl;
		printFields(field1, field2, field3);
		checkField(field2, a, b);
		enterFireManual(field1, field2, field3);
	}
	else {
		if (field2[a][b] != '*' && field2[a][b] != '$') field2[a][b] = '+';
		cout << "Sadly! You are missed! " << endl;
		printFields(field1, field2, field3);
		enterFireMachineManual(field1, field2, field3);
	}
}
void enterFireMachineManual(char field1[10][10], char field2[10][10], char field3[10][10]) {
	srand(time(NULL));
	int a, b;
	a = rand() % 10;
	b = rand() % 10;
	while (field1[a][b] == '+' || field1[a][b] == '*' || field1[a][b] == '$')
	{
		a = rand() % 10;
		b = rand() % 10;
	}
	if (field1[a][b] == '#' && field1[a][b] != '$') {
		field1[a][b] = '$';
		if (field1[a + 1][b + 1] == '.' && field1[a + 1][b + 1] != '$')  field1[a + 1][b + 1] = '*';
		if (field1[a + 1][b - 1] == '.' && field1[a + 1][b - 1] != '$')  field1[a + 1][b - 1] = '*';
		if (field1[a + 1][b] == '.' && field1[a + 1][b] != '$')      field1[a + 1][b] = '*';
		if (field1[a - 1][b + 1] == '.' && field1[a - 1][b + 1] != '$')  field1[a - 1][b + 1] = '*';
		if (field1[a - 1][b - 1] == '.' && field1[a - 1][b - 1] != '$')  field1[a - 1][b - 1] = '*';
		if (field1[a - 1][b] == '.' && field1[a - 1][b] != '$')      field1[a - 1][b] = '*';
		if (field1[a][b + 1] == '.' && field1[a][b + 1] != '$')      field1[a][b + 1] = '*';
		if (field1[a][b - 1] == '.' && field1[a][b - 1] != '$')      field1[a][b - 1] = '*';
		cout << "Great! I am hit the ship! Shoot again.." << endl;
		printFields(field1, field2, field3);
		checkField2(field1, a, b);
		enterFireMachineManual(field1, field2, field3);
	}
	else {
		if (field1[a][b] != '*' && field1[a][b] != '$') field1[a][b] = '+';
		cout << "Sadly! I am missed! " << endl;
		printFields(field1, field2, field3);
		enterFireManual(field1, field2, field3);
	}
}
void enterFireUserAuto(char field1[10][10], char field2[10][10], char field3[10][10]) {
	int a, b;
	srand(time(NULL));
	a = rand() % 10;
	b = rand() % 10;
	while (field2[a][b] == '+' || field2[a][b] == '*' || field2[a][b] == '$')
	{
		a = rand() % 10;
		b = rand() % 10;
	}
	if (field3[a][b] == '#' && field2[a][b] != '$') {
		field2[a][b] = '$';
		if (field2[a + 1][b + 1] == '.' && field3[a][b] != '$')  field2[a + 1][b + 1] = '*';
		if (field2[a + 1][b - 1] == '.' && field3[a][b] != '$')  field2[a + 1][b - 1] = '*';
		if (field2[a + 1][b] == '.' && field3[a][b] != '$')      field2[a + 1][b] = '*';
		if (field2[a - 1][b + 1] == '.' && field3[a][b] != '$')  field2[a - 1][b + 1] = '*';
		if (field2[a - 1][b - 1] == '.' && field3[a][b] != '$')  field2[a - 1][b - 1] = '*';
		if (field2[a - 1][b] == '.' && field3[a][b] != '$')      field2[a - 1][b] = '*';
		if (field2[a][b + 1] == '.' && field3[a][b] != '$')      field2[a][b + 1] = '*';
		if (field2[a][b - 1] == '.' && field3[a][b] != '$')      field2[a][b - 1] = '*';
		cout << "Great! You are hit the ship! Shoot again.." << endl;
		printFields(field1, field2, field3);
		checkField(field2, a, b);
		enterFireUserAuto(field1, field2, field3);
	}
	else {
		if (field2[a][b] != '*' && field2[a][b] != '$') field2[a][b] = '+';
		cout << "Sadly! You are missed! " << endl;
		printFields(field1, field2, field3);
		enterFireMachine(field1, field2, field3);
	}
}
void enterFireMachine(char field1[10][10], char field2[10][10], char field3[10][10]) {
	srand(time(NULL));
	int a, b;
	a = rand() % 10;
	b = rand() % 10;
	while (field1[a][b] == '+' || field1[a][b] == '*' || field1[a][b] == '$')
	{
		a = rand() % 10;
		b = rand() % 10;
	}
	if (field1[a][b] == '#' && field1[a][b] != '$') {
		field1[a][b] = '$';
		if (field1[a + 1][b + 1] == '.' && field1[a + 1][b + 1] != '$')  field1[a + 1][b + 1] = '*';
		if (field1[a + 1][b - 1] == '.' && field1[a + 1][b - 1] != '$')  field1[a + 1][b - 1] = '*';
		if (field1[a + 1][b] == '.' && field1[a + 1][b] != '$')      field1[a + 1][b] = '*';
		if (field1[a - 1][b + 1] == '.' && field1[a - 1][b + 1] != '$')  field1[a - 1][b + 1] = '*';
		if (field1[a - 1][b - 1] == '.' && field1[a - 1][b - 1] != '$')  field1[a - 1][b - 1] = '*';
		if (field1[a - 1][b] == '.' && field1[a - 1][b] != '$')      field1[a - 1][b] = '*';
		if (field1[a][b + 1] == '.' && field1[a][b + 1] != '$')      field1[a][b + 1] = '*';
		if (field1[a][b - 1] == '.' && field1[a][b - 1] != '$')      field1[a][b - 1] = '*';
		cout << "Great! I am hit the ship! Shoot again.." << endl;
		printFields(field1, field2, field3);
		checkField2(field1, a, b);
		enterFireMachine(field1, field2, field3);
	}
	else {
		if (field1[a][b] != '*' && field1[a][b] != '$') field1[a][b] = '+';
		cout << "Sadly! I am missed! " << endl;
		printFields(field1, field2, field3);
		enterFireUserAuto(field1, field2, field3);
	}
}
void smartAutoFire(char field1[10][10], char field2[10][10], char field3[10][10], int a, int b) {

	if (field1[a][b + 1] == '#') 		{
		cout << "Great! I am hit the ship! Shoot again.." << endl;
		checkField2(field1, a, b);
		smartAutoFire(field1, field2, field3, a, b);
	}
	else if (field1[a][b + 1] == '$') {
		if (field1[a][b + 2] == '#') {
			cout << "Great! I am hit the ship! Shoot again.." << endl;
			checkField2(field1, a, b);
			smartAutoFire(field1, field2, field3, a, b);
		}
	}
	else if (field1[a][b + 1] == '+') {
		if (field1[a][b - 1] == '#') {
			cout << "Great! I am hit the ship! Shoot again.." << endl;
			checkField2(field1, a, b);
			smartAutoFire(field1, field2, field3, a, b);
		}
	}
	else {
		field2[a][b] = '+';
		cout << "Sadly! You are missed! " << endl;
		printFields(field1, field2, field3);
		enterFireUserAuto(field1, field2, field3);

	}
}










//void checkField(char field1[10][10], char field2[10][10], int a, int b, int counter, int c) {       //проверка поля для установки корабля
//	/*cout << field1[a + 1][b] << field1[a + 1][b + 1] << field1[a + 1][b - 1] <<
//		field1[a - 1][b - 1] << field1[a - 1][b + 1] << field1[a - 1][b] <<
//		field1[a][b - 1] << field1[a][b - 1] << endl;*/
//
//	if (field1[a + 1][b] != '#' && field1[a + 1][b + 1] != '#' && field1[a + 1][b - 1] != '#'
//		&& field1[a - 1][b - 1] != '#' && field1[a - 1][b + 1] != '#' && field1[a - 1][b] != '#'
//		&& field1[a][b - 1] != '#' && field1[a][b + 1] != '#' && counter == 0) {
//		field1[a][b] = '#';
//	}
//	else if (counter != 0 && (field1[a + 1][b] == '#' || field1[a][b - 1] == '#' || field1[a][b + 1] == '#'
//		|| field1[a - 1][b] == '#')) {
//		int temp = 0;
//		if (field1[a + 1][b] == '#') temp++;
//		if (field1[a - 1][b] == '#') temp++;
//		if (field1[a][b + 1] == '#') temp++;
//		if (field1[a][b - 1] == '#') temp++;
//		if (temp == 1)	field1[a][b] = '#';
//	}
//	else cout << "Error Check Field, illegal number or field, retry " << endl;
//}
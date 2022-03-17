// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// 1 задача

#include "pch.h"
#include <iostream>
#include <stdio.h>
using namespace std;

/*

void main()
{	
	int num;
    cout << "Hello World!\n"; 
	cin >> num;
	int i, k;
	int power(int, int);
	for (i = 0; i < 10; i++) {
		k = power(num, i);
		cout << "i = " << i << ", k = " << k << endl;
	}
}
int power(int x, int n) {
	int i, p = 1;
	for (i = 0; i < n; i++) p *= x;
	return p;
} */
/*
#define PR(x) printf ("x=%u, *x=%d, &x=%u\n", x, *x, &x)
void main(void) {

	int mas[] = { 100, 200, 300 };
	int *ptr1, *ptr2;
	
	printf("%x \n", sizeof(int*));

	ptr1 = mas;
	ptr2 = &mas[2];
	printf("%x \n", ptr1);
	printf("%x \n", ptr2);
	PR(ptr1);
	ptr1++;
	PR(ptr1);
	PR(ptr2);
	++ptr2;
	printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
}*/

void main(void) {
	setlocale(LC_ALL, "Russian");
	int a = 2, b = 5;
	void obmen1(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	cout << "до обмена: a = " << a << ", b = " << b << endl;
	obmen1(a, b);
	cout << "после обмена 1 : a = " << a << ", b = " << b << endl;
	int* ptr = &a;
	int* ptr2 = &b;
	obmen2(ptr , ptr2);
	cout << "после обмена 2 : a = " << a << ", b = " << b << endl;

	int &ptr3 = a;
	int &ptr4 = b;

	obmen3(ptr3, ptr4);
	cout << "после обмена 3 : a = " << a << ", b = " << b << endl;

}

void obmen1(int x, int y) {
	int a = x, b = y;
	a = a + b;
	b = a - b;
	a = a - b;
	
	
}
void obmen2(int* x, int* y) {
	int buff;
	buff = *x;
	*x = *y;
	*y = buff;
}
void obmen3(int& x, int& y) {
	int *buff, bff;
	bff = x;
	x = y;
	y = bff;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

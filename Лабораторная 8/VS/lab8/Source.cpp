// ConsoleApplication1.cpp s: ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
#include <Windows.h>
#include <locale>
#include <fstream>


#define _CRT_SECURE_NO_WARNINGS
using namespace std;

const char fname[] = "NewFile.txt";

int main() {
	setlocale(LC_CTYPE, "rus");
	ofstream ofs(fname, ios::out);
	if (!ofs) {
		cout << "��������� ��������! ���� "
			<< fname
			<< " �� ���������� "
			<< endl;
		return 0;
	}
	else {
		ofs << "��� ������ ������������ � ����� ����";
		ofs.close();
		fstream fs;
		fs.open(fname, ios::out | ios::ate);
		fs << "addition made ";
		fs.close();

		fstream ifs(fname);

		if (ifs) {
			cout << "� ������ ����� ����������"
				<< "... " << endl;
			char Line[80];
			ifs.getline(Line, sizeof(Line));
			cout << Line;
		}
		else {
			cout << "��������� �������� "
				<< "��� ��������� �������� "
				<< fname
				<< endl;
		}
	}

	return 0;
}
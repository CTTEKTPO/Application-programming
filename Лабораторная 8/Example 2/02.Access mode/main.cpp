// ConsoleApplication1.cpp s: Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
		cout << "Wrong situation! File "
			<< fname
			<< " does not exist "
			<< endl;
		return 0;
	}
	else {
		ofs << "This line is written to a new file";
		ofs.close();
		fstream fs;
		fs.open(fname, ios::out | ios::ate);
		fs << "addition made ";
		fs.close();

		fstream ifs(fname);

		if (ifs) {
			cout << "The old file contains"
				<< "... " << endl;
			char Line[80];
			ifs.getline(Line, sizeof(Line));
			cout << Line;
		}
		else {
			cout << "Erroneous situation "
				<< "when reopening "
				<< fname
				<< endl;
		}
	}

	return 0;
}
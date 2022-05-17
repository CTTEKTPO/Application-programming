#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>

using namespace std;
class Stroka {
    char str[80];
public:
    Stroka(char*);
    Stroka(const char*);
    Stroka() {};
    Stroka(const Stroka&);
    Stroka& operator=(const Stroka&);
    Stroka& operator+(const Stroka&);
    int operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();


};

Stroka::Stroka(char* string) {
    strcpy(str, string);
}
Stroka::Stroka(const char* string) {
    strcpy(str, string);
}
Stroka::Stroka(const Stroka& s) {
    strcpy(str, s.str);
}
Stroka& Stroka::operator=(const Stroka& s) {
    strcpy(str, s.str);
    return *this;
}
Stroka& Stroka::operator+(const Stroka& s) {
    strcat(str, s.str);
    return *this;
}
int Stroka::operator==(const Stroka& s) {
    if ((strcmp(str, s.str)) == 0)
        return 1;
    else
        return 0;
}
int Stroka::dlina() {
    return strlen(str);
}
void Stroka::vvod() {
    cin >> str;
}
void Stroka::vyvod() {
    cout << str << endl;
}

int main(int argc, char* argv[])
{
    Stroka s1("qwerty"), s3, s4(s1), s5;
    printf("input s3: ");
    s3.vvod();
    s3 = "asdfg";
    s3.vyvod();
    s5 = s1 + s3 + s4;
    cout << "length s5 = " << s5.dlina() << endl;
    s5.vyvod();
    if (s1 == s5)
        cout << "String s1 and s5 is equals" << endl;
    else if (s1 == s4)
        cout << "Strings s1 and s4 is equals" << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

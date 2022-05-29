#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



class Stroka {
public:
    char str[80];
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

    friend std::ostream& operator << (std::ostream &out, Stroka& str) {
        return out << str.str;
    }
    friend std::istream& operator >> (std::istream &in, Stroka& str) {
        return in >> str.str;;
    }


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
    std::cin >> str;
}
void Stroka::vyvod() {
    std::cout << str << std::endl;
}
int main()
{
    Stroka s1("qwerty"), s3, s4(s1), s5;
    printf("input s3: ");
    s3.vvod();
    s3 = "asdfg";
    s3.vyvod();
    s5 = s1 + s3 + s4;
    std::cout << "length s5 = " << s5.dlina() << std::endl;
    s5.vyvod();
    if (s1 == s5)
        std::cout << "String s1 and s5 is equals" << std::endl;
    else if (s1 == s4)
        std::cout << "Strings s1 and s4 is equals" << std::endl;

    //-----Laboratory work ?8. Task 1 ------//
    Stroka s2;
    std::cout << "Enter s2: ";
    std::cin >> s2;
    std::cout << "s2: " << s2 << std::endl;
    //--------------------------------------//
    system("PAUSE");
    return 0;
}

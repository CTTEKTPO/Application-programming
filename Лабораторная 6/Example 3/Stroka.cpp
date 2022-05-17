
#include "Stroka.h"
#include <iostream>

int strLen1(const char* p) {
    int i = 0;
    while (*p++) i++;
    return i;
}
char* strCopy(char* str1, const char* str2) {
    int i = 0;

    while (str2[i] != '\0') { str1[i] = str2[i]; i++; }
    str1[i] = '\0';
    return str1;
}
char* strConcat(char* str1, const char* str2) {
    int i = strLen1(str1);
    int len = strLen1(str2);
    str1[i + len];
    for (int j = 0; j < len; j++) {
        str1[i] = str2[j];
        i++;
    }
    str1[i] = '\0';
    return str1;
}

bool strCompare(char* str1, const char* str2) {
    bool result = true;
    int i = 0;
    if (strLen1(str1) == strLen1(str2)) {
        for (; i < strLen1(str1); i++) {
            if (str1[0] == str2[0]) {}
            else return false;
        }
    }
    else return result = false;

    return result;
}

Stroka::Stroka(char* string) {
    strCopy(str, string);
}
Stroka::Stroka(const char* string) {
    strCopy(str, string);
}
Stroka::Stroka(const Stroka& s) {
    strCopy(str, s.str);
}
Stroka& Stroka::operator=(const Stroka& s) {
    strCopy(str, s.str);
    return *this;
}
Stroka& Stroka::operator+(const Stroka& s) {
    strConcat(str, s.str);
    return *this;
}
int Stroka::operator==(const Stroka& s) {
    if ((strCompare(str, s.str)) == 0)
        return 1;
    else
        return 0;
}
int Stroka::dlina() {
    return strLen1(str);
}
void Stroka::vvod() {
    std::cin >> str;
}
void Stroka::vyvod() {
    std::cout << str << std::endl;
}

#pragma once
#ifndef Stroka_H_
#define Stroka_H_

#include <iostream>

class Stroka {
private:
    
    char* str;
public:
    
    Stroka(char*);
    Stroka(const char*);
    Stroka(int size);
    Stroka() {};
    ~Stroka();
    Stroka(const Stroka&);
    Stroka& operator=(const Stroka&);
    Stroka& operator+(const Stroka&);
    Stroka& operator=(const char* s);
    char& operator[](size_t index);
    int operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();


};

#endif /* Stroka_H_ */

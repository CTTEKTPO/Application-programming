#ifndef Stroka_H_
#define Stroka_H_

#include <iostream>

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

#endif /* Stroka_H_ */

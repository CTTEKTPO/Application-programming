#include <cstdlib>
#include <iostream>
#include "Stroka.h"

using namespace std;

int main(int argc, char *argv[])
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

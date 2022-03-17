#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <string.h>


using namespace std;

int strLen1 (char *p){
    int i = 0;
    while (*p++) i++;
    return i;
}
int strLen2(char *p){ //в этой функции ищем конец строки а затем вычитаем адрес начала строки из адреса ее конца
    char *q = p;
    while (*q++);
    return q-p - 1;
}
int strLen3(char *p){
    int i = 0;
    while (p[i]!= '\0')i++;
    return i;    
}

char* strCopy(char *str1, char *str2){
     int i = 0;
     
     while(str2[i] != '\0'){str1[i] = str2[i]; i++;}
     str1[i] = '\0';
     return str1; 
}

bool strCompare(char *str1, char *str2){
    bool result = true;
    int i = 0;
    if (strLen1(str1) == strLen1(str2)){
       for(; i < strLen1(str1); i++){
               if (str1[0] == str2[0]){}
               else return false;
       }
    }else return result = false;
    
    return result;
}

char* strConcat(char *str1, char *str2){
      int i = strLen1(str1);
      int len = strLen1(str2);
      str1[i + len];
      for (int j = 0; j < len; j++){
          str1[i] = str2[j];
          i++;
      }
      str1[i] = '\0';
      return str1;
}
int strConstLength(const char* str)
{
    int size = 0;
    while (*str++) ++size;
    return size;
}

char* strConcat2(char *str3, char *str4){
      int i = strLen1(str3);
      int len = strLen1(str4);
      for (int j = 0; j < len; j++){
          str3[i] = str4[j];
          i++;
      }
      str3[i] = '\0';
      return str3;
}
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    
    char str1[] = "qwerty";
    char str2[] = "1234567890";
    
    cout << "str1= " << str1 << " str2= " << str2 << endl;
    cout << "длина str1=" << strLen1(str1) << " длина str2=" << strLen1(str2) << endl;
    cout << "длина str1=" << strLen2(str1) << " длина str2=" << strLen2(str2) << endl;
    cout << "длина str1=" << strLen3(str1) << " длина str2=" << strLen3(str2) << endl;
    cout << "Вызов функции копирования строк:\n";
    strCopy(str1, str2);
    cout << "Результат копирования: str1= " << str1 << ", str2= " << str2 << endl;
    cout << "Вызов функции сравнения строк:\n";
    if (strCompare(str1,str2)) cout << str1 << "=" << str2;
    else cout << "Строка str1 и str 2 не равны";
    strConcat(str1, str2);
    cout << "\nРезультат сцепления: str1= " << str1 << ", str2=" << str2 << endl;
	
    
    char* str3 = (char*)malloc(100);
    char* str4 = (char*)malloc(100);


    strcpy(str3, "qwerty");
    strcpy(str4, "HELP");
    //str3 = (char*)"qwerty";
    //str4 = (char*)"HELP_";

    cout << "str3= " << str3 << " str4= " << str4 << endl; 
    cout << "длина str3=" << strLen1(str3) << " длина str4=" << strLen1(str4) << endl;
    cout << "длина str3=" << strLen2(str3) << " длина str4=" << strLen2(str4) << endl;
    cout << "длина str3=" << strLen3(str3) << " длина str4=" << strLen3(str4) << endl;
    cout << "Вызов функции копирования строк:\n";
    strCopy(str3, str4);
    cout << "Результат копирования: str3= " << str3 << ", str4= " << str4 << endl;
    cout << "Вызов функции сравнения строк:\n";
    if (strCompare(str3,str4)) cout << str3 << "=" << str4;
    else cout << "Строка str3 и str4 не равны";
    strConcat(str3, str4);
    cout << "\nРезультат сцепления: str3= " << str3 << ", str4=" << str4 << endl;
    
    char *str5 = (char*)calloc(1, 50); //функция calloc выделяет n объектов размером m
    char* str6 = (char*)calloc(1, 50);
    
    strcpy(str5, "HelloHelloMan");
    strcpy(str6, "World!");
    cout << str5 << " " << str6 << endl;
    cout << strLen1(str5) << endl;

    char arrstr[4][11]{
        "Nice",
        "To",
        "Meet",
        "You"
    };
    
    cout << strLen1(arrstr[0]) << endl;
    cout << strConcat(arrstr[0], arrstr[1]) << endl;
    strCopy(arrstr[2], arrstr[3]);
    cout << arrstr[2] << " " << arrstr[3] << endl;
    cout << strCompare(arrstr[2], arrstr[3]) << endl;
    
    free(str3);
    free(str4);
    free(str5);
    free(str6);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

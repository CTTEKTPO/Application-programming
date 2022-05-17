#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void checkNonEmptyAndEmptyChar(char ch, int *empty, int *nonEmpty){
     bool check = false;
     for ( int i = 0; i < 33; i++ ){ 
         if (( char )i == ch || (char)127 == ch ){
            *empty = *empty + 1 ;
            check = true;
         }        
     }    
     if (!check) *nonEmpty = *nonEmpty + 1;
}
bool checkAsciiChar(char ch){
     bool check = true;
     for ( int i = 0; i < 33; i++ ){ 
         if (( char )i == ch || (char)127 == ch ){
            check = false;
         }        
     }
     return check; 
}     
/*
void substringSearch(char[] str, FILE *in, char[] name){
     char[] checkString;
    *in = fopen(name,"r");
    if (in == NULL)
       printf("Файл %s не открыт", name);
    else{
        while(!feof(in)){
}*/

int main(int argc, char *argv[]){
    
    setlocale(LC_ALL, "Russian");
    
    char ch, name [50], buffer[100];
    int valEmptyChar = 0, valNonEmptyChar = 0;
    int count = 0;
    
    printf ("Введите имя файла для просмотра: ");
    scanf("%s", name);
    FILE *in = fopen(name,"r");
    if (in == NULL){
       printf("Файл %s не открыт\n", name);
    }else{
        while(!feof(in)){
           
           ch = getc(in);
           if(ch == EOF) break;
           checkNonEmptyAndEmptyChar(ch, &valEmptyChar, &valNonEmptyChar);
           buffer[count] = ch;
           putchar(ch);
           count++;
        }
    
    
    cout << "\nКоличество пустых символов: " << valEmptyChar << endl << "Количество непустых символов: " << valNonEmptyChar << endl;
    cout << "Введите искомую строку: ";
    char search[80], newName[80],ch2;
    scanf("%s", search);
    if (strstr(buffer,search)){
       cout << "Строка найдена\n";
       char *ptrch = strstr(buffer,search);
       cout << "Введите имя файла для создания: ";
       scanf("%sf",newName);
       FILE *in_2 = fopen(newName,"w");
       if (in_2 == NULL)
          printf("Файл %s не cоздан", newName);
       else{
            do{
              ch2 = *ptrch;
              putc(ch2,in_2);
              *ptrch++;      
           }while(checkAsciiChar(ch2));     
       }
    fclose(in_2);   
    }else cout << "Строка не найдена" << endl;
    
}
    
    fclose(in);
	
    system("PAUSE");
    return EXIT_SUCCESS;
}



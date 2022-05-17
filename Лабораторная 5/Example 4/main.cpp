#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
void tab(char *ch, FILE *out){
     for(int i = 0; i < 8; i++){
             *ch = '\t';
             putc(*ch,out);
     }
}
int main(int argc, char *argv[])
{
    char ch, buff;
    char *chptr;
    char buffer[100];
    int count = 0, number = 49;
    FILE *in = fopen("test.txt","r");
    FILE *out = fopen("output.txt", "w");
    if ((in == NULL) && (out == NULL))
       printf("File test.txt or output.txt is not open\n");
    else{
             while(!feof(in)){
                ch = fgetc(in);
                if(feof(in)){
                             ch= ' ';
                             putc(ch,out);
                             putc(ch,out);
                             tab(&ch,out);
                             ch = number;
                             putc(ch,out);
                             break;                            
                }             
                if(ch != '\f'){
                      putc(ch,out);
                }
                if(ch == '\f'){
                
                     while(true){
                            ch = fgetc(in);
                            if (ch == '-'){
                                ch = ' ';
                                putc(ch,out);
                                count++;
                             }
                             if (count == 2){
                                       
                                tab(&ch,out);
                                ch = number;
                                putc(ch,out);
                                number++;
                                break;
                             }
                             }
                             }             
                count = 0;     
             }
        }         
    
    fclose(in);
    fclose(out);
    system("PAUSE");
    return EXIT_SUCCESS;
}

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char nameInput[50], nameOutput[50], key[50];
    char ch, encryptCh;
    int index = 0;
    
	if(argc == 1){
    printf("Enter the name of the source file: ");
    scanf("%s", nameInput);
    printf("Enter a file name with encryption: ");
    scanf("%s", nameOutput);
    printf("Enter the key: ");
    scanf("%s", key);
	}
	if(argc == 2){
    strcpy(nameInput,argv[1]);
	printf("Enter a file name with encryption: ");
    scanf("%s", nameOutput);
    printf("Enter the key: ");
    scanf("%s", key);
	}
	if(argc == 3){
    strcpy(nameInput,argv[1]);
    strcpy(nameOutput,argv[2]);        
	printf("Enter the key: ");
    scanf("%s", key);
	}
	if(argc == 4){
    strcpy(nameInput,argv[1]);
    strcpy(nameOutput,argv[2]);
    strcpy(key,argv[3]);
    }if(argc > 4){cout << "Error"; return 1;}       
	
		
    FILE *in = fopen( nameInput, "r" );
	FILE *out = fopen( nameOutput, "w" );
	if (( in != NULL ) && ( out != NULL )){
       while(!feof( in )){
                    ch = getc(in);
                    if(ch == EOF) break;
                    if(key[index] == '\0') index = 0; 
                    encryptCh = ch ^ key[index];
                    putc(encryptCh,out);
                    index++;             
       }
        fclose( in );
		fclose( out );
    } else{
      printf( "Failed to open files\n");
    }             
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

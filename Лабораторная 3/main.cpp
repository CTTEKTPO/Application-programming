#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;
void clrscr(){system ("cls");}

void sortMasMinMax(int *mas, int size){
    int imin = 0, imax = 0;
    for (int i = 0; i < size-1; i++){
        imin = i;
        for(int j = i+1; j < size; j++)
                if(mas[j] < mas [imin]) imin = j;
        int t = mas[i];
        mas[i] = mas[imin];
        mas[imin] = t;
    }  
    
}

void bubbleSort(int *mas, int size){
     int temp = 0;
     for (int i = 0; i < size; i++){
         for (int j = 0; j < size-1; j++){
             if (mas[j] > mas [j+1]){
                temp =  mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;
             }
         }
     }          
}

void bubbleSortDes(int *mas, int size){
     int temp = 0;
     for (int i = 0; i < size; i++){
         for (int j = 0; j < size-1; j++){
             if (mas[j] < mas [j+1]){
                temp =  mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;
             }
         }
     }          
}

void QuickSortR(int *mas, int size) {
     int i = 0, j = size-1;
     int temp, p;
     p = mas[size>>1];
     do {
        while (mas[i] < p) i++;
        while (mas[j] > p) j--;
        if (i <= j) {
        temp = mas[i];
        mas[i] = mas[j];
        mas[j] = temp;
        i++;
        j--;
        }
     }while (i<=j);
     if (j > 0) QuickSortR(mas, j);
     if (size > i) QuickSortR(mas+i, size-i);
}

void sortEvenOddElementsArr(int *mas,int size){
    int buffer = 0, buffer_2 = 0;
    for (int i = 0; i < size; i++)
        if (mas [i] % 2 == 0) buffer++;
        else buffer_2++;
    int masEven[buffer], masOdd[buffer_2];
    int k = 0, b = 0;
    for (int i = 0; i < size; i++)
        if (mas [i] % 2 == 0){masEven[k] = mas[i]; k++;}
        else {masOdd[b] = mas[i]; b++;}
    cout << "\nМассив четных значений из исходного:\n";       
    for (int i = 0; i < buffer; i++)cout << masEven[i] << ' ';
    cout << "\nМассив нечетных значений из исходного:"<<endl;
    for (int i = 0; i < buffer_2; i++)cout << masOdd[i] << ' ';
    cout << endl;
    bubbleSort(masEven,buffer);
    bubbleSortDes(masOdd,buffer_2);
    cout << "\nОтсортированный массив четных значений по возрастанию из исходного:\n";    
    for (int i = 0; i < buffer; i++)cout << masEven[i] << ' ';
    cout << "\nОтсортированный массив нечетных значений по убыванию из исходного:" << endl;
    for (int i = 0; i < buffer_2; i++)cout << masOdd[i] << ' ';
}

void bubbleSortAscInRangeN1N2(int *mas, int N1, int N2){
     
     int temp = 0;
     for (int i = N1; i < N2; i++){
         for (int j = N1; j < N2; j++){
             if (mas[j] > mas [j+1]){
                temp =  mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;
             }
         }
     }
     
}
void bubbleSortDesInRangeN1N2(int *mas, int N1, int N2){
     int temp = 0;
     for (int i = N1; i < N2; i++){
         for (int j = N1; j < N2; j++){
             if (mas[j] < mas [j+1]){
                temp =  mas[j];
                mas[j] = mas[j+1];
                mas[j+1] = temp;
             }
         }
     }
}        
int main(int argc, char *argv[])
{   
    setlocale (LC_ALL, "rus");
    int size = 10;
    int masMinMax[size], masBubbleSort[size], masQuickSortR[size], masSortEvenOdd[size],masSortAscInRange[size], masSortDesInRange[size];
    srand(time(NULL));
    
    for (int i = 0; i < size; i++){ 
        masMinMax[i] = rand()%1000-300;
        masBubbleSort[i] = rand()%1000-300;
        masQuickSortR[i] = rand()%1000-300;
        masSortEvenOdd[i] = rand()%1000-300;
        masSortAscInRange[i] = rand()%1000-300;
        masSortDesInRange[i] = rand()%1000;
    }
    
    cout <<"Первый исходный массив:\n";
    for (int i = 0; i < size; i++) cout << masMinMax[i] << ' ';
    sortMasMinMax(masMinMax,size);
    cout << "\nМассив после сортировки методом мини макса:\n";
    for (int i = 0; i < size; i++) cout << masMinMax[i] << ' ';
    
    cout <<"\n\nВторой исходный массив:\n";
    for (int i = 0; i < size; i++) cout << masBubbleSort[i] << ' ';
    bubbleSort(masBubbleSort,size);
    cout << "\nМассив после сортировки методом пузырька:\n";
    for (int i = 0; i < size; i++) cout << masBubbleSort[i] << ' ';
    
    cout <<"\n\nТретий исходный массив:\n";
    for (int i = 0; i < size; i++) cout << masQuickSortR[i] << ' ';
    QuickSortR(masQuickSortR,size);
    cout << "\nМассив после быстрой сортировки:\n";
    for (int i = 0; i < size; i++) cout << masQuickSortR[i] << ' ';
    
    cout <<"\n\nЧетвертый исходный массив:\n";
    for (int i = 0; i < size; i++) cout << masSortEvenOdd[i] << ' ';
    sortEvenOddElementsArr(masSortEvenOdd,size);  
    
    cout <<"\n\nПятый исходный массив:\n";
    for (int i = 0; i < size; i++) cout << masSortAscInRange[i] << ' ';
	int N1 = 2, N2 = 5;
    bubbleSortAscInRangeN1N2(masSortAscInRange,N1,N2);
    cout << "\nМассив после сортировки по возрастанию методом пузырька в заданном диапазоне от " << N1 << " до " << N2 << ":\n" ;
    for (int i = 0; i < size; i++) cout << masSortAscInRange[i] << ' ';
    
    cout <<"\nШестой исходный массив:\n";
    for (int i = 0; i < size; i++) cout << masSortDesInRange[i] << ' ';
    bubbleSortDesInRangeN1N2(masSortDesInRange,2,5);
    cout << "\nМассив после сортировки по убыванию методом пузырька в заданном диапазоне от " << N1 << " до " << N2 << ":\n";
    for (int i = 0; i < size; i++) cout << masSortDesInRange[i] << ' ';
    cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}



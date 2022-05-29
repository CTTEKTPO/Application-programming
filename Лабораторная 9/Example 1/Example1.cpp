#include <iostream>

using namespace std;

template<typename T>
void Sort(T array[], size_t size) {
	T tmp; 
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i] > array[j]) {	
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

class Money
{
	long dollars;
	int cents;

public:
	Money(){};
	Money(long, int);
	~Money();
	int operator>(const Money&);
	friend std::ostream& operator<<(std::ostream&, Money&);
};

Money::Money(long d, int c)
{
	dollars = d;
	cents = c;
}

Money::~Money() { }


int Money::operator>(const Money & amt)
{
	return dollars > amt.dollars || (dollars == amt.dollars && cents > amt.cents);
}

std::ostream & operator<<(std::ostream & os, Money & that)
{
	 
	os << "$" << that.dollars << "." << that.cents;
	return os;
}

int main (){
	
	/*Money mas [] ={Money (19,10),
				   Money (99,99),
				   Money (99,95),
				   Money (19,95)  
				  };*/
	double mas [] = {1.1,
					 5.3,
					 2.9,
					 4.0,
					 3.15
					};
	int sizez = sizeof(mas) / sizeof(mas[0]);
	Sort(mas, sizez);

	for (int i = 0; i < sizez; i++) {
		cout << "mas[" << i << "] = " << mas[i] << endl;
	}
	return 0;
	
}







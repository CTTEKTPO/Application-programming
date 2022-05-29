#include <stdlib.h>
#include <iostream>

template<typename T>
class Tstack
{
protected:
	int numItem;
	T* item;
public:
	Tstack(size_t size = 10) {
		numItem = 0;
		item = new T[size];
	}

	~Tstack() {
		delete[] item;
	}

	bool empty() {
		return this->numItem == 0;
	}

	void push(T t) {
		this->item[this->numItem++] = t;
	}
	T pop() {
		return item[--numItem];
	}

	T peek() {
		return item[numItem - 1];
	}

	size_t sizeNum() {
		return numItem;
	}
	T min() {

	}

};
template<typename T>
T getmin(T arr[], int from, int to) {
	int min = from;
	for (int i = from; i < to; i++) {
		if (arr[i] < arr[min]) {
			min = i;
		}
	}
	return arr[min];
}


//
int* sortWagons(int wagons[], size_t size) {
	int* way2 = (int*)malloc(sizeof(int) * size);

	Tstack <int> stk(size);
	int wayOneIndex = 0;h b
	int wayTwoIndex = 0;
	while (true) {
		if (wayOneIndex == size && stk.empty())
			break;

		int min = getmin(wagons, wayOneIndex, size);
		if (wagons[wayOneIndex] == min) {
			if (stk.empty()) {
				way2[wayTwoIndex] = wagons[wayOneIndex];
				wayTwoIndex++;
				wayOneIndex++;
			}
			else if (stk.peek() < wagons[wayOneIndex]) {
				way2[wayTwoIndex++] = stk.peek();
				stk.pop();
			}
			else {
				way2[wayTwoIndex] = wagons[wayOneIndex];
				wayTwoIndex++;
				wayOneIndex++;
			}
		}else stk.push(wagons[wayOneIndex++]);

		if (stk.sizeNum() > 1 && stk.peek()<= min) {
			if (stk.peek() < stk.peek() - 1) {
				way2[wayTwoIndex++] = stk.peek();
				stk.pop();
			}
			else {
				wagons[--wayOneIndex] = stk.peek();
				stk.pop();
			}
		}
	}
	return way2;
}



int main() {

	int wagons[] = { 1, 5, 3, 4, 6 };

	int wagons2[] = { 2,4,1,7,8,3 };
	int size = sizeof(wagons) / sizeof(wagons[0]);
	int* ptr = sortWagons(wagons, size);
	for (int i = 0; i < sizeof(wagons) / sizeof(wagons[0]);i++)
		std::cout << ptr[i] << " " << std::endl;
	std::cout << std::endl;
	/*
	int size2 = sizeof(wagons2) / sizeof(wagons2[0]);
	int* ptr2 = sortWagons(wagons2, size2);
	for (int i = 0; i < sizeof(wagons2) / sizeof(wagons2[0]);i++)
		std::cout << ptr2[i] << " " << std::endl;
		*/
	system("pause");
	return 0;
}



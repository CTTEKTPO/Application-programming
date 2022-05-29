#include <iostream> 
using namespace std;

template <typename T>
class List {
public:
	List();
	~List();

	void push_back(T data); //функция для добавления данных конец списка (или add в C#)
	void push_front(T data); //добавить элемент в начало списка
	void pop_front(); //удаление головного элемента списка
	void pop_back();//удаление последнего элемента
	void clear(); //очистка всего списка
	int GetSize() { return Size; } 
	T& operator[](const int index);
	void insert(T data, int index);//вставка элемента внутрь списка
	void removeAt(int index); //удаление элемента по указанному индексу

private:

	template <typename T>
	//Класс элемента (узел)
	class Node {
	public:
		Node* pNext; //Указатель на следующий элемент
		T data;
		// T() - при передаче в Node класса вызывает его конструктор по-умолчанию 
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size; //переменная для хранения кол-ва элементов в списке
	Node <T> *head; // самый первый элемент списка
};

template <typename T>
List<T>::List() {

	//инициализация
	Size = 0;
	head = nullptr;
}
template <typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	//Если элемента нет создаем первый
	if (head == nullptr)
	{
		head = new Node <T>(data);
	}
	//Иначе ищем конец списка и добавляем новый элемент
	else
	{
		Node <T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data,head);
	Size++;
}

template<typename T>
void List<T>::pop_front()
{
	
	Node <T> *temp = head; 
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::clear()
{
	while (Size) 
	{
		pop_front();
	}
}

//Получение данных в списке по индексу элемента
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node <T>* current = this->head;
	while (current != nullptr) //пока не конец списка выполнять
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node <T>* newNode = new Node <T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}

	
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
		pop_front();
	else
	{
		Node <T>* previous = this->head;
		for (int i = 0; i < index-1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;

	}
}



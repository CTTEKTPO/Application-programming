#include <iostream>
#include "bus_info.cpp"
#include "LinkedList.cpp"

void print_list(List<bus_info>& lst) {
	for (int i = 0; i < lst.GetSize(); i++) {
		bus_info b = lst[i];
		std::cout << "[" << i << "] "
				  << "["<< b.bus_id <<"] " 
			      << "[" << b.driver_name << "] " 
				  << "[" << b.route_id << "]\n";
	}
}

int main() 
{
	setlocale(LC_ALL, "rus");
	List<bus_info> lst_free;
	List<bus_info> lst_busy;
	bus_info first = bus_info(6, "Алексеев П.М.", 15);
	bus_info second = bus_info(8, "Иванов И.И.", 23);
	bus_info third = bus_info(7, "Пешков А.Д.", 44);
	lst_free.push_back(first);
	lst_free.push_back(second);
	lst_free.push_back(third);
	cout << "Структура: \n"
		 << "[Порядковый номер в списке]"
		 << "[Номер автобуса]" 
		 << "[ФИО водителя]"
		 << "[Номер маршрута]\n";
	cout << "Автобусы в парке:\n";
	print_list(lst_free);
	std::cout << "Доступные операции:\n"
		<< "print_free     - вывести свободные автобусы\n"
		<< "print_busy     - вывести автобусы на маршруте\n"
		<< "add_free id - добавить автобус из занятых в свободные\n"
		<< "add_busy id - добавить автобус из свободных в занятые\n"
		<< "где id - порядковый номер \n"
		<< "exit          - выход\n";

	while (true) {
		string command;
		int idx;

		cout << " > ";
		cin >> command;
		if (command == "print_free") {
			cout << "Автобусы в парке:\n";
			print_list(lst_free);
		}
		else if (command == "print_busy") {
			cout << "Автобусы на маршруте:\n";
			print_list(lst_busy);
		}
		else if (command == "add_free") {
			cin >> idx;
			if (idx >= lst_busy.GetSize() || idx < 0) {
				std::cout << "Автобуса под номером " << idx << " нет в списке\n";
				continue;
			}
			
			bus_info buff = lst_busy[idx];
			lst_busy.removeAt(idx);
			lst_free.push_back(buff);
			cout << "  " << buff.bus_id << " " << buff.driver_name << " " << buff.route_id << " вернулся в парк \n";
		}
		else if (command == "add_busy") {
			std::cin >> idx;
			if (idx >= lst_free.GetSize() || idx < 0) {
				std::cout << "Автобуса под номером " << idx << " нет в списке\n";
				continue;
			}
			
			if (idx == first.getBusId()) idx = 0;
			if (idx == second.getBusId()) idx = 1;
			if (idx == third.getBusId()) idx = 2;
			bus_info buff = lst_free[idx];
			lst_free.removeAt(idx);
			lst_busy.push_back(buff);
			cout << "  " << buff.bus_id << " " << buff.driver_name << " " << buff.route_id << " вышел в рейс \n";
		}
		else if (command == "exit") {
			exit(0);
		}
		else {
			cout << "Неизвестная команда.\n";
		}
	}
	
	return 0;
}

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
	bus_info first = bus_info(6, "�������� �.�.", 15);
	bus_info second = bus_info(8, "������ �.�.", 23);
	bus_info third = bus_info(7, "������ �.�.", 44);
	lst_free.push_back(first);
	lst_free.push_back(second);
	lst_free.push_back(third);
	cout << "���������: \n"
		 << "[���������� ����� � ������]"
		 << "[����� ��������]" 
		 << "[��� ��������]"
		 << "[����� ��������]\n";
	cout << "�������� � �����:\n";
	print_list(lst_free);
	std::cout << "��������� ��������:\n"
		<< "print_free     - ������� ��������� ��������\n"
		<< "print_busy     - ������� �������� �� ��������\n"
		<< "add_free id - �������� ������� �� ������� � ���������\n"
		<< "add_busy id - �������� ������� �� ��������� � �������\n"
		<< "��� id - ���������� ����� \n"
		<< "exit          - �����\n";

	while (true) {
		string command;
		int idx;

		cout << " > ";
		cin >> command;
		if (command == "print_free") {
			cout << "�������� � �����:\n";
			print_list(lst_free);
		}
		else if (command == "print_busy") {
			cout << "�������� �� ��������:\n";
			print_list(lst_busy);
		}
		else if (command == "add_free") {
			cin >> idx;
			if (idx >= lst_busy.GetSize() || idx < 0) {
				std::cout << "�������� ��� ������� " << idx << " ��� � ������\n";
				continue;
			}
			
			bus_info buff = lst_busy[idx];
			lst_busy.removeAt(idx);
			lst_free.push_back(buff);
			cout << "  " << buff.bus_id << " " << buff.driver_name << " " << buff.route_id << " �������� � ���� \n";
		}
		else if (command == "add_busy") {
			std::cin >> idx;
			if (idx >= lst_free.GetSize() || idx < 0) {
				std::cout << "�������� ��� ������� " << idx << " ��� � ������\n";
				continue;
			}
			
			if (idx == first.getBusId()) idx = 0;
			if (idx == second.getBusId()) idx = 1;
			if (idx == third.getBusId()) idx = 2;
			bus_info buff = lst_free[idx];
			lst_free.removeAt(idx);
			lst_busy.push_back(buff);
			cout << "  " << buff.bus_id << " " << buff.driver_name << " " << buff.route_id << " ����� � ���� \n";
		}
		else if (command == "exit") {
			exit(0);
		}
		else {
			cout << "����������� �������.\n";
		}
	}
	
	return 0;
}

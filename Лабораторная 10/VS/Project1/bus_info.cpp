#include <iostream>

struct bus_info {
	int bus_id;
	std::string driver_name;
	int route_id;
	bus_info(int bus, std::string driver, int route) 
	{
		this->bus_id = bus;
		this->driver_name = driver;
		this->route_id = route;
	}
	bus_info() {};
	int getBusId() { return bus_id; }

};
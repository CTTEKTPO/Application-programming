#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	
	char c;
	
	ifstream ifs("1.txt");
	if (!ifs)
	{
		cout << "File not open\n";
		return 1;
	}

	ofstream ofs("2.txt");
	if (!ofs)
	{
		cout << "File not open\n";
		return 1;
	}


	while (ifs.get(c)) //пока нет ошибок
	{
		c = toupper(c);
		ofs.put(c);
		cout << "character copy successful" << endl;
	}
	return 0;
}
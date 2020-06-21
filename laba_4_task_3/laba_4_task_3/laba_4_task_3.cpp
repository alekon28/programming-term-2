#include "Array.h"

int main()
{

	Array arr_50(50);
	Array arr_100(100);
	Array arr_1000(1000);

	cout << "--------------------------------------------------------------------------------------------------\n";
	cout << "MAX\t" << "MIN\t" << "LENGTH\t" << "EXPECTED VALUE\t" << "REAL EXPECTED VALUE\t" << "XI VALUE\n";
	cout << arr_50.get_MAX() 
		<< "\t" << arr_50.get_MIN() 
		<< "\t" << arr_50.get_length() 
		<< "\t" << arr_50.expected_value() 
		<< "\t\t" << arr_50.real_expected_value() 
		<< "\t\t\t" << arr_50.xi() << "\n";
	cout << arr_100.get_MAX() 
		<< "\t" << arr_100.get_MIN() 
		<< "\t" << arr_100.get_length() 
		<< "\t" << arr_100.expected_value() 
		<< "\t\t" << arr_100.real_expected_value() 
		<< "\t\t\t" << arr_100.xi() << "\n";
	cout << arr_1000.get_MAX() 
		<< "\t" << arr_1000.get_MIN() 
		<< "\t" << arr_1000.get_length() 
		<< "\t" << arr_1000.expected_value() 
		<< "\t\t" << arr_1000.real_expected_value() 
		<< "\t\t\t" << arr_1000.xi() << "\n";
	cout << "--------------------------------------------------------------------------------------------------\n";
}

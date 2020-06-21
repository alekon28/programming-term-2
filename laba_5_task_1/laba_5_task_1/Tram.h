#pragma once
#include <vector>
#include <string>
using namespace std;

class Tram
{
private:
	int tram_number;
	vector<string> stops;

public:
	Tram(int tram_number, vector<string> stops) {
		this->tram_number = tram_number;
		this->stops = stops;
	};
};


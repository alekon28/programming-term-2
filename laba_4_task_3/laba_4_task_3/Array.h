#include <vector>
#include <random>
#include <iostream>
#include <ctime>
using namespace std;

class Array
{
private:
	uint32_t LENGTH;
	vector<uint32_t> ARRAY;
	int MIN;
	int MAX;
	ranlux48_base generator;
	uniform_int_distribution<> distribution;
	
public:
	Array(uint32_t LENGTH) {
		this->LENGTH = LENGTH;
		this->MIN = int(1);
		this->MAX = int(100);
		this->generator = ranlux48_base(time(NULL));
		this->distribution = uniform_int_distribution<>(1,100);
		fill_arrays();
	}

	void fill_arrays(void) {
		for (uint32_t i = 0; i < LENGTH; i++) {
			ARRAY.push_back(distribution(generator));
		}
	}

	void display(void) {
		cout << endl;
		for (auto ptr : ARRAY) {
			cout << ptr << " ";
		}
		cout << endl;
	}

	double expected_value(void) {
		double res = 0;
		for (int i = MIN; i <= MAX; i++) {
			res += (i * (0.01));
		}
		return res;
	}

	double real_expected_value(void) {
		double n = 0;
		double res = 0;
		for (int i = MIN; i <= MAX; i++) {
			for (auto ptr : ARRAY) {
				if (ptr == i) {
					n++;
				}
			}
			res += i * (n / double(LENGTH));
			n = 0;
		}
		return res;
	}

	double xi(void) {
		double xi = 0, Vexp = LENGTH / 100.0, Vn = 0.0;
		for (int i = MIN; i <= MAX; i++) {
			for (auto ptr : ARRAY) {
				if (ptr == i) {
					Vn++;
				}
			}
			xi += (pow(Vn - (Vexp), 2) / (Vexp));
			Vn = 0;
		}
		return xi;
	}

	uint32_t get_length(void) {
		return LENGTH;
	}

	int get_MIN(void) {
		return MIN;
	}

	int get_MAX(void) {
		return MAX;
	}
};

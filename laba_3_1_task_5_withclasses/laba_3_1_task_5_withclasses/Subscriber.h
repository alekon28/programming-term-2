#pragma once
#include<string>
#include<vector>
using namespace std;
class Subscriber
{
protected:
	string message;
	string current_message;
	vector<int> formated_message;
	vector<int> current_formated_message;
	int enc_key;
	int dec_key;
	int p;

private:
	int write_decrypt_key(int a, int m) {
		if (a == 1)
			return 1;
		return ((1 - write_decrypt_key(m % a, a) * m) / a + m);
	}

public:
	Subscriber(int enc_key, int p, string message) 
	{
			this->enc_key = enc_key;
			this->p = p;
			this->message = message;
			this->current_message = message;
			this->dec_key = write_decrypt_key(enc_key, p - 1);
	}
	int get_enc_key(void) {
		return enc_key;
	}
	int get_dec_key(void) {
		return dec_key;
	}
};


#pragma once
#include "Message.h"
class Crypto :
	public Message
{
private:
	int pwr_mod(int a, int x, int p) 
	{
		int exp = (x % (p - 1));
		int res = a % p;
		for (int i = 0; i < exp - 1; i++) {
			res = (res * a) % p;
		}
		return res;
	}

public:

	Crypto(int enc_key, int p, string message) : Message(enc_key, p, message) {}

	void encrypt(void) 
	{
		format_to_ord();
		for (auto i : formated_message) {
			current_formated_message.push_back(pwr_mod(i, enc_key, p));
			//cout <<"chr: "<< i << endl;
			//cout <<"mod: "<< pwr_mod(i, enc_key, p) << endl;
		}
		clear_current_message();
		format_to_str();
		formated_message.clear();
		current_formated_message.clear();
	}

	void decrypt(void)
	{
		format_to_ord();
		for (auto i : formated_message) {
			current_formated_message.push_back(pwr_mod(i, dec_key, p));
		}
		clear_current_message();
		format_to_str();
		formated_message.clear();
		current_formated_message.clear();
	}
};


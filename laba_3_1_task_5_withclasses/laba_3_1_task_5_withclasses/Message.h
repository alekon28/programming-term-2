#pragma once
#include "Subscriber.h"
class Message :
	public Subscriber
{
public:
	Message(int enc_key, int p, string message) : Subscriber(enc_key, p, message) {}

public:
	void get_message(string mes)
	{
		//cout <<"->>This is mes: " <<mes<<endl;
		current_message = mes;
	}

	string send_message(void)
	{
		return current_message;
	}

protected:	
	void format_to_ord(void)
	{
		formated_message.clear();
		for (char c : current_message) {
			//cout << "->> This is c(ord): " << c << endl;
			formated_message.push_back((unsigned int)(c));
		}
	}

	void format_to_str(void)
	{
		for (unsigned int c : current_formated_message) {
			//cout << "->> This is c(str): " << c << endl;
			current_message += (char)(c);
		}
	}

	void clear_current_message(void) 
	{
		current_message.clear();
	}
};


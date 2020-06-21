#include <iostream>
#include "Crypto.h"
using namespace std;
int main()
{
    cout << "--- Shamir's alghorithm ---\n";
    string message;
    cout << "Input Secret message: ";
    cin >> message;
    int p = 127;
    int KeyA = 101;
    int KeyB = 67;
    Crypto a(KeyA, p, message);
    Crypto b(KeyB, p, message);
    cout << "-> p = " << p << "\n";
    cout << "-> Subscriber A encrypt/decrypt key: " << a.get_enc_key() << "/" << a.get_dec_key() << "\n";
    cout << "-> Subscriber B encrypt/decrypt key: " << b.get_enc_key() << "/" << b.get_dec_key() << "\n";
    cout << "-> Message: " << message << "\n";
    a.encrypt();
    cout << "-> A encrypted this message: " << a.send_message() << "\n";
    cout << "Sending message to B...\n\n";
    b.get_message(a.send_message());
    //cout << "\nb get messege: "<<b.send_message()<<endl;
    b.encrypt();
    cout << "-> B encrypted received message: " << b.send_message() << "\n";
    cout << "Sending message to A...\n\n";
    a.get_message(b.send_message());
    a.decrypt();
    cout << "-> A decrypted received message: " << a.send_message() << "\n";
    cout << "Sending message to B...\n\n";
    b.get_message(a.send_message());
    b.decrypt();
    cout << "-> B decrypted received message: " << b.send_message() << "\n";
}



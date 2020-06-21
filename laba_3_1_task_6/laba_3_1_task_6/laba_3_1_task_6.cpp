#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<uint32_t> fill_sequence(uint32_t a, uint32_t p, uint32_t t) {
    vector<uint32_t> seq;
    for (int i = 0; i <= t; i++) {
        seq.push_back(uint32_t(pow(a, (uint32_t(pow(2, i))) % (p - 1))) % p);
    }
    return seq;
}

vector<uint32_t> fill_bin(uint32_t x, uint32_t t) {
    uint32_t current_x = x;
    vector<uint32_t> bin;
    while (current_x > 1) {
        bin.push_back(current_x % 2);
        current_x = uint32_t(current_x / 2);
    }
    bin.push_back(current_x);
    return bin;
}

vector<uint32_t> fill_pwr_bin_sequence(const vector<uint32_t>& seq, const vector<uint32_t>& bin, uint32_t i_end) {
    vector<uint32_t> pwr;
    for (int i = 0; i <= i_end; i++) {
        pwr.push_back(uint32_t(pow(seq[i], bin[i])));
    }
    return pwr;
}

int result(uint32_t p, const vector<uint32_t>& pwr) {
    uint32_t res = 1;
    for (auto i : pwr) {
        res *= i;
    }
    return res % p;
}

void output(uint32_t log_x, uint32_t x, const vector<uint32_t>& seq, const vector<uint32_t>& bin, const vector<uint32_t>& pwr) {
    for (int i = 0; i <= log_x; i++) cout << "a^" << pow(2, i) << "\t";
    cout << endl;
    for (auto i : seq) {
        cout << i << '\t';
    }
    cout << endl << endl;

    for (auto i : bin) {
        cout << i << ' ';
    }
    cout << endl << endl;

    for (int i = 0; i <= log_x; i++) cout << "a^" << pow(2, i) << "\t";
    cout << endl;
    for (auto i : pwr) {
        cout << i << '\t';
    }
    cout << endl << endl;
}

int main()
{
    unsigned int a, x, p;
    cout << "a ^ x mod p\n";
    cout << "Input a: ";
    cin >> a;
    cout << "Input x: ";
    cin >> x;
    cout << "Input p: ";
    cin >> p;
    vector<uint32_t> bin;
    vector<uint32_t> sequence;
    vector<uint32_t> pwr_bin_sequence;
    uint32_t log_2_x = uint32_t(log(x)/log(2));
    bin = fill_bin(x, log_2_x);
    sequence = fill_sequence(a, p, log_2_x);
    pwr_bin_sequence = fill_pwr_bin_sequence(sequence, bin, log_2_x);
    output(log_2_x, x, sequence, bin, pwr_bin_sequence);
    uint32_t resultat = result(p, pwr_bin_sequence);
    cout << "\nAnswer: " << resultat << endl << endl;

}


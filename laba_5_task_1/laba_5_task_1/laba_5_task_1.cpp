#include <iostream>
#include <string>
//#include "Tram.h"
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <map>

using namespace std;

string input_cmd(void) {
    string cmd;
    cin >> cmd;
    //cin.ignore();
    return cmd;
}

void CREATE_TRAM(map<int, vector<string>>& trams) {
    string tram_number;
    string current_stop;
    string stops_counter;
    int TRAM_NUMBER;
    int STOPS_COUNER;
    vector<string> stops;

    cin >> tram_number;
    TRAM_NUMBER = atoi(tram_number.c_str());
    //cin.ignore();

    cin >> stops_counter;
    STOPS_COUNER = atoi(stops_counter.c_str());
    //cin.ignore();

    for (int i = 0; i < STOPS_COUNER;i++) {
        cin >> current_stop;
        //cin.ignore();
        stops.push_back(current_stop);
        current_stop.clear();
    }
    trams.emplace(TRAM_NUMBER,stops);
}

void TRAMS_IN_STOP(const map<int, vector<string>>& trams) {
    string stop;
    bool stop_exist = false;

    cin >> stop;
    //cin.ignore();

    for (auto trams : trams) {
        for (auto cur_stop : trams.second) {
            if (cur_stop == stop) {
                if (!stop_exist) {
                    cout << "Stop " << stop << ": ";
                }
                stop_exist = true;
                cout << " " << trams.first;
            }
        }
    }
    if (!stop_exist) {
        cout << "Stop is absent";
    }
    cout << "\n";
}

void STOPS_IN_TRAM(const map<int, vector<string>>& trams) {
    string tram_num;
    int tram_number;
    bool tram_exist = false;

    cin >> tram_num;
    //cin.ignore();

    
    tram_number = atoi(tram_num.c_str());
    for (auto trams : trams) {
        if (trams.first == tram_number) {
            tram_exist = true;
            cout << "TRAM " << tram_number << ": ";
            for (auto stop : trams.second) {
                cout << " " << stop;
            }
        }
    }
    if (!tram_exist) {
        cout << "Tram is absent";
    }
    cout << "\n";
}

void TRAMS(const map<int, vector<string>>& trams) {
    if (trams.empty()) {
        cout << "Trams is absent\n";
    }
    else {
        for (auto tram : trams) {
            cout << "TRAM " << tram.first << ": ";
            for (auto stop : tram.second) {
                cout << " " << stop;
            }
            cout << "\n";
        }
    }
}

int main()
{
    string command;
    map<int,vector<string>> trams;

    while (true) {
        command = input_cmd();
        cout << "-> " << command << "\n";
        if (command == "CREATE_TRAM") {
            CREATE_TRAM(trams);
        }
        else if (command == "TRAMS_IN_STOP") {
            TRAMS_IN_STOP(trams);
        }
        else if (command == "STOPS_IN_TRAM") {
            STOPS_IN_TRAM(trams);
        }
        else if (command == "TRAMS") {
            TRAMS(trams);
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Invalid commad :(\n";
            continue;
        }
    }

}
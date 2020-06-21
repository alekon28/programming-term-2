#include <iostream>
#include <map>
#include <string>

using namespace std;

void change(map <string, string>& regions) {
    string region;
    string new_center;
    string old_center;
    bool region_exists = false;

    cin >> region;
    cin >> new_center;

    for (auto ptr : regions) {
        if (ptr.first == region) {
            region_exists = true;
            old_center = ptr.second;
            break;
        }
    }

    regions[region] = new_center;

    if (region_exists) {
        cout << "Region " << region << " has changed its administrative center from " << old_center << " to " << new_center << endl;
    }
    else {
        cout << "New region " << region << " with administrative center " << new_center << endl;
    }
}

void rename(map <string, string>& regions) {
    string old_region;
    string new_region;
    string old_center;
    bool correct = false;

    cin >> old_region;
    cin >> new_region;

    for (auto ptr : regions) {
        if (ptr.first == old_region) {
            old_center = ptr.second;
            regions.erase(old_region);
            regions[new_region] = old_center;
            correct = true;
            break;
        }
    }
    
    if (correct) {
        cout << old_region << " has been renamed to " << new_region << endl;
    }
    else { cout << "-> NOT CORRECT <-"; }
}

void about(const map <string, string>& regions) {
    string region;

    cin >> region;
    for (auto ptr : regions) {
        if (ptr.first == region) {
            cout << region << " has administrative center " << ptr.second << endl;
        }
    }
    
}

void all(const map <string, string>& regions) {
    for (auto ptr : regions) {
        cout << ptr.first << " - " << ptr.second << endl;
    }
}


int main()
{
    map <string, string> regions;
    int number_requests;
    string command;

    cin >> number_requests;

    for (int i = 0; i < number_requests; i++) {
        cin >> command;
        if (command == "CHANGE") {
            change(regions);
        } 
        if (command == "RENAME") {
            rename(regions);
        }
        if (command == "ABOUT") {
            about(regions);
        }
        if (command == "ALL") {
            all(regions);
        }

    }
}
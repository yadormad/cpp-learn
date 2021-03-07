#include <string>
#include <iostream>
#include <map>

using namespace std;

map<string, string> countries;

void change_capital(const string& country, string new_capital) {
    auto country_iterator = countries.find(country);
    if (country_iterator == countries.end()) {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    } else if (country_iterator->second != new_capital) {
        cout << "Country " << country << " has changed its capital from " << country_iterator->second << " to " << new_capital << endl;
    } else {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    }
    countries[country] = new_capital;
}

void rename(const string& old_country, string new_country) {
    auto old_country_iterator = countries.find(old_country);
    auto new_country_iterator = countries.find(new_country);
    if (old_country_iterator == countries.end() || old_country == new_country || new_country_iterator != countries.end()) {
        cout << "Incorrect rename, skip" << endl;
    } else {
        countries[new_country] = countries[old_country];
        countries.erase(old_country);
        cout << "Country " << old_country << " with capital " << countries[new_country] << " has been renamed to " << new_country << endl;
    }
}

void about(string& country) {
    auto country_iterator = countries.find(country);
    if (country_iterator == countries.end()) {
        cout << "Country " << country << " doesn't exist" << endl;
    } else {
        cout << "Country " << country << " has capital " << country_iterator->second << endl;
    }
}

void dump() {
    if (countries.size() == 0) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (auto country : countries) {
            cout << country.first << '/' << country.second << ' ';
        }
        cout << endl;
    }
}

int main() { 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            change_capital(country, new_capital);
        }
        if (command == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            rename(old_country_name, new_country_name);
        }
        if (command == "ABOUT") {
            string country;
            cin >> country;
            about(country);
        }
        if (command == "DUMP") {
            dump();
        }
    }
}

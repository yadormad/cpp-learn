#include <string>
#include <map>
#include <iostream>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        history_first_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        history_last_name[year] = last_name;
    }
    string GetFullName(int year) {
        auto first_name = FindName(history_first_name, year);
        auto last_name = FindName(history_last_name, year);
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
            // return full_name->second.firstName + ' ' + full_name->second.lastName;
        }
        if (first_name.empty()) {
            return last_name + " with unknown first name";
        }
        if (last_name.empty()) {
            return first_name + " with unknown last name";
        }
        return first_name + ' ' + last_name;
    }
private:
    string FindName (const map<int, string>& history, int year) {
        auto name_it = history.upper_bound(year);
        if (name_it == history.begin()) {
            return "";
        }
        --name_it;
        return name_it->second;
    }

    map<int, string> history_first_name;
    map<int, string> history_last_name;
};

int main() {
    Person person;
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    return 0;
}

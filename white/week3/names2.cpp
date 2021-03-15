#include <string>
#include <map>
#include <vector>
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
        return GetFullNameString(first_name, last_name);
    }
    string GetFullNameWithHistory(int year) {
        auto first_name_history = NameHistoryAsString(FindNameHistory(history_first_name, year));
        auto last_name_history = NameHistoryAsString(FindNameHistory(history_last_name, year));
       
        return GetFullNameString(first_name_history, last_name_history);
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

    vector<string> FindNameHistory (const map<int, string>& history, int year) {
        vector<string> result;
        auto name_it = history.upper_bound(year);
        string prev_name;
        while (name_it != history.begin()) {
            --name_it;
            if (name_it->second != prev_name) {
                result.push_back(name_it->second);
                prev_name = name_it->second;
            }
        }
        return result;
    }

    string NameHistoryAsString(const vector<string>& name_with_history) {
        if (name_with_history.empty()) {
            return "";
        }
        if (name_with_history.size() == 1) {
            return name_with_history[0];
        }
        string history = "";
        for (int i = 1; i < name_with_history.size(); i++) {
            if (i != 1) {
                history += ", ";
            }
            history += name_with_history[i];
        }
        return name_with_history[0] + " (" + history + ")";
    }

    string GetFullNameString(const string& first_name, const string& last_name) {
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }
        if (first_name.empty()) {
            return last_name + " with unknown first name";
        }
        if (last_name.empty()) {
            return first_name + " with unknown last name";
        }
        return first_name + ' ' + last_name;
    }

    map<int, string> history_first_name;
    map<int, string> history_last_name;
};

int main() {
 Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1965, "Appolinaria");

  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1965, "Volkova");
  person.ChangeLastName(1965, "Volkova-Sergeeva");

  for (int year : {1964, 1965, 1966}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
}

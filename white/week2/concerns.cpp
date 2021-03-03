#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<int> month_sizes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Add(vector<vector<string>>& calendar) {
    int i;
    string task;
    cin >> i >> task;
    i--;
    calendar[i].push_back(task);
}

void Dump(const vector<vector<string>>& calendar) {
    int i;
    cin >> i;
    i--;
    cout << calendar[i].size() << ' ';
    for (auto task: calendar[i]) {
        cout << task << ' ';
    }
    cout << endl;
}

void Next(vector<vector<string>>& calendar, int& current_month) {
    const int current_size = calendar.size();
    const int next_size = month_sizes[(current_month + 1) % month_sizes.size()];
    vector<string> transfered_tasks;
    for (int i = next_size; i < current_size; i++) {
        transfered_tasks.insert(end(transfered_tasks), begin(calendar[i]), end(calendar[i]));
    }
    calendar.resize(next_size);
    calendar.back().insert(end(calendar.back()), begin(transfered_tasks), end(transfered_tasks));
    current_month++;
}

int main() {
    int operation_count;
    int current_month = 0;
    vector<vector<string>> calendar(month_sizes[current_month]);
    cin >> operation_count;
    for (int i = 0; i < operation_count; i++) {
        string operation;
        cin >> operation;
        if (operation == "ADD") {
            Add(calendar);
        }
        if (operation == "DUMP") {
            Dump(calendar);
        }
        if (operation == "NEXT") {
            Next(calendar, current_month);
        }
    }
    return 0;
}
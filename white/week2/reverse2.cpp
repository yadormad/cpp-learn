#include <vector>
#include <iostream>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> reversed_v;
    for (int i = v.size() - 1; i >= 0; i--) {
        reversed_v.push_back(v[i]);
    }
    return reversed_v;
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int> reversed_numbers = Reversed(numbers);
    for (auto str : reversed_numbers) {
        cout << str << ' ';
    }
    cout << endl;
}
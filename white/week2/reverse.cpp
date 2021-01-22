#include <vector>
#include <iostream>

using namespace std;

void Reverse(vector<int>& v) {
    for (int i = 0; i < v.size() / 2; i++) {
        int tmp = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = tmp;
    }
}

int main() {
    vector<int> numbers = {1, 2};
    Reverse(numbers);
    for (auto str : numbers) {
        cout << str << ' ';
    }
    cout << endl;
}
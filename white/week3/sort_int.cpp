#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (auto& number: numbers) {
        cin >> number;
    }
    sort(numbers.begin(), numbers.end(), [](const int& i, const int& j) {
        return (abs(i) < abs(j));
    });
    for (auto& number: numbers) {
        cout << number << ' ';
    }
    cout << endl;
} 
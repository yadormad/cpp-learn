#include <string>
#include <iostream>

using namespace std;

void UpdateIfGreater(int first, int& second) {
    if (first > second) {
        second = first;
    }
}

int main() {
    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    b *= 2;
    cout << a << ' ' << b << endl;
}
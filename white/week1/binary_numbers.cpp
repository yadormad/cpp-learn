#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> vec = {};
    int i = 0;
    while (n > 0) {
        auto it = vec.begin();
        it = vec.insert(it, n % 2);
        n /= 2;
        i++;
    }
    for (auto digit:vec) {
        cout << digit;
    }
    return 0;
}

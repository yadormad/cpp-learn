#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int even = a + a % 2; even <= b; even += 2) {
        cout << even << ' ';
    }
    cout << endl;
    return 0;
}

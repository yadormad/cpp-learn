#include <iostream>
using namespace std;

int main()
{
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (n <= a) {
        cout << n << endl;
    } else if (n <= b) {
        cout << n * (1 - x * 0.01) << endl;
    } else {
        cout << n * (1 - y * 0.01) << endl;
    }
    return 0;
}

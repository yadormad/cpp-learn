#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            return 0;
        }
        cout << -c / b << endl;
        return 0;
    }
    double discr = b * b - 4 * a * c;
    if (discr < 0) {
        return 0;
    }
    if (discr != 0) {
        double x1 = (-b + sqrt(discr)) / (2 * a);
        double x2 = x1  - 2 * sqrt(discr) / (2 * a);
        cout << x1 << ' ' << x2 << endl;
        return 0;
    }
    double x = -b / (2 * a);
    cout << x << endl;
    return 0;
}

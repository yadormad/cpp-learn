#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    // a = 2; b = 3;
    int div = b;
    while (a % div != 0 || b % div != 0) {
        int temp_div_a, temp_div_b;
        temp_div_a = a % div;
        temp_div_b = b % div;
        div = temp_div_a > temp_div_b ? temp_div_a : temp_div_b;
    }
    cout << div;
    return 0;
}

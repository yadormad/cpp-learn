#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in;
    cin >> in;
    int f_counter = -2;
    int second_f_index;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 'f' && ++f_counter == 0) {
            second_f_index = i;
        }
    }
    if (f_counter >= 0) {
        cout << second_f_index << endl;
    } else {
        cout << f_counter << endl;
    }

    return 0;
}

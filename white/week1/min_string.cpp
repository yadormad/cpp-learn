#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string in_1, in_2, in_3;
    cin >> in_1 >> in_2 >> in_3;

    vector<string> input = {in_1, in_2, in_3};
    string min_string = input[0];
    for (auto s : input) {
        if (s < min_string) {
            min_string = s;
        }
    }

    cout << min_string << endl;
}

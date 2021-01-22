#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> temps(n);
    int temps_sum = 0;
    for (int& temp : temps) {
        temps_sum += temp;
        cin >> temp;
    }
    int avg_temp = temps_sum / n;
    vector<int> result_vec;
    for (int i = 0; i < temps.size(); i++) {
        if (temps[i] > avg_temp) {
            result_vec.push_back(i);
        }
    }
    cout << result_vec.size() << endl;
    for (auto res : result_vec) {
        cout << res << ' ';
    }
    cout << endl;
}
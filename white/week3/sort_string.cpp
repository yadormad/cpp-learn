#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string tolower_str(const string& str) {
    string result;
    for(const char& c : str) {
        result += (tolower(c));
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> strings(n);
    for (auto& str: strings) {
        cin >> str;
    }
    sort(begin(strings), strings.end(), [](const string& i, const string& j) {
        return (tolower_str(i) < tolower_str(j));
    });
    for (auto& str: strings) {
        cout << str << ' ';
    }
    cout << endl;
} 
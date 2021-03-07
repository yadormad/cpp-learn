#include <string>
#include <iostream>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word) {
    map<char, int> result;
    for (auto c: word) {
        ++result[c];
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string word1, word2;
        cin >> word1 >> word2;
        if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
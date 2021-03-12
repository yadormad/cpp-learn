#include <string>
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, set<string>> synonyms_map;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            synonyms_map[word1].insert(word2);
            synonyms_map[word2].insert(word1);
        }
        if (command == "COUNT") {
            string word;
            cin >> word;
            cout << synonyms_map[word].size() << endl;
        }
        if (command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (synonyms_map[word1].count(word2) == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

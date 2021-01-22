#include <string>
#include <iostream>

using namespace std;

bool IsPalindrom(string word) {
    for (int i = 0; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string word;
    cin >> word;
    cout << (IsPalindrom(word) ? "true" : "false") << endl;
}
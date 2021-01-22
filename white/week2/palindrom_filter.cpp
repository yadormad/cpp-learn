#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool IsPalindrom(string word) {
    for (int i = 0; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> filtered_words;
    for (auto word : words) {
        if (IsPalindrom(word) && word.size() >= minLength)
            filtered_words.push_back(word);
    }
    return filtered_words;
}

int main() {
    string word1, word2, word3;
    int minLen;
    cin >> word1 >> word2 >> word3 >> minLen;
    vector<string> words_vector = {word1, word2, word3};
    for (auto filtered_word : PalindromFilter(words_vector, minLen)) {
        cout << filtered_word << ' ';
    }
    cout << endl;
}
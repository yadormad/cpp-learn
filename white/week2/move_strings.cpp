#include <string>
#include <vector>
#include <iostream>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto str : source) {
        destination.push_back(str);
    }
    source.clear();
}

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    cout << "source: " << endl;
    for (auto str : source) {
        cout << str << ' ';
    }
    cout << "destination: " << endl;
    for (auto str : destination) {
        cout << str << ' ';
    }
    cout << endl;
}
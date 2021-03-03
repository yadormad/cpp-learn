#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ChangeQueueMember(vector<bool>& queue, bool value) {
    int i;
    cin >> i;
    queue[i] = value;
}

void Come(vector<bool>& queue) {
    int i;
    cin >> i;
    queue.resize(queue.size() + i);
}

void WorryCount(const vector<bool>& queue) {
    int count = 0;
    for (auto queue_member: queue) {
        if (queue_member) {
            count++;
        }
    }
}

int main() {
    int operation_count;
    vector<bool> queue(0, false);
    cin >> operation_count;
    for (int i = 0; i < operation_count; i++) {
        string operation;
        cin >> operation;
        if (operation == "WORRY") {
            ChangeQueueMember(queue, true);
        }
        if (operation == "COME") {
            Come(queue);
        }
        if (operation == "QUIET") {
            ChangeQueueMember(queue, false);
        }
        if (operation == "WORRY_COUNT") {
            queue
        }
    }
    return 0;
}
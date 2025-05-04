#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int findClosestRequest(const vector<int>& requests, int head, const vector<bool>& visited) {
    int minDistance = numeric_limits<int>::max();
    int index = -1;
    for (int i = 0; i < requests.size(); ++i) {
        if (!visited[i]) {
            int distance = abs(head - requests[i]);
            if (distance < minDistance) {
                minDistance = distance;
                index = i;
            }
        }
    }
    return index;
}

void SSTF(vector<int> requests, int head) {
    int totalSeekTime = 0;
    vector<bool> visited(requests.size(), false);
    vector<int> sequence;

    for (int i = 0; i < requests.size(); ++i) {
        int index = findClosestRequest(requests, head, visited);
        visited[index] = true;
        totalSeekTime += abs(head - requests[index]);
        head = requests[index];
        sequence.push_back(head);
    }

    cout << "\nSSTF Disk Scheduling Order: ";
    for (int sector : sequence) {
        cout << sector << " ";
    }
    cout << "\nTotal Seek Time: " << totalSeekTime << endl;
    cout << "Average Seek Time: " << (float)totalSeekTime / requests.size() << endl;
}

int main() {
    int n, head;
    vector<int> requests;

    cout << "Enter the number of disk requests: ";
    cin >> n;

    cout << "Enter the disk requests (cylinder numbers):\n";
    for (int i = 0; i < n; ++i) {
        int request;
        cin >> request;
        requests.push_back(request);
    }

    cout << "Enter the initial head position: ";
    cin >> head;

    SSTF(requests, head);

    return 0;
}

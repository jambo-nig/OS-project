#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void scanDiskScheduling(vector<int> requests, int head, int diskSize, string direction) {
    vector<int> left, right;
    vector<int> seekSequence;
    int seekCount = 0;
    int step = 1;

    cout << "\nInitial Head Position: " << head << endl;
    cout << "Direction of head movement: " << direction << endl;

    if (direction == "left")
        left.push_back(0);
    else if (direction == "right")
        right.push_back(diskSize - 1);

    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] < head)
            left.push_back(requests[i]);
        else if (requests[i] > head)
            right.push_back(requests[i]);
        else {
            cout << "Step " << step++ << ": Request at " << head << " is at current head. No movement.\n";
            seekSequence.push_back(head);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    cout << "\nStarting SCAN disk scheduling...\n";

    if (direction == "left") {
        for (int i = left.size() - 1; i >= 0; i--) {
            int distance = abs(head - left[i]);
            seekCount += distance;
            cout << "Step " << step++ << ": Move from " << head << " to " << left[i]
                 << " -> Seek = " << distance << endl;
            head = left[i];
            seekSequence.push_back(head);
        }
        for (int i = 0; i < right.size(); i++) {
            int distance = abs(head - right[i]);
            seekCount += distance;
            cout << "Step " << step++ << ": Move from " << head << " to " << right[i]
                 << " -> Seek = " << distance << endl;
            head = right[i];
            seekSequence.push_back(head);
        }
    } else {
        for (int i = 0; i < right.size(); i++) {
            int distance = abs(head - right[i]);
            seekCount += distance;
            cout << "Step " << step++ << ": Move from " << head << " to " << right[i]
                 << " -> Seek = " << distance << endl;
            head = right[i];
            seekSequence.push_back(head);
        }
        for (int i = left.size() - 1; i >= 0; i--) {
            int distance = abs(head - left[i]);
            seekCount += distance;
            cout << "Step " << step++ << ": Move from " << head << " to " << left[i]
                 << " -> Seek = " << distance << endl;
            head = left[i];
            seekSequence.push_back(head);
        }
    }

    cout << "\nSeek Sequence (in order of service):\n";
    for (int i = 0; i < seekSequence.size(); i++) {
        cout << i + 1 << ". " << seekSequence[i] << endl;
    }

    cout << "\nTHM: " << seekCount << " cylinders\n";
}

int main() {
    int n, head, diskSize;
    string direction;
    vector<int> requests;

    cout << "=== SCAN (Elevator) Disk Scheduling ===\n";
    cout << "Enter number of disk requests: ";
    cin >> n;

    cout << "Enter disk requests (space-separated): ";
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        requests.push_back(r);
    }

    sort(requests.begin(), requests.end());

    cout << "Enter initial head position: ";
    cin >> head;

    cout << "Enter disk size (e.g 200): ";
    cin >> diskSize;

    cout << "Enter direction (left/right): ";
    cin >> direction;

    scanDiskScheduling(requests, head, diskSize, direction);

    return 0;
}

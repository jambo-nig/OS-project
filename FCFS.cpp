#include <iostream>
#include <vector>
#include <cmath>  // for abs()

using namespace std;

int main() {
    cout << "===== FCFS Disk Scheduling Algorithm =====\n\n";

    int diskSize, headPosition, numRequests;

    // Get disk size
    cout << "Enter the disk size (e.g., 200): ";
    cin >> diskSize;
    if (diskSize <= 0) {
        diskSize = 200;
        cout << "Invalid input. Using default disk size: " << diskSize << endl;
    }

    // Get initial head position
    cout << "Enter the initial position of the disk head (0 to " << diskSize - 1 << "): ";
    cin >> headPosition;
    if (headPosition < 0 || headPosition >= diskSize) {
        headPosition = diskSize / 4;
        cout << "Invalid input. Using default head position: " << headPosition << endl;
    }

    // Get number of disk requests
    cout << "Enter the number of disk requests: ";
    cin >> numRequests;
    if (numRequests <= 0) {
        numRequests = 8;
        cout << "Invalid input. Using default number of requests: " << numRequests << endl;
    }

    // Get disk request positions
    vector<int> requests;
    cout << "\nEnter the disk request positions (0 to " << diskSize - 1 << "):" << endl;
    for (int i = 0; i < numRequests; i++) {
        int position;
        cout << "Request " << (i + 1) << ": ";
        cin >> position;

        // Validate input
        if (position >= 0 && position < diskSize) {
            requests.push_back(position);
        } else {
            // Generate a random fallback
            cout << "Invalid position. Using random value instead." << endl;
            position = rand() % diskSize;
            cout << "Generated position: " << position << endl;
            requests.push_back(position);
        }
    }

    // Display initial configuration
    cout << "\n===== Configuration =====\n";
    cout << "Disk size: " << diskSize << endl;
    cout << "Initial head position: " << headPosition << endl;
    cout << "Request order: ";
    for (int req : requests) {
        cout << req << " ";
    }
    cout << "\n=========================\n";

    // Simulate FCFS
    int totalHeadMovement = 0;
    int currentPosition = headPosition;

    cout << "\nDisk Head Movement:\n";
    cout << currentPosition;

    for (int req : requests) {
        cout << " -> " << req;
        totalHeadMovement += abs(req - currentPosition);
        currentPosition = req;
    }

    // Final results
    cout << "\n\n===== Results =====\n";
    cout << "Total head movement: " << totalHeadMovement << " units" << endl;
    cout << "Average seek time: " << (float)totalHeadMovement / requests.size() << " units" << endl;
    cout << "===================\n";

    return 0;
}

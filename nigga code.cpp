#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cout << "LOOK Disk Scheduling Algorithm\n";
    cout << "-----------------------------\n";
    
    int disk_size, head, n;
    
    cout << "Enter the disk size (positive number): ";
    cin >> disk_size;
    if (disk_size <= 0) {
        disk_size = 200; // Default if invalid
        cout << "Using default disk size: " << disk_size << endl;
    }
    
    cout << "Enter the initial position of disk head (0-" << disk_size-1 << "): ";
    cin >> head;
    if (head < 0 || head >= disk_size) {
        head = disk_size / 4; 
        cout << "Using default head position: " << head << endl;
    }
    
    cout << "Enter the number of disk requests: ";
    cin >> n;
    if (n <= 0) {
        n = 8; 
        cout << "Using default number of requests: " << n << endl;
    }
    
    vector<int> requests;
    cout << "Enter the disk request positions (0-" << disk_size-1 << "):" << endl;
    
    for (int i = 0; i < n; i++) {
        int position;
        cout << "Request " << (i+1) << ": ";
        cin >> position;
        
        if (position >= 0 && position < disk_size) {
            requests.push_back(position);
        } else {
            cout << "Position out of range. Using random value instead." << endl;
            position = rand() % disk_size;
            cout << "Generated position: " << position << endl;
            requests.push_back(position);
        }
    }
    
    cout << "\nConfiguration:" << endl;
    cout << "Disk size: " << disk_size << endl;
    cout << "Initial head position: " << head << endl;
    cout << "Request positions: ";
    for (int req : requests) {
        cout << req << " ";
    }
    cout << endl;
    
    vector<int> left, right;
    for (int req : requests) {
        if (req < head) {
            left.push_back(req);
        } else if (req > head) {
            right.push_back(req);
        }
    }
    
    sort(left.begin(), left.end(), greater<int>());
    
    sort(right.begin(), right.end());
    
    int total_seek_time = 0;
    int current_position = head;
    
    cout << "\nDisk head movement sequence:" << endl;
    cout << head;
    
    for (int req : right) {
        cout << " -> " << req;
        total_seek_time += abs(req - current_position);
        current_position = req;
    }
    
    for (int req : left) {
        cout << " -> " << req;
        total_seek_time += abs(req - current_position);
        current_position = req;
    }
    
    cout << "\n\nTotal seek time: " << total_seek_time << " units" << endl;
    if (!requests.empty()) {
        cout << "Average seek time: " << (float)total_seek_time / requests.size() << " units" << endl;
    }
    
    return 0;
}
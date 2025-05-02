#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cout << "C-SCAN Disk Scheduling Algorithm\n";
    cout << "-------------------------------\n";
    
    int disk_size, head, n;
    
    // Simple input with defaults to prevent errors
    cout << "Enter the disk size: ";
    cin >> disk_size;
    if (disk_size <= 0) disk_size = 200;
    
    cout << "Enter the initial position of disk head: ";
    cin >> head;
    if (head < 0 || head >= disk_size) head = 50;
    
    cout << "Enter the number of disk requests: ";
    cin >> n;
    if (n <= 0) n = 8;
    
    vector<int> requests(n);
    cout << "Enter the disk request positions:" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "Request " << (i+1) << ": ";
        cin >> requests[i];
        
        // Ensure request is within valid range
        if (requests[i] < 0 || requests[i] >= disk_size) {
            requests[i] = rand() % disk_size;
            cout << "Invalid input. Using " << requests[i] << " instead." << endl;
        }
    }
    
    // Add the requests to vectors based on their position relative to head
    vector<int> greater_than_head;
    vector<int> less_than_head;
    
    for (int i = 0; i < n; i++) {
        if (requests[i] >= head)
            greater_than_head.push_back(requests[i]);
        else
            less_than_head.push_back(requests[i]);
    }
    
    // Sort the vectors
    sort(greater_than_head.begin(), greater_than_head.end());
    sort(less_than_head.begin(), less_than_head.end());
    
    // Print request positions
    cout << "\nRequest positions: ";
    for (int i = 0; i < n; i++) {
        cout << requests[i] << " ";
    }
    cout << endl;
    
    // Calculate total head movement
    int seek_time = 0;
    int current_track = head;
    
    cout << "\nDisk head movement:\n";
    cout << current_track;
    
    // Service all requests greater than head
    for (int i = 0; i < greater_than_head.size(); i++) {
        cout << " -> " << greater_than_head[i];
        seek_time += abs(greater_than_head[i] - current_track);
        current_track = greater_than_head[i];
    }
    
    // If not already at disk end, go there
    if (current_track != disk_size - 1) {
        cout << " -> " << (disk_size - 1);
        seek_time += (disk_size - 1) - current_track;
    }
    
    // Jump to beginning (this movement is not counted in seek time)
    cout << " -> 0";
    current_track = 0;
    
    // Service all requests less than head
    for (int i = 0; i < less_than_head.size(); i++) {
        cout << " -> " << less_than_head[i];
        seek_time += abs(less_than_head[i] - current_track);
        current_track = less_than_head[i];
    }
    
    cout << "\n\nTotal Seek Time: " << seek_time << endl;
    cout << "Average Seek Time: " << (float)seek_time / n << endl;
    
    return 0;
}
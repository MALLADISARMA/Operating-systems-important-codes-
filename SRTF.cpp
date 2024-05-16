#include <iostream>

using namespace std;

void SRTF(int arrival_time[], int burst_time[], int n) {
    int remaining_time[n];
    int completion_time[n];
    bool completed[n] = {false};
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    int min_index;

    // Initialize remaining time with burst time
    for (int i = 0; i < n; ++i)
        remaining_time[i] = burst_time[i];

    while (true) {
        int min_burst = 99999;
        bool all_completed = true;

        // Find the process with minimum remaining time at current time
        for (int i = 0; i < n; ++i) {
            if (arrival_time[i] <= current_time && !completed[i] && remaining_time[i] < min_burst) {
                min_index = i;
                min_burst = remaining_time[i];
                all_completed = false;
            }
        }

        if (all_completed)
            break;

        // Update current time
        ++current_time;
        --remaining_time[min_index];

        // Mark the process as completed
        if (remaining_time[min_index] == 0) {
            completion_time[min_index] = current_time;
            completed[min_index] = true;
        }
    }

    // Calculate waiting time and turnaround time
    for (int i = 0; i < n; ++i) {
        total_waiting_time += completion_time[i] - arrival_time[i] - burst_time[i];
        total_turnaround_time += completion_time[i] - arrival_time[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrival_time[n];
    int burst_time[n];

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> arrival_time[i];
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> burst_time[i];
    }

    SRTF(arrival_time, burst_time, n);

    return 0;
}

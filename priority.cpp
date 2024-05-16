#include <iostream>

using namespace std;

void priorityScheduling(int at[], int burst_time[], int priority[], int n) {
    int completion_time[n];
    int waiting_time[n];
    int turnaround_time[n];
    bool completed[n] = {false};
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    int current_time = 0;
    while (true) {
        int min_priority = 999;
        int min_index = -1;

        // Find the process with the highest priority that has arrived
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && priority[i] < min_priority && current_time >= at[i]) {
                min_priority = priority[i];
                min_index = i;
            }
        }

        // If no process is found, break the loop
        if (min_index == -1)
            break;

        // Update completion time
        completion_time[min_index] = current_time + burst_time[min_index];

        // Calculate turnaround time
        turnaround_time[min_index] = completion_time[min_index] - at[min_index];

        // Calculate waiting time
        waiting_time[min_index] = turnaround_time[min_index] - burst_time[min_index];

        // Update total waiting and turnaround time
        total_waiting_time += waiting_time[min_index];
        total_turnaround_time += turnaround_time[min_index];

        // Mark the process as completed
        completed[min_index] = true;

        // Update current time
        current_time = completion_time[min_index];
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

    int at[n];
    int burst_time[n];
    int priority[n];

    cout << "Enter arrival time, burst time, and priority for each process:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> at[i];
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> burst_time[i];
        cout << "Process " << i + 1 << " Priority: ";
        cin >> priority[i];
    }

    priorityScheduling(at, burst_time, priority, n);

    return 0;
}

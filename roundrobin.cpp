#include <iostream>

using namespace std;

void roundRobin(int arrival_time[], int burst_time[], int n, int quantum) {
    int remaining_time[n];
    int completion_time[n];
    int waiting_time[n];
    int turnaround_time[n];
    int current_time = 0;

    // Initialize remaining time with burst time
    for (int i = 0; i < n; ++i)
        remaining_time[i] = burst_time[i];

    while (true) {
        bool all_completed = true;

        // Traverse all processes
        for (int i = 0; i < n; ++i) {
            if (remaining_time[i] > 0) {
                all_completed = false;

                // Execute current process for quantum time
                if (remaining_time[i] > quantum) {
                    current_time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    // Process completes before the quantum time
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                    completion_time[i] = current_time;
                }
            }
        }

        // Break the loop if all processes are completed
        if (all_completed)
            break;
    }

    // Calculate waiting time and turnaround time
    for (int i = 0; i < n; ++i) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }

    // Calculate average waiting time and average turnaround time
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    for (int i = 0; i < n; ++i) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main() {
    int n, quantum;
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

    cout << "Enter time quantum: ";
    cin >> quantum;

    roundRobin(arrival_time, burst_time, n, quantum);

    return 0;
}

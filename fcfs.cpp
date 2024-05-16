#include <iostream>
using namespace std;
void FCFS(int arrival_time[], int burst_time[], int n) {
    int current_time = 0;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    cout << "Process\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; ++i) {   
        int waiting_time = max(0, current_time - arrival_time[i]);
        total_waiting_time += waiting_time;

        // Turnaround time for current process
        int turnaround_time = waiting_time + burst_time[i];
        total_turnaround_time += turnaround_time;

        // Update current time
        current_time += burst_time[i];

        cout << i + 1 << "\t" << waiting_time << "\t\t" << turnaround_time << endl;
    }

    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;
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

    FCFS(arrival_time, burst_time, n);

    return 0;
}

#include <iostream>
using namespace std;

int main() {

	// Matrix for storing Process Id, Burst Time, Arrival Time, Average Waiting Time & Average Turnaround Time.
	int A[100][5];
	int i, j, n, total_wt = 0, total_tat = 0, temp;
	float avg_wt, avg_tat;

	cout << "Enter number of processes: ";
	cin >> n;

	cout << "Enter Burst Time and Arrival Time:" << endl;

	// User Input Burst Time and Arrival Time, and alloting Process Id.
	for (i = 0; i < n; i++) {
		cout << "P" << i + 1 << " Burst Time: ";
		cin >> A[i][1];
		cout << "P" << i + 1 << " Arrival Time: ";
		cin >> A[i][2];
		A[i][0] = i + 1;
	}

	// Sorting process according to their Arrival Time.
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (A[j][2] > A[j + 1][2]) {
				// Swap the processes if the arrival time of j+1 is less than j
				for (int k = 0; k < 3; k++) {
					temp = A[j][k];
					A[j][k] = A[j + 1][k];
					A[j + 1][k] = temp;
				}
			}
		}
	}

	A[0][3] = A[0][2];
	// Calculation of Waiting Times and Turnaround Times
	for (i = 1; i < n; i++) {
		int waiting_time = 0;
		for (j = 0; j < i; j++) {
			waiting_time += A[j][1];
		}
		A[i][3] = waiting_time - A[i][2] + A[i][1]; // Turnaround Time
		A[i][4] = waiting_time; // Waiting Time
		total_wt += waiting_time;
		total_tat += A[i][3];
	}

	avg_wt = (float)total_wt / n;
	avg_tat = (float)total_tat / n;

	cout << "Process  Burst Time  Arrival Time  Waiting Time  Turnaround Time" << endl;

	for (i = 0; i < n; i++) {
		cout << "P" << A[i][0] << "        " << A[i][1] << "             " << A[i][2] << "             " << A[i][4] << "              " << A[i][3] << endl;
	}

	cout << "Average Waiting Time= " << avg_wt << endl;
	cout << "Average Turnaround Time= " << avg_tat << endl;

	return 0;
}

#include<iostream>
using namespace std;

// Number of processes
const int P = 5;

// Number of resources
const int R = 3;

// Function to find the need of each process
void calculateNeed(int need[P][R], int maxm[P][R],
                int allot[P][R])
{
    // Calculating Need of each P
    for (int i = 0 ; i < P ; i++)
        for (int j = 0 ; j < R ; j++)

            // Need of instance = maxm instance -
            //                  allocated instance
            need[i][j] = maxm[i][j] - allot[i][j];
}

// Function to find the system is in safe state or not
bool isSafe(int processes[], int avail[], int maxm[][R],
            int allot[][R])
{
    int need[P][R];

    // Function to calculate need matrix
    calculateNeed(need, maxm, allot);

    // Mark all processes as infinish
    bool finish[P] = {0};

    
    int safeSeq[P];

    int work[R];
    for (int i = 0; i < R ; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < P)
    {
        
        bool found = false;
        for (int p = 0; p < P; p++)
        {
        
            if (finish[p] == 0)
            {
             
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                // If all needs of p were satisfied.
                if (j == R)
                {
                    
                    for (int k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];

                    // Add this process to safe sequence.
                    safeSeq[count++] = p;

                    // Mark this p as finished
                    finish[p] = 1;

                    found = true;
                }
            }
        }

        // If we could not find a next process in safe
        // sequence.
        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }

    // If system is in safe state then
    // safe sequence will be as below
    cout << "System is in safe state.\nSafe"
        " sequence is: ";
    for (int i = 0; i < P ; i++)
        cout << safeSeq[i] << " ";

    return true;
}

// Driver code
int main()
{
    int processes[P];
    int avail[R];
    int maxm[P][R];
    int allot[P][R];

    cout << "Enter the available instances of resources: ";
    for (int i = 0; i < R; ++i) {
        cin >> avail[i];
    }

    cout << "Enter the maximum resources that can be allocated to processes: " << endl;
    for (int i = 0; i < P; ++i) {
        cout << "For process " << i << ": ";
        for (int j = 0; j < R; ++j) {
            cin >> maxm[i][j];
        }
    }

    cout << "Enter the resources allocated to processes: " << endl;
    for (int i = 0; i < P; ++i) {
        cout << "For process " << i << ": ";
        for (int j = 0; j < R; ++j) {
            cin >> allot[i][j];
        }
    }

    for (int i = 0; i < P; ++i) {
        processes[i] = i;
    }

    // Check system is in safe state or not
    isSafe(processes, avail, maxm, allot);

    return 0;
}

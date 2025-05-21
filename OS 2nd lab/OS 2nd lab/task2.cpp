#include<iostream>
using namespace std;

const int p = 5;
const int r = 3;

void needcalc(int need[p][r], int maxm[p][r], int allot[p][r]) {
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = maxm[i][j] - allot[i][j];
}

bool safe(int avail[r], int maxm[p][r], int allot[p][r]) {
    int need[p][r], work[r], seq[p], cnt = 0;
    bool done[p] = {0};
    needcalc(need, maxm, allot);
    for (int i = 0; i < r; i++) work[i] = avail[i];

    while (cnt < p) {
        bool ok = 0;
        for (int i = 0; i < p; i++) {
            if (!done[i]) {
                int j;
                for (j = 0; j < r; j++)
                    if (need[i][j] > work[j]) break;
                if (j == r) {
                    for (int k = 0; k < r; k++)
                        work[k] += allot[i][k];
                    seq[cnt++] = i;
                    done[i] = 1;
                    ok = 1;
                }
            }
        }
        if (!ok) {
            cout << "not safe";
            return 0;
        }
    }
    cout << "safe\nseq: ";
    for (int i = 0; i < p; i++) cout << seq[i] << " ";
    return 1;
}

int main() {
    int avail[r], maxm[p][r], allot[p][r];

    cout << "enter Available Resources (" << r << " values):\n";
    for (int i = 0; i < r; i++)
        cin >> avail[i];

    cout << "enter max value:\n";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            cin >> maxm[i][j];

    cout << "enter allocation value:\n";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            cin >> allot[i][j];

    safe(avail, maxm, allot);
    return 0;
}
/*
Enter Available Resources (3 values):
3 3 2
Enter Maximum Matrix row by row:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter Allocation Matrix row by row:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
*/

#include <iostream>

using namespace std;



void display(int mat[][10], int p, int r) {

 for (int i = 0; i < p; i++) {

 cout << "Process " << i << ": ";

 for (int j = 0; j < r; j++) {

 cout << mat[i][j] << " ";

 }

 cout << endl;

 }

}

bool isSafe(int processes[], int avail[], int max[][10], int allot[][10], int n, int m)

{

 int need[10][10];

 bool finish[10] = { false };

 int safeSeq[10];

 int work[10];

 for (int i = 0; i < n; i++) {

 for (int j = 0; j < m; j++) {

 need[i][j] = max[i][j] - allot[i][j];

 }

 }

 for (int i = 0; i < m; i++) {

 work[i] = avail[i];

 }

 int count = 0;

 while (count < n) {

 bool found = false;

 for (int p = 0; p < n; p++) {

 if (!finish[p]) {

 int j;

 for (j = 0; j < m; j++) {

 if (need[p][j] > work[j]) {

 break;

 }

 }

 if (j == m) {

 for (int k = 0; k < m; k++) {

 work[k] += allot[p][k];

 }

 safeSeq[count++] = p;

 finish[p] = true;

 found = true;

 }

 }

 }

 if (!found) {

 cout << "System is in an unsafe state." << endl;

 return false;

 }

 }

 cout << "System is in a safe state." << endl;

 cout << "Safe sequence is: ";

 for (int i = 0; i < n; i++) {

 cout << "P" << safeSeq[i] << " ";

 }

 cout << endl;

 return true;

}

int main() {

 cout << "Enter total number of Resources: ";

 int re;

 cin >> re;

 cout << "Enter total number of Processes: ";

 int pro;

 cin >> pro;

 cout << "Enter Allocation Matrix:\n";

 int allo[10][10];

 int max[10][10];

 for (int i = 0; i < pro; i++) {

 for (int j = 0; j < re; j++) {

 cin >> allo[i][j];

 }

 }

 cout << "Enter the Maximum Matrix:\n";

 for (int i = 0; i < pro; i++) {

 for (int j = 0; j < re; j++) {

 cin >> max[i][j];

 }

 }

 int ava[10];

 cout << "\nAvailable Resources:\n";

 for (int i = 0; i < re; i++) {

 cout << "Enter available resources for resource type " << i << ": ";

 cin >> ava[i];

 }

 int processes[10];

 for (int i = 0; i < pro; i++) {

 processes[i] = i;

 }

 isSafe(processes, ava, max, allo, pro, re);

 return 0;

}

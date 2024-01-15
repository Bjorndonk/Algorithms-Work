#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

 binary_search (long int A[], long int size, long int target) {
    long int L = 0;
    long int R = size - 1;
    long int index;
    while (L <= R) {
        index = (L + R) / 2;
        if (A[index] < target) {
            L = index + 1;
        }
        else if (A[index] > target) {
            R = index - 1;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    // initializing variables
    long int n, m, a, c, x;

    // taking input
    cin >> n >> m >> a >> c >> x;
    // TEMP: Printing input to check for correctness
    cout << n << " " << m << " " << a << " " << c << " " << x << endl;

    // generating sequence
    long int A[n];
    long int prev = x;
    long int curr;
    for (int i = 0; i < n; i++) {
        curr = prev * a;
        curr = curr + c;
        curr = curr % m;
        A[i] = curr;
        prev = curr;
    }
    // TEMP: Printing generated sequence to check for correctness
    for (long int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // calculating number of searchable list elements
    long int num = 0;
    for (long int i = 0; i < n; i++) {
        if (binary_search(A, n, A[i]) == true) {
            num++;
        }
    }

    // printing solution
    cout << num << endl;

    return 0;
}
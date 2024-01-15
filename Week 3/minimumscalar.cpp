#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

vector<int> populate(int n) {
    vector<int> v;
    int curr;
    for (int j = 0; j < n; j++) {
        cin >> curr;
        v.push_back(curr);
    }
    return v;
}

int main() {

    // defining variables
    int t; // num test cases
    int n; // num integers
    long int output; // used for calculating the output for each test case
    long int temp;
    vector<int> v1, v2;
    
    // starting algorithm
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        // populating vectors
        v1 = populate(n);
        v2 = populate(n);
        // sorting vectors
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        // calculate solution
        output = 0;
        for (int j = 0; j < n; j++) {
            temp = v1[j] * v2[n-j-1];
            output += temp;
        }
        cout << "Case #" << i+1 << ": " << output << endl;
    }
    return 0;
}
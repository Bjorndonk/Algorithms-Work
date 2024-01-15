#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m, diff;
    int count = 1;
    while (cin >> n) {
        cout << "Case " << count << ":" << endl;
        count++;
        
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int e;
            cin >> e;
            nums.push_back(e);
        }
        
        cin >> m;
        vector<int> queries;
        for (int i = 0; i < m; i++) {
            int e;
            cin >> e;
            queries.push_back(e);
        }
        
        // 3 nested loops to compare queries to all possible sums
        for (int i = 0; i < m; i++) {
            int idx_1 = 0;
            int idx_2 = 1;
            int csum = abs(nums[0] + nums[1] - queries[i]);
            
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != k) {
                        
                        // Compare the absolute value of differences between the sum
                        // and queries[i]
                        diff = abs(nums[j] + nums[k] - queries[i]);
                        // If the difference is greater then previously stored, keep going
                        
                        // If the difference is smaller, store new indexes and new difference
                        if (diff < csum) {
                            csum = diff;
                            idx_1 = k;
                            idx_2 = j;
                        }
                    }
                }
            }
            
            cout << "Closest sum to " << queries[i] << " is " << nums[idx_1] + nums[idx_2] << "." << endl;
        }
    }
}
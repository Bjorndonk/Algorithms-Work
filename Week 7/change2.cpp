#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <numeric>

using namespace std;

int main() {
    
    // initializing variables
    int num_tests, value, num_coins, curr_coin, curr_val, curr_min;
    // int curr_gcd;
    vector<int> coins;
    vector<vector<int>> mins;

    // taking input
    cin >> num_tests;
    
    // for each case
    while (num_tests > 0) {

        // taking remaining input
        cin >> value;
        cin >> num_coins;
        coins.clear();
        for (int i = 0; i < num_coins; i++) {
            cin >> curr_coin;
            coins.push_back(curr_coin);
        }
        sort(coins.begin(), coins.end());

        mins.clear();
        
        mins.push_back(0);
        curr_val = 1;
        






        // moving to next test case
        num_tests--;
    }

    return 0;
}
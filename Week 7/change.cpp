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
    vector<int> mins;

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

        /*

        // TEMP BEGIN
        for (int i = 0; i < coins.size(); i++) {
            cout << coins[i] << " ";
        }
        cout << endl;
        // TEMP END

        // find gcd of coins array
        curr_gcd = coins[0];
        for (int i = 1; i < coins.size(); i++) {
            curr_gcd = gcd(curr_gcd, coins[i]);
        }

        // TEMP BEGIN (testing gcd function)
        cout << curr_gcd << endl;
        // TEMP END

        */

        mins.clear();
        mins.push_back(0);
        curr_val = 1;
        while (mins.size() <= value || curr_min == 0) {
            curr_min = value;
            for (int i = 0; i < coins.size(); i++) {
                if (curr_val - coins[i] == 0) {
                    curr_min = 1;
                    /*
                    // TEMP BEGIN
                    cout << "Min coins for value " << curr_val << " set to " << curr_min << endl;
                    // TEMP END
                    */
                }
                else if (curr_val - coins[i] > 0) {
                    if (1 + mins[curr_val-coins[i]] < curr_min) {
                        if (mins[curr_val-coins[i]] != 0) {
                            curr_min = 1 + mins[curr_val-coins[i]];
                            /*
                            // TEMP BEGIN
                            cout << "Min coins for value " << curr_val << " set to " << curr_min << endl;
                            // TEMP END
                            */
                        }                        
                    }
                }
            }
            if (curr_min == value) {
                curr_min = 0;
            }
            mins.push_back(curr_min);
            curr_val++;
        }

        // printing output
        if (value <= 0 || num_coins <= 0 || coins[0] < 1) {
            //cout << '\n' << endl;
        }
        else {
            cout << curr_val - 1 << " " << mins.back() << endl;
        }

        // moving to next test case
        num_tests--;
    }

    return 0;
}
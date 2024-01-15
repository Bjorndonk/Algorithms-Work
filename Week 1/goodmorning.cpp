#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

bool isValid(int input) {
    string x = to_string(input);
    char curr, next;
    for (int i = 0; i < x.length() - 1; i++) {
        curr = x[i];
        next = x[i + 1];

        // TEMP - TO DELETE
        // cout << curr << endl;
        // cout << next << endl;

        // No need to check for valid if curr = 1
        // 2
        if (curr == '2') {
            if (next == '1') {
                return false;
            }
            if (next == '4') {
                return false;
            }
            if (next == '7') {
                return false;
            }
        }
        // 3
        if (curr == '3') {
            if (next == '1') {
                return false;
            }
            if (next == '2') {
                return false;
            }
            if (next == '4') {
                return false;
            }
            if (next == '5') {
                return false;
            }
            if (next == '7') {
                return false;
            }
            if (next == '8') {
                return false;
            }
            if (next == '0') {
                return false;
            }
        }
        // 4
        if (curr == '4') {
            if (next == '1') {
                return false;
            }
            if (next == '2') {
                return false;
            }
            if (next == '3') {
                return false;
            }
        }
        // 5
        if (curr == '5') {
            if (next == '1') {
                return false;
            }
            if (next == '2') {
                return false;
            }
            if (next == '3') {
                return false;
            }
            if (next == '4') {
                return false;
            }
            if (next == '7') {
                return false;
            }
        }
        // 6
        if (curr == '6') {
            if (next == '1') {
                return false;
            }
            if (next == '2') {
                return false;
            }
            if (next == '3') {
                return false;
            }
            if (next == '4') {
                return false;
            }
            if (next == '5') {
                return false;
            }
            if (next == '7') {
                return false;
            }
            if (next == '8') {
                return false;
            }
            if (next == '0') {
                return false;
            }
        }
        // 7
        if (curr == '7') {
            if (next == '1') {
                return false;
            }
            if (next == '2') {
                return false;
            }
            if (next == '3') {
                return false;
            }
            if (next == '4') {
                return false;
            }
            if (next == '5') {
                return false;
            }
            if (next == '6') {
                return false;
            }
        }
        // 8
        if (curr == '8') {
            if (next == '1') {
                return false;
            }
            if (next == '2') {
                return false;
            }
            if (next == '3') {
                return false;
            }
            if (next == '4') {
                return false;
            }
            if (next == '5') {
                return false;
            }
            if (next == '6') {
                return false;
            }
            if (next == '7') {
                return false;
            }
        }
        // 9
        if (curr == '9') {
            if (next != '9') {
                return false;
            }
        }
        // 0
        if (curr == '0') {
            if (next != '0') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    int curr;
    int offset = 0;
    bool foundValid = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        offset = 0;
        foundValid = false;
        while (foundValid == false) {
            if (isValid(curr + offset) == true) {
                cout << curr + offset << endl;
                foundValid = true;
            }
            if (foundValid == false && isValid(curr - offset) == true) {
                cout << curr - offset << endl;
                foundValid = true;
            }
            offset++;
        }
    }



    // TEST CASES - TEMP
    // cout << isValid(180) << endl;
    // cout << isValid(83) << endl;
    // cout << isValid(132) << endl;
}
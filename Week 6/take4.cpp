#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

vector<long int> populate_sequence(int num_elements) {
    vector<long int> sequence;
    long int curr;
    for (int i = 0; i < num_elements; i++) {
        cin >> curr;
        sequence.push_back(curr);
    }
    return sequence;
}

vector<int> populate_predecessors(int num_elements) {
    vector<int> predecessors;
    int curr = -1;
    for (int i = 0; i < num_elements; i++) {
        predecessors.push_back(curr);
    }
    return predecessors;
}

int main() {
    
    // initialize variables 
    vector<long int> sequence;
    vector<long int> temp;
    vector<int> temp_ind;
    vector<int> predecessors;
    int num_elements;
    int ind;
    int worm;

    // beginning algorithm
    while (cin >> num_elements) {
        sequence = populate_sequence(num_elements);
        predecessors.clear();
        predecessors.push_back(-1);
        temp.clear();
        temp_ind.clear();

        temp.push_back(sequence[0]);
        temp_ind.push_back(0);
        for (int i = 1; i < num_elements; i++) {
            if (sequence[i] > temp.back()) {
                temp.push_back(sequence[i]);
                temp_ind.push_back(i);
                predecessors.push_back(temp_ind[temp.size() - 2]);
            }
            else {
                ind = lower_bound(temp.begin(), temp.end(), sequence[i]) - temp.begin();
                if (ind == 0) {
                    predecessors.push_back(-1);
                }
                else {
                    predecessors.push_back(temp_ind[ind - 1]);
                }
                temp[ind] = sequence[i];
                temp_ind[ind] = i;
            }

            /*
            // TEMP
            for (int j = 0; j < temp.size(); j++) {
                cout << temp[j] << "(" << temp_ind[j] << ") ";
            }
            cout << endl;
            */

        }
        // printing size
        cout << temp.size() << endl;

        /*
        // TEMP: Printing predecessors
        cout << "Predecessors: ";
        for (int i = 0; i < predecessors.size(); i++) {
            cout << predecessors[i] << " ";
        }
        cout << endl;
        */

        // printing path
        ind = temp.back();
        // cout << "Searching for final element of subset: " << temp.back() << endl;
        for (int i = num_elements - 1; i >= 0; i--) {
            if (sequence[i] == ind) {
                worm = i;
                break;
            }
        }
        // cout << "Found at index " << worm << endl;
        temp.clear();
        temp.push_back(worm);
        worm = predecessors[worm];
        while (worm != -1) {
            temp.push_back(worm);
            worm = predecessors[worm];
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
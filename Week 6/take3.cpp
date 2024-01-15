#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

struct node {
    int length = 1;
    int next = -1;
};

void print_solution(vector<node> subproblems, int num_elements) {
    int max = 1;
    int index = -1;
    for (int i = 0; i < num_elements; i++) {
        if (subproblems[i].length > max) {
            max = subproblems[i].length;
            index = i;
        }
    }
    cout << max << endl;
    if (index == -1) {
        cout << "1";
    }
    while (index != -1) {
        cout << index << " ";
        index = subproblems[index].next;
    }
    cout << endl;
    return;
}

vector<long int> populate_sequence(int num_elements) {
    vector<long int> sequence;
    long int curr;
    for (int i = 0; i < num_elements; i++) {
        cin >> curr;
        sequence.push_back(curr);
    }
    return sequence;
}

vector<node> populate_subproblems(int num_elements) {
    vector<node> subproblems;
    node curr;
    for (int i = 0; i < num_elements; i++) {
        subproblems.push_back(curr);
    }
    return subproblems;
}

int main() {

    // initializing variables
    vector<long int> sequence;
    int num_elements;
    vector<node> subproblems;
    int curr_max = 0;
    int curr_next = -1;

    // FOR EACH TEST CASE
    
    while (cin >> num_elements) {

        sequence = populate_sequence(num_elements);
        subproblems = populate_subproblems(num_elements);

        vector<int> temp;
        temp.push_back(sequence[0]);
        for (int i = 1; i < num_elements; i++) {
            if(sequence[i] > temp.back()) {
                temp.push_back(sequence[i]);
            }
            else {
                int ind = lower_bound(temp.begin(), temp.end(), sequence[i]) - temp.begin();
                temp[ind] = temp[i];
            }
        }
        cout << temp.size() << endl;
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << endl;
        }
    }
}
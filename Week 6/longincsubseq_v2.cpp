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

vector<int> construct_sorted_indices(vector<long int> sequence, vector<long int> sorted, int num_elements) {
    vector<int> indices;
    for (int i = 0; i < num_elements; i++) {
        for (int j = 0; j < sequence.size(); j++) {
            if (sorted[i] == sequence[j]) {
                indices.push_back(j);
                sequence[j] = sorted[sorted.size()] + 1;
                break;
            }
        }
    }
    return indices;
}

int binary_search (vector<long int> A, long int size, long int target) {
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
            return index;
        }
    }
    return -1;
}

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
    // NOTE: not sure yet how to terminate this program, ie checking if we've run out of test cases
    
    // initializing variables
    vector<long int> sequence;
    int num_elements;
    vector<node> subproblems;
    int curr_max = 0;
    int curr_next = -1;
    vector<int> indices;
    vector<long int> sorted;
    long int temp;

    // FOR EACH TEST CASE
    
    while (cin >> num_elements) {

        sequence = populate_sequence(num_elements);
        subproblems = populate_subproblems(num_elements);
        sorted = sequence;
        sort(sorted.begin(), sorted.end());
        indices = construct_sorted_indices(sequence, sorted, num_elements);

        cout << "Sorted:" << endl;
        for (int i = 0; i < sorted.size(); i++) {
            cout << sorted[i] << " ";
        }
        cout << endl;
        cout << "Indices:" << endl;
        for (int i = 0; i < indices.size(); i++) {
            cout << indices[i] << " ";
        }
        cout << endl;

        // begin algorithm
        // start at the end of the num_elements array
        for (int i = num_elements - 1; i >= 0; i--) {
            // check which of the available following elements results in the longest increasing substring
            curr_max = 1;
            curr_next = -1;
            temp = binary_search(sorted, num_elements, sequence[i]);
            for (int j = temp; j < num_elements; j++) {
                // checking if sequence element results in an increasing substring
                cout << "Checking " << sequence[i] << " against " << sequence[indices[j]] << endl;
                if (sequence[i] < sequence[indices[j]]) {
                    if (curr_max < subproblems[indices[j]].length + 1) {
                        curr_max = subproblems[indices[j]].length + 1;
                        curr_next = indices[j];
                    }
                }
            }
            subproblems[i].length = curr_max;
            subproblems[i].next = curr_next;

            // TEMP:
            cout << "Sequence element " << i << " set to length " << curr_max << " and next element index " << curr_next << endl;

        }
        // printing solution
        // print_solution(subproblems, num_elements);
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Pick classroom whose last activity finisihed at the latest time

// Essentially trying to minimize the ddifference between start of 
// the new activity and finishs of the previous activity in any
// given classroom

// We do this by doing a linear search on the array of classes
// This is O(n)

// But we can do this (picking the class with latest finish time)
// in O(logN) time by using a priority queue
// So in the following function use a priority queue instead of 
// an array (c) to store class finish times
int find_latest(vector<int> &c, int classes, int s, int f) {
    int latest = -1;
    for (int i = 0; i < classes; i++) {
        if (s > c[i]) {
            latest = i;
            return latest;
        }
    }
    
    return latest;
}

int main() {
    int activities, classes;
    cin >> activities >> classes;
    
    vector<pair<long long int, long long int> > times;
    vector<int> c;
    for (int i = 0; i < classes; i++) {
        c.push_back(0);
    }
    
    for (int i = 0; i< activities; i++) {
        long long int s, f;
        cin >> s >> f;
        times.push_back(make_pair(f, s));
    }
    
    sort(times.begin(), times.end());
    
    int max_finish = times[activities - 1].first;
    int ans = 0;
    
    for (int i = 0; i< activities; i++) {
        int s = times[i].second;
        int f = times[i].first;
        
        int latest = find_latest(c, classes,s, f);

        if(latest == -1) {
            continue;
        }
        else{
            c[latest] = f;
            sort(c.begin(), c.end());
            ans++;
        }
        
        //cout << latest << endl;
        //cout << c[0] << " " << c[1] << endl;
    
    }
    
    cout << ans << endl;
}
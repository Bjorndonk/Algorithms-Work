#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printGraph(vector<vector<int> > &graph) {
    
    if(graph.size() == 0) {
        cout << "Empty Graph" << endl;
        return;
    }
    
    cout << "Graph:" << endl;
    
    for(int i = 1; i < graph.size(); i++) {
        cout << i << " : ";
        for (int j = 1; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


void printVisited(vector<bool> &visited) {
    
    if(visited.size() == 0) {
        cout << "Graph not initialized" << endl;
        return;
    }
    
    cout << "Visited: " << endl;
    
    for (int i = 1; i < visited.size(); i++) {
        cout << visited[i] << " " ;
    }
    cout << endl;
}

void addEdge(vector<vector<int> > &g, int i, int j) {
    g[i].push_back(j);
    g[j].push_back(i);
}

void dfs(vector<vector<int> > &graph, vector<bool> &visited, int source){
    // Write traversal Code
    queue<int> q;
    int current;
    visited[source] = true;
    q.push(source);
    while (q.empty() == false) {
        current = q.front();
        q.pop();
        for (int i = 1; i < graph[current].size(); i++) {
            if (visited[graph[current][i]] == false) {
                visited[graph[current][i]] = true;
                q.push(graph[current][i]);
            }
        }
    }

}


int main() {
    vector<vector<int> > graph;
    vector<bool> visited;
    
    int n, m;
        
    cin >> n >> m;
    
    /*
    printGraph(graph);
    printVisited(visited);
    cout << endl;
    */
    
    // Initialize graph - note we are ignoring index 0 in the vector
    for(int i = 0; i < (n+1); i++){
        visited.push_back(false);
        
        vector<int> temp = {-1};
        graph.push_back(temp);
    }
    
    /*
    printGraph(graph);
    printVisited(visited);
    cout << endl;
    */
    
    // Add edges
    for(int i = 0; i < m; i++) {
        int j, k;
        cin >> j >> k;
        addEdge(graph, j, k);
    }

    /*
    printGraph(graph);
    printVisited(visited);
    cout << endl;
    */

    dfs(graph, visited, 1);
    
    /*
    printGraph(graph);
    printVisited(visited);
    cout << endl;
    */

    // Check for unvisited vertices
    bool flag = true;
    for(int i = 1; i < visited.size(); i++){
        if(visited[i] == false) {
            cout << i << endl; 
            flag = false;
        }
    }
    
    if(flag == true) {
        cout << "Connected" << endl;
    }
    
}
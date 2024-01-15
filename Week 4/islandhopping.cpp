#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

struct edge;

struct vertex {
    double x;
    double y;
    vector<edge*> edges;
    vertex* parent = NULL;
};

struct edge {
    double weight;
    vertex* v1;
    vertex* v2;
    bool visited = false;
};

struct graph {
    vector<edge> edges;
    vector<vertex> vertices;
};

bool compare_weights(edge a, edge b) {
    if (a.weight > b.weight) {
        return 0;
    }
    else {
        return 1;
    }
}

graph populate(int m) {
    // initializing variables
    graph g;
    vertex curr_vertex;
    edge curr_edge;
    double curr_weight, curr_x, curr_y;
    double x_squared, y_squared;
    // adding vertices
    for (int i = 0; i < m; i++) {
        // cout << "Adding vertex " << i + 1 << endl;
        cin >> curr_x >> curr_y;
        curr_vertex.x = curr_x;
        curr_vertex.y = curr_y;
        g.vertices.push_back(curr_vertex);
        // cout << "Added vertex " << i + 1 << endl;
    }
    // adding edges
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            x_squared = (g.vertices[i].x - g.vertices[j].x) * (g.vertices[i].x - g.vertices[j].x);
            y_squared = (g.vertices[i].y - g.vertices[j].y) * (g.vertices[i].y - g.vertices[j].y);
            curr_weight = sqrt(x_squared + y_squared);
            curr_edge.weight = curr_weight;
            curr_edge.v1 = &g.vertices[i];
            curr_edge.v2 = &g.vertices[j];
            g.edges.push_back(curr_edge);
            // adding edge pointer to connected vertices
            g.vertices[i].edges.push_back(&g.edges.back());
            g.vertices[j].edges.push_back(&g.edges.back());
        }
    }
    return g;
}

void print_graph(graph &g) {
    for (int i = 0; i < g.vertices.size(); i++) {
        cout << "(" << g.vertices[i].x << ", " << g.vertices[i].y << ") has a parent " << g.vertices[i].parent << endl;
    }
    for (int i = 0; i < g.edges.size(); i++) {
        cout << g.edges[i].weight << " from (" << g.edges[i].v1->x << "," << g.edges[i].v1->y << ") to (" << g.edges[i].v2->x << "," << g.edges[i].v2->y << ") with parents " << g.edges[i].v1->parent << " and " << g.edges[i].v2->parent << " respectively." << endl;
    }
    return;
}

bool check_if_safe(edge &current_edge) {
    cout << "Entered check if safe. Setting current parents..." << endl;
    vertex* parent1_curr;
    vertex* parent1_next;
    vertex* parent2_curr;
    vertex* parent2_next;
    parent1_curr = current_edge.v1;
    parent1_next = current_edge.v1->parent;
    parent2_curr = current_edge.v2;
    parent2_next = current_edge.v2->parent;
    cout << "Parents set. Finding master parent of each tree..." << endl;
    while (parent1_next != NULL) {
        parent1_curr = parent1_curr->parent;
        parent1_next = parent1_next->parent;
    }
    while (parent2_next != NULL) {
        parent2_curr = parent2_curr->parent;
        parent2_next = parent2_next->parent;
    }
    cout << "Found master parents: " << parent1_curr << " and " << parent2_curr << ". Comparing and returning..." << endl;
    if (parent1_curr != parent2_curr) {
        return true;
    }
    else {
        return false;
    }
}

struct o;

struct L {
    o* head;
    o* tail;
};

struct o {
    L* next;
    L set;
    vertex value;
};

L make_set(vertex x) {
    // defining o
    o curro;
    // defining L and its properties
    L currL;
    currL.head = curro;
    currL.tail = curro;
    // setting o's properties
    curro.next = NULL;
    curro.set = currL;
    curro.value = x;
    return currL;
}

find_set(vertex x) {
    
}

int main() {








    // ATTEMPT 2 BELOW:
    /*
    // defining variables
    graph g;
    int n, m;
    bool found_safe_edge;
    double cumulative_edge_weight = 0;
    vertex curr_vertex;
    vector<edge> mst;
    
    // taking num test cases
    cin >> n;
    for (int i = 0; i < n; i++) {
        // populating graph
        cin >> m;
        g = populate(m);

        // beginning algorithm
        sort(g.edges.begin(), g.edges.end(), compare_weights); // sorting edges
        cout << "Vertices size: " << g.vertices.size() << endl;
        for (int i = 0; i < g.vertices.size(); i++) {
            found_safe_edge = false;
            while (found_safe_edge == false && g.edges.size() != 0) {
                if (check_if_safe(g.edges[0]) == true) {
                    cout << "Found safe edge." << endl;
                    mst.push_back(g.edges[0]);
                    found_safe_edge = true;
                    // update parent vector and set new connected_vetex
                    if (g.edges[0].v1->parent == NULL) {
                        g.edges[0].v1->parent = g.edges[0].v2;
                    }
                    else {
                        g.edges[0].v2->parent = g.edges[0].v1;
                    }
                }
                g.edges.erase(g.edges.begin());
            }
            print_graph(g);
        }
        cout << "temp" << endl;
        // calculating final weight
        for (int i = 0; i < mst.size(); i++) {
            cumulative_edge_weight += mst[i].weight;
        }
        cout << setprecision(10) << cumulative_edge_weight << endl;
    }
    return 0;
    */








    // ATTEMPT 1 BELOW
    /*
    // defining variables
    graph g;
    int n, m;
    vertex curr_vertex;
    vector<edge> mst;
    vector<edge> connected_edges;
    
    // taking num test cases
    cin >> n;
    for (int i = 0; i < n; i++) {
        // populating graph
        cin >> m;
        g = populate(m);

        // testing sorting edges
        sort(g.edges.begin(), g.edges.end(), compare_weights);
        print_graph(g);
        // testing end

        // beginning algorithm
        curr_vertex = g.vertices[0];
        for (int i = 0; i < g.vertices.size(); i++) {
            // adding edges of current vertex to connected_edges
            cout << "Adding edges of current vertex..." << endl;
            for (int j = 0; j < curr_vertex.edges.size(); j++) {
                // if the edge bordering the vertex has not yet been visited we add it to the connected_edges vector
                if (curr_vertex.edges[j]->visited == false) {
                    connected_edges.push_back(*curr_vertex.edges[j]);
                    curr_vertex.edges[j]->visited = true;
                }
            }
            // sorting connected edges
            cout << "Sorting edges..." << endl;
            sort(connected_edges.begin(), connected_edges.end(), compare_weights);
            // moving through sorted vertex, checking if edge is safe
            while (connected_edges.size() != 0) {
                // if edge is safe
                cout << "Checking if current edge is safe..." << endl;
                if (check_if_safe(connected_edges[0]) == true) {
                    // add edge to mst
                    cout << "Edge is safe. Adding to mst and adding edges of new vertex..." << endl;
                    mst.push_back(connected_edges[0]);
                    // update parent vector and set new connected_vetex
                    if (connected_edges[0].v1->parent == NULL) {
                        connected_edges[0].v1->parent = connected_edges[0].v2;
                        curr_vertex = *connected_edges[0].v2;
                    }
                    else {
                        connected_edges[0].v2->parent = connected_edges[0].v1;
                        curr_vertex = *connected_edges[0].v1;
                    }
                    connected_edges.erase(connected_edges.begin());
                    break;
                }
                connected_edges.erase(connected_edges.begin());
                cout << "Edge was not safe. Deleting..." << endl;
            }
        }
        // TEMP - printing out added weights
        for (int i = 0; i < mst.size(); i++) {
            cout << mst[i].weight << endl;
        }
    }

    return 0;
    */
}
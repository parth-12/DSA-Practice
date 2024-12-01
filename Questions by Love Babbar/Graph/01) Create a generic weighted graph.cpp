#include <iostream>
#include <string>
using namespace std;


template <typename T>
class graph {
public:
    unordered_map<T, vector<pair<T, int>>> adjList;

    void addEdge(T u, T v, int dist, bool bidirec = 1) {
        adjList[u].push_back({v, dist});

        if (bidirec)
            adjList[v].push_back({u, dist});
        if (adjList.find(v) == adjList.end())
            adjList[v];
    }

    void printGr() {
        for (auto& n: adjList) {
            cout << n.first << ":  ";
            for (auto& v: n.second) {
                cout << "(" << v.first << ", " << v.second << ") ";
            }
            cout << endl;
        }
    }
};

int main () {
    graph<string> g;
    g.addEdge("apple", "banana", 6, 0);
    g.addEdge("banana", "orange", 20, 0);
    g.addEdge("orange", "lemon", 5, 0);
    g.addEdge("apple", "kiwi", 55, 0);

    g.printGr();
    return 0;
}

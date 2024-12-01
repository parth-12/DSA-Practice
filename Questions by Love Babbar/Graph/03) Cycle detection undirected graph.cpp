// if the node is already visited (and is not parent), there is a cycle

// just keep track of the parent (like here DFS), same thing can done with BFS


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<bool> vis;
    bool isCycle(vector<vector<int>>& adj) {
        vis.assign(adj.size(), 0);

        for(int i=0; i<adj.size(); i++){
            if (!vis[i]) {                              // if(!vis[i] and dfs_visit(adj, -1, i)) return 1; (concise way)
                bool val = dfs_visit(adj, -1, i);
                if (val) return 1;
            }
        }
        return 0;
    }

    bool dfs_visit(vector<vector<int>>& adj, int par, int n) {
        vis[n] = 1;
        for(auto& ch: adj[n]) {
            if (!vis[ch]) {
                bool val = dfs_visit(adj, n, ch);
                if(val) return 1;
            }
            else if (ch != par) return 1;
        }
        return 0;
    }
};

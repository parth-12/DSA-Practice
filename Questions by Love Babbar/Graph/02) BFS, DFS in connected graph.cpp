//BFS

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<int> vis (adj.size(), 0), ans;
        queue<int> q ({0});
        vis[0] = 1;
        while (!q.empty()) {
            int i = q.front();
            q.pop(); ans.push_back(i);

            for (auto& n : adj[i]) {
                if (vis[n] == 0) {
                    q.push(n);
                    vis[n] = 1;
                }
            }
        }
        return ans;
    }
};


// DFS

class Solution {
  public:
  vector<bool> vis;
  vector<int> ans;
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vis.assign(adj.size(), 0);
        ans.clear();
        dfs_visit(adj, 0);

        return ans;
    }

    void dfs_visit(vector<vector<int>>& adj, int n) {
        vis[n] = 1;
        ans.push_back(n);
        for (auto& ch: adj[n])
            if(!vis[ch])
                dfs_visit(adj, ch);
    }
};

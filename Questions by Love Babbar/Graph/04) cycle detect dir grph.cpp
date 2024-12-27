// instead of maintaining visisted and recursive_stack, and 3 states could be give to nodes
// but to make it space efficient (vis and recu-stack) could be used with vector<bool> which has diff
// underlying constructor (uses bits)


class Solution {
  public:
  vector<int> vis;
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        vis.assign(V, 0);
        for(int i=0; i<V; i++) {
            if(vis[i] == 0) {
                if(dfs_visit(adj, i)) return 1;
            }
        }
        return 0;
    }

    bool dfs_visit(vector<vector<int>>& adj, int n) {
        vis[n] = 1;
        for(auto& ch: adj[n]) {
            if (vis[ch] == 1) return 1;
            if (vis[ch] == 0 and dfs_visit(adj, ch)) return 1;
        }
        vis[n] = 2;
        return 0;
    }
};


// this soln works as well, the soln u learn first
// class Solution {
//   public:
//   vector<bool> vis;
//   vector<bool> rec_st;
//     // Function to detect cycle in a directed graph.
//     bool isCyclic(int V, vector<vector<int>> adj) {
//         vis.assign(V, 0);
//         rec_st.assign(V, 0);
//         for(int i=0; i<V; i++) {
//             if (!vis[i] and dfs_visit(adj, i))
//                 return 1;
//         }
//         return 0;
//     }
//
//     bool dfs_visit(vector<vector<int>>& adj, int n) {
//         vis[n] = 1;
//         rec_st[n] = 1;
//         for(auto& ch: adj[n]) {
//             if (rec_st[ch]) return 1;
//             if (!vis[ch] and dfs_visit(adj, ch)) return 1;
//         }
//         rec_st[n] = 0;
//         return 0;
//     }
// };


// Using Kahn's algorithm
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> inDeg (V, 0);
        for(int i = 0; i<V; i++) {
            for(auto& n: adj[i])
                inDeg[n]++;
        }

        queue<int> q;
        for(int i=0; i<inDeg.size(); i++)
            if(inDeg[i] == 0)
                q.push(i);

        int cnt = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop(); cnt++;

            for(auto& v: adj[u]){
                // inDeg[v]--;
                if (--inDeg[v] == 0) q.push(v);
            }
        }
        if (cnt != V) return 1;
        return 0;
    }
};

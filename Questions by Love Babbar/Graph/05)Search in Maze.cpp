class Solution {
  public:
  vector<vector<int>> rec_st;
  vector<string> ans;
  int N;
    vector<string> findPath(vector<vector<int>> &mat) {
        if (mat[0][0] == 0) return {};
        N = mat.size();
        rec_st.assign(N, vector<int> (N, 0));
        ans.clear();

        dfs(0, 0, "", mat);
        return ans;
    }
    void dfs(int i, int j, string s, vector<vector<int>> &mat) {
        if(i==N-1 and j==N-1) {
            ans.push_back(s);
            return;
        }
        rec_st[i][j] = 1;
        //Up and Down
        if(i-1 >= 0 and !rec_st[i-1][j] and mat[i-1][j])
            dfs(i-1, j, s+'U', mat);
        if(i+1 <= N-1 and !rec_st[i+1][j] and mat[i+1][j])
            dfs(i+1, j, s+'D', mat);
        // Left and Right
        if(j-1 >= 0 and !rec_st[i][j-1] and mat[i][j-1])
            dfs(i, j-1, s+'L', mat);
        if(j+1 <= N-1 and !rec_st[i][j+1] and mat[i][j+1])
            dfs(i, j+1, s+'R', mat);
        rec_st[i][j]=0;

    }
};

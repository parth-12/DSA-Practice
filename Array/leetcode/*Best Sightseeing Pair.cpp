// https://leetcode.com/problems/best-sightseeing-pair/description/
// DP // 27/12/24

//aftr seeing editorial soln
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int n = values.size(), mxleft = 0;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = max(ans, values[i] - i + mxleft);
            mxleft = max(mxleft, values[i] + i);
        }
        return ans;
    }
};


//someboys's op soln
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int ans = 0;
        int a = values[0];
        for(int i = 1;i<values.size();i++){
            a--;
            int b = values[i];
            ans = max(ans,a+b);
            a = max(a,b);
        }
        return ans;
    }
};


// my first attempt very very stupid but O(n) soln
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> lin (n, -1), rin(n, -1);
        for(int i=0; i<n; i++) {
            rin[i] = values[i] - i;
            lin[i] = values[i] - (n-1+i);
        }
        vector<int> lf (n, -1), rf(n, -1);
        int lmx = 0;
        for(int i = 1; i<n; i++) {
            lf[i] = lmx;
            if(lin[i] > lin[lmx])
                lmx = i;
        }
        int rmx = n-1;
        for(int i = n-2; i>=0; i--) {
            rf[i] = rmx;
            if(rin[i] > rin[rmx])
                rmx = i;
        }

        int ans = 0;
        for(int i = 1; i<n-1; i++) {
            int l = lf[i], r = rf[i];
            int a1 = max(values[i] + values[l] - i + l,values[i] + values[r] + i - r);
            ans = max(ans, a1);
        }
        int a1 = max(values[0] + values[rf[0]] - rf[0], values[n-1] + values[lf[n-1]] + lf[n-1]- (n-1));
        return max(ans, a1);
    }
};

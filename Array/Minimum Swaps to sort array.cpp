int minSwaps(vector<int>&nums) {
    int ans = 0, n = nums.size();

    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i){
        arr[i] = {nums[i], i};
    }
    sort(arr, arr+n);

    for(int i = 0; i < n; ++i){
        // in short moving each element to its original postion and counting the no. of swaps
        while(i != arr[i].second){                          // while until the original number present before sorting comes back to i
            ans++;
            swap(arr[i], arr[arr[i].second]);
        }
    }
    return ans;
}



// code 2
int minimumswaps (vector<int> position) {
    vector<int>& ps = position;
    int n = (int) ps.size();

    vector<int> s (n);

    iota(s.begin(), s.end(), 0);

    sort(s.begin(), s.end(), [&] (int& i, int& j) {
        return (ps[i] < ps[j]);
    });

    vector<bool> vis (n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        int cyc = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            j = s[j];
            cyc++;
        }
        ans += cyc - 1;
    }
    return ans;
}

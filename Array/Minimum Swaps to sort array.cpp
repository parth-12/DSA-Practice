int minSwaps(int arr[], int n)
{

    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }


    sort(arrPos, arrPos + n);

    // To keep track of visited elements.
    // Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);

    // Initialize result
    int ans = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;

        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }

        ans += (cycle_size - 1);
    }

    // Return result
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

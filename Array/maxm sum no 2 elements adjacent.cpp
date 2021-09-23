// array modified here

int maxx_sum(vector<int>& arr) {
    int n = arr.size();

    if (n == 1) return arr[0];
    if (n == 2) return max(arr[0], arr[1]);

    arr[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
        arr[i] = max(arr[i - 1], arr[i - 2] + arr[i]);

    return arr[n - 1];
}


// w/o modifying array

int maxx_sum(vector<int>& nums) {
        vector<int>& arr = nums;
        int n = arr.size();

        int v1 = arr[0];
        if (n == 1) return v1;

        int v2 = max(arr[0], arr[1]);
        if (n == 2) return v2;

        for (int i = 2; i < n; i++) {
            int x = max(v2, v1 + arr[i]);
            v1 = v2;
            v2 = x;
        }
        return v2;
    }

// If the array is circular so 1 and n cannnot be chosen together.
// Then we calculate from (1 to n - 1) & (2, n) and take their max.

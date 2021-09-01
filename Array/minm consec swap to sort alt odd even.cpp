#include <bits/stdc++.h>

using namespace std;


// Also look for method 2 below

int solve() {
    int n; cin >> n;


    vector<int> a(n);
    vector<int> b;

    int temp , co = 0, ce = 0;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp & 1) {a[i] = 0; co++;}
        else {a[i] = 1; ce++;}
    }


    if (n == 1) return 0;

    int st = 1;
    if (n & 1) {
        if (abs(co - ce) == 1) {
            if (co > ce) st = 0;
            else st = 1;
        }
        else return -1;
    }
    else {
        if (co != ce) return -1;
        b = a;
    }

    int e = 0;
    while (a[e] != 1) e++;

    int o = 0;
    while (a[o] != 0) o++;


    int i = 0;

    // 2 ptr method first time.
    int ans = 0;
    while (e < n and o < n and i < n) {
        if (a[i] == st) {
            if (st == 1) {
                e++;
                while (e < n and a[e] != 1) e++;

            }
            else {
                o++;
                while (o < n and a[o] != 0) o++;
            }
        }
        else {
            if (st == 1) {
                ans += e - i;
                swap(a[i], a[e]);
                while (e < n and a[e] != 1) e++;
                while (o < n and a[o] != 0) o++;
            }
            else {
                ans += o - i;
                swap(a[i], a[o]);
                while (o < n and a[o] != 0) o++;
                while (e < n and a[e] != 1) e++;
            }
        }
        st = 1 - st;
        i++;
    }

    // returning if odd
    if (b.empty()) return ans;


    // 2 ptr method second time.
    st = 0;
    e = 0;
    while (b[e] != 1) e++;

    o = 0;
    while (b[o] != 0) o++;


    i = 0;

    int aa = 0;
    while (e < n and o < n and i < n) {
        if (b[i] == st) {
            if (st == 1) {
                e++;
                while (e < n and b[e] != 1) e++;

            }
            else {
                o++;
                while (o < n and b[o] != 0) o++;
            }
        }
        else {
            if (st == 1) {
                aa += e - i;
                swap(b[i], b[e]);
                while (e < n and b[e] != 1) e++;
                while (o < n and b[o] != 0) o++;
            }
            else {
                aa += o - i;
                swap(b[i], b[o]);
                while (o < n and b[o] != 0) o++;
                while (e < n and b[e] != 1) e++;
            }
        }
        st = 1 - st;
        i++;
    }

    return min(ans, aa);

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;

    while (T--)
        cout << solve() << "\n";

    return 0;
}





// ----------------------------------------------------

int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= 2;
    }
    const long long inf = (long long) 1e18;
    long long ans = inf;
    for (int r = 0; r < 2; r++) {
      vector<int> x;
      vector<int> y;
      for (int i = r; i < n; i += 2) {
        x.push_back(i);
      }
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
          y.push_back(i);
        }
      }
      if (x.size() == y.size()) {
        long long cur = 0;
        for (int i = 0; i < (int) x.size(); i++) {
          cur += abs(x[i] - y[i]);
        }
        ans = min(ans, cur);
      }
    }
    cout << (ans == inf ? -1 : ans) << '\n';

// -------------------------------------------------------------

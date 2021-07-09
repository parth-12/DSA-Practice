// You are given an array prices where prices[i] is the price of a given stock on the ith day.
//
// Find the maximum profit you can achieve.
// You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 0; i < prices.size() - 1; i++)
            profit += max(prices[i+1] - prices[i], 0);

        return profit;
    }
};


// Find the maximum profit you can achieve. You may complete at most two transactions.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int* profit = new int [n];

        int maxx = prices[n - 1];
        profit[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxx = max(maxx, prices[i]);

            profit[i] = max(profit[i + 1], maxx - prices[i]);
        }

        int minn = prices[0];
        int result = 0;
        for (int i = 1; i < n; i++) {
            minn = min(minn, prices[i]);
            result = max(result, profit[i] + prices[i] - minn);
        }
        delete[] profit;

        return result;
    }
};

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
// return the area of the largest rectangle in the histogram.


#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

//can also be done by just pushing index in the stack and not the heights

// and calculating the area by if stack is not empty
// area = arr[top] * (i - st.top() - 1)
// or if stack is empty
// area = arr[top] * i

//see 06) Maxm rectangle.cpp




// used 2 stack
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        // adding 0 at ending to empty the stack at the end automatically
        heights.push_back(0);

        stack<int> h_st, p_st;

        int i = 0;
        for (auto& h: heights) {
            int start = i;

            // Pushing in stack when value of current height is less than top of stack
            while (!h_st.empty() and h < h_st.top()) {
                start = p_st.top();                             // changing start since it can be extended baxkwards
                maxArea = max(maxArea, h_st.top() * (i - start));

                p_st.pop(); h_st.pop();
            }

            // Not pushing in stack when value is equal
            if (h_st.empty() or h > h_st.top()) {
                h_st.push(h);
                p_st.push(start);
            }
            i++;
        }
        heights.pop_back();
        return maxArea;
    }
};


// used pair in one stack
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = (int) heights.size();
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {

            int start = i;
            while (!s.empty() and heights[i] < s.top().second) {
                auto a = s.top();
                s.pop();

                maxArea = max(maxArea, a.second * (i - a.first));
                start = a.first;
            }
            if (s.empty() or heights[i] > s.top().second) {
                s.push({start, heights[i]});
            }
        }

        while(!s.empty()) {
            auto a = s.top();
            s.pop();
            maxArea = max(maxArea, a.second * (n - a.first));
        }
        return maxArea;
    }
};


int main() {
    vector<int> hist = {6, 2, 5, 4, 5, 1, 6};
    Solution1 ob;

    cout << "Maximum area is: " << ob.largestRectangleArea(hist)<< endl;
    return 0;

}

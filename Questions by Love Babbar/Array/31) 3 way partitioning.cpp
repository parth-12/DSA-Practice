// Given an array of size n and a range [a, b].
// The task is to partition the array around the range such that array is divided into three parts.
//
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array.


class Solution{
public:
    //Function to partition the array around the range such
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b) {

        int start = 0, mid = 0, end = array.size() - 1;

        while (mid <= end) {
            if (array[mid] > b)
                swap(array[mid], array[end--]);
            else if (array[mid] < a) {
                swap(array[start++], array[mid++]);
            }
            else
                mid++;
        }
    }
};

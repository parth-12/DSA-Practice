// Given an array of n positive integers and a number k.
// Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

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

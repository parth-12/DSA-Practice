// Given a linked list, the task is to reverse every k node in the linked list.
// If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.



//One of those question where writing a iterative > recursive code is difficult
/*
struct node {
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}
*/

//iterative soln.... Time complexity O(n).... Space complexity O(1)

class Solution {
  public:
    struct node *reverseKGroup(struct node *head, int k) {
        int kk;
        node *curr = head, *prevGrpTail = nullptr;
        node *ans;
        while(curr) {
            kk = k;
            node *prev = nullptr, *next = nullptr;
            node* grpTail = curr;                   // currently it's grp head, but it will be grp tail later
            while(kk-- and curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // prev is the current grp tail originally, which is being assigned previous Group's new Tail
            if(prevGrpTail) prevGrpTail->next = prev;
            else ans = prev;

            prevGrpTail = grpTail;
        }
        return ans;
    }
};


// recursive code.... Time complexity O(n).... space complexity O(n/k).. precisely O(n) (due to recurcion stack)
// n/k or n/k + 1 call will be made during recursionm
class Solution {
  public:
    struct node *reverseKGroup(struct node *head, int k) {
        return recur(head, k);
    }
    node *recur(node *nd, int k) {
        node *sp = nd;
        node *prev = nullptr, *curr = nd, *next = nullptr;
        int kk = k;
        while(kk-- and curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (curr) sp->next = recur(curr, k);
        return prev;
    }
};

/* Linked List Node structure:
struct Node
{
    int data;
    struct Node *next;
}
*/

//iterative soln
class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        if(head->next == nullptr) return head;

        // Node* prev = nullptr, curr = head, nxt;          this will line give error it's Node *a, *b and not Node* a, b;
        Node *prev = nullptr, *curr = head, *nxt;
        while(curr != nullptr) {
            nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};



//my recursive soln
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        return recur(head, nullptr);
    }

    ListNode* recur(ListNode* curr, ListNode* prev) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        if(nxt != nullptr) return recur(nxt, curr);
        return curr;
    }
};
// could be done by passing just a single argument... see gfg

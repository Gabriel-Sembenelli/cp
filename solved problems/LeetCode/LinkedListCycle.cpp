/*
https://leetcode.com/problems/linked-list-cycle/

Using Fast and Slow Pointers, is guaranteed that, if there is a cycle,
the fast pointer will reach slow pointer eventually
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(fast != nullptr and fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
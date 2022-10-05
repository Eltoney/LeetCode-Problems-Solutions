/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        int c = 0;
        while(l1 != NULL || l2 != NULL || c != 0){
            int a = (l1 ? l1 -> val : 0);
            int b = (l2 ? l2 -> val : 0);
            
            cur -> next = new ListNode((a + b + c) % 10);
            cur = cur -> next;
            
            c = (a + b + c) / 10;
            
            l1 = (l1 ? l1 -> next : NULL);
            l2 = (l2 ? l2 -> next : NULL);
        }
        return head -> next;
        
        
        
    }
};
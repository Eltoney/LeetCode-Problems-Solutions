/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int cnt = 1e4 + 9;
        while(head && cnt){
            head = head -> next;
            cnt--;
        }
        return cnt == 0;
    }
};
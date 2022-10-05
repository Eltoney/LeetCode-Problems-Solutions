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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL ){
            return NULL;
        }else if(list1 == NULL){
            return list2;
        }else if(list2 == NULL){
            return list1;
        }
        ListNode* list = NULL;
        if(list1 -> val < list2 -> val){
            list = list1;
            list1 = list -> next;
        }else{
            list = list2;
            list2 = list2 -> next;
        }
        ListNode *head = list;
        while(list1 != NULL || list2 != NULL){
            if(list1 == NULL){
                list -> next = list2;
                list = list -> next;
                list2 = list2 -> next;
            }else if(list2 == NULL){
                list -> next = list1;
                list = list -> next;
                list1 = list1 -> next;
            }else{
                if(list1 -> val < list2 -> val){
                     list -> next = list1;
                     list = list -> next;
                     list1 = list1 -> next;
                }else{
                     list -> next = list2;
                     list = list -> next;
                     list2 = list2 -> next;
                }
            }
        }
        
        return head;
    }
};
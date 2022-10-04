class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        int count = 0;
        
        while(temp != NULL)         // count the total number of nodes
        {
            count++;
            temp = temp->next;
        }
        
        if(count == 1)              // if the count of node is 1, no node will be left
        {
            return NULL;
        }
        
        if(n == count)              // if we have to delete 1st node, i.e, n node from last where n = total number of nodes(count-n = 0)
        {
            return head->next;
        }
        
        count = count-n;            // find the node from start which is just previous to the node that has to be deleted
        temp = head;
        
        while(count > 1)
        {
            temp = temp->next;
            count--;
        }
        
        temp->next = temp->next->next;    // insert the value of next->next in the next of the node which is just before the node to be deleted                                      
        return head;
    }
};
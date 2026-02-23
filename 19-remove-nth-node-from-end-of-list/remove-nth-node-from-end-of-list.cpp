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
    int getLength(ListNode* &head){
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int len = getLength(head);
        int pos = len-n;
        // Most imp step, pos=0 means we have delete head node
        if (pos == 0) {
          ListNode* newHead = head->next;
          delete head;
          return newHead;
    }
            ListNode* prev = head;
           
            int i = 1;
            while(i<pos){
                prev = prev->next;
                i++;
            }
            if(prev->next!=NULL){
             ListNode* curr = prev->next;
             prev->next = curr->next;
             curr->next = NULL;
             delete curr;
        }
        
        return head;
    }
};
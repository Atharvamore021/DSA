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
    int getlength(ListNode* head){
        ListNode* temp = head;
        int i = 0;
        while(temp!=NULL){
            temp = temp->next;
            i++;
        }
        return i;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;
        int len = getlength(head);
        if(k>len) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* f = curr->next;
        int i = 0;
        while(i<k){
            f = curr->next;
            curr->next = prev;
            prev = curr;
            curr = f;
            i++;
        }
        if(f!=NULL){
          head->next = reverseKGroup(curr,k);

        }
        return prev;
    }
};
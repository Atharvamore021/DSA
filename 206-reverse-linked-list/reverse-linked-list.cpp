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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* reverseList(ListNode* head) {
              if(head==NULL) return {};
              int len = getLength(head);
              if(len<0 && len>5000) return {};
              ListNode* prev = NULL;
              ListNode* curr = head;
              ListNode* forward = head->next;
              while(curr!=NULL){
                   forward = curr->next;
                   curr->next = prev;
                   prev = curr;
                   curr = forward;
              }
              return prev;
        
    }
};
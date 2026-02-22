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
    ListNode* getMiddle(ListNode* &head){
             ListNode* slow = head;
             ListNode* fast = head->next;
             while(fast!=NULL){
                fast = fast->next;
                if(fast!=NULL){
                    fast = fast->next;
                    slow = slow->next;
                }
             }
                return slow;
        } 
    
    ListNode* reverseLL(ListNode* &head){
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;

        ListNode* temp1 = head;
        ListNode* temp2 = getMiddle(head);
        
        ListNode* reverseHead = reverseLL(temp2->next);

        temp2->next = reverseHead;
        temp2 = reverseHead;
        while(temp2!=NULL){
             if(temp1->val == temp2->val){
                temp1 = temp1->next;
                temp2 = temp2->next;
             }
             else return false;
        }
        return true;
        
    }
};
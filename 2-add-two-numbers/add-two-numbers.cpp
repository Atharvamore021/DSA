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
    ListNode* reverse(ListNode* &head){
              ListNode* prev = NULL;
              ListNode* curr = head;
              ListNode* f = head->next;
              while(curr!=NULL){
                   f = curr->next;
                   curr->next = prev;
                   prev = curr;
                   curr = f;
              }
              return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
              if(l1==NULL) return l2;
              if(l2==NULL) return l1;
             // l1 = reverse(l1);
            //  l2 = reverse(l2);

              ListNode* ansHead = NULL;
              ListNode* ansTail = NULL;
              int carry = 0;
              while(l1!=NULL && l2!=NULL){
                    int sum = l1->val + l2->val + carry;
                    int digit = sum%10;
                    carry = sum/10;
                    ListNode* temp = new ListNode(digit);
                    if(ansHead==NULL){
                        ansHead = temp;
                        ansTail = temp;
                    }
                    else{
                        ansTail->next = temp;
                        ansTail = temp;
                    }
                    l1 = l1->next;
                    l2 = l2->next;
              }
              while(l1!=NULL){
                    int sum = l1->val + carry;
                    int digit = sum%10;
                    carry = sum/10;
                    ListNode* temp = new ListNode(digit);
                
                    ansTail->next = temp;
                    ansTail = temp;
                    
                    l1 = l1->next;
                
              }
               while(l2!=NULL){
                    int sum = l2->val + carry;
                    int digit = sum%10;
                    carry = sum/10;
                    ListNode* temp = new ListNode(digit);
                
                    ansTail->next = temp;
                    ansTail = temp;
                    
                    l2 = l2->next;
                
              }
               while(carry!=0){
                    int sum = carry;
                    int digit = sum%10;
                    carry = sum/10;
                    ListNode* temp = new ListNode(digit);
                
                    ansTail->next = temp;
                    ansTail = temp;
                
              }
              
           // ansHead = reverse(ansHead);
            return ansHead;
        
    }
};
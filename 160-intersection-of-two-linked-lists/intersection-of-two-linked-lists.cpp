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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
              if(headA==NULL || headB==NULL) return 0;

              ListNode* a = headA;
              ListNode* b = headB;
              while(a->next!=NULL && b->next!=NULL){
                    if(a==b) return a;
            
                    a = a->next;
                    b = b->next;
              }
            if(a->next==NULL){
                 int lenB = 0;
                 while(b->next!=NULL){
                       b = b->next;
                       lenB++;
                 }
                 while(lenB--){
                     headB = headB->next;
                 }
            }
            else{
                 int lenA = 0;
                 while(a->next!=NULL){
                       a = a->next;
                       lenA++;
                 }
                 while(lenA--){
                    headA = headA->next;   
            }

        }
            while(headA!=headB){
                   headA = headA->next;
                   headB = headB->next;
            }
            return headA;
    }

};
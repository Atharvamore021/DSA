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
    ListNode* getMid(ListNode* head){
              ListNode* s = head;
              ListNode* f = head->next;
              while(f!=NULL){
                    f = f->next;
                    if(f!=NULL){
                        f = f->next;
                        s = s->next;
                    }
              }
              return s;
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
            if(head1==NULL) return head2;
            if(head2==NULL) return head1;

            ListNode* newHead = new ListNode(-1);
            ListNode* mptr = newHead;
            while(head1!=NULL && head2!=NULL){
                  if(head1->val<=head2->val){
                     mptr->next = head1;
                     mptr = head1;
                     head1 = head1->next;
                  }
                  else{
                    mptr->next = head2;
                    mptr = head2;
                    head2 = head2->next;
                  }
            }
            while(head1!=NULL){
                 mptr->next = head1;
                 mptr = head1;
                 head1 = head1->next;
            }
            while(head2!=NULL){
                 mptr->next = head2;
                 mptr = head2;
                 head2 = head2->next;
            }
            return newHead->next;
    }
    ListNode* sortList(ListNode* head) {
            if(head==NULL || head->next==NULL){
                return head;
            }
            
            ListNode* temp1 = head;
            
            ListNode* midHead = getMid(head);
            
            ListNode* temp2 = midHead->next;
            midHead->next = NULL;
            

            temp1 = sortList(temp1);
            temp2 = sortList(temp2);

            ListNode* mergeLL = merge(temp1,temp2);

         return mergeLL;
    }
};
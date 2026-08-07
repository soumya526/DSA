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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*l3=new ListNode();
        ListNode*ptr1=l1;
        ListNode*ptr2=l2;
        ListNode*ptr3=l3;
        int carry=0;
        while(ptr1!=NULL||ptr2!=NULL||carry){
            int sum=0;
            sum=carry;
            if(ptr1!=NULL){
                sum+=ptr1->val;
                ptr1=ptr1->next;
            }
            if(ptr2!=NULL){
                sum+=ptr2->val;
                ptr2=ptr2->next;

            }
            carry=sum/10;
            int remainder=sum%10;
            ptr3->next=new ListNode(remainder);
            ptr3=ptr3->next;
        }
        return l3->next;
    }
};
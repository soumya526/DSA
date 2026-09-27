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
    ListNode* partition(ListNode* head, int x) {
        ListNode*head1=new ListNode();
        ListNode*temp1=head1;
        ListNode*temp=head;
        while(temp!=NULL){
            if(temp->val<x){
            temp1->val=temp->val;
            temp1->next=new ListNode();
            temp1=temp1->next;
            }
            temp=temp->next;
        }
        temp=head;
        ListNode*head2=new ListNode();
        ListNode*temp2=head2;
        while(temp!=NULL){
            if(temp->val>=x){
                 temp2->val=temp->val;
                temp2->next=new ListNode();
                temp2=temp2->next;
            }

            temp=temp->next;
        }
        ListNode*dummy1=new ListNode(0);
        dummy1->next=head1;
        ListNode*curr=dummy1;
        while(curr->next && curr->next!=temp1){
            curr=curr->next;
        }
        curr->next=NULL;
        head1=dummy1->next;

        ListNode*dummy2=new ListNode(0);
        dummy2->next=head2;
        curr=dummy2;
        while(curr->next && curr->next!=temp2){
            curr=curr->next;
        }
        curr->next=NULL;
        head2=dummy2->next;

        if(!head1) return head2;
        if(!head2) return head1;

        temp1=head1;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=head2;
        return head1;
    }
};
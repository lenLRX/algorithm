/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#define NULL 0
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode* head;
		ListNode* p;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		if (p1->val < p2->val){
			head = p1;
			p1 = p1->next;
		}
		else{
			head = p2;
			p2 = p2->next;
		}
		p = head;
		while (p1&&p2){
			ListNode* tmp;
			if (p1->val < p2->val){
				tmp = p1;
				p1 = p1->next;
			}
			else{
				tmp = p2;
				p2 = p2->next;
			}
			p->next = tmp;
			p = tmp;
		}

		if (p1)
			p->next = p1;
		else
			p->next = p2;

		return head;
	}
};
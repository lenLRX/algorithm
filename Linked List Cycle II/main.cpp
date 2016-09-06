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
	ListNode *detectCycle(ListNode *head) {
		ListNode* h1 = head;
		ListNode* h2 = head;

		//this part to find if the cycle exists.
		while (h1&&h1->next != h2) {
			h1 = h1->next;
			if (h1)
				h1 = h1->next;
			else
				return NULL;
			h2 = h2->next;
		}
		if (!h1)
			return NULL;

		h1 = h1->next;

		//to find the length of the cycle.
		int cycle_length = 1;
		h1 = h1->next;

		//if node is linked to itself.
		if (h1 == h2)
			return h1;

		//finding the length of cycle as we move to the next node.
		while (h1 != h2) {
			h1 = h1->next;
			++cycle_length;
		}

		//separate h1 and h2 cycle_length distance apart.
		h1 = h2 = head;
		while (cycle_length) {
			h2 = h2->next;
			--cycle_length;
		}

		if (h1 == h2)
			return h1;

		//finally loop until you encounter the same nodes.    
		while (h2 != h1) {
			h2 = h2->next;
			h1 = h1->next;
		}

		//return the start.
		return h1;
	}
};

int main(){
	return 0;
}
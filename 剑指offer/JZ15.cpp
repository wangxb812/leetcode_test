//输入一个链表，反转链表后，输出新链表的表头。
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL)	return NULL;
		if(pHead->next == NULL)	return pHead;
		ListNode * pReverse =NULL;
		ListNode * pNode=pHead;
		ListNode * pPrev = NULL;
		while(pNode){
			pPrev = pNode->next;
			pNode->next = pPrev;
			pReverse = pNode;
			pNode = pPrev;
		}
		return pReverse;
    }
};
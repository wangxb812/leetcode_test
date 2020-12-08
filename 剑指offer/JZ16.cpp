//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
	//普通迭代法，但是内存可能受限
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* res=nullptr;
		if(pHead1 == nullptr)	return pHead2;
		if(pHead2 == nullptr)	return pHead1;
		while(pHead1!=nullptr && pHead2!=nullptr){
			if(pHead1->val<=pHead2->val){
				res = pHead1;
				res->next = Merge(pHead1->next,pHead2);
			}else{
				res = pHead2;
				res->next = Merge(pHead1,pHead2->next);
			}
		}
		return res;
    }
	ListNode* Merge_2(ListNode* pHead1, ListNode* pHead2){
		ListNode* res=new ListNode(-1);
		ListNode* cur=res;
		if(pHead1 == nullptr)	return pHead2;
		if(pHead2 == nullptr)	return pHead1;
		while(pHead1 && pHead2){
			if(pHead1->val<=pHead2->val){
				cur->next = pHead1;
				pHead1=pHead1->next;
			}
			else{
				cur->next=pHead2;
				pHead2=pHead2->next;
			}
			cur=cur->next;
		}
		cur->next= pHead1?pHead1:pHead2;
		return res->next;
	}
};
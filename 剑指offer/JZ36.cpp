//输入两个链表，找出它们的第一个公共结点。
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
//先多走若干步，然后同时开始遍历，找到第一个相同的节点就是第一个公共节点
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1=getLength(pHead1);
		int len2=getLength(pHead2);
		int temp = len1>len2?len1-len2:len2-len1;
		ListNode* pLong = len1>len2?pHead1:pHead2;
		ListNode* pShort = len1>len2?pHead2:pHead1;
		for(int i=0;i<temp;i++){
			pLong=pLong->next;
		}
		while(pLong!=nullptr&&pShort!=nullptr&&pLong!=pShort){
			pLong=pLong->next;
			pShort=pShort->next;
		}
		ListNode *common=pLong;
		return common;
    }
	int getLength(ListNode* pHead){
		int len=0;
		ListNode *pnode = pHead;
		while (pnode!=nullptr)
		{
			len++;
			pnode=pnode->next;
		}
		return len;
	}
};
//输入一个链表，输出该链表中倒数第k个结点。
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
    //遍历到尾部，然后回溯到k
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead==nullptr || k <= 0) return nullptr;
        int n = 0;
        ListNode *cur = pListHead;
        while (cur) {
            cur = cur->next;
            ++n;
        }
        if (n < k) return nullptr;
        n -= k;
        while (n--) {
            pListHead = pListHead->next;
        }
        return pListHead;
    }
    //两个指针，指针之间的距离为k，当一个指向尾部，另一个刚好是倒数第k个。
    ListNode* FindKthToTail_2(ListNode* pListHead, unsigned int k){
        if(pListHead == nullptr || k == 0) return nullptr;
        ListNode *pHead = pListHead;
        ListNode *pBehind = nullptr;
        for(int i=0;i<k-1;i++){
            if(pHead->next!=nullptr)    pHead=pHead->next;
            else{
                return nullptr;
            }
        }
        pBehind = pListHead;
        while(pHead->next!=nullptr){
            pHead=pHead->next;
            pBehind=pBehind->next;
        }
        return pBehind;
    }
};
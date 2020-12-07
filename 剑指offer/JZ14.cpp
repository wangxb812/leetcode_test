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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k <= 0) return nullptr;
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
};
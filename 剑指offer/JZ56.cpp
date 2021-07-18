//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};
#include<set>
using namespace std;
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (!pHead) return pHead;
        set<int> st;
        ListNode *pre = pHead;
        ListNode *cur = pHead->next;
        while (cur) {
            if (pre->val == cur->val) {
                st.insert(pre->val);
            }
            pre = pre->next;
            cur = cur->next;
        }
        ListNode *vhead = new ListNode(-1);
        vhead->next = pHead;
        pre = vhead;
        cur = pHead;
        while (cur) {
            if (st.count(cur->val)) {
                cur = cur->next;
                pre->next = cur;    
            }
            else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return vhead->next;
    }
};
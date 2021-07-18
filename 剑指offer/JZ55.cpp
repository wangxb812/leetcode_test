#include<string>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *fast =pHead;
        ListNode *slow =pHead;
        while(fast &&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)    break;
        }
        if (!fast || !fast->next) return nullptr;
        fast = pHead;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
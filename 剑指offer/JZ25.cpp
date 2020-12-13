//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），
//请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode *pClonedHead = NULL;
        RandomListNode *pNode = pHead;
        RandomListNode *pClonedNode = NULL;
        cloneNodes(pHead);
        connectRandom(pHead);
        //长链表拆成两个链表，奇数节点是原始，偶数节点是复制出来的链表
        if(pNode!=NULL){
            pClonedHead = pClonedNode = pNode ->next;
            pNode->next = pClonedNode->next;
            pNode =pNode->next;
        }
        while(pNode !=NULL){
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
    //复制原始链表的节点并创建副本节点，再连接到原节点后
    void cloneNodes(RandomListNode *pHead){
        RandomListNode *pNode = pHead;
        while(pNode){
            RandomListNode *pCloned = NULL;
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = NULL;
            pNode->next= pCloned;
            pNode= pCloned->next;
        }
    }
    //设置复制出来的节点的random指针
    void connectRandom(RandomListNode *pHead){
        RandomListNode *pNode = pHead;
        while(pNode){
            RandomListNode *pCloned = pNode->next;
            if(pNode->random!=NULL){
                pCloned->random = pNode->random->next;
            }
            pNode=pCloned->next;
        }
    }
};
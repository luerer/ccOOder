/************
Linked List Random Node
大意：
一个不知道长度的链表，随机返回一个节点，使得每个节点被返回的概率相等。
思路：
蓄水池
容量(k=1),首先前k个元素初始化水池，从第m(m>k)个开始，以k/m选择，如果选中，随机替换掉水池中一个元素。

可证明最终每个元素被选择的概率是k/n
************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        tmp = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* p = tmp;
        int val = p->val;
        for(int i=1; p; ++i)
        {
            if(rand()%i==0) val=p->val;
            p = p->next;
        }
        return val;
    }
private:
    struct ListNode* tmp;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
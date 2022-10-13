/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dumyhead = new ListNode(0);
        dumyhead->next = head;
        ListNode* cur = dumyhead;//保留好头节点
        while(cur->next != nullptr && cur->next->next !=nullptr){
            ListNode* temp = cur->next;
            ListNode* temp1 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = temp;
            temp->next = temp1;
            cur = cur->next->next;
        }
        // head = dumyhead->next;
        // delete dumyhead;
        return head;
        //注意这里也可以直接return dumyhead->next;
        //但是不能直接return head;因为head的头节点是没有变化的
    }
};
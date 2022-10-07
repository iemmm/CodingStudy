//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
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

//第一种解法，直接使用原链表进行结点删除操作
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//     //删除头结点
//     while(head != nullptr && head->val == val){
//         ListNode* temp = head;
//         head = head->next;
//         delete temp;
//     }
//     //删除非头结点
//     ListNode *cur = head;
//     while(cur != nullptr && cur->next != nullptr){
//         if(cur->next->val == val){
//             ListNode* temp = cur->next;
//             cur->next = cur->next->next;
//             delete temp;
//         }
//         else{
//             cur = cur->next;
//         }
//     }
//     return head;
//     }
// };


//第二种解法，创建虚拟头结点

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
       ListNode* virtal = new ListNode(0, head);
       ListNode* cur = virtal;
       while(cur->next != nullptr){
           if(cur->next->val == val){
               ListNode* temp = cur->next;
               cur->next = cur->next->next;
               delete temp;
           }
           else{
               cur = cur->next;
           }
       }
        head = virtal->next;
        delete virtal;
        return head;
    }
};

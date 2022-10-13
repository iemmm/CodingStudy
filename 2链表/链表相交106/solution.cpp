/*给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
图示两个链表在节点 c1 开始相交：
题目数据 保证 整个链式结构中不存在环。
注意，函数返回结果后，链表必须 保持其原始结构 。
*/


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0;
        int lenB = 0;
        //计算链的长度
        while(curA != NULL){
            lenA ++;
            curA = curA->next;
        }
        while(curB != NULL){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if(lenA < lenB){ //将A设为长链
            swap(lenA, lenB);
            swap(curA, curB);
        } 
        //计算链长度差值
        int n = lenA - lenB;
        while(n--){
            curA = curA->next;
        }
        
        while(curA != NULL){
            if(curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
            
        }
        return NULL;
        
    }
};
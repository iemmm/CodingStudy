/*给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-linked-list
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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp;
//         ListNode* cur = head;
//         ListNode* pre = NULL;
//         while(cur){
//             temp = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = temp;
//         }
//         return pre;

//     }
// };
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if(cur == NULL){
            return pre;
        }
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL,head);
    }
};
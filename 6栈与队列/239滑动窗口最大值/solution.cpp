/**
 *给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

 

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * */

class Solution {
public:
    class MyQueue{
    public:
    deque<int> que;
    void pop(int val){
        if(!que.empty() && val == que.front()){
            que.pop_front();
        }
    }
    void push(int val){
        while(!que.empty() && val > que.back()){
            que.pop_back();
        }
        que.push_back(val);
    }
    int front(){
        return que.front();
    }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue qu;
        vector<int> res;
        for(int i = 0; i < k; i++){
            qu.push(nums[i]);
        }
        res.push_back(qu.front());
        for(int i = k; i < nums.size(); i++){
            qu.pop(nums[i - k]);
            qu.push(nums[i]);
            res.push_back(qu.front());
        }
        return res;
    }
};

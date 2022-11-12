/**
 *给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
class Solution {
public:
    //定义实现小顶堆数据结构的compare函数
    class mycompare{
    public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
        return lhs.second > rhs.second;//如果是大顶堆 "<"
    }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //用map记录每个元素出现的次数
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }

        //对元素出现的频率排序
        //数据结构为小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> que;
        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            que.push(*it);
            if(que.size() > k){
                que.pop();
            }
        }
        vector<int> res(k);
        //找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        for(int i = k - 1; i >=0; i--){
            res[i] = que.top().first;
            que.pop();
        }
        return res;
    }
};

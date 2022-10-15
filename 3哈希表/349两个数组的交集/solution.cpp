/**
 * @file solution.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 .
 */

#include<unordered_set>
#include<vector>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> reselt_set;
        unordered_set<int> num_set(nums1.begin(), nums1.end());//将数组nums1的值映射到哈希表；
        for(int num : nums2){
            if(num_set.find(num) != num_set.end()){
                reselt_set.insert(num);
            }
        }
        return vector<int>(reselt_set.begin(), reselt_set.end());
    }
};
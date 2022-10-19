#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i; i < nums.size(); i++){
            if(nums[i] > 0)
                return res;
            // if(i > 0 && nums[i] == nums[i - 1])
            //     continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0) right--;
                else if(nums[i] + nums[left] + nums[right] < 0) left++;
                else{
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(right > left && nums[left] == nums[left + 1]) left++;
                    while(right >left && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }

            }
        }
        return res;
    }
};

int main(){
    vector<int> test={-1, 0, 1, 2, -1, -4};
    // for(auto iter = test.begin(); iter != test.end(); iter++){
    //     cout << *iter<<", ";
    // }
    for(int i=0; i < test.size(); i++){
        cout << test[i]<<", ";
    }
    
    Solution a;
    vector<vector<int>> res = a.threeSum(test);
    for(auto iter =res.begin(); iter != res.end(); iter++){
        cout<<"[";
        vector res1 = *iter;
        for (auto iter1 = res1.begin(); iter1 !=res1.end(); iter1++){
        cout<<*iter1<<", ";
        }
        cout <<"] ";
    }
    return 0;
}
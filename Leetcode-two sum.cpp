class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> hashmap;
        for(int i=0; i<nums.size(); i++){
            hashmap[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){
            if(hashmap.count(target-nums[i])){
                int j = hashmap[target-nums[i]];
                if(i>j){
                    result.push_back(j);
                    result.push_back(i);
                }
                else if(i<j){
                    result.push_back(i);
                    result.push_back(j);
                }
                if(i!=j)break;
            }
        }
        return result;
    }
};

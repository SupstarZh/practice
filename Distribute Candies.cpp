/*
575. Distribute Candies
Given an integer array with even length, where different 
numbers in this array represent different kinds of candies. 
Each number means one candy of the corresponding kind. 
You need to distribute these candies equally in number to brother and sister. 
Return the maximum number of kinds of candies the sister could gain.
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int num=candies.size(),unum=0;
        set<int> kinds;
        for(auto &i:candies){
            int oldsize = kinds.size();
            kinds.insert(i);
            if(oldsize!=kinds.size()){
                unum++;
            }
        }
        return num/2<unum?num/2:unum;
    }
};

/*
946. Validate Stack Sequences
Given two sequences pushed and popped with distinct values,
return true if and only if thiscould have been the result of 
a sequence of push and pop operations on an initially empty stack.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sta;
        int pushednum=0,poppednum=0;
        while(pushednum < pushed.size()){
            sta.push(pushed[pushednum++]);
            while(!sta.empty() && sta.top()==popped[poppednum]){
                sta.pop();
                poppednum++;
            }
        }
        return sta.empty();
    }
};

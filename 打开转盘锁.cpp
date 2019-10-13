/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        set<string> deadend;
        for(int i=0; i<deadends.size(); i++){
            deadend.insert(deadends[i]);
        }
        if(deadend.count(start)) return -1;
        queue<string> que;
        que.push(start);
        set<string> used;
        used.insert(start);
        int result=0;
        while(!que.empty()){
            int sizes = que.size();
            result++;
            for(int j=0; j<sizes; j++){
                string temp = que.front();
                que.pop();
                if(temp == target) return result-1;
                for(int i=0; i<temp.size(); i++){
                    if(temp[i] == '0'){
                        string temp2 = temp;
                        temp2[i] = '9';
                        if(!deadend.count(temp2) && !used.count(temp2)) que.push(temp2);
                        used.insert(temp2);
                        temp2[i] = '1';
                        if(!deadend.count(temp2) && !used.count(temp2)) que.push(temp2);
                        used.insert(temp2);
                    }
                    else if(temp[i] == '9'){
                        string temp2 = temp;
                        temp2[i] = '8';
                        if(!deadend.count(temp2) && !used.count(temp2)) que.push(temp2);
                        used.insert(temp2);
                        temp2[i] = '0';
                        if(!deadend.count(temp2) && !used.count(temp2)) que.push(temp2);
                        used.insert(temp2);
                    }
                    else{
                        string temp2 = temp;
                        temp2[i] += 1;
                        if(!deadend.count(temp2) && !used.count(temp2)) que.push(temp2);
                        used.insert(temp2);
                        temp2[i] -= 2;
                        if(!deadend.count(temp2) && !used.count(temp2)) que.push(temp2);
                        used.insert(temp2);
                    }
                }
            }
        }
        return -1;
    }
};

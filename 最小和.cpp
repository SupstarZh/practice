/*wofole easy题*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
int n;
deque<int> que;
vector<int> pay;
stack<int> c;
void dfs(int i, int sum)
{
    if(i==n){
        int all=0, ss=0;
        while(!que.empty()){
            ss++;
            c.push(que.front());
            all = all*10+que.front();
            que.pop_front();
        }
        sum+=all;
        pay.push_back(sum);
        while(ss--){
            que.push_front(c.top());
            c.pop();
        }
        return ;
    }
    for(int j=1; j<=que.size()-n+i; j++){
        int ttt=0;
        int ss=j;
        while(ss--){
            c.push(que.front());
            ttt = que.front()+ttt*10;
            que.pop_front();
        }
        dfs(i+1, sum+ttt);
        ss=j;
        while(ss--){
            que.push_front(c.top());
            c.pop();
        }
    }

}
int main()
{
    string num;
    cin>>num>>n;
    for(int i=0; i<num.size(); i++){
        que.push_back(num[i]-'0');
    }
    dfs(1, 0);
    int m=pay[0];
    for(int i=1; i<pay.size(); i++){
        if(pay[i]<m) m=pay[i];
    }
    cout<<m<<endl;
    return 0;
}

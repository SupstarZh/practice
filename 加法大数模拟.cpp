#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
    string a, b;
    while(cin>>a>>b)
    {
        bool tag1=0, tag2=0;
        if(a[0] == '-') {
            tag1 = 1;
            a[0] = '0';
        }
        if(b[0] == '-') {
            tag2 = 1;
            b[0] = '0';
        }
        if(tag2+tag1 != 1)
        {
            if(tag2==1)
                cout<<'-';
            if(a.size()<b.size() || (a.size()==b.size() && (a<b)))
            {
                swap(a, b);
            }
            int i;
            unsigned long la = a.size(), lb = b.size();
            for(i=0; i<la-lb; i++)
                b = '0' + b;
            stack<int>s;
            int jiewei = 0;
            for(i=la-1; i>=0; i--)
            {
                int v = (a[i]-'0') + (b[i]-'0') + jiewei;
                s.push(v>=10 ? v-10:v);
                jiewei = (v>=10 ? 1:0);
            }
            while(s.top()==0)
                s.pop();
            while(!s.empty()){
                cout<<s.top();
                s.pop();
            }
            cout<<endl;
        }
        else if(tag1==1 && tag2 == 0)
        {
            swap(a,b);
            if(a.size()<b.size() || (a.size()==b.size() && (a<b)))
            {
                cout<<"-";
                swap(a, b);
            }
            int i;
            unsigned long la = a.size(), lb = b.size();
            for(i=0; i<la-lb; i++)
                b = '0' + b;
            stack<int>s;
            int jiewei = 0;
            for(i=la-1; i>=0; i--)
            {
                int v = a[i] - b[i] + jiewei;
                s.push(v>=0 ? v:v+10);
                jiewei = (v>=0 ? 0:-1);
            }
            while(s.top()==0)
                s.pop();
            while(!s.empty()){
                cout<<s.top();
                s.pop();
            }
            cout<<endl;
        }
        else
        {
            if(a.size()<b.size() || (a.size()==b.size() && (a<b)))
            {
                cout<<"-";
                swap(a, b);
            }
            int i;
            unsigned long la = a.size(), lb = b.size();
            for(i=0; i<la-lb; i++)
                b = '0' + b;
            stack<int>s;
            int jiewei = 0;
            for(i=la-1; i>=0; i--)
            {
                int v = a[i] - b[i] + jiewei;
                s.push(v>=0 ? v:v+10);
                jiewei = (v>=0 ? 0:-1);
            }
            while(s.top()==0)
                s.pop();
            while(!s.empty()){
                cout<<s.top();
                s.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}
 

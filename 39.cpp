#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> firstnegative(vector<int>v,int n,int k)
{
    int start=0;
    int end=0;
    queue<int>q;
    vector<int>ans;
    while(end<n)
    {
        if(v[end]<0)
        {
            q.push(v[end]);
        }
        if(end-start+1<k)
        {
            end++;
        }
        else if(end-start+1==k)
        {
            if(q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
                if(v[start]==q.front())
                {
                    q.pop();
                }
            }
            start++;
            end++;
        }
    }
    return ans;
}
int main()
{
    vector<int>v={1,2,-3,4,5,-6,-5};
    vector<int>ans=firstnegative(v,v.size(),2);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
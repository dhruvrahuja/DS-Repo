#include<bits/stdc++.h>
using namespace std;
class que
{
    stack<int>s1;
    stack<int>s2;
    public:
        void push(int x)
        {
            s1.push(x);
        }
        int pop()
        {
            if(s1.empty()&&s2.empty())
            {
                return -1;
            }
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    {
                        s1.pop();
                    }
                }
            }
            int val=s2.top();
            s2.pop();
            return val;
        }
        bool empty()
        {
            if(s1.empty()&&s2.empty())
            {
                return true;
            }
            return false;
        }
};
int main()
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"front element is "<<q.pop();
}
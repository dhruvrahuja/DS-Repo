//3. Rain water trapping
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int water=0,count=0,start=height[0],m=start;
        for(int i=1;i<height.size();i++){
            count=start-height[i];
            if(count>0){
                water+=count;
            }else{
                start=height[i];
            }
            if(m<height[i]){
                m=height[i];
            }
        }
        start=height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            if(height[i]==m){
                break;
            }
            water-=m-height[i];
            count=start-height[i];
            if(count>0){
                water+=count;
            }else{
                start=height[i];
            }
        }
        return water;
    }
};
vector<int> vec(int a[],int n){
    vector<int> r;
    for(int i=0;i<n;i++){
        r.push_back(a[i]);
    }
    return r;
}
int main(){
    Solution S;
    int a[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v1=vec(a,12);
    int b[6]={4,2,0,3,2,5};
    vector<int> v2=vec(b,6);
    cout<<S.trap(v1)<<endl;//6
    cout<<S.trap(v2)<<endl;//9
    return 0;
}
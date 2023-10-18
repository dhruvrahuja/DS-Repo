//8. First negative integer in every window of size k

#include <iostream>
using namespace std;

int neg(vector<int> v, int start, int k){
    int res=0;
    for(int i=start;i<start+k;i++){
        if(v[i]<0){
            res=v[i];
            break;
        }
    }
    return res;
}

vector<int> firstNeg(vector<int> v, int k){
    int n=v.size();
    vector<int> result;
    int start=0;
    int m=neg(v,start,k);
    result.push_back(m);
    start++;
    while(start<=n-k){
        if(v[start-1]==m|| m==0){
            m=neg(v,start,k);
        }
        result.push_back(m);
        start++;
    }
    return result;
}

vector<int> vec(int a[],int n){
    vector<int> r;
    for(int i=0;i<n;i++){
        r.push_back(a[i]);
    }
    return r;
}

void display(vector<int> x){
    int n=x.size();
    for (int i = 0; i < n-1; i++){
        cout<<x[i]<<", ";
    }
    cout<<x[n-1]<<endl;
}

int main(){
    int a[10]={2,-2,5,-1,3,-5,7,3,-9,10};
    vector<int> v=vec(a,10);
    display(v);
    display(firstNeg(v,1));
    display(firstNeg(v,2));

    return 0;
}
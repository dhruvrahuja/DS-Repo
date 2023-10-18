//2. Nse, nge, next greater to right, next greater to left, nearest smaller to left, next smaller to right

#include <iostream>
using namespace std;

int ngr(int a[],int i){
    int m=a[i];
    for (int j = i+1; j < 10; j++){
        if(a[j]>m){
            m=a[j];
        }
    }
    if(m==a[i])return -1;
    return m;   
}
int nsr(int a[],int i){
    int m=a[i];
    for (int j = i+1; j < 10; j++){
        if(a[j]<m){
            m=a[j];
        }
    }
    if(m==a[i])return -1;
    return m;   
}
int ngl(int a[],int i){
    int m=a[i];
    for (int j = i-1; j > 0; j--){
        if(a[j]>m){
            m=a[j];
        }
    }
    if(m==a[i])return -1;
    return m;   
}
int nsl(int a[],int i){
    int m=a[i];
    for (int j = i-1; j > 0; j--){
        if(a[j]<m){
            m=a[j];
        }
    }
    if(m==a[i])return -1;
    return m;   
}

int main(){
    int a[10]={2,3,5,2,4,8,4,6,7,0};
    cout<<ngr(a,4)<<endl;
    cout<<nsr(a,4)<<endl;
    cout<<ngl(a,4)<<endl;
    cout<<nsl(a,4)<<endl;
    return 0;
}
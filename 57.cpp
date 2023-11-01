//57. Converting post order from pre order
#include <iostream>
using namespace std;

void findPostOrder(int pre[7], int n, int minval,int maxval, int& preIndex){
    if (preIndex == n) return;
    if (pre[preIndex] < minval || pre[preIndex] > maxval) {
        return;
    }
    int val = pre[preIndex];
    preIndex++;
    findPostOrder(pre, n, minval, val, preIndex);
    findPostOrder(pre, n, val, maxval, preIndex);
    cout << val << " ";
}
 
void findPostOrder(int pre[], int n){
    int preIndex = 0;
    findPostOrder(pre, n, INT16_MIN, INT16_MAX, preIndex);
}

int main(){
    int pre[5] = { 5, 3, 2, 4, 7};// 5 3 2 4 7
    cout<<"Pre Order :";
    for (int i = 0; i < 4; i++){
        cout<<pre[i]<<" ";
    }
    cout<<pre[4]<<endl;
    cout<<"Post Order :";
    findPostOrder(pre, 5);// 2 4 3 7 5
    cout<<endl;
    return 0;
}
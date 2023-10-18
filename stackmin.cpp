//4. Minimum element in stack in constant space
#include <iostream>
using namespace std;

class StackArray{
    int* a,capacity,top;

    public:
    StackArray(int n){
        capacity=n;
        a=new int[n];
        top=0;
    }
    bool isEmpty(){
        return top==0;
    }
    bool isFull(){
        return top==capacity-1;
    }
    int getTop(){
        return a[top-1];
    }
    void push(int x){
        if(!isFull()){
            a[top]=x;
            top++;
        }else{
            cout<<"Stack OverFlow"<<endl;
        }
    }
    int pop(){
        if(!isEmpty()){
            int d=a[top-1];
            a[top-1]=0;
            top--;
            return d;
        }else{
            cout<<"Stack UnderFlow"<<endl;
        }
    }
    int min(){
        int m=getTop();
        StackArray* minStack= new StackArray(capacity);
        while(!isEmpty()){
            int x=pop();
            minStack->push(x);
            if(x<m){
                m=x;
            }
        }
        while(!minStack->isEmpty()){
            int x=minStack->pop();
            push(x);
        }
        return m;

    }
};

int min(StackArray* stack){

}

int main(){
    StackArray* stack=new StackArray(10);
    stack->push(23);
    stack->push(2);
    stack->push(8);
    cout<<stack->min()<<endl;
    stack->push(1);
    stack->push(6);
    stack->push(5);
    cout<<stack->min()<<endl;
    stack->push(2);
    stack->push(9);
    stack->push(0);
    cout<<stack->min()<<endl;


    return 0;
}
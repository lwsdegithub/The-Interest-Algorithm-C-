#include<iostream>
using namespace std;
template<typename DataType> class Stack{
private:
    DataType *elements;
    int top;
    int maxSize;
public:
    Stack(int size){
        maxSize=size;
        top=-1;//so we can say that the empty stack'top is -1
        elements=new DataType[maxSize];
    }
    ~Stack(){
        delete[] elements;
    }
    bool push(DataType data){
        if(top==maxSize){
            return false;
        }
        elements[++top]=data;
        return true;
    }
    DataType pop(){
        if(top==-1){
            cout<<"the stack is empty";
            return NULL;
        }
        return elements[top--];
    }
    void showStack(){
        if(top==-1) return;
        for (int i=0;i<=top;i++){
            cout<<elements[i]<<",";
        }
        cout<<endl;
    }
};
int main(){
    Stack<int> stack=Stack<int>(6);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.showStack();
    stack.pop();
    stack.showStack();
}

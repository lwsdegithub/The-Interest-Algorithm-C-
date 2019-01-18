#include <iostream>
using namespace std;
template<typename DataType> class Queue{
private:
    int count;
    int maxSize;
    int front;
    int rear;
    DataType *elements;
public:
    Queue(int size=10){
        maxSize=size;
        //init the front=0,rear=0,and count=0
        front=0;
        rear=0;
        count=0;
        elements=new DataType[maxSize];
    }
    ~Queue(){
        delete[] elements;
    }
    bool insert(DataType data);
    DataType delElement();
    int getCount(){
        return count;
    }
};
template <typename DataType> bool Queue<DataType>::insert(DataType data){
    if(count==maxSize){
        cout<<"the queue is full"<<endl;
        return false;//the queue is full
    }
    elements[rear]=data;
    rear=(rear+1)%maxSize;//we use the circular queue,
    count++;
    return true;
}
template <typename DataType> DataType Queue<DataType>::delElement(){
    if(count==0) return NULL;
    DataType temp=elements[front];
    front=(front+1)%maxSize;//also the circular queue
    count--;
    return temp;
}
// int main(){
//     Queue<int> queue=Queue<int> (6);
//     for (int i=0;i<=5;i++){
//         queue.insert(i);
//     }
//     cout<<queue.delElement()<<endl;
//     queue.insert(8);
//     queue.insert(9);
//     for (int i=0;i<=5;i++){
//         cout<<queue.delElement()<<endl;
//     }
// }
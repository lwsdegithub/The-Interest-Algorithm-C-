/****
 * This is a SequenceList C++ source code,also I want to practice my english and c++ skill.
 * */
#include <iostream>
using namespace std;
template<typename DataType> class SeqList{
    private:
        DataType *elements;
        int maxSize;
        int length;
        static const int defaultSize=10;
    public:
        SeqList(int size=defaultSize){
            if(size>0){
                maxSize=size;
                elements=new DataType[maxSize];
            }
            length=0;
        }
        ~SeqList(){
            delete[] elements;//recovery the memory 
        }
        bool appendElement(DataType data);//add the data to the tail of the list 
        DataType popElement();//return the tail of the list
        //the location means 0,1,2,3
        bool insertElement(int location,DataType data);//add the data to the gived location
        bool deleteElement(int location);//delete the data of the location
        DataType getElement(int location);
        bool changeElement(int location,DataType data);
        void showList(){
            for(int i=0;i<=length-1;i++){
                std::cout<<elements[i];
            }
            std::cout<<endl;
        }
        int getLength(){
            return this.length;
        }
};
template<typename DataType> bool SeqList<DataType>::appendElement(DataType data){
    if(length>=maxSize){
        return false;//
    }
    else{
        elements[length]=data;
        length++;
        return true;
    }
}
template<typename DataType> DataType SeqList<DataType>::popElement(){
    return elements[--length];
}
template<typename DataType> bool SeqList<DataType>::insertElement(int location,DataType data){
    //the location means:
    //0,1,2,3
    if(location<0||location>length){
        return false;
    }
    if(length+1>maxSize){
        return false;//out of the size
    }
    //elements should move
    //  8 7 5 6 9
    //  0 1 2 3 4 5 6 ,maxSize=7,length=5,location=3,data=4
    //loop1: i=4,location-1=2,8 7 5 6 9 9,i=3
    //loop2: i=3,location-1=2,8 7 5 6 6 9,i=2
    //loop3: i=2,location-1=2,break
    for(int i=length-1;i>location-1;--i){
        elements[i+1]=elements[i];
    }
    //8 7 5 6 6 9,location=3,data=4
    //8 7 5 4 6 9,right
    elements[location]=data;
    length++;
    return true;
}
template<typename DataType> bool SeqList<DataType>::deleteElement(int location){
    if(location<0||location>=length){
        return false;
    }
    else{
        for(int i=location;i<length;i++){
            elements[i]=elements[i+1];
        }
        length--;
        return true;
    }
}
template<typename DataType> DataType SeqList<DataType>::getElement(int location){
    if(location<0||location>=length) return false;
    return elements[location];
}
template<typename DataType> bool SeqList<DataType>::changeElement(int location,DataType data){
    if(location<0||location>=length) return false;
    elements[location]=data;
    return true;
}
int main(int argc, char const *argv[])
{
    SeqList<int> list(10);
    for(int i=0;i<10;i++){
        list.appendElement(i);
    }
    list.showList();
    list.popElement();
    list.showList();
    list.deleteElement(8);
    list.showList();
    return 0;
}


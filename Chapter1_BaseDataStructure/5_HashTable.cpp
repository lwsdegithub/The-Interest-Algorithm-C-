#include <iostream>
using namespace std;
template<typename DataType> class HashTable{
private:
    int maxSize;
    int count;
    DataType *elements;
    int Q;//the value%q is the hash value
public: 
    HashTable(int size){
        maxSize=size;
        count=0;
        elements=new DataType(maxSize);
        for(int i=0;i<maxSize;i++){
            //when it cout,the "NULL" will be as 0
            elements[i]=NULL;
        }
        Q=13;
    }
    ~HashTable(){
        delete elements;
    }
    void setQ(int q){
        Q=q;
    }
    //get the hash value
    int hash(DataType value){
        return value % Q;
    }
    //the search algorithm
    int searchHash(DataType value){
        int p=hash(value);
        if(elements[p]==value){
            return p;//searching is right
        }
        if(!elements[p]) return p;
        int rp=(p+1)%maxSize;
        while(rp!=p){
            if(elements[rp]==value) return rp;//had exist the value 
            if(elements[rp]==NULL){
                return rp;//find the null position
            }
            rp=(rp+1)%maxSize;//Cyclic Linear Detection Method for Finding Blank Addresses
        }
        if(rp=p)
        {
            cout<<"full"<<endl;
            return -1;
        }else return rp;
    }
    bool insertHash(DataType value){
        int pos=searchHash(value);
        if(pos<0) return false;//full
        else if(elements[pos]==value){
            cout<<"this value had been in the table"<<endl;
            return false;
        }else{
            elements[pos]=value;
            return true;
        }
    }
    void show(){
        for(int i=0;i<maxSize;i++){
            cout<<elements[i]<<",";
        }
        cout<<endl;
    }
};
int main(int argc, char const *argv[])
{
    HashTable<int> table=HashTable<int>(5);
    table.insertHash(1);
    table.insertHash(2);
    table.insertHash(3);
    table.insertHash(6);
    table.insertHash(16);
    table.insertHash(29);
    table.insertHash(42);
    table.show();
    return 0;
    //excellent!!!!
}
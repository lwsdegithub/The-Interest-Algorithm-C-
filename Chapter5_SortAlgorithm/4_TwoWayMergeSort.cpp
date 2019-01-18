#include <iostream>
using namespace std;
void merge(int A[],int B[],int C[],int lengthA,int lengthB){
    int i=0,j=0,counter=0;//C is full
    while(counter<lengthA+lengthB){
        if(A[i]<B[j]){
            C[counter++]=A[i++];
        }else{
            C[counter++]=B[j++];
        }
        if(i==lengthA){
            while(j<lengthB){
                C[counter++]=B[j++];
            }
        }else if (j==lengthB){
            while(i<lengthA){
                C[counter++]=A[i++];
            }
        }
    }
}
void mergeSort(int A[],int length){
    if(length>1){
        int i=length/2;
        int j=length-i;
        int B[i];
        int C[j];
        for(int k=0;k<i;k++){
            B[k]=A[k];
        }
        for(int k=0;k<j;k++){
            C[k]=A[k+i];
        }
        mergeSort(B,i);
        mergeSort(C,j);
        merge(B,C,A,i,j);
    }
}
int main(int argc, char const *argv[])
{
    int data[]={23,25,4,5,69,78};
    mergeSort(data,6);
    for(int i=0;i<6;i++){
        cout<<data[i]<<",";
    }   
     return 0;
}

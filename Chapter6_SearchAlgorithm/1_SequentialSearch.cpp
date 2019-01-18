#include<iostream>
int sequentialSearch(int val[],int n,int k){
    for(int i=0;i<n;i++){
        if (val[i]==k) return i;
    }
    return -1;
}
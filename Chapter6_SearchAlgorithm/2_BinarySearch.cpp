#include <iostream>
using namespace std;
int binarySearch(int val[],int n,int k){
    int low=0,high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(k==val[mid]) return mid;
        else if(k>val[mid]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int a[5]={5,8,12,45,63};
    cout<<binarySearch(a,5,12);
}
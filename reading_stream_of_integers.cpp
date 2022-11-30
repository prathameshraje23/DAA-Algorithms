//Q) Imagine you are reading in stream of integers. Periodically, you wish
//to be able to look up the rank of number x (the number of values less
//than or equal to x). Implement the data structures and algorithms to
//support these operations. That is, Implement the method track (int x),
//which is called when each number is generated, and the method
//getRankOfNumber (int x), which returns the number of values less than
//or equal to x (not including x itself).
//EXAMPLE Stream (in order of appearance) : 5, 1, 4, 4, 5, 9, 7, 13, 3
//getRankOfNumber(1) = 0
//getRankOfNumber(3) = 1
//getRankOfNumber(4) = 3
//Ans.




#include <bits/stdc++.h>
using namespace std;

int getRank(int arr[],int n,int val){
    int ans=0;
    sort(arr,arr+n);
    for (int i=0;i<n;i++){
        if (arr[i]<val){
            ans++;
        }
        else {
            break;
        }
    }
    return ans;
   
}

int main(){
    int arr[]={5, 1, 4, 4, 5, 9, 7, 13, 3};
    int val=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    int rank=getRank(arr,n,val);
    cout<<"Rank: "<<rank;
    return 0;
}





//
//Algorithm:
//1)	Start.
//2)	Sort the given array of integers.
//3)	Linearly traverse the array till the key is not found.
//4)	Return the index of key, that is only the rank for that element.
//5)	Stop.
//
//T.C : o(n*log(n))  s.c: O(n)



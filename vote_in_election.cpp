//Q) Given an array A[0…n-1] , where each element of the array represents a vote in the election. Assume that each vote is given as an integer representing the ID of the chosen candidate. Given an algorithm for determining who wins the election.




#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    vector<int>a;
    cin>>n;

    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        m[x]++;
    }

    int maxi=INT_MIN,ans;
    for(auto ele:m){
        if(ele.second>maxi){
            maxi=ele.second;
            ans=ele.first;
        }
    }
    
    cout<<"The Person With Id "<<ans<<" has Won election\n";

    return 0;
}





//
//Algorithm:
//1)	Start 
//2)	For each entry maintain a hash map which would store the occurrence of each element in an array
//3)	Than traverse a Hashmap and then find the max element in hashmap
//4)	Stop 
//
//T.C: O(n)  S.C: O(n).
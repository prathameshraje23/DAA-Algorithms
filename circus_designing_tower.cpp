//Q) A circus is designing a tower routine consisting of people standing
//atop one another’s shoulders. For practical and aesthetic reasons, each
//person must be both shorter and lighter than the person below him or
//her. Given the heights and weight of each circus, write a method to
//compute the largest possible number of people in such a tower.
//EXAMPLE:
//Input(ht,wt): (65, 100) (70, 150) (56, 90) (75,190) (60, 95) (68, 110).
//Output: The longest tower is length 6 and includes from top to bottom:
//(56, 90) (60, 95) (65, 100) (68, 110) (70, 150) (75, 190)
//Ans.











#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

int main(){

   vector<pair<ll,ll>>v ;
    v.push_back({65,100}) ; 
    v.push_back({70,150}) ; 
    v.push_back({56,90}) ; 
    v.push_back({75,190}) ; 
    v.push_back({60,95}) ; 
    v.push_back({68,110}) ; 

   sort(v.begin(),v.end()) ;

   ll n = v.size() ;

   int lis[n] ;

   for (ll i = 0; i < n; i++)
   {
        lis[i] = 1 ;
   }
   

   for (ll i = 1; i < n; i++)
   {
        for (ll j = 0; j < i; j++)
        {
                if(v[i].second > v[j].second && lis[i]<lis[j]+1) lis[i] = lis[j]+1 ;
        }
        
   }

   ll maxi = INT_MIN ;
   for (ll i = 0; i < n; i++)
   {
        if(maxi < lis[i]) maxi = lis[i] ;
   }
   
   cout<<maxi<<endl;
}





//Processing:
//1. store the result in pair form in vector
//2. sort the vector according to height in increasing order
//3.create one n size array and initialise every element with 1
//4. find the length of longest increasing subsequence according weight
//5. return the computed maximum length
//
//
//
//Time Complexity: O(n*n)


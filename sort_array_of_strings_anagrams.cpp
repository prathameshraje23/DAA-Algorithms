#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

int main(){
   
    ll n ;
    cin>>n ;
    vector<string>strs(n) ;

    for (ll i = 0; i < n; i++)
    {
        cin>>strs[i] ;
    }
    

        vector<string>v = strs ;
        map<string,vector<int>>mp ;
  
        
        for(int i = 0; i < n; i++) {
            sort(v[i].begin(),v[i].end()) ;
            mp[v[i]].push_back(i) ;
        }
        
         vector<set<string>>ans ;
        
        for(auto it: mp) {
            set<string>res ;
            for(auto it1 : it.second) {
                res.insert(strs[it1]) ;
            }
            ans.push_back(res) ;
        }
        
        sort(ans.begin(),ans.end()) ;

        for (ll i = 0; i < ans.size(); i++)
        {
                for(auto it : ans[i]) cout<<it<<" ";
        }
        
        cout<<endl;

}


//Processing:
//It sorts the strings in lexicographical order. It creates a map with key as sorted string
//and value as vector of indices where that string occurs. It iterates over the map and
//for each key it creates a set of strings. It sorts the sets in lexicographical order. It
//prints the sorted sets.
//
//
//Complexity Analysis:
//Time Complexity : O(n*mlog(m))
//Space Complexity : O(n)


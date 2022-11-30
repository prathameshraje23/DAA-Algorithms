//Q) Let A and B two arrays of n elements, each. Given a number K, give
//an O (nlogn) time algorithm for determining whether there exists a ? A
//and b ? B such that a+b =K



	#include <bits/stdc++.h>
	using namespace std;
	int binarySearch(int array[], int , int , int );
	
	int binarySearch(int array[], int x, int low, int high) {
	  
	  // Repeat until the pointers low and high meet each other
	  while (low <= high) {
	    int mid = low + (high - low) / 2;
	
	    if (array[mid] == x)
	      return mid;
	
	    if (array[mid] < x)
	      low = mid + 1;
	
	    else
	      high = mid - 1;
	  }
	  return -1;
	}
	
	int main(){
	    int i,k,n,r=-1;
	    cout<<"Input the value of k : ";
	    cin>> k;
	    cout<<"Input the value of n : ";
	    cin>> n;
	    int a[n],b[n];
	    cout<< "Input Array a elements :"<<endl;
	    for(i=0;i<n;i++){
	        cin>> a[i];
	    }
	    cout<< "Input Array b elements :"<<endl;
	    for(i=0;i<n;i++){
	        cin>> b[i];
	    }
	    sort(a,a+n);
	    for(i=0;i<n;i++){
	        int r = binarySearch(a, k-b[i], 0, n - 1);
	        if(r+1){
	            cout<< "The values are as follows : "<< a[r] << "+" << b[i]<< "="<< k;
	             
	            break;
	           
	        } 
	    }
	    
	    if(r==-1)
	        cout<< "Elements not found"; 
	    else{
	         cout<< "Elements  found"; 
	    }  
	    return 0;
	}



//
//Algorithm:
//Step 1:Start
//Step 2:Input array A and B
//Step 3:Sort array A
//Step 4:Search for a=k-b in array A
//Step 5: apply binary search
//Step 6: If element found print a,b
//Step 7: go to next b element and go to step 4
//Step 8: End


//time comoplexity: O(nlogn)
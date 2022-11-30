//Q) Given an array A[0…n-1] of n numbers containing repetition of some
//number. Given an algorithm for checking whether there are repeated
//element or not. Assume that we are not allowed to use additional space
//(i.e., we can use a few temporary variable, O(1) storage).




#include <bits/stdc++.h>
using namespace std;
	
int main()
{
	int arr[] = { 1, 5, 8, 0, 6, 7, 3, 4, 2, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bool flag = false;
	/*Here we take two parameters, the beginning of the
	array and the length n upto which we want the array to
	be sorted*/
	sort(arr, arr + n);
	
	for (int i = 1; i < n-1; ++i)
	    if(arr[i]==arr[i-1])
	    flag = true;
	if(flag)
	cout << "Array contains duplicates"<<endl; 
	else 
	cout << "Array does not contains duplicates"<<endl;  
	
	return 0;
}



//Algorithm:
//Step 1:Start
//Step 2: Sort the given array
//Step 3: for I <- 1 to size-1
//Step 4 : check if consecutive elements are same or not
//Step 4: if same then array contains duplicates
//Else
//No duplicates
//Step 3: End
//· Time complexity
//O( nlogn )
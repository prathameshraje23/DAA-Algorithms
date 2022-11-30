//Q) Given a sorted array of n integers that has been rotated an unknown
//number of times, write code to find an element in the array. You may
//assume that the array was originally sorted in increasing order.
//EXAMPLE
//Input: find 5 in {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
//Output: 8 (the index of 5 in the array)




#include<bits/stdc++.h>
using namespace std;

int findElement(int a[],int l,int h,int search)
{
	if(l>h) //if element not found
	{
		return -1;
	}
	int mid = (l+h)/2;
	if(a[mid]==search)
	{
		return mid;
	}
	
	//if l to mid array is sorted
	if(a[l]<=a[mid])
	{
		if(search>=a[l] && search<=a[mid])
		{
			return findElement(a,l,mid-1,search);
		}
		else
		{
			return findElement(a,mid+1,h,search);
		}
	}
	
	//if above part is not sorted
	if(search>a[mid] && search<=a[h])
	{
		return findElement(a,mid+1,h,search);
	}
	
	return findElement(a,l,mid-1,search);
}

int main()
{
	int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	int x = findElement(a,0,11,5);
	cout<<x;
	return 0;
}







//Algorithm:
//findElement(int a[],l,h,search)
//{
//if(l>h)
//{
//return -1; //element not found
//}
//mid = (l+h)/2;
//if(a[mid]==search)
//{
//return mid; //element found
//}
//if(a[l]<=a[mid]) //array from l to mid is sorted
//{
//if(search>=a[l] && search<=a[mid]) //element is in between l to mid
//{
//return findElement(a,l,mid-1,search); //call for that subarray
//}
//else
//{
//return findElement(a,mid+1,h,search);
//}
//}
//if(search>a[mid] && search<=a[h])//if above part is not sorted
//{
//return findElement(a,mid+1,h,search);
//}
////if all above condition fails
//return findElement(a,l,mid-1,search);
//}
//
//
//Processing:
//Here, we will use a recursive function and binary search.
//I.e. first search for mid element
//Then if left subarray is sorted, search in that
//Otherwise search in the right subarray.
//
//
//
//Time Complexity :
//O(logn) : As binary search is used
//Q) Given a sorted array of string which is interspersed with empty string,
//write a method to find the location of a given string.
//EXAMPLE Input: find “ball” in {“at”, “”, “”, “ball”, “”, “”, “car”, “”, “”,
//“dad”, “”,””}
//Output: 4
//Ans.



#include<iostream>
using namespace std;

int findString(string a[],int l,int h,string s)
{
	if(l>h)
	{
		return -1;
	}
	int mid = (l+h)/2;
	if(a[mid]==s)
	{
		return mid;
	}
	
	if(a[mid]=="")
	{
		int left=mid,right=mid;
		while(a[left]=="" && left>l)
		{
			left--;
		}
		while(a[right]=="" && right<h)
		{
			right++;
		}
		
		if(s<=a[left])
		{
			return findString(a,l,left,s);
		}
		if(s>=a[right])
		{
			return findString(a,right,h,s);
		}
	}
	
	if(s<a[mid])
	{
		return findString(a,l,mid-1,s);
	}
	else
	{
		return findString(a,mid+1,h,s);
	}
}

int main()
{
	string a[] = {"at", "", "", "ball", "", "", "car", "", "", "dad", "",""};
	int p = findString(a,0,11,"ball");
	cout<<"Position of ball : "<<(p+1);
}





//Algorithm:
//findString(string a[],int l,int h,string s)
//{
//if(l>h)return -1; //no element found
//mid=(l+h)/2;
//if(a[mid]==s)return mid;
//if(a[mid]=="")
//{
////find left & right to non-empty element
//left=right=mid;
//while(a[left--]=="" && left>=l);
//while(a[right++]=="" && right<=h);
////compare left and right
//if(s<=a[left]) // search in l to left
//if(s>=a[right]) //search in right to h
//}
//if(s<a[mid]) //search in l to mid-1
//else //search in mid+1 to h
//}


//Processing:
//Here, we also use binary search.
//The only thing we need to handle is if the middle element is empty.
//Then we move to left and right non-empty elements, compare them with our
//searching element and decide the search space.

//Time Complexity :
//O(logn) : As binary search is used here.
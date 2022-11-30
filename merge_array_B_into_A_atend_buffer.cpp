#include<iostream>
using namespace std;

int main()
{
	int a[8]={2,6,7,9};
	int b[4]={1,4,10,15};
	int i=3,j=3,k=7;
	while(i>=0 && j>=0)
	{
		if(a[i]>=b[j])
		{
			a[k--]=a[i--];
		}
		if(a[i]<b[j])
		{
			a[k--]=b[j--];
		}
		
	}
	for(;i>=0;i--)
	{
		a[k--]=a[i];
	}
	for(;j>=0;j--)
	{
		a[k--]=b[j];
	}
    for(int i=0;i<8;i++)
    {
    	cout<<a[i]<<" ";
	}
}






//Algorithm:
//Let x-elements in a[]
//y-elements in b[]
//n-size of a[] i.e. array having buffer
//merge(a[],b[],x,y,n)
//{
//i=x-1,j=y-1,k=n-1;
//while(i>=0 && j>=0)
//{
//if(a[i]>=b[j])
//{
//a[k–] = a[i–];
//}
//Else
//{
//a[k–] = b[j–];
//}
//}
//for(;i>=0;i--)
//{
//a[k--]=a[i];
//}
//for(;j>=0;j--)
//{
//a[k--]=b[j];
//}
//}
//
//Processing:
//Here, we will scan both arrays from last, compare elements and store greater
//elements from last of array A.
//
//
//Complexity Analysis : TC = O(m+n) SC = O(1)
//I.e. traversing size of array a[] = m and size of array b[] = n
//Hence total = m+n




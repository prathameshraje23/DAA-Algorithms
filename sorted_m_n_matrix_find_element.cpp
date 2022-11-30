//Q) Given an M*N matrix in which each row and each column is sorted in
//ascending order, write a method to find an element.
//Ans.


#include<iostream>
using namespace std;

void search(int mat[4][4],int n,int key)
{
	if(n==0)
	{
		cout<<"No element found";
		return;
	}
	
	if(key<mat[0][0] || key>mat[n-1][n-1])
	{
		cout<<"No element found";
		return;
	}
	
	//we traverse from bottom-left element
	int i=n-1,j=0;
    while(i>=0 && i<n && j>=0 && j<n)
    {
    	if(mat[i][j]==key)
    	{
    		cout<<"Element found at : "<<i<<" "<<j;
    		return;
		}
		if(mat[i][j]<key)
		{
			j++;
		}
		else
		{
			i--;
		}
	}
}

int main()
{
	int matrix[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
    search(matrix, 4, 35);
    return 0;
}







//Algorithm:
//search(int mat[][],int n,int key)
//{
////if n==0 return
//if(n==0)return;
////check element is smaller than smallest or larger than largest
//return;
////we will traverse from bottom left element
//i=n-1,j=0;
//while(//constraints of indices of matrix i and j)
//{
//if(mat[i][j]==key)
//{
////found element
//return;
//}
//if(mat[i][j]<key)
//{
//j++;
//}
//else
//{
//i--;
//}
//}
//}
//
//
//
//Processing:
//Here, we reduce the traversal of elements by starting from bottom-left element
//If element to be find greater than current element, we shift to next column
//If element to be find smaller than current element, we shift to previous row
//If element found, give result


//
//Time Complexity :
//O(m+n) : As only one traversal is needed from n-1 to 0 for row and 0 to n-1 for
//column

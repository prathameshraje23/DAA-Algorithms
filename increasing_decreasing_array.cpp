//Q1) Implement algorithm to Find the maximum element in an array which
//is first increasing and then decreasing, with Time Complexity O(Logn).




#include <iostream>
using namespace std;
 
int maxInBitonic(int arr[], int low, int high)
{
    // find out the size of the array
    // for edge case checking
    int n = high + 1;
 
    // main code goes as follows
    while (low <= high) {
        // find out the mid
        int mid = low + (high - low) / 2;
         
          // if mid index value is maximum
        if(arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1])
              return arr[mid];
 
        // reducing search space by moving to right
        else if (arr[mid] < arr[mid + 1])
            low = mid + 1;
 
        // reducing search space by moving to left
        else
            high = mid - 1;
    }
 
    return arr[high];
}
 
// Driver function
int main()
{
    int arr[] = { 1, 3, 50, 10, 9, 7, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The maximum element is "
         << maxInBitonic(arr, 0, n - 1);
    return 0;
}




//Algorithm:
//1) Start.
//2) Read the array.
//3) Apply binary search on the array.
//4) If mid is greater than both its sides then it’s the max elemnt.
//5) If mid < its next element then,
//a. Make low=mid +1;
//b. Apply binary search on the right array.
//6) If(mid> it s nest element ) then,
//a. Make high= mid-1;
//b. Apply binary search on the left array.
//7) End.
//
//
//Time Complexity: O(logn)
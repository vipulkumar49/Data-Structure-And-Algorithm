// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int binarySearch(int A[], int l, int h, int key) {
        if(l > h) return -1;
        int mid = (l + h) / 2;
        if(A[mid] == key) return mid;
        else if(A[mid] > key) return binarySearch(A, l, mid - 1, key);
        else return binarySearch(A, mid + 1, h, key);
    }
    int findPivot(int A[], int low, int high) {
        if(low > high) return -1;
        if(low == high) return low;
        int mid = (low + high) / 2;
        if(mid < high && A[mid] > A[mid + 1]) return mid;
        else if(mid > low && A[mid] < A[mid - 1]) return mid - 1;
        else if(A[low] >= A[mid]) return findPivot(A, low, mid - 1);
        else return findPivot(A, mid + 1, high);
    }
    int search(int A[], int l, int h, int key){
        // First find pivot using binary search
        // Binary search the sorted array
        int pivot = findPivot(A, l, h);
        if(pivot == -1) return binarySearch(A, l, h, key);
        else if(A[pivot] == key) return pivot;
        else if(A[0] <= key) return binarySearch(A, l, pivot - 1, key);
        else return binarySearch(A, pivot + 1, h, key);
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends
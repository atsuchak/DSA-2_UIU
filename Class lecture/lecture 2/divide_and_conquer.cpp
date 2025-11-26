#include <bits/stdc++.h>
using namespace std;

int exponential(int b, int n) {
    if(n == 0) return 1;

    return b * exponential(b, n-1);
}

int expoDivAndCon(int b, int n) {
    if(n == 0) return 1;

    int temp = expoDivAndCon(b, n/2);
    if(n%2 == 0) return pow(temp, 2);
    else return pow(temp, 2) * b;
}

int findSum(int arr[], int st, int fn) {
    if(st == fn) return arr[st];

    int mid = (st+fn)/2;
    int leftSum = findSum(arr, st, mid);
    int rightSum = findSum(arr, mid+1, fn);

    return leftSum + rightSum;
}

int divByThree(int arr[], int st, int fn) {
    if (st == fn) {
        if(arr[st]%3 == 0) return 1;
        else return 0;
    }

    int mid = (st+fn)/2;
    int leftPart = divByThree(arr, st, mid);
    int rightPart = divByThree(arr, mid+1, fn);

    return leftPart + rightPart;
}

pair<int, int> findSecondMax(int arr[], int st, int fn) {
    if(st == fn) return make_pair(arr[st], INT_MIN);

    int mid = (st+fn)/2;
    pair<int, int> left = findSecondMax(arr, st, mid);
    pair<int, int> right = findSecondMax(arr, mid+1, fn);

    int mx = max(left.first, right.first);
    int scndMx = max(min(left.first, right.first), max(left.second, right.second));

    return make_pair(mx, scndMx);
}

int findPeek(int arr[], int st, int fn) {
    int mid = (st+fn)/2;

    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
    if(arr[mid] > arr[mid - 1]) return findPeek(arr, mid+1, fn);
    return findPeek(arr, st, mid);
}

int main() {

    cout << exponential(3, 4);
    // cout << expoDivAndCon(3, 4);

    // int arr[] = {1, 9, 3, 5, 14, 6};
    // cout << findSum(arr, 0, 5);
    // cout << divByThree(arr, 0, 5);
    // cout << findSecondMax(arr, 0, 5).second << endl;
    // cout << findPeek(arr, 0, 5) << endl;


    return 0;
}
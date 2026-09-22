#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(int i , vector<int>& arr , int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int maxidx = i;
    if(left < n && arr[left] > arr[maxidx]){
       maxidx = left;
    }
     if(right < n && arr[right] > arr[maxidx]){
       maxidx = right;
    }
    if(maxidx != i){
        swap(arr[i] , arr[maxidx]);
        heapify(maxidx , arr , n);
    }


}
void heapSort(vector<int>& arr){
    int n = arr.size();
    for(int i = n/2-1; i >= 0; i--){
        heapify(i , arr , n);
    }

    for(int i = n-1; i >= 0; i--){
        swap(arr[0] , arr[i]);
        heapify(0 , arr , i);
    }
}
int main() {
    vector<int> arr = {1,7,3,6,8,2};
    heapSort(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] <<"    ";
    }
    return 0;
}
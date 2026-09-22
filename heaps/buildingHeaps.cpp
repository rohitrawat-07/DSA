// implement heaps as a vector;
// property of heap is parent child relation means parent's value is greater then child;
// if we convert complete binary tree in form of array then index of the left child is (2 * index of parent +1) and index of right child is (2*index of parent +2)
// if child index is x then parents index is (x-1)/2;









#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Heap{
        vector<int> vec;
     public:
     

    void push(int val){
        vec.push_back(val);     // push value

        // fixing heap ;
        int x = vec.size()-1;
        int parentIdx = (x-1)/2;
        while(parentIdx >= 0 && vec[x] > vec[parentIdx]){         // this is maxHeap but if you want to convert it to minHeap then change the sign (<)
            swap(vec[x] , vec[parentIdx]);
            x = parentIdx;
            parentIdx = (x-1)/2;
        }
    }

       void heapify(int i){
        if(i >= vec.size()){
            return;
        }
        int l = 2*i+1;
        int r = 2*i+2;
        int maxIdx = i;
        while(l < vec.size() && vec[maxIdx] < vec[l]){
            maxIdx = l;
        }
         while(r < vec.size() && vec[maxIdx] < vec[r]){
            maxIdx = r;
        }
        swap(vec[i] , vec[maxIdx]);
        if(i != maxIdx){
            heapify(maxIdx);
        }
       }




    
    void pop(){
      swap(vec[0] , vec[vec.size()-1]);
      vec.pop_back();
      heapify(0);
    }
    int top(){
        return vec[0];

    }
    bool empty(){
        return vec.size() == 0;

    }

    };
    
int main() {
    Heap heap;
    heap.push(20);
    heap.push(50);
    heap.push(100);
    heap.pop();
    cout << heap.top();
    
}
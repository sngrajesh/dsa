//https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379
#include <bits/stdc++.h> 

//Method 1
vector<int> mergeKSortedArrays1(vector<vector<int>>&kArrays, int k)
{
    vector<int>ans;
    for(auto i : kArrays)
        for(auto j : i)
            ans.push_back(j);
    sort(ans.begin() , ans.end());
    return ans;
}




//Method 2 : Using min heap to sove the proble
/*
    Time Complexity: O((N * K) * log(K)) 
    Space Complexity: O(N * K)
    
    Where N is the total number of elements in all the arrays, and K is the number of arrays.

**********************************************************************************************
The idea is to use the concept of min-heap. As we know, the root of the min-heap is always the minimum element in the heap. Thus, insert the first elements of all the ‘K’ arrays into the heap along with their indices, and then removing the minimum ( root ) element and adding it to the output array will give us the required result. We will store indices into the heap because we can get the next greater element from the same array where the current element has been popped.
 

Algorithm: 

 

Create an output array ‘RESULT’.
Create a min-heap of size K and insert the first element of all the arrays, along with its indices, into the heap.
The heap is ordered by the element of the array/list.
While the min-heap is not empty, we will keep doing the following operations :
Remove the minimum element from the min-heap (the minimum element is always at the root) and store it in the output array.
Insert the next element from the array for which the current element is extracted. If the array doesn’t have any more elements i.e. if the index of the above-removed component is equal to ‘LENGTH-1’ of the array from which the element is extracted, then do nothing. Because we are done with this array.
After the above process, 'RESULT' will contain all the elements of ‘K’ arrays in ascending order.
Return the output array i.e. ‘RESULT’.
Time Complexity
O((N * K) * log(K)), Where ‘K’ is the number of arrays and ‘N’ is the average number of elements in every array. 

 

We are using the min-heap of size K. Due to the insertion and the removal of elements in the heap, the final complexity of this approach is O(K * N * log(K)).

Space Complexity
O(N * K), where ‘K’ is the number of arrays and ‘N’ is the average number of elements in every array.

 

Since we are using a min-heap of size K arrays for the average N elements present in every array, therefore, the space complexity of the approach is O(N * K).

*/
class Node{
    public:
        int data;
        int row;
        int col;
        Node(int data, int row, int col){
            this->data =data;
            this->row =row;
            this->col = col;
        }
};

class NodeCompare{
    public:
    bool operator()(Node*a , Node*b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays2(vector<vector<int>>&kArrays, int k){
    vector<int>ans;
    priority_queue<Node* , vector<Node*>, NodeCompare> pq;

    for(int i = 0 ; i < k  ;i++){
            Node* temp = new Node(kArrays[i][0] ,i , 0 );
            pq.push(temp);
    }
    while(pq.size() > 0){
        Node* minimum  = pq.top();
        ans.push_back(minimum->data);
        pq.pop();

        int row = minimum->row;
        int col = minimum->col;

        if(kArrays[row].size() > col+1){
            Node* temp = new Node(kArrays[row][col+1] ,row , col+1);
            pq.push(temp);
        }

    }
    return ans;
}


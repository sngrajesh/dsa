#include<iostream>
using namespace std;

void printArray(int arr[], int n) {

    for(int i = 0; i<n; i++ ) {
        cout<< arr[i] <<" ";
    }cout<<endl;

}

// void swapAlternate(int arr[], int size) {
//     for(int i = 0; i<size; i+=2 ) {
//         if(i+1 < size) {
//             swap(arr[i], arr[i+1]);
//         }
//     }
// }

//Rajesh Singh
void swapAlternate(int arr[]){
    int n = sizeof(arr)/ sizeof(arr[0]);
    int m = n & 1 ? n -1 : n;
    for(int i = 0; i < m ; i+=2){

        swap(arr[i], arr[i+1]);
    }
}


int main() {

    int even[8] = {5,2,9,4,7,6,1,0};
    int odd[5] = {11, 33, 9, 76, 43};

    swapAlternate(even);
    printArray(even,8);

    cout << endl;

    swapAlternate(odd);
    printArray(odd, 5);



    return 0;
}
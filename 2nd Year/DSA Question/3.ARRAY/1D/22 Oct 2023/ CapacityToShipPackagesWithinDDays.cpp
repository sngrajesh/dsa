#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int mid ){
        int daysCount = 1;
        int weightSum = 0;
        for(int i = 0 ; i < weights.size(); i++){
            if(weightSum + weights[i] <= mid){
                weightSum += weights[i];
            }else{
                daysCount++;
                if(daysCount > days || weights[i] > mid ){
                    return false;
                }
                weightSum = weights[i];
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
    int ans = -1;
    int sum = 0;
    for(int i=0 ; i< weights.size() ; i++) sum += weights[i];


    int start = 0;
    int end = sum;
    int mid = start + (end -start)/2;

    while(start <= end){
        if(isPossible(weights, days , mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1 ;
        }
        mid = start + (end -start)/2;
    }

    return ans;
    }
};


int main( ){
    vector<int>weights {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    Solution* find = new Solution();
    int ans = find->shipWithinDays(weights, days);

    cout << ans << endl;

}
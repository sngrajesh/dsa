// https://leetcode.com/problems/pascals-triangle-ii/
class Solution {
public: 
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1,1};
        
        vector<int> prevRows = getRow(rowIndex - 1);
        vector<int> newRow(rowIndex+1 , 1);
        
        for (int i = 1; i < rowIndex; i++) {
            newRow[i] = prevRows[i - 1] + prevRows[i];
        }
        
        return newRow;
    }
};

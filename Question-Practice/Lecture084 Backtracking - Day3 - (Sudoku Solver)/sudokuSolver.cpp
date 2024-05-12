// https://www.naukri.com/code360/problems/sudoku-solver_699919
#include <bits/stdc++.h>

bool isSafe(int row, int col, vector<vector<int>>& sudoku , int val){
    int n = sudoku.size();
    
    // Check for same value in the row
    for(int i = 0; i < n; i++)
        if(sudoku[row][i] == val)
            return false;
    
    // Check for same value in the column
    for(int i = 0; i < n; i++)
        if(sudoku[i][col] == val)
            return false;

    // Check for same value in the subgrid
    int subgridRow = 3 * (row / 3);
    int subgridCol = 3 * (col / 3);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(sudoku[subgridRow + i][subgridCol + j] == val)
                return false;
    
    return true;
}

bool solve(vector<vector<int>>& sudoku){
    int n = sudoku[0].size();

    for(int row = 0; row < n ; row++){
        for(int col = 0 ; col < n ; col ++){
            if(sudoku[row][col] == 0){
                for(int val = 1; val  <= 9 ; val++){
                    if(isSafe(row ,col, sudoku, val)){
                            sudoku[row][col] = val;
                            bool backTrackNextSolution = solve(sudoku);
                            if(backTrackNextSolution){
                                return true;
                            }else{
                                sudoku[row][col] = 0;    
                            }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}
















 

 

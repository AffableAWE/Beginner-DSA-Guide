#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<char>> rows;
    unordered_map<int, unordered_set<char>> cols;
    unordered_map<int, unordered_set<char>> squares;

    for(int r = 0; r<9; r++) {
        for(int c = 0; c<9; c++) {
            char num = board[r][c]; // current number at position (r,c)

            //skip empty cells
            if(num == '.') {
                continue;
            }

            // calculate grid index
            int gridIndex = (r/3)*3 + (c/3);

            // check for duplicated
            if(rows[r].count(num) || cols[c].count(num) || squares[gridIndex].count(num)) {
                return false;
            }

            // Insert the numbers
            rows[r].insert(num);
            cols[c].insert(num);
            squares[gridIndex].insert(num);
        }
    }
    return true; // No duplicates are found, Board is valid
}

int main() {
     // A valid 9x9 Sudoku board
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    // Check if the board is valid
    bool isValid = isValidSudoku(board);

    if (isValid) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is invalid." << endl;
    }

    return 0;
}

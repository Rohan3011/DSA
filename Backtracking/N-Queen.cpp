#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<bool>> &board);
void printBoard(vector<vector<bool>> &board);

// All possible solutions
bool nQueenSolver(int n, int row, vector<vector<bool>> &board) {
  if (row >= n) {
    printBoard(board);
    return true;
  }
  for (int col = 0; col < n; col++) {
    if (!isSafe(row, col, board))
      continue;
    board[row][col] = true;
    nQueenSolver(n, row + 1, board);
    board[row][col] = false;
  }
  return false;
}

// Driver Code
int main() {
  int n;
  cin >> n;
  vector<vector<bool>> board(n, vector<bool>(n, false));
  nQueenSolver(n, 0, board);
}

// helper functions
bool isSafe(int row, int col, vector<vector<bool>> &board) {
  int n = board.size();

  // row [[current approach doesn't need to check for row]]
  for (int x = 0; x < n; x++) {
    if (board[x][col])
      return false;
  }

  // column
  for (int y = 0; y < n; y++) {
    if (board[row][y])
      return false;
  }

  // upper-left diagonal
  for (int x = row, y = col; x >= 0 && y >= 0; x--, y--) {
    if (board[x][y])
      return false;
  }

  // bottom-right diagonal
  for (int x = row, y = col; x < n && y < n; x++, y++) {
    if (board[x][y])
      return false;
  }

  // upper-right diagonal
  for (int x = row, y = col; x >= 0 && y < n; x--, y++) {
    if (board[x][y])
      return false;
  }

  // bottom-left diagonal
  for (int x = row, y = col; x < n && y >= 0; x++, y--) {
    if (board[x][y])
      return false;
  }

  return true;
}

void printBoard(vector<vector<bool>> &board) {
  for (auto row : board) {
    for (bool col : row)
      cout << col << " ";
    cout << "\n";
  }
  cout << "\n";
}
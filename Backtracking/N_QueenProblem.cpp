#include <iostream>
using namespace std;

void printBoard(int **board, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << board[i][j] << " ";
    cout << "\n";
  }
}

bool isSafe(int **board, int n, int row, int col) {
  int i, j;
  for (i = 0; i < n; i++) {
    if (board[i][col])
      return false;
  }
  for (j = 0; j < n; j++) {
    if (board[row][j])
      return false;
  }

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j])
      return false;
  }

  for (i = row, j = col; i < n && j >= 0; i++, j--)
    if (board[i][j])
      return false;
  return true;
}

bool placeQueen(int **board, int n, int col) {
  if (col >= n)
    return true;
  for (int i = 0; i < n; i++) {
    if (isSafe(board, n, i, col)) {
      board[i][col] = 1;
      if (placeQueen(board, n, col + 1))
        return true;
      board[i][col] = 0;
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  // double pointer
  int **board = new int *[n]; // row
  for (int i = 0; i < n; i++)
    board[i] = new int[n]; // column

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      board[i][j] = 0;
  }
  if (placeQueen(board, n, 0))
    printBoard(board, n);
  else
    cout << "Not Possible\n";
}
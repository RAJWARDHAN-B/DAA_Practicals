#include <iostream>
#include <vector>
using namespace std;
int totalSolutions = 0; // Global counter
bool firstPrinted = false;
int stepCounter = 0; // Step counter for placements and removals
void printBoard(const vector<vector<int>> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int n = board.size();
    // Column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }
    // left diagonal up
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
    // right diagonal up
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j])
            return false;
    }
    return true;
}
void solvequeen(vector<vector<int>> &board, int row)
{
    int n = board.size();
    if (row == n)
    {
        totalSolutions++;
        // Print only first Solution
        if (!firstPrinted)
        {
            cout << "\nOne of the valid solutions found:\n";
            printBoard(board);
            firstPrinted = true;
        }
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;

            // Print addition step
            if (!firstPrinted)
            {
                stepCounter++;
                cout << "Step " << stepCounter << ": Placed Queen at (" << row << ", " << col << "):\n";
                printBoard(board);
            }
            solvequeen(board, row + 1);
            // Backtrack
            board[row][col] = 0;
            // Print removal step
            if (!firstPrinted)
            {
                stepCounter++;
                cout << "Step " << stepCounter << ": Removed Queen from (" << row << ", " << col << "):\n";
                printBoard(board);
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter number of queens (N): ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solvequeen(board, 0);
    if (totalSolutions == 0)
    {
        cout << "No solution exists for N = " << n << endl;
    }
    else
    {
        cout << "Total number of valid solutions: " << totalSolutions << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
// 0/1 Knapsack using DP
int zeroOneKnapsack(vector<vector<int>> &dp, vector<int> &profit, vector<int> &weight, int capacity)
{
    int n = weight.size();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                int pick = 0;
                if (weight[i - 1] <= j)
                    pick = profit[i - 1] + dp[i - 1][j - weight[i - 1]];
                int notPick = dp[i - 1][j];
                dp[i][j] = max(pick, notPick);
            }
        }
    }
    return dp[n][capacity];
}
// Print DP table
void printMatrix(const vector<vector<int>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> profit(n), weight(n);
    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    int maxProfit = zeroOneKnapsack(dp, profit, weight, capacity);
    cout << "\nMaximum Profit = " << maxProfit << "\n";
    cout << "DP Table:\n";
    printMatrix(dp);
    return 0;
}

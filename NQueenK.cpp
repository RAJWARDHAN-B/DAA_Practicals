#include<bits/stdc++.h>
// PASS BY ADDRESS ALL THE UNORDERED MAPS AND ALL
using namespace std;

void print(vector<vector<char>> arr) {
    int n = arr.size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

bool isSafe(unordered_map<int,bool> row, unordered_map<int,bool> &lowdia, unordered_map<int,bool> &updia, int c, int r) {
    if(row[r] || lowdia[r-c] || updia[r+c]) return false;
    return true;
}

void solveQueens(vector<vector<char>> &chess, int col, int n, unordered_map<int, bool> &row, unordered_map<int,bool> &lowdia, unordered_map<int,bool> &updia, int solcount, bool first) {
    if(col >= n) {
        solcount++;
        cout<<"Solution count: "<<solcount<<endl;
        print(chess);
        first=true;
        return;
    }

    for(int i=0;i<n;i++) {
        if(isSafe(row, lowdia, updia, col, i)){
            row[i] = true;
            updia[i+col] = true;
            lowdia[i-col] = true;
            chess[i][col] = 'Q';

            solveQueens(chess, col+1, n, row, lowdia, updia, solcount, first);
            row[i] = false;
            updia[i+col] = false;
            lowdia[i-col] = false;
            chess[i][col] = '.';
        }
        

        
    }
}

int main() {
    int n = 5;
    vector<vector<char>> chess(n,vector<char>(n,'.'));
    unordered_map<int, bool> row;
    unordered_map<int, bool> lowdia;
    unordered_map<int, bool> upperdia;

    solveQueens(chess, 0,n,row,lowdia,upperdia,0,false);
    

}
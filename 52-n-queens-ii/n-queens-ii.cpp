class Solution {
public:
    int c=0;
    void solve(int n,vector<vector<char>>& board,vector<int>& row,vector<int>& ld,vector<int>& rd,int i){
        if(i==n){
            c++;
            return;
        }
        for(int j=0;j<n;j++){
            if(board[i][j]=='.' && row[j]==0 && ld[i-j+(n-1)]==0 && rd[i+j]==0){
                board[i][j]='Q';
                row[j]=1;
                ld[i-j+(n-1)]=1;
                rd[i+j]=1;

                solve(n,board,row,ld,rd,i+1);

                board[i][j]='.';
                row[j]=0;
                ld[i-j+(n-1)]=0;
                rd[i+j]=0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<int> row(n,0);
        vector<int> ld(2*n-1,0);
        vector<int> rd(2*n-1,0);
        vector<vector<char>> board(n,vector<char> (n,'.'));
        solve(n,board,row,ld,rd,0);
        return c;
    }
};
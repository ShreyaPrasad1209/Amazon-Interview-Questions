class Solution {
public:
    
    void floodFill(vector<vector<char>>& board,int x, int y, char prevV,char newV)
    {
          // Base cases 
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || 
        board[x][y] != prevV) 
        return; 
        
  
    // Replace the color at (x, y) 
    board[x][y] = newV; 
  
    // Recur for north, east, south and west 
    floodFill(board, x+1, y, prevV, newV); 
    floodFill(board, x-1, y, prevV, newV); 
    floodFill(board, x, y+1, prevV, newV); 
    floodFill(board, x, y-1, prevV, newV); 
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty())
        {
            return;
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='-';
                }
            }
        }
        
        int row = board.size();
        int col = board[0].size();
        
         // Call floodFill for all '-' lying on edges 
   for (int i=0; i<row; i++)   // Left side 
      if (board[i][0] == '-') 
        floodFill(board, i, 0, '-', 'O'); 
        
   for (int i=0; i<row; i++)  //  Right side 
      if (board[i][col-1] == '-') 
        floodFill(board, i, col-1, '-', 'O'); 
        
   for (int i=0; i<col; i++)   // Top side 
      if (board[0][i] == '-') 
        floodFill(board, 0, i, '-', 'O'); 
        
   for (int i=0; i<col; i++)  // Bottom side 
      if (board[row-1][i] == '-') 
        floodFill(board, row-1, i, '-', 'O'); 
  
 
   for (int i=0; i<row; i++) 
      for (int j=0; j<col; j++) 
         if (board[i][j] == '-') 
             board[i][j] = 'X'; 
    }
};

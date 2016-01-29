void solveSudoku(vector<vector<char> >& board) {
        fillboard(board,0,0);
    }
    bool fillboard(vector<vector<char> >& board,int row,int col)
    {
    	if(row==9) return true; 
    	if(col==9) return fillboard(board,row+1,0);
    	if(board[row][col]!='.') return fillboard(board,row,col+1);
    	for(char c='1';c<='9';c++)
    		{
    			if(isvalid(board,row,col,c))
    			{
    				board[row][col]=c;
    				if(fillboard(board,row,col+1)) return true;
    				board[row][col]='.';
    			}
    		}
    		return false;
    }

    bool isvalid(vector<vector<char> >& board,int row,int col,char val)
    {
    	for(int i=0;i<9;++i)
    	{
    		if(board[row][i]==val)return false;
    		if(board[i][col]==val)return false;
    	//0->0 1->0 2->0 3->3 4->3 5->3 6->6 7->6 8->6
    	int x=row/3*3;
    	int y=col/3*3;
    	//cout<<x+i/3<<" "<<y+i%3<<" ";
    	if(board[x+i/3][y+i%3]==val)return false;
    	}
    	return true;

    }

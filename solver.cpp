#include <iostream>
#include "solverUtils.h"

bool solve(int b[][9]);

int main(){
	solverUtils tools;
    int input;
    
    int solvedBoard[9][9] = {
        {4,8,3,9,2,1,6,5,7},
        {9,6,7,3,4,5,8,2,1},
        {2,5,1,8,7,6,4,9,3},
        {5,4,8,1,3,2,9,7,6},
        {7,2,9,5,6,4,1,3,8},
        {1,3,6,7,9,8,2,4,5},
        {3,7,2,6,8,9,5,1,4},
        {8,1,4,2,5,3,7,6,9},
        {6,9,5,4,1,7,3,8,2}
    };

    int board[9][9] =
	{
		{0,6,0,0,4,5,3,7,0},
		{0,0,5,6,7,3,4,2,0},
		{0,0,4,0,0,0,0,0,1},
		{5,0,0,7,0,2,0,0,4},
		{6,0,9,0,0,0,2,5,0},
		{8,0,7,0,0,9,0,0,3},
		{4,9,0,5,1,7,8,0,0},
		{2,1,0,0,3,6,0,0,0},
		{0,5,0,0,2,0,1,0,0},
	};
    if(tools.isFinished(solvedBoard))
        std::cout << "Solved Board: " << "solved" << std::endl;
    else
        std::cout << "Solved Board: " << "Not solved" << std::endl;
    
    if(tools.isFinished(board))
        std::cout << "Unsolved Board: " << "solved" << std::endl;
    else
        std::cout << "Unsolved Board: " << "Not solved" << std::endl;
    

	//if(solve(board)) printBoard(board);
}

/*
bool solve(int b[][9]){
    //printBoard(b);
    if(isFinished(b)) return true;
    int trial = 1; 
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){	
            while(!isFinished(b) && !solve(b)){
		if(b[i][j] == 0){
			if(isInBox(b,i,j,trial) || isInRow(b,i,trial) || isInCol(b,j,trial)){
		    		trial++;
				if(trial>9){
					return false;
				}
			}
			if(trial>9){
				return false;
			}
			b[i][j] = trial;
			trial = 1;
			solve(b);
		    }
		}
	    continue;
	}
    }
    if(isFinished(b)) return true;
    else return false;
}
*/

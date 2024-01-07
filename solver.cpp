#include <iostream>
#include <string>

void defineBoard(int board[][9]);

bool isFinished(int board[][9]);

void printBoard(int b[][9]);

void printBoard(int b[][9], int row, int col);

bool isInRow(int b[][9], int row, int num);

bool isInCol(int b[][9], int col, int num);

bool isInBox(int b[][9], int row, int col, int num);

bool solve(int b[][9]);

int main(){
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
	std::cout<<isInBox(board, 0,0,6);
	//defineBoard(board);
	if(solve(board)) printBoard(board);
}

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

void defineBoard(int board[][9]){
	std::string input = "";
	int inputInt = 0;
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
			printBoard(board,i,j);
			std::cout << "Enter integer 1-9: ";
			std::getline(std::cin, input);
			if(input == "u"){
				j-=2;
				continue;
			}
			if(input != "") inputInt = input.at(0) - '0';
			else inputInt = 0;
			std::cout << input;
			while(inputInt > 9|| inputInt < 0){
				std::cout << "Please enter integer 1-9: ";
				std::getline(std::cin, input);
				if(input != "") inputInt = input.at(0) - '0';
			}
			std::cout << std::endl;
			board[i][j] = inputInt;
		}
	}

}

bool isFinished(int board[][9]){
	for(int i = 0; i < 9; i++){
		if(isInRow(board, i, 0)) return false;
	}
	return true;
}

void printBoard(int b[][9]){
	for(int i = 0; i<9; i++){
		if(i % 3 == 0 && i != 0){
			std::cout << "---------";
			std::cout << "\n";
		}
		for(int j = 0; j<9; j++){
			if(j%3 == 0 && j!=0) std::cout << "|";
			std::cout << b[i][j];
		}
		std::cout << "\n";
	}
}

void printBoard(int b[][9], int row, int col){
	for(int i = 0; i<9; i++){
		if(i % 3 == 0 && i != 0){
			std::cout << "---------";
			std::cout << "\n";
		}
		for(int j = 0; j<9; j++){
			if(j%3 == 0 && j!=0) std::cout << "|";
			if(i == row && j == col) std::cout << '_';
			else std::cout << b[i][j];
		}
		std::cout << "\n";
	}
}

bool isInBox(int b[][9], int row, int col, int num){
	row /= 3;
	col /= 3;
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			if(b[row*3 + i][col*3 + j] == num)
				return true;
		}
	}
	return false;
}

bool isInRow(int b[][9], int row, int num){
	for(int i = 0; i < 9; i++){
		if(b[row][i]==num){
			return true;
		}
	}
	return false;
}

bool isInCol(int b[][9], int col, int num){
	for(int i = 0; i < 9; i++){
		if(b[i][col]==num){
			return true;
		}
	}
	return false;
}

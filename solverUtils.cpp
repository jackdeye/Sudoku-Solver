#include <iostream>
#include "solverUtils.h"

solverUtils::solverUtils(){
}

void solverUtils::defineBoard(int board[][9]){
	std::string input = "";
	int inputInt = 0;
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
            solverUtils::printBoard(board,i,j);
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

bool solverUtils::isFinished(int board[][9]){
	for(int i = 0; i < 9; i++){
		for(int j = 1; j < 10; j++){
            if(!isInRow(board, i, j)) return false;
        }
	}
    for(int i = 0; i < 9; i++){
		for(int j = 1; j < 10; j++){
            if(!isInCol(board, i, j)) return false;
        }
	}
    for(int i = 0; i<9; i+=3){
        for(int j = 0; j<9; j+=3){
            for(int num = 1; num < 10; num++){
                if(!isInBox(board, i, j, num)) return false;
            }
        }
    }
	return true;
}

void solverUtils::printBoard(int b[][9]){
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

void solverUtils::printBoard(int b[][9], int row, int col){
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

bool solverUtils::isInBox(int b[][9], int row, int col, int num){
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

bool solverUtils::isInRow(int b[][9], int row, int num){
	for(int i = 0; i < 9; i++){
		if(b[row][i]==num){
			return true;
		}
	}
	return false;
}

bool solverUtils::isInCol(int b[][9], int col, int num){
	for(int i = 0; i < 9; i++){
		if(b[i][col]==num){
			return true;
		}
	}
	return false;
}

bool solverUtils::solveSudoku(int board[][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) { 
                for (int num = 1; num <= 9; num++) { 
                    if (!isInRow(board, row, num) && !isInCol(board, col, num) 
                    && !isInBox(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = 0; // undo the assignment
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int (*solverUtils::solve(int board[][9]))[9] {
    if (solveSudoku(board)) {
        return board;
    } else {
        return nullptr;
    }
}


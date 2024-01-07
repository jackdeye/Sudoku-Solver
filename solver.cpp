#include <iostream>
#include <string>

void defineBoard(int board[][9]);

void printBoard(int b[][9]);

bool isInRow(int b[][9], int row, int num);

bool isInCol(int b[][9], int col, int num);

bool isInBox(int b[][9], int row, int col, int num);

void solve(int b[][9]);

int main(){
	int board[9][9] =
	{
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
	};
	defineBoard(board);
}

bool solve(int b[][9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(b[i][j] == 0){
					while(isInBox(b,i,j,trial)||isInRow(b,i,trial)||isInCol(b,j,trial)){
						trial++;







}

void defineBoard(int board[][9]){
	std::string input = "";
	int inputInt = 0;
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
			std::cout << "Enter integer 1-9: ";
			std::getline(std::cin, input);
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
			printBoard(board);
		}
	}

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

bool isInBox(int b[][9], int row, int col, int num){
	row /= 3;
	col /= 3;
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			if(b[row + i][col + j] == num)
				return false;
		}
	}
	return true;
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

#include<iostream>

void printBoard(int b[][9]){
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
			if(j%3 == 0 && j!=0) std::cout << "|";
			std::cout << b[i][j];
		}
		std::cout<<"\n";
	}
}

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
	int input = 0;
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++){
			std::cout << "Enter integer 1-9: ";
			std::cin >> input;
			while(input>9||input<1){
				std::cin >> input;
			}
			std::cout << std::endl;
			board[i][j] = input;
			printBoard(board);
		}
	}
}

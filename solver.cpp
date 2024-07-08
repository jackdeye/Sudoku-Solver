#include <iostream>
#include "solverUtils.h"

int main(){
	solverUtils tools;
    int inputBoard[9][9] = {0};
    tools.defineBoard(inputBoard);
    if(tools.solve(inputBoard)){
        std::cout << "The board is solvable! Here is the solution" << std::endl;
        tools.printBoard(inputBoard);
    } else {
        std::cout << "The board is not solvable!" << std::endl;
    }
}

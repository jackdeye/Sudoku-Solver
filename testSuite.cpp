#include "solverUtils.h"
#include "testBoards.h"
#include <iostream>
#include <vector>

solverUtils tester = solverUtils();
std::vector<bool> arr(6,false);

void solvedBoardDetection(){
    arr[0] = tester.isFinished(solvedBoard1) ? true : false;
    arr[1] = tester.isFinished(solvedBoard2) ? true : false;
    arr[2] = tester.isFinished(solvedBoard3) ? true : false;
    arr[3] = tester.isFinished(unSolvedBoard1) ? false : true;
    arr[4] = tester.isFinished(unSolvedBoard2) ? false : true;
    arr[5] = tester.isFinished(unSolvedBoard3) ? false : true;
}

int main(){
    solvedBoardDetection();
    for(auto i = arr.begin(); i!=arr.end(); i++){
        std::cout << "Passes test: " << *i << std::endl;
    }
}

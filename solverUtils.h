#ifndef UTILS
#define UTILS

class solverUtils{
    public: 
        solverUtils();
        void defineBoard(int board[][9]);
        bool isFinished(int board[][9]);
        void printBoard(int b[][9]);
        void printBoard(int b[][9], int row, int col);
        bool isInRow(int b[][9], int row, int num);
        bool isInCol(int b[][9], int col, int num);
        bool isInBox(int b[][9], int row, int col, int num);
};

#endif //UTILS

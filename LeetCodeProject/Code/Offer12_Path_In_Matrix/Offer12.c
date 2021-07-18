#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int g_row;
int g_col;
int g_wordLen;
bool Dfs (char** board,char* word,const int index,const int row,const int col) {
    if ((row<0||row>=g_row)||(col<0||col>=g_col)) {
        return false;
    }
    if (g_wordLen == index) {
        return true;
    }
    bool res = false;
    if (board[row][col] == word[index]) {
        res = true;
        char str = board[row][col];
        board[row][col] = '\0';
        if ( g_wordLen == index+1 ) {
            return res;
        }
        bool tmp = Dfs(board,word,index + 1,row + 1,col) || 
                   Dfs(board,word,index + 1,row - 1,col) ||
                   Dfs(board,word,index + 1,row,col + 1) ||
                   Dfs(board,word,index + 1,row,col - 1);
        board[row][col] = str;
        return tmp&&res;
    }
    return res;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word){
    g_row = boardSize;
    g_col = boardColSize[0];
    g_wordLen = strlen(word);
    bool res;
    for (int i = 0;i<g_row;++i) {
        for (int j= 0;j<g_col;++j) {
           if (board[i][j] == word[0]) {
               res = Dfs(board,word,0,i,j);
                if ( res == true ) {
                    return res;
                }
           } 
        }
    }
    return res;
}
int main (void) {
    int boardSize = 3;
    int boardColSize = 4;
    int* boardColSizePtr = &boardColSize;
    char word[] = "ABCCED";
    char** board = (char **)malloc(sizeof(char *) * boardSize);
    for (int i = 0;i<boardSize;++i) {
        board[i] = (char *)malloc(sizeof(char) * boardColSize);
    }
    board[0][0] = 'A';
    board[0][1] = 'B';
    board[0][2] = 'C';
    board[0][3] = 'E';

    board[1][0] = 'S';
    board[1][1] = 'F';
    board[1][2] = 'C';
    board[1][3] = 'S';

    board[2][0] = 'A';
    board[2][1] = 'D';
    board[2][2] = 'E';
    board[2][3] = 'E';

    bool res = exist(board,boardSize,boardColSizePtr,word);
    printf("res = %d\n",res);
    system("pause");
    return 0;
}
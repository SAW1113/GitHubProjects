//07/17 07/18
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int g_row;
int g_col;
int g_tagNum;
void AddTag(char** board,int** queue) {
    //第一行和最后一行
    for (int j = 0;j<g_col;++j) {
        if(board[0][j] == 'O') {
            board[0][j] = 'A';
            queue[g_tagNum][0] = 0;
            queue[g_tagNum++][1] = j;
        }
        if(board[g_row - 1][j] == 'O') {
            board[g_row - 1][j] = 'A';
            queue[g_tagNum][0] = g_row - 1;
            queue[g_tagNum++][1] = j;
        }
    }
    //第一列和最后一列
    for (int i = 0;i<g_row;++i) {
        if(board[i][0] == 'O') {
            board[i][0] = 'A';
            queue[g_tagNum][0] = i;
            queue[g_tagNum++][1] = 0;
        }
        if(board[i][g_col-1] == 'O') {
            board[i][g_col-1] = 'A';
            queue[g_tagNum][0] = i;
            queue[g_tagNum++][1] = g_col-1;
        }
    }
}
void changeTag(char** board) {
    for (int i = 0;i<g_row;++i) {
        for (int j = 0;j<g_col;++j) {
            if (board[i][j] == 'A') {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}
void solve(char** board, int boardSize, int* boardColSize){
    g_row = boardSize;
    g_col = boardColSize[0];
    int ** queue = (int **)malloc(sizeof(int *) * (g_row * g_col));
    for (int i = 0;i<(g_row * g_col);++i) {
        queue[i] = (int *)malloc(sizeof(int) * 2);
        memset(queue[i],0,sizeof(int) * 2);
    }
    g_tagNum = 0;
    AddTag(board,queue);
    int index = 0;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while (index<g_tagNum) {
        int x = queue[index][0];
        int y = queue[index++][1];
        for (int i = 0;i<4;++i) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if ((mx<0||mx>=g_row)||(my<0||my>=g_col)) {
                continue;
            }
            if (board[mx][my] == 'O') {
                board[mx][my] = 'A';
                queue[g_tagNum][0] = mx;
                queue[g_tagNum++][1] = my;
            }
        }
    }
    changeTag(board);
    for (int i = 0; i < g_row * g_col; i++) {
        free(queue[i]);
    }
    return;
}
int main(void ) {
    return 0;
}
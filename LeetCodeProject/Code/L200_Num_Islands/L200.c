#include <stdio.h>
int g_row;
int g_col;
void Dfs (char** grid,int row,int col) {
    if( (row<0||row>=g_row)||(col<0||col>=g_col) ) {
        return;
    }
    if (grid[row][col] == '1') {
        grid[row][col] = '0';
        Dfs(grid,row + 1,col);
        Dfs(grid,row - 1,col);
        Dfs(grid,row,col + 1);
        Dfs(grid,row,col - 1);
    }
    return;
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    g_row = gridSize;
    g_col = gridColSize[0];
    int res = 0;
    for (int i = 0;i<g_row;++i) {
        for (int j = 0;j<g_col;++j) {
            if (grid[i][j] == '1') {
                res++;
                Dfs(grid,i,j);
            }
        }
    }
    return res;
}
int main (void) {
    return 0;
}
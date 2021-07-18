//7 15 7 18
#include <stdio.h>
#include <math.h>
int g_row;
int g_col;
int Dfs (int** grid,const int row,const int col) {
    if ( (row<0||row>=g_row)||(col<0||col>=g_col) ) {
        return 0;
    }
    int res = 0;
    if (grid[row][col] == 1) {
        grid[row][col] = 0;
        res++;
        res += Dfs(grid,row + 1,col) +
               Dfs(grid,row - 1,col) +
               Dfs(grid,row,col + 1) +
               Dfs(grid,row,col - 1);
    }
    return res;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    g_row = gridSize;
    g_col = gridColSize[0];
    int max = 0;
    for (int i = 0;i<g_row;++i) {
        for (int j = 0;j<g_col;++j) {
            if (grid[i][j] == 1) {
                max = fmax(Dfs(grid,i,j),max);
            }
        }
    }
    return max;
}
int main (void) {
    return 0;
}
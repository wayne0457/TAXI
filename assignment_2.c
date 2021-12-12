#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int route_num = 0;
static int n, m;

typedef struct {
    int code;
    int doors[4];
} maze_t;

void push(int* path, int top, int data){
    path[top] = data;
}
void track(int* path, int top){
    int i = 0;
    while (i < top) {
        printf("(%d,%d)->", path[i]%4+1, path[i]/4+1);
        i++;
    }
    printf("(%d,%d)\n", path[i]%4+1, path[i]/4+1);
}

void ramble(maze_t** maze, int i, int j, int** before, int* path, int top){
    if (i == n - 1  && j == m - 1) {
        if (maze[i][j].doors[1] == 0){
            ++route_num;
            push(path, top, 4*i+j);
            track(path,top);
        }
    } else if (i >= 0 && i < n && j >= 0 && j < m && before[i][j] == 0){
        before[i][j] = 1;
        if (maze[i][j].doors[0] == 0) {
            push(path, top, 4*i+j);
            ramble(maze, i - 1, j, before, path, top+1);
        }
        if (maze[i][j].doors[3] == 0){
            push(path, top, 4*i+j);
            ramble(maze, i, j - 1, before, path, top+1);
        }
        if (maze[i][j].doors[1] == 0){
            push(path, top, 4*i+j);
            ramble(maze, i, j + 1, before, path, top+1);
        }
        if (maze[i][j].doors[2] == 0){
            push(path, top, 4*i+j);
            ramble(maze, i + 1, j, before, path, top+1);
        }
    }
}

int main(){
    scanf("%d %d", &n ,&m);
    maze_t** maze = (maze_t**) malloc(n * sizeof(maze_t*));
    int** before = (int**) malloc(n * sizeof(int*));
    int* path = (int *) malloc((n * m + 1)* sizeof(int));

    for (int i = 0; i < n; i++) {
        maze[i] = (maze_t*) malloc(m * sizeof(maze_t));
        before[i] = (int*) malloc(m * sizeof(int));

        for (int j = 0; j < m; j++) {
            path[n*i+j] = 0;
            scanf("%d", &maze[i][j].code);
            before[i][j] = 0;
            int bit = 3;
            while (bit >= 0) {
                if (maze[i][j].code >= pow(2, bit)) {
                    maze[i][j].doors[3-bit] = 1;
                    maze[i][j].code -= pow(2, bit);
                } else {
                    maze[i][j].doors[3-bit] = 0;
                }
                -- bit;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i - 1 >= 0) {
                if (maze[i][j].doors[0] != maze[i-1][j].doors[2]) {
                    printf("input error\n");
                    return 0;
                }
            }
            if (j - 1  >= 0) {
                if (maze[i][j].doors[3] != maze[i][j-1].doors[1]) {
                    printf("input error\n");
                    return 0;
                }
            }
        }
    }
    ramble(maze, 0, 0, before, path, 0);
    if (route_num == 0) {
        printf("no way out\n");
    }
}

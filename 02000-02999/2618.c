#include <stdio.h>
#include <math.h>
#define MAX 987654321

/*
문제 : N * N(N <= 1000) 크기의 격자의 왼쪽 위와 오른쪽 아래 두 점이 있다. W(W <= 1000)개의 점에 대해 두 점 중 한 점을 이동시켜
순서대로 방문한다고 할 때, 두 점의 이동거리를 가장 작게 하는 방법과 그때의 이동 거리를 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 두 점의 마지막 위치(점 번호)에 대한 최소 이동거리를 저장한다.
만약 두 점의 마지막 위치가 2 이상 차이 나는 경우에는 마지막 이동으로 가능한 것은 더 위치 번호가 큰 점을 1 뒤로 옮기는 것 뿐이다.
차이가 1만 난다면, 위치 번호가 더 큰 점(이전에는 더 작은 점이었던)을 더 작은 점보다 뒤로 옮기는 것이 가능하다.
이 행동은 더 작은 점보다 위치 번호가 작았던 모든 점에 대해 가능하다. 차이가 0인 경우는 나올 수 없다.
마지막 점의 최소 이동거리를 찾으면 거기서부터 다시 역추적을 통해 이동 방법을 확인하면 된다.

주요 알고리즘 : DP, 역추적

출처 : 정올 2003 중2번
*/

int pos[1024][2], mem[1024][1024], route[1024]; //pos: W개의 점의 X, Y 좌표 / mem: 첫 번째 점과 두 번째 점의 위치
int n;

int small(int a, int b) {
    return a < b ? a : b;
}

int getdist(int a, int p) {
    if (p < 0) {
        //0에 대한 예외 처리(-1은 왼쪽 위, -2는 오른쪽 아래)
        if (p == -1) return pos[a][0] + pos[a][1] - 2;
        else return n * 2 - pos[a][0] - pos[a][1];
    }
    else return (abs(pos[a][0] - pos[p][0]) + abs(pos[a][1] - pos[p][1]));
}

int main(void) {
    int w, best, x = 0, y = 0;
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= w; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    mem[0][1] = getdist(1, -1); //첫 번째 점에 대해서는 각각 미리 구해둔다.
    mem[1][0] = getdist(1, -2);
    for (int i = 2; i <= w; i++) {
        for (int j = 0; j < i - 1; j++) {
            //차이가 2 이상 나는 경우에는 1칸만 옮길 수 있다.
            mem[j][i] = mem[j][i - 1] + getdist(i, i - 1);
            mem[i][j] = mem[i - 1][j] + getdist(i, i - 1);
        }
        best = MAX;
        for (int j = 0; j < i - 1; j++) {
            //더 작은 점보다 작은 위치에서 시작하는 모든 경우에 대해 최솟값을 구한다.
            best = small(best, mem[i - 1][j] + getdist(i, j == 0 ? -1 : j));
        }
        mem[i - 1][i] = best;
        best = MAX;
        for (int j = 0; j < i - 1; j++) {
            //더 작은 점보다 작은 위치에서 시작하는 모든 경우에 대해 최솟값을 구한다.
            best = small(best, mem[j][i - 1] + getdist(i, j == 0 ? -2 : j));
        }
        mem[i][i - 1] = best;
    }
    best = MAX;
    for (int i = 0; i < w; i++) {
        if (mem[i][w] < best) {
            best = mem[i][w];
            x = i;
            y = w;
        }
        if (mem[w][i] < best) {
            best = mem[w][i];
            x = w;
            y = i;
        }
    }
    printf("%d\n", best);

    while (x > 0 || y > 0) {
        //역추적
        if (x > y) {
            route[x] = 2;
            if (x > y + 1) x--;
            else {
                for (int i = 1; i < y; i++) {
                    if (mem[i][y] + getdist(i, x) == mem[x][y]) {
                        x = i;
                        break;
                    }
                }
                if (x == y + 1) x = 0;
            }
        }
        else {
            route[y] = 1;
            if (y > x + 1) y--;
            else {
                for (int i = 1; i < x; i++) {
                    if (mem[x][i] + getdist(i, y) == mem[x][y]) {
                        y = i;
                        break;
                    }
                }
                if (y == x + 1) y = 0;
            }
        }
    }
    for (int i = 1; i <= w; i++) {
        printf("%d\n", route[i]);
    }
    return 0;
}
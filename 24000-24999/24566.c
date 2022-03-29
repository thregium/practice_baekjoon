#include <stdio.h>
#include <stdlib.h>

/*
문제 : H * W(H, W <= 50) 크기의 공원에 물 또는 서로 다른 높이의 석상들이 있다. 물이 있는 칸을 제외하고
석상들을 대각선으로 키 순서대로 정렬시키려 할 때, 옮겨야 하는 석상 개수의 최솟값을 구한다.

해결 방법 : 방향이 4개 뿐이므로 각 방향으로 정렬시킬 때 옮겨야 하는 개수 가운데 최솟값을 찾으면 된다.
각 방향에서 최솟값은 제 위치에 있지 않은 석상의 수와 같다.
이는 각 방향에서 줄 번호를 구한 다음 누적 합으로 각 줄에 포함되는 번째수를 구하고
그 번째에 포함되지 않는 석상의 수를 구하는 방법으로 구현 가능하다. 이를 위해서는 석상들의 높이를 미리 전처리로
정렬한 배열이 있어야 한다.

주요 알고리즘 : 구현, 브루트 포스

출처 : ECNA 2021 L번
*/

int sta[64][64], asta[2560], stend[128];

void diag(int h, int w, int x) {
    for (int i = 0; i < 128; i++) stend[i] = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sta[i][j] < 0) continue;
            if (x == 0) stend[i + j + 1]++;
            else if (x == 1) stend[i - j + w]++;
            else if (x == 2) stend[h + w - (i + j + 1)]++;
            else if (x == 3) stend[j - i + h]++;
        }
    }
    for (int i = 1; i < 128; i++) stend[i] += stend[i - 1];
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int h, w, n = 0, tomov, pos = -1, res = 103000;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &sta[i][j]);
            if (sta[i][j] > 0) asta[n++] = sta[i][j];
        }
    }
    qsort(asta, n, sizeof(int), cmp1);
    asta[n] = 1012345678;
    for (int i = 0; i < 4; i++) {
        diag(h, w, i);
        tomov = 0;
        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                if (sta[x][y] < 0) continue;
                if (i == 0) pos = x + y + 1;
                else if (i == 1) pos = x - y + w;
                else if (i == 2) pos = h + w - (x + y + 1);
                else if (i == 3) pos = y - x + h;
                
                if (sta[x][y] < asta[stend[pos - 1]] || sta[x][y] > asta[stend[pos] - 1]) tomov++;
            }
        }
        if (tomov < res) res = tomov;
    }
    printf("%d", res);
    return 0;
}
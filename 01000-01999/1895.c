#include <stdio.h>
#include <stdlib.h>

/*
문제 : R * C(R, C <= 40) 크기의 이미지에서 모든 3 * 3 크기 영역의 중앙값을 취하였다.
중앙값이 T 이상인 것의 개수를 구한다. 이미지의 각 픽셀의 값은 0 이상 255 이하로 주어진다.

해결 방법 : 모든 3 * 3 영역에 대해 해당하는 픽셀들을 저장한 다음, 정렬하고 5번째 수를 구한다.
각 수에 대해 5번째 수가 몇 번 나왔는지 센 다음, T 이상의 수에 대해 그 합을 구하면 답이 된다.

주요 알고리즘 : 브루트 포스, 정렬

출처 : NOIS 2003 1번
*/

int img[48][48], cnt[256], tmp[9];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int r, c, t, res = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &img[i][j]);
        }
    }
    for (int i = 0; i < r - 2; i++) {
        for (int j = 0; j < c - 2; j++) {
            for (int ii = 0; ii < 3; ii++) {
                for (int jj = 0; jj < 3; jj++) {
                    tmp[ii * 3 + jj] = img[i + ii][j + jj];
                }
            }
            qsort(tmp, 9, sizeof(int), cmp1);
            if (tmp[4] < 0 || tmp[4] > 255) return 1;
            cnt[tmp[4]]++;
        }
    }
    scanf("%d", &t);
    for (int i = t; i < 256; i++) {
        res += cnt[i];
    }
    printf("%d", res);
    return 0;
}
#include <stdio.h>

/*
문제 : N * M(N, M <= 100, 짝수) 크기의 배열에서 연산 R(R <= 1000)회를 한 후의 배열을 출력한다.
1. 배열을 상하반전함
2. 배열을 좌우반전함
3. 배열을 우측으로 90도 회전시킴
4. 배열을 좌측으로 90도 회전시킴
5. 배열을 4등분 후 조각 단위로 우측으로 90도 회전시킴
6. 배열을 4등분 후 조각 단위로 좌측으로 90도 회전시킴

해결 방법 : 각 연산을 구현한다. 임시 배열을 만드는 것이 좋다.

주요 알고리즘 : 구현, 시뮬레이션
*/

int arr[128][128], tarr[128][128];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void ud(int* a, int h, int w, int lsz) {
    for (int i = 0; i < h - i - 1; i++) {
        for (int j = 0; j < w; j++) {
            swap(&a[i * lsz + j], &a[(h - i - 1) * lsz + j]);
        }
    }
}

void lr(int* a, int h, int w, int lsz) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w - j - 1; j++) {
            swap(&a[i * lsz + j], &a[i * lsz + (w - j - 1)]);
        }
    }
}

void rotl(int* a, int* t, int* h, int* w, int lsz) {
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) {
            t[i * lsz + j] = a[j * lsz + (*w - i - 1)];
        }
    }
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) a[i * lsz + j] = t[i * lsz + j];
    }
    swap(h, w);
}

void rotr(int* a, int* t, int* h, int* w, int lsz) {
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) {
            t[i * lsz + j] = a[(*h - j - 1) * lsz + i];
        }
    }
    for (int i = *w - 1; i >= 0; i--) {
        for (int j = *h - 1; j >= 0; j--) a[i * lsz + j] = t[i * lsz + j];
    }
    swap(h, w);
}

void subl(int* a, int* t, int h, int w, int lsz) {
    int sh = h >> 1, sw = w >> 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i < sh && j < sw) t[i * lsz + j] = a[i * lsz + (j + sw)];
            else if (i < sh) t[i * lsz + j] = a[(i + sh) * lsz + j];
            else if (j < sw) t[i * lsz + j] = a[(i - sh) * lsz + j];
            else t[i * lsz + j] = a[i * lsz + (j - sw)];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) a[i * lsz + j] = t[i * lsz + j];
    }
}

void subr(int* a, int* t, int h, int w, int lsz) {
    int sh = h >> 1, sw = w >> 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i < sh && j < sw) t[i * lsz + j] = a[(i + sh) * lsz + j];
            else if (i < sh) t[i * lsz + j] = a[i * lsz + (j - sw)];
            else if (j < sw) t[i * lsz + j] = a[i * lsz + (j + sw)];
            else t[i * lsz + j] = a[(i - sh) * lsz + j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) a[i * lsz + j] = t[i * lsz + j];
    }
}

int main(void) {
    int n, m, r, x;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        scanf("%d", &x);
        if (x == 1) ud(arr, n, m, 128);
        else if (x == 2) lr(arr, n, m, 128);
        else if (x == 3) rotr(arr, tarr, &n, &m, 128);
        else if (x == 4) rotl(arr, tarr, &n, &m, 128);
        else if (x == 5) subr(arr, tarr, n, m, 128);
        else if (x == 6) subl(arr, tarr, n, m, 128);
        else return 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d%c", arr[i][j], j == m - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
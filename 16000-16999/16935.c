#include <stdio.h>

/*
���� : N * M(N, M <= 100, ¦��) ũ���� �迭���� ���� R(R <= 1000)ȸ�� �� ���� �迭�� ����Ѵ�.
1. �迭�� ���Ϲ�����
2. �迭�� �¿������
3. �迭�� �������� 90�� ȸ����Ŵ
4. �迭�� �������� 90�� ȸ����Ŵ
5. �迭�� 4��� �� ���� ������ �������� 90�� ȸ����Ŵ
6. �迭�� 4��� �� ���� ������ �������� 90�� ȸ����Ŵ

�ذ� ��� : �� ������ �����Ѵ�. �ӽ� �迭�� ����� ���� ����.

�ֿ� �˰��� : ����, �ùķ��̼�
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
#include <stdio.h>
#define INF 1012345678

/*
���� : N * N(N <= 500) ũ���� �� �迭�� �־��� ��, ù��° �迭�� �ι�° �迭�� �ٲٱ� ����
�ʿ��� �ּ� ���� Ƚ���� ���Ѵ�.
1. �迭�� Ư�� ���Ҹ� ���ϴ� ������ �ٲ۴�.
2. �迭�� �������� 90�� ������. 3. �迭�� ���������� 90�� ������.

�ذ� ��� : �迭�� ������ �ʴ´ٸ� ���� �� �迭�� �ٸ� ���� �����̴�.
�迭�� ������ ���� �ִ� 4�����̹Ƿ� 4���� ��� ��츦 ����غ��� �� �� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����?

��ó : JOI 2020��2 1��
*/

char s[512][512], t[512][512], p[512][512], tmp[512][512];

int small(int a, int b) {
    return a < b ? a : b;
}

int getdiff(int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r += (t[i][j] != p[i][j]);
        }
    }
    return r;
}

void rotl(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[n - j - 1][i] = p[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) p[i][j] = tmp[i][j];
    }
}

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < n; j++) p[i][j] = s[i][j];
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", t[i]);
    }
    r = small(r, getdiff(n));
    rotl(n);
    r = small(r, getdiff(n) + 1);
    rotl(n);
    r = small(r, getdiff(n) + 2);
    rotl(n);
    r = small(r, getdiff(n) + 1);
    printf("%d\n", r);
    return 0;
}
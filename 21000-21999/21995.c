#include <stdio.h>

/*
���� : N * 2(N <= 1000) ũ���� 1���� N * 2������ �ڿ����� �̷���� ������ �ִ�.
�� ������ i��°�� N + i��°�� �ٲٴ� ����� i * 2��°�� i * 2 + 1��°�� �ٲٴ� ������ ����
�־��� ������ ���� ������ �� ���ϰ�, �����ϴٸ� �׷��� �ϴ� �ּ� ���� Ƚ���� ���Ѵ�.
�Ұ����� ��� -1�� ����Ѵ�.

�ذ� ��� : �� ������ ��� �������� �ϴ� ��� ������� ���ƿ��Ƿ� �� ������ ����� ����ؾ� �Ѵ�.
�� ������ �����ؼ� ����ϴ� ���� ���ƾ� N * 2ȸ �̳����� ������� ���ƿ��� ���� �� �� �ִ�.
����, ������� ���ƿ��� ������ ���� ���⿡ ���� �õ��� ���� �� ���� ���ĵǴ� ���� ������ �ϸ� �ȴ�.
������� ���ƿ� ���� �־��� ������ ���ĵ��� �ʴ´ٸ� -1�� ����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�, �ֵ� Ȥ?

��ó : NERC 2020 K��
*/

int a[2048], b[2048];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int issame(int* a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int issorted(int* a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) return 0;
    }
    return 1;
}

int main(void) {
    int n, p = 0, r1 = 0, r2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    if (issorted(a, n * 2)) {
        printf("0");
        return 0;
    }


    do {
        if ((p++) & 1) {
            for (int i = 0; i < n; i++) {
                swap(&b[i], &b[i + n]);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                swap(&b[i * 2], &b[i * 2 + 1]);
            }
        }
        if (issorted(b, n * 2)) {
            r1 = p;
            break;
        }
    } while (!issame(a, b, n * 2));

    for (int i = 0; i < n * 2; i++) b[i] = a[i];
    p = 0;
    do {
        if (~(p++) & 1) {
            for (int i = 0; i < n; i++) {
                swap(&b[i], &b[i + n]);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                swap(&b[i * 2], &b[i * 2 + 1]);
            }
        }
        if (issorted(b, n * 2)) {
            r2 = p;
            break;
        }
    } while (!issame(a, b, n * 2));
    if (!r1) printf("-1");
    else printf("%d", r1 < r2 ? r1 : r2);
    return 0;
}
#include <stdio.h>

/*
���� : 0���� N - 1(N <= 10^9)���� ���ʷ� �ִ� ������ K(0 <= K < N)��ŭ ���������� �̵���Ų ����
����� ���� ���� ������ ������ �ּҷ� �� ��, ���� Ƚ���� �� ������� ����Ѵ�.

�ذ� ��� : ���Ʈ ������ ���� ũ���� ������ ���� ��� ��츦 ã�ƺ��� ��츦 ���� �� �ִ�.
�� ������ ���� ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ, ��ó��

��ó : Petro 2015W5 C��
*/

int a[128], b[128], res[128];

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

void rev(int* a, int s, int e) {
    for (int i = s, j = e; i < j; i++, j--) {
        swap(&a[i], &a[j]);
    }
}

int main(void) {
    int n, k, r;
    scanf("%d %d", &n, &k);
    if (k == 0) {
        printf("0");
    }
    else if (n == 2) {
        printf("1\n0 1");
    }
    else if (k == 1) {
        printf("2\n0 %d\n0 %d", n - 2, n - 1);
    }
    else if (k == n - 1) {
        printf("2\n0 %d\n0 %d", n - 1, n - 2);
    }
    else if (k == 2) {
        printf("2\n0 %d\n1 %d", n - 2, n - 1);
    }
    else if (k == n - 2) {
        printf("2\n1 %d\n0 %d", n - 1, n - 2);
    }
    else {
        printf("3\n0 %d\n%d %d \n0 %d", n - k - 1, n - k, n - 1, n - 1);
    }
    /*
    for (int n = 1; n <= 20; n++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                a[i] = i;
                b[i] = (i - k + n) % n;
            }
            r = 4;
            if (issame(a, b, n)) r = 0;
            for (int x1 = 0; x1 < n; x1++) {
                for (int y1 = x1 + 1; y1 < n; y1++) {
                    rev(a, x1, y1);
                    if (issame(a, b, n) && r > 1) {
                        r = 1;
                        res[0] = x1, res[1] = y1;
                    }
                    if (r > 2) {
                        for (int x2 = 0; x2 < n; x2++) {
                            for (int y2 = x2 + 1; y2 < n; y2++) {
                                rev(a, x2, y2);
                                if (issame(a, b, n) && r > 2) {
                                    r = 2;
                                    res[0] = x1, res[1] = y1, res[2] = x2, res[3] = y2;
                                }
                                if (r > 3) {
                                    for (int x3 = 0; x3 < n; x3++) {
                                        for (int y3 = x3 + 1; y3 < n; y3++) {
                                            rev(a, x3, y3);
                                            if (issame(a, b, n) && r > 3) {
                                                r = 3;
                                                res[0] = x1, res[1] = y1, res[2] = x2, res[3] = y2;
                                                res[4] = x3, res[5] = y3;
                                            }
                                            rev(a, x3, y3);
                                        }
                                    }
                                }
                                rev(a, x2, y2);
                            }
                        }
                    }
                    rev(a, x1, y1);
                }
            }
            printf("N = %d, K = %d --- %d(", n, k, r);
            for (int i = 0; i < r * 2; i += 2) {
                printf("(%d, %d),", res[i], res[i + 1]);
            }
            printf(")\n");
        }
    }
    */
    return 0;
}
#include <stdio.h>

/*
���� : N(N <= 1000)���� ���� �̷���� �迭�� Q(Q <= 10000)���� ������ �־��� ��, �� ������ �����Ѵ�.
1. A��° ������ B��° �� ������ ���� ����� ����, A��° ���� B��° ���� ���� �ٲ۴�.
2. A��° ������ B��° �� ������ �տ��� C��° ������ D��° �� ������ ���� �� ���� ����Ѵ�/

�ذ� ��� : N�� Q�� ũ�� �ʱ� ������ �� �������� ���� ���� ���ϰ� �ٲٴ� ���굵 ���� ó���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���� 1ȸ�� D��
*/

int arr[1024];

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int n, q, o, a, b, c, d;
    long long res;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &o);
        if (o == 1) {
            scanf("%d %d", &a, &b);
            res = 0;
            for (int j = a; j <= b; j++) {
                res += arr[j];
            }
            printf("%lld\n", res);
            swap(&arr[a], &arr[b]);
        }
        else {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            res = 0;
            for (int j = a; j <= b; j++) {
                res += arr[j];
            }
            for (int j = c; j <= d; j++) {
                res -= arr[j];
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}

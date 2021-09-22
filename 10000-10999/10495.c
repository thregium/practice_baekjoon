#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� �ڿ����� �־��� ��, �� �ڿ����� ��� �ٸ� ��� ������ �ִ������� 1�� ���� ū ���� ���Ѵ�.

�ذ� ��� : ������ ������������ ������ ��, �� �� ������ ���ʷ� ������ ��� ������ �ִ������� ���Ѵ�.
��� 1�� ���� ������ �ٷ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ŭ���� ȣ����, ����

��ó : NAQ 2012 E��
*/

int numbers[1024];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, t;
    //freopen("E:\\PS\\ICPC\\North America\\Qualifier\\2012\\test_data\\choosingnumbers\\data\\secret\\random.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Qualifier\\2012\\test_data\\choosingnumbers\\data\\secret\\random_t.out", "w", stdout);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }
        qsort(numbers, n, sizeof(int), cmp1);
        for (int i = 0; i < n; i++) {
            t = 1;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (gcd(numbers[i], numbers[j]) > 1) {
                    t = 0;
                    break;
                }
            }
            if (t) {
                printf("%d\n", numbers[i]);
                break;
            }
        }
    }
    return 0;
}
#include <stdio.h>

/*
���� : N(N <= 500)���� �ڿ���(<= 5 * 10^7)�� ���ʷ� �־��� ��, X�� i�� ���� ���� �ش� �ڿ����� �ǵ���
���� �� �ִ� �� ���θ� ���Ѵ�.

�ذ� ��� : ������ ������ ���� ���� 3�� �ݺ��ϸ� 3������ ���� �ȴ�.
�� ���� �����ϴٸ� 3���Լ��� ��Ÿ�� �� �ְ�, �������� �ʴٸ� 3���Լ��� ��Ÿ�� �� ����.

�ֿ� �˰��� : ����

��ó : GCPC 2010 H��
*/

long long a[512];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        if (n <= 4) {
            printf("YES\n");
            continue;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = n - 1; j > i; j--) a[j] -= a[j - 1];
        }
        r = 1;
        for (int i = 4; i < n; i++) {
            if (a[i] != a[i - 1]) r = 0;
        }
        printf("%s\n", r ? "YES" : "NO");
    }
    return 0;
}
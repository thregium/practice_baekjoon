#include <stdio.h>
#include <string.h>

/*
���� : �ڿ��� N(N <= 10^10)�� ���μ� ��� ȸ������ ���� ������ ���Ѵ�.

�ذ� ��� : �־��� ���� ��� ���μ��� O(sqrt(N))�� ���� �� �� ���μ����� sprintf()�� ���ڿ��� �ٲٰ�
�� ���μ��� ��� �Ҽ��� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, �Ҽ� ����, ���ڿ�

��ó : GKS 2022B B��
*/

char buff[1024];

int ispal(char* s) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

int main(void) {
    int t, r;
    long long n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld", &n);
        r = 0;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sprintf(buff, "%lld", i);
                if (ispal(buff)) r++;
                if (i * i == n) break;
                sprintf(buff, "%lld", n / i);
                if (ispal(buff)) r++;
            }
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}
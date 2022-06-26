#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ���� �ƴ� ����(<= 10^15)�� �̷���� �񳻸����� �迭�� �־�����.
�� �迭�� �� ���ڸ� �ٲپ� �迭�� ���� ���¸� �� �� �ִ� �� ���Ѵ�.
��, ���� 0�� �ƴ� ��� 0���� ������ �� ����, ���ڸ� �����ϰų� ������ �� ����.

�ذ� ��� : �� �ڸ����� �ϳ��� ���ڸ� �ٲپ� ���鼭 �� �� �� �� ���� ���� ���������� �Ǵ�
��찡 �ִ��� Ȯ���Ѵ�. �ִٸ� �װӰ� �ٲ� ���� ������ ������ ����ϰ�,
���� ��� impossible�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : NCPC 2020 A��
*/

char s[32], t[32];
long long a[128];

int main(void) {
    int n;
    long long x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            s[j] = '\0';
            t[j] = '\0';
        }
        sprintf(s, "%lld", a[i]);
        sprintf(t, "%lld", a[i]);
        for (int j = 0; t[j]; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j == 0 && k == 0 && t[j + 1] != '\0') continue;
                if (k + '0' == s[j]) continue;
                t[j] = k + '0';
                x = strtoll(t, NULL, 10);
                if ((i > 0 && x < a[i - 1]) || (i < n - 1 && x > a[i + 1])) {
                    a[i] = x;
                    for (int ii = 0; ii < n; ii++) {
                        printf("%lld ", a[ii]);
                    }
                    return 0;
                }
            }
            t[j] = s[j];
        }
    }
    printf("impossible");
    return 0;
}
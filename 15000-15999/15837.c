#include <stdio.h>

/*
���� : 

�ذ� ��� : ���� �����ϸ� N^2 ���� �������� ���� ������ �ȴ�. �� ���� ����ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : Khwarizmi 2018 F��
*/

int main(void) {
    int t, n;
    long long res;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        res = n * (n + 1LL) * (n + 2LL);
        res /= 6;
        res *= res;
        printf("%lld\n", res);
    }
    return 0;
}
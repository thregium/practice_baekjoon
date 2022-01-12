#include <stdio.h>

/*
���� : 2 �̻��� �ڿ��� X(X <= 1299709)�� �־��� ��, �� ���� �����ϴ� �Ҽ� ���� ������ ���̸� ���Ѵ�.
�Ҽ� ���� ������ ������ �� �Ҽ� ���̿� �ִ� �ռ����� �̷���� �����̴�. ���� �Ҽ� ���� ������ ���Ե��� �ʴ� ���� ���
0�� ����ϸ� �ȴ�.

�ذ� ��� : X�� �Ҽ��� ��� �Ҽ� ���� ������ ���Ե��� �ʰ�, �� �ܿ��� X���� ū ù �Ҽ����� ���� ������ �Ҽ��� ���� �ȴ�.

�ֿ� �˰��� : ����, �Ҽ� ����, ���Ʈ ����

��ó : Tokyo 2007 B��
*/

int prime[103000];
int pp = 0;

int main(void) {
    int n, t;
    for (int i = 2; i <= 1299709; i++) {
        t = 1;
        for (int x = 2; x * x <= i; x++) {
            if (i % x == 0) {
                t = 0;
                break;
            }
        }
        if (t) prime[pp++] = i;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < pp; i++) {
            if (prime[i] == n) {
                printf("0\n");
                break;
            }
            else if (prime[i] > n) {
                printf("%d\n", prime[i] - prime[i - 1]);
                break;
            }
        }
    }
    return 0;
}
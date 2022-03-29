#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ������ �������� �ִ�. �� ������ ��ǥ�� ������ 10^9 ������ �����̸�,
��� �ִ� �ο����� 10^9�� ������ �ڿ����̴�. �̶�, �������� �� �α����� �Ÿ� ���� �ּҰ� �Ǵ�
���� ��� ���� ���ʿ� �ִ� ���� ã�´�.

�ذ� ��� : ���� �ű� �� �α����� �Ÿ� ���� �����غ��� �� ���� ���� �α����� ���ƾ� ���� �� �� �ִ�.
����, ��ǥ ������� ������ ���� ���� �α����� ���� ��ü�� ���� �̻��� �Ǵ� ù ������ ã�� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����
*/

int post[103000][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long sum = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &post[i][0], &post[i][1]);
        sum += post[i][1];
    }
    qsort(post, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        cnt += post[i][1];
        if (cnt * 2 >= sum) {
            printf("%d", post[i][0]);
            return 0;
        }
    }
    return 1;
}
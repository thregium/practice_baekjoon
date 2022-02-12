#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10000)���� ��ī�̶��� ���� ��ȭ�� �־��� ��, �ǹ��� �ּ� ������ ���Ѵ�.
��ī�̶����� ���̴� 0 �̻� 500000 ���ϸ�, ���� 0�� �ǹ��� ���� �����̴�.

�ذ� ��� : ������ ���� ���� ��ī�̶����� �̷�� �ǹ��� ���̵��� �����Ѵ�.
�� ���� �ǹ��� ������ ���ÿ��� ������ �ִ� �����̸� �ش� �ǹ��� �������� ����, ���� �����̸�
0�� �ƴ϶�� ���ο� �ǹ��� ����. �̸� �ݺ��Ͽ� �ǹ��� ������ ���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ����

��ó : USACO 2005N S6��
*/

int stack[51200], ht[51200][2];
int top = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ht[i][0], &ht[i][1]);
    }
    qsort(ht, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        while (top > 0 && stack[top - 1] > ht[i][1]) top--;
        if (top <= 0 || stack[top - 1] < ht[i][1]) {
            if (ht[i][1] == 0) continue;
            stack[top++] = ht[i][1];
            r++;
        }
    }
    printf("%d", r);
    return 0;
}
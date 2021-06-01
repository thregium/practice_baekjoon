#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1024)���� ���̵��� ���̿�, ���� �ʱ� ���� L�� �־�����. ���� ���� ���� ������ ���̸� ���� �� �ְ�,
���� �ϳ��� ���� �� ���� ���̰� 1�� �þ�ٸ� �ִ�� ���� ���� ���̸� ���Ѵ�.

�ذ� ��� : ���� ���� ���� �ִ� ���̺��� ������� �Դٰ� ���� ���� ���̿� �ִ� ���̸� ���� �� ���ٸ� �׶��� ���̸� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ��ϴ� 2018 ���
*/

int h[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    qsort(h, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (h[i] > l) break;
        else l++;
    }
    printf("%d", l);
    return 0;
}
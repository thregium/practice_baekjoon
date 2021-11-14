#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� �������� �־�����. �� ���� ������ �ϸ� �������� ���� ����� �װ� ���� ����� ���� �����
�����¸�ŭ�� ���� �� �ִٰ� �ϸ�, ù ��° ����� ��θ� �̱� �� �ִ��� ���Ѵ�.

�ذ� ��� : ù ��° ����� �׸� ������ �������� ���� ���� ������� ������ �ϴ� ���� �̵��̴�.
����, �����¿� ���� ������������ ������ �ϰ�, �� ����� �������� ���� ù ��° ����� ������ �̻��� ��찡 ������
Ȯ���Ѵ�. �ִٸ� �̱� �� ����, ���ٸ� �̱� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ���� 2021 A��
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long x;
    scanf("%d", &n);
    if (n == 1) {
        printf("Yes");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a + 1, n - 1, sizeof(int), cmp1);
    x = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] >= x) {
            printf("No");
            return 0;
        }
        x += a[i];
    }
    printf("Yes");
    return 0;
}
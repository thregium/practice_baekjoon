#include <stdio.h>

/*
���� : ���� N(N <= 1000)�� �迭�� �־��� ��, �� �迭���� �� ������ �� ���� ���� ���� ������ ����Ѵ�.

�ذ� ��� : ���� ������ ������ �ȴ�.

�ֿ� �˰��� : ����

��ó : Startlink #1 E1��
*/

int a[1024];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        r = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}
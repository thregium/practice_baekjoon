#include <stdio.h>

/*
���� : N(N <= 1000)���� ���� �̷���� �迭�� ���� ��, �� ���� ���� K�� �Ǵ� ���� ������ ���Ѵ�.

�ذ� ��� : N�� ������ ���� ���̹Ƿ� ��� �ֿ� ���� ���� K���� �˻��ϰ� �� ������ ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : AIPO 2017P 3��
*/

int a[1024];

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == k) r++;
        }
    }
    printf("%d", r);
    return 0;
}
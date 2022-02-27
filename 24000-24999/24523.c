#include <stdio.h>

/*
���� : ���� N(N <= 10^6)�� ���� 10^9 ������ ������ �̷���� �迭�� �־��� ��,
�� �迭�� �� ������ �����ʿ� �ִ� �� �� �� ���� �ٸ� ù ���� ��ȣ�� ���Ѵ�.
���� ��� -1�� ����Ѵ�.

�ذ� ��� : ��͸� ���� ���������� �����̸鼭 ó������ �ٸ� ���� ������ ������ ã��
�� ������ ��� ������ �ִ� ��� ������ �ٲ��ָ� �ȴ�. �̹� ���� �˰� �ִ� ������ ����
������ �ʰ� �Ѿ��.

�ֿ� �˰��� : ���

��ó : ���հ��� 2022 A��
*/

int a[1048576], res[1048576];

int track(int n, int x) {
    if (x >= n - 1) return res[x] = -1;
    else if (a[x + 1] == a[x]) return res[x] = track(n, x + 1);
    else return res[x] = x + 2;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (res[i]) continue;
        track(n, i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
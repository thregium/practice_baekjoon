#include <stdio.h>

/*
���� : N(N <= 10^6)���� ������� ������ ������ ��ȣ(1 <=, <= 10^6)�� ���ϴ� ������ ��ȣ�� �־�����.
�̶�, �� ������� ������ ���Ǹ� ���� �ٲ� �� �ְ�, �̸� ���������� �� �� �ִٸ�
���ϴ� ���Ǹ� ���� �� ���� ����� �ּ� ���� ���Ѵ�.

�ذ� ��� : �� ������� �ڽ� �Ǵ� �ٸ� ����� ������ ���� �� ���� ���� ���ϴ� ��� �ϳ� ���� �� ������
�� �� �ִ�. �̸� �̿��Ͽ� �� ���Ǹ��� ������ ����� ���� ���� ����, ���ϴ� ���ǿ� ��Ī�� �Ǵ� ���
��� ���� 1�� �ٿ�������. �������� ���� ������� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����

��ó : ������ 2021 B��
*/

int cnt[1048576];

int main(void) {
    int n, x, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (cnt[x]) cnt[x]--;
    }
    for (int i = 1; i <= 1000000; i++) {
        r += cnt[i];
    }
    printf("%d", r);
    return 0;
}
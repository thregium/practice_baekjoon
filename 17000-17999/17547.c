#include <stdio.h>

/*
���� : �ڿ��� N(N <= 10^9)�� �־��� ��, �� ���� ������ ���� N�� �Ǵ� �� ���� �ƴ� ������ ���Ѵ�. ���ٸ� impossible�� ����Ѵ�.

�ذ� ��� : �� ���� ���̰� 1�� ��� ������ ���� ��� Ȧ���� ���� �� �ִ�. �� ���� ������ ���� �� ���� �հ� ����,
���� N / 2�� N / 2 + 1�� ���ϸ� �ȴ�. ����, ���̸� 2�� ����� �̸� ���� ��� 4�� ����� ����� ���� �����ϴ�.
�̶��� �� ���� ������ ���� �� ���� ���� 2��� �����Ƿ� N / 4 - 1�� N / 4 + 1�� ���ϸ� �ȴ�. �� ���� ���� �� ������ ����
����� ���� �Ұ����ϴ�.

�ֿ� �˰����� : ����, ������

��ó : BAPC 2019P F��
*/

int main(void) {
    int n;
    scanf("%d", &n);
    if ((n & 3) == 0) {
        printf("%d %d", (n >> 2) + 1, (n >> 2) - 1);
    }
    else if (n & 1) {
        printf("%d %d", (n >> 1) + 1, (n >> 1));
    }
    else printf("impossible");
    return 0;
}
#include <stdio.h>

/*
���� : N(N <= 100000)���� �ߺ����� �ʴ� ������ �־��� ��, �� ������ ���� ���� �� �ִ� ��ǥ���� ������
�����ﰢ���� ���� ���Ѵ�.

�ذ� ��� : ����, �ش� X��ǥ�� Y��ǥ�� ���� ������ ���� �� �ش�. �� ��������, ��� ������ ���� �ش� ������ ����
X��ǥ�� ���� ������ Y��ǥ�� ���� ������ ���� ���� ���ϸ� �ش� ���� �������� �ϴ� �����ﰢ���� ���� �ǹǷ� �� ������ ���� ���ϸ� �ȴ�.

�ֿ� �˰����� : ������, ���շ�

��ó : COCI 07/08#3 4��
*/

int points[103000][2], xposes[103000], yposes[103000];

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
        xposes[points[i][0]]++;
        yposes[points[i][1]]++;
    }
    for (int i = 0; i < n; i++) {
        r += ((long long)xposes[points[i][0]] - 1) * ((long long)yposes[points[i][1]] - 1);
    }
    printf("%lld", r);
    return 0;
}
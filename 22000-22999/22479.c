#include <stdio.h>

/*
���� : ���� N(N <= 50)������ �־��� ��, �� ������ Ư�� ������ 2�� �ڸ� ��, ���ֺ��� �� �߸� ������ ũ�Ⱑ
���� �Ǵ� ���� �ִ� �� ���ϰ�, �ִٸ� �� ���� ����Ѵ�. ���� ��ǥ�� ���� 10^6 ������ �����̴�.

�ذ� ��� : Ȧ�� ������ ��� ������ ������ �� ������ ������ �� �� �ִ�. ¦�� ������ ��쿡��
���ֺ��� �� ���� �����ϰ� ���̰� ���ƾ߸� ������ �����ϰ� �ȴ�. �׷��� ������ ���ֺ��� �� ��������
������ �׾��� �� ���̰� �������� �ʰ� �Ǳ� ������ ������ ������ �� ����.
������ �����ϴ� ��� �� ���� ��ǥ�� ���ֺ��� �� �������� ������ ����.

�ֿ� �˰��� : ������

��ó : JAG 2012S3B C��
*/

long long point[64][2];

long long sqr(long long x) {
    return x * x;
}

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    if (n & 1) {
        printf("NA\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &point[i][0], &point[i][1]);
    }
    point[n][0] = point[0][0], point[n][1] = point[0][1];
    for (int i = 0, j = (n >> 1); j < n; i++, j++) {
        if (sqr(point[i][0] - point[i + 1][0]) + sqr(point[i][1] - point[i + 1][1])
            != sqr(point[j][0] - point[j + 1][0]) + sqr(point[j][1] - point[j + 1][1])) r = 0;
        if ((point[i][0] - point[i + 1][0]) * (point[j][1] - point[j + 1][1]) !=
            (point[j][0] - point[j + 1][0]) * (point[i][1] - point[i + 1][1])) r = 0;
    }
    if (r) printf("%.9f %.9f\n", (point[0][0] + point[n >> 1][0]) / 2.0,
        (point[0][1] + point[n >> 1][1]) / 2.0);
    else printf("NA\n");
    return 0;
}
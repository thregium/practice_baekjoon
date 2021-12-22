#include <stdio.h>

/*
���� : N(N <= 1500)���� ���� �ٸ� ��(|| <= 10^9, ����)�� ��ǥ���� �־��� ��, �ش� ������ �̾� ���� �� �ִ� �����ﰢ���� ������ ���Ѵ�.
(���ѽð� 5��)

�ذ� ��� : ������ ��� �����ﰢ���� ������ ���ϸ� nC3����, ���ѽð� 5�ʸ� �����ϸ� �ð� ���� ���ư� �� �ִ�.
����, ��� �����ﰢ���� �Ÿ��� ������ ���� ��, ��� �ϳ��� �������� �հ� ���� ��츦 ��� ã�Ƴ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������
*/

long long point[1536][2];

int main(void) {
    int n;
    long long r = 0, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &point[i][0], &point[i][1]);
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = i + 1; j < n; j++) {
            for (long long k = j + 1; k < n; k++) {
                a = (point[i][0] - point[j][0]) * (point[i][0] - point[j][0]) + (point[i][1] - point[j][1]) * (point[i][1] - point[j][1]);
                b = (point[j][0] - point[k][0]) * (point[j][0] - point[k][0]) + (point[j][1] - point[k][1]) * (point[j][1] - point[k][1]);
                c = (point[k][0] - point[i][0]) * (point[k][0] - point[i][0]) + (point[k][1] - point[i][1]) * (point[k][1] - point[i][1]);
                if (a == b + c || b == a + c || c == a + b) r++;
            }
        }
    }
    printf("%lld", r);
    return 0;
}
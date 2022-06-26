#include <stdio.h>
#define INF 12345678987654321

/*
���� : N(N <= 2000)���� ���� ��ǥ���� �ִ�. Q(Q <= 250000)���� ������ ����
�� ���� ���γ��� ���̾�׷��� ��� �ش��ϴ� �� �����Ѵ�. (���ѽð� 10��)

�ذ� ��� : ���ѽð��� ����� ��� ������ ��� ���� ���� �Ÿ��� ���� ����
���� ����� ���� ������ ���� ��츦 ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ������, ���Ʈ ����

��ó : KAIST 2018F L��
*/

typedef struct point {
    long long x, y;
} point;

point p[2048];
long long dt[2048];

long long dist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(void) {
    int n, q, bcnt;
    long long best;
    point pp;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &pp.x, &pp.y);
        best = INF, bcnt = 0;
        for (int j = 0; j < n; j++) {
            dt[j] = dist(pp, p[j]);
            if (dt[j] < best) {
                best = dt[j];
                bcnt = 1;
            }
            else if (dt[j] == best) bcnt++;
        }

        if (bcnt == 0) return 1;
        else if (bcnt >= 3) {
            printf("POINT\n");
            continue;
        }
        else if (bcnt == 1) printf("REGION ");
        else printf("LINE ");
        for (int j = 0; j < n; j++) {
            if (dt[j] == best) printf("%d ", j + 1);
        }
        printf("\n");
    }
    return 0;
}
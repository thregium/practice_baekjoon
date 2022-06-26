#include <stdio.h>

/*
���� : N(N <= 100000)���� ������ �̷���� ���� �ٰ���(|X|, |Y| <= 10^8)�� �ִ�.
�� ���� �ٰ����� ���� �ٸ� �� ���� �����ϴ� ������ �׾� ���� �ٰ����� Ż������ ���ϵ��� �ϴ�
����� ���� ���Ѵ�.

�ذ� ��� : ���ϴٰ����� Ż���� �� �ִ� ���� �� ������ �̷�� ���� ū ���� 180�� �̻��� ����̴�.
�� ���� �� �����͸� �̿��� �� ������ �ݽð�������� ���鼭 �̷�� ���� 180���� �Ѵ� ù ������ ���� ����,
�� ������ �� ������ �̴� ����� ���� ���ϸ� �ȴ�.
�� ���� ���� ���� ���� �� ���� ���� �ٸ� ������ �̴� ��� ����� ������ �տ��� ���� ���� ����
Ż���� �� �ִ� ����� ���� �ȴ�.

�ֿ� �˰��� : ������, �� ������, ���շ�

��ó : Latin 2018 E��
*/

typedef struct point {
    long long x, y;
} point;

point p[103000];

long long geteulersum(long long a, long long b) {
    return ((b - a + 1) * (b + a)) >> 1;
}

int ccw(point p1, point p2, point p3) {
    long long int tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
        (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (tri > 0) return 1; //turn left(x->y^)
    else if (tri == 0) return 0;
    else return -1; //turn right
}

point pointplus(point p1, point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

point pointminus(point p1, point p2) {
    p1.x -= p2.x;
    p1.y -= p2.y;
    return p1;
}

int main(void) {
    int e = 1, c;
    long long n, res = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    for (int i = 0; i < n; i++) {
        while (ccw(p[i], p[(i + 1) % n],
            pointplus(pointminus(p[(e + 1) % n], p[e]), p[(i + 1) % n])) >= 0) {
            e = (e + 1) % n;
        }
        c = e - i;
        if (c < 0) c += n;
        if (c > 2) res += geteulersum(1, c - 2);
    }
    res = n * (n - 1) * (n - 2) / 6 - res;
    printf("%lld", res);
    return 0;
}
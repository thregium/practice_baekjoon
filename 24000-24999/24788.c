#include <stdio.h>
#include <math.h>

/*
���� : N(N <= 50)���� ������ �̷���� �ٰ����� �־�����. �� �ٰ����� ũ�⸦ �����Ͽ� ���̰�
A(A <= 10^8)�� �ǰ� �� ��, �� ������ ��ġ���Ѿ� �ϴ� ��ǥ�� ���� ���Ѵ�.
�� ���� ��ǥ�� ���� 500 ������ �Ǽ��̰�, ��ġ���Ѿ� �ϴ� ��ǥ�� ��� ���� �ƴ� �Ǽ����� �Ѵ�.
�׸��� �ּ� �ϳ��� ���� ���� X��� Y�� ���� ��ġ�ؾ� �Ѵ�.

�ذ� ��� : �켱 �ٰ����� �ʿ��� ��ҷ� �ű��. �� ���� �ٰ����� ���̸� ���ؼ� ������ �����Ͽ�
������ ��ġ�� ����ϸ� �ȴ�. �ٰ����� ���̴� ������ ����ϰ�, ������ sqrt(A / ���� ����)�� �Ѵ�.
�� ������ ��ǥ�� �׸�ŭ�� ���ϸ� ������ �������� �� �� �ִ�.

�ֿ� �˰��� : ������, �ٰ����� ����

��ó : VTH 2016 F��
*/

double pos[64][2];

double getarea(int n) {
    double res = 0.0;
    for (int i = 1; i < n; i++) {
        res += pos[i][0] * pos[i - 1][1];
        res -= pos[i][1] * pos[i - 1][0];
    }
    res += pos[0][0] * pos[n - 1][1];
    res -= pos[0][1] * pos[n - 1][0];
    if (res < 0) res *= -1;
    return res / 2.0;
}

int main(void) {
    int n;
    double xl = 103000.0, yl = 103000.0, na, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &pos[i][0], &pos[i][1]);
        if (pos[i][0] < xl) xl = pos[i][0];
        if (pos[i][1] < yl) yl = pos[i][1];
    }
    for (int i = 0; i < n; i++) {
        pos[i][0] -= xl;
        pos[i][1] -= yl;
    }
    na = getarea(n);
    scanf("%lf", &a);
    for (int i = 0; i < n; i++) {
        printf("%.9f %.9f\n", pos[i][0] * sqrt(a / na), pos[i][1] * sqrt(a / na));
    }
    return 0;
}
#include <stdio.h>
#include <math.h>

/*
���� : �� ���� 3���� ��Ʈ�� ������ ���� ��ġ�� �־��� ��, �� ����� ������ ���Ѵ�.

�ذ� ��� : ��Ʈ�� ������ ���� ������ ���ϰ�, �׿� ���� ������ �����Ѵ�. ������ ���� ������ �߽ɰ��� �Ÿ��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ������, ��Ÿ��� ����

��ó : GNY 2004 A��
*/

double getdist(double x, double y) {
    return sqrt(x * x + y * y);
}

int getscore(double x, double y) {
    double dist = getdist(x, y);
    if (dist <= 3) return 100;
    else if (dist <= 6) return 80;
    else if (dist <= 9) return 60;
    else if (dist <= 12) return 40;
    else if (dist <= 15) return 20;
    else return 0;
}

int main(void) {
    int t, a, b;
    double x, y;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        a = 0;
        b = 0;
        for (int i = 0; i < 3; i++) {
            scanf("%lf %lf", &x, &y);
            a += getscore(x, y);
        }
        for (int i = 0; i < 3; i++) {
            scanf("%lf %lf", &x, &y);
            b += getscore(x, y);
        }
        printf("SCORE: %d to %d, ", a, b);
        if (a > b) printf("PLAYER 1 WINS.\n");
        else if (a == b) printf("TIE.\n");
        else printf("PLAYER 2 WINS.\n");
    }
    return 0;
}
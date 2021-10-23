#include <stdio.h>

/*
���� : �ش� ���� ���(����, ����)�� �־�����, �� ���� ��п� ���� ����� �ٲ� Ȯ���� �־��� ��,
N(N <= 100)�� ���� ��п� ���� Ȯ�� ����Ѵ�.

�ذ� ��� : N�ϰ� �� ���� ����� ���� Ȯ���� ������ ������ ����Ѵ�. N���� ������ �� Ȯ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, Ȯ����

��ó : �Ѿ��E 2019M B�� / 2019P B��
*/

int main(void) {
    int n, m;
    double good = 0.0, bad = 0.0, gg, gb, bg, bb, ng, nb;
    scanf("%d %d", &n, &m);
    if (m) bad = 1.0;
    else good = 1.0;
    scanf("%lf %lf %lf %lf", &gg, &gb, &bg, &bb);
    for (int i = 0; i < n; i++) {
        ng = good * gg + bad * bg;
        nb = good * gb + bad * bb;
        good = ng;
        bad = nb;
    }
    printf("%.0f\n%.0f", good * 1000, bad * 1000);
    return 0;
}
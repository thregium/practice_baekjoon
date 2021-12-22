#include <stdio.h>
#include <string.h>
#define RT2 1.414213562373

/*
���� : (X, Y)���� �����Ͽ� N - 1(N <= 100)ȸ�� �̵��� �־��� ��, �����ϴ� ���� ��ġ�� ���Ѵ�.
�� �̵��� ��, ��, ��, ��, �ϵ�, �ϼ�, ����, ���� �� �ϳ��̸� ���� �̵��̴�. �־����� �� ��ǥ�� ���� 0 �̻� 100 ������ �����̴�.

�ذ� ��� : ��, ��, ��, �� �̵��� ���� ��ġ����, X �Ǵ� Y ���� ���ϰų� ���� ������� ������ ���� �� �ִ�.
�� �� ���������� �̵��� ���� ��ġ���� X, Y�� ���� sqrt(2)��ŭ ������ ���ϰų� ���� ������� ���� �� �ִ�.
��� �̵��� �� �� ������ ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ������

��ó : ECRC 2017 PA��
*/

char buff[8];

int main(void) {
    int n;
    double x, y, d;
    scanf("%d%lf %lf", &n, &x, &y);
    for (int i = 1; i < n; i++) {
        scanf("%s %lf", buff, &d);
        if (!strcmp(buff, "N")) y += d;
        else if (!strcmp(buff, "E")) x += d;
        else if (!strcmp(buff, "S")) y -= d;
        else if (!strcmp(buff, "W")) x -= d;
        else if (!strcmp(buff, "NE")) {
            x += d / RT2;
            y += d / RT2;
        }
        else if (!strcmp(buff, "SE")) {
            x += d / RT2;
            y -= d / RT2;
        }
        else if (!strcmp(buff, "SW")) {
            x -= d / RT2;
            y -= d / RT2;
        }
        else if (!strcmp(buff, "NW")) {
            x -= d / RT2;
            y += d / RT2;
        }
        else return 1;
    }
    printf("%.9lf %.9lf", x, y);
    return 0;
}
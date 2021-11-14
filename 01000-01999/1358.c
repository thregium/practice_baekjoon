#include <stdio.h>
#include <math.h>

/*
���� : P(P <= 50)���� ���� ��ġ�� �־��� ��, Ʈ�� ���� �Ǵ� ��迡 �ִ� ���� ������ ���Ѵ�.
Ʈ���� ���簢���� �� ���� �ݿ��� ����� �����̴�.

�ذ� ��� : �� ���� ���� ���簢���� ���� �� �� �� �� �ȿ� �ִ��� ���θ� Ȯ���Ѵ�. �ϳ��� ���ʿ� �ִٸ�
�ȿ� �ִ� ���̰� �� �ܿ��� �ۿ� �ִ� ���̴�. �ȿ� �ִ� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ������, ���̽� ��ũ
*/

int sqr(int x) {
    return x * x;
}

int getdist(int x1, int y1, int x2, int y2) {
    return sqr(x1 - x2) + sqr(y1 - y2);
}

int main(void) {
    int w, h, x, y, p, rad, xx, yy, r = 0;
    scanf("%d %d %d %d %d", &w, &h, &x, &y, &p);
    rad = h / 2;
    for (int i = 0; i < p; i++) {
        scanf("%d %d", &xx, &yy);
        if (getdist(xx, yy, x, y + rad) <= rad * rad) r++;
        else if (getdist(xx, yy, x + w, y + rad) <= rad * rad) r++;
        else if (xx >= x && yy >= y && xx <= x + w && yy <= y + h) r++;
    }
    printf("%d", r);
    return 0;
}
#include <stdio.h>
#include <math.h>

/*
���� : ��ǥ���� ���������� ���� ���·� ������ �þ��� �ִ�. �������� �� ���� ���̴� N�̰�, ������ �� �������� �߽��̸�,
���������� X�࿡ ������ ���·� ���� �ִ�. �̶�, ������ (X1, Y1)���� (X2, Y2)�� �̵��Ϸ��� �Ѵ�. �� ������ ���� ������ �ȿ� �ִٸ�
�� �������� �ٷ� �̵�������, �ٸ� ������ �ȿ� �ִ� ��� �켱 (X1, Y1)�� ��ġ�� �������� �߽����� �̵��� �� �������� �߽ɵ��� ��������
(X2, Y2)�� ��ġ�� �������� �߽ɱ��� �̵��� ���� (X2, Y2)�� �̵��ϰ� �ȴ�. �� ������ �־����� �� �������� ������ �̵��ϴ� �Ÿ��� ���Ѵ�.

�ذ� ��� : �켱 �� �������� � �������� �����ִ����� Ȯ���ؾ� �Ѵ�. Y��ǥ �������δ� ������׷� ��ġ�Ǿ� �ֱ� ������ X��ǥ�� �������� ���캻��.
X��ǥ�� ���� X���� �������� �߽ɿ� �ִ� ����(������ ���� ����)�� �������� ���� �ִ� ����(������ �� �� ������ ���� ����), �� �� �� �� �ִ� ����
(���������� �¹����� ����)���� ���� �� �ִ�. ���� �� ������ ������ ���簢�� �����̹Ƿ� ���� ������ �Ҽӵ� �������� ���� �� �ִ�.
�� ��° ��쿡�� \ ������ �밢������ / ������ �밢�������� ���� �� ��츦 ���� ���� �ش� �밢���� �Ѿ ��� �Ҽӵ� �������� �ٲ���� �Ѵ�.

���� �տ��� ���� �� �������� ���� ������ ��� �� ���� ������ ���� �Ÿ��� ���ϸ� �ȴ�. �ٸ� ������ ��� �켱, �� �������� ���� �� �������� ����
�������� �߽����� ���� ���� �Ÿ��� ���Ѵ�. �� �������� ���� ������ �˸� �߽��� ���ϴ� ���� ������ ���̹Ƿ� ���� ���� �� �ִ�.
�� �������� ���������� �̾ �� ������ ������ �ִ� ��θ� ���ؾ� �Ѵ�. �ִ� ��δ� �켱 �� ������ ������ �������� ���� ���� �� �������� �ִ� �࿡
���� ����� ����� ������ ���� ���� �ุŭ �����̸� �ȴ�.

�ֿ� �˰��� : ������, ���̽� ��ũ

��ó : GNY 2000 B��
*/

typedef struct hex {
    int row;
    int col;
} hex;

hex gethex(double x, double y, double len) {
    double height = len / 2 * sqrt(3);
    hex res;
    double xpos = x / (len * 3) - floor(x / (len * 3));
    double ypos = y / height - floor(y / height);
    if ((xpos < 1.0 / 6) || (xpos > 5.0 / 6)) {
        res.col = floor((x + 1.5) / (len * 3)) * 2;
        res.row = floor((y + height) / (height * 2)) * 2;
    }
    else if ((xpos >= 1.0 / 3) && (xpos <= 2.0 / 3)) {
        res.col = floor(x / (len * 3)) * 2 + 1;
        res.row = floor(y / (height * 2)) * 2 + 1;
    }
    else {
        res.col = floor(x / (len * 1.5));
        if (res.col & 1) res.row = floor(y / (height * 2)) * 2 + 1;
        else res.row = floor((y + height) / (height * 2)) * 2;
        if (((int)floor(y / height) % 2 && xpos >= 2.0 / 3 && ypos > 1 - (xpos * 3 - 2) * 2) || ((int)floor(y / height) % 2 == 0 && xpos <= 1.0 / 3) && ypos > 1 - (xpos * 3 - 0.5) * 2) {
            res.col++;
            res.row++;
        }
        else if (((int)floor(y / height) % 2 && xpos <= 1.0 / 3 && ypos < (xpos * 3 - 0.5) * 2) || ((int)floor(y / height) % 2 == 0 && xpos >= 2.0 / 3) && ypos < (xpos * 3 - 2) * 2) {
            res.col++;
            res.row--;
        }
    }
    return res;
}

double getx(hex a, double len) {
    return a.col * len * 1.5;
}

double gety(hex a, double len) {
    return a.row * len * sqrt(3) / 2;
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double hexdistance(hex a, hex b, double len) {
    double res = len * abs(a.col - b.col) * sqrt(3);
    if (abs(a.row - b.row) > abs(a.col - b.col)) {
        res += len * (abs(a.row - b.row) - abs(a.col - b.col)) * sqrt(3) / 2;
    }
    return res;
}

int main(void) {
    double len, x1, y1, x2, y2, d1, d2, dh;
    while (1) {
        scanf("%lf %lf %lf %lf %lf", &len, &x1, &y1, &x2, &y2);
        if (len == 0) break;
        hex h1 = gethex(x1, y1, len);
        hex h2 = gethex(x2, y2, len);
        d1 = distance(x1, y1, getx(h1, len), gety(h1, len));
        d2 = distance(x2, y2, getx(h2, len), gety(h2, len));
        dh = hexdistance(h1, h2, len);
        if (h1.col == h2.col && h1.row == h2.row) printf("%.3f\n", distance(x1, y1, x2, y2));
        else printf("%.3f\n", d1 + d2 + dh);
    }
    return 0;
}
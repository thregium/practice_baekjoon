#include <stdio.h>

/*
���� : �� x��� y�࿡ ������ ���簢���� ��ǥ�� �� ������ ��ǥ�� �־����� �� �� ���� ������ ������ ������ ����Ѵ�.

�ذ� ��� : ���簢���� ��� ���п� ���� �־��� ���а� ���� ������ �Ѵ�. �Ϲ����� ���� ������ �ణ ������ ������ ������ ���� ��츦 ���� ��ȯ�Ѵ�.
�̶� �ϳ��� ��ġ�� �ʴ� ��� ������ 0��, ������ ���� ������ ��ġ�� ��찡 �ϳ��� �ִٸ� ������ ������ ����,
�����Ǵ� ��찡 1���� ��쿡�� ������ 1���̰�, �����Ǵ� ��찡 2���� ���� �� ������������ ������ ���� ������ 1��, �������� ������ 2���̴�.
�����Ǵ� ��찡 3�� �Ǵ� 4���� �� ���� ������ 2���̴�.

�ֿ� �˰��� : ������, ������ ���� ����
*/

typedef struct square {
     long long int xmin;
     long long int ymin;
     long long int xmax;
     long long int ymax;
} square;

typedef struct dot {
     long long int x;
     long long int y;
} dot;

long long int big(long long a, long long b) {
     return a > b ? a : b;
}

long long int small(long long a, long long b) {
     return a < b ? a : b;
}

int ccw(dot d1, dot d2, dot d3) {
     long long int x1 = d1.x, y1 = d1.y, x2 = d2.x, y2 = d2.y, x3 = d3.x, y3 = d3.y;
     long long int tri = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
     if (tri > 0) return 1;
     else if (tri == 0) return 0;
     else return -1;
}

int dotinline(dot d1, dot d2, dot d3) {
     long long int x1 = d1.x, y1 = d1.y, x2 = d2.x, y2 = d2.y, x3 = d3.x, y3 = d3.y;
     if (ccw(d1, d2, d3)) return 0;
     if (x3 > big(x1, x2) || x3 < small(x1, x2) || y3 > big(y1, y2) || y3 < small(y1, y2)) return 0;
     else if ((x3 == big(x1, x2) || x3 == small(x1, x2)) && (y3 == big(y1, y2) || y3 == small(y1, y2))) return -1;
     else return 1;
}

int crossline(dot d1, dot d2, dot d3, dot d4) {
     int r1 = ccw(d1, d2, d3) * ccw(d1, d2, d4), r2 = ccw(d3, d4, d1) * ccw(d3, d4, d2);
     if (r1 < 0 && r2 < 0) return 1; //���� ��� �� ������ ����
     else if (r1 && r2) return 0; //������ ����
     else if (r1 + r2 == -1) {
          return 16; //�� ���� ���� �ٸ� ���� ����� ����
     }
     else if (r1 + r2 == 1) {
          if (dotinline(d1, d2, d3) || dotinline(d1, d2, d4) || dotinline(d3, d4, d1) || dotinline(d3, d4, d2)) return 256; //�� ���� ���� �ٸ� ���� ���� ����
          else return 0; //������ ����
     }
     else {
          if (!(dotinline(d1, d2, d3) || dotinline(d1, d2, d4) || dotinline(d3, d4, d1) || dotinline(d3, d4, d2))) return 0; //������ ����
          else if (dotinline(d1, d2, d3) + dotinline(d1, d2, d4) + dotinline(d3, d4, d1) + dotinline(d3, d4, d2) == -2) return 256;
          else return 65536; //������ ���� ������ ����
     }
}

int insec(square s, dot d1, dot d2) {
     dot rd1, rd2, rd3, rd4;
     rd1.x = s.xmin, rd1.y = s.ymax;
     rd2.x = s.xmax, rd2.y = s.ymax;
     rd3.x = s.xmin, rd3.y = s.ymin;
     rd4.x = s.xmax, rd4.y = s.ymin;

     int r = crossline(d1, d2, rd1, rd2) + crossline(d1, d2, rd1, rd3) + crossline(d1, d2, rd2, rd4) + crossline(d1, d2, rd3, rd4);

     if (r >= 65536) return 4;
     else if (r == 0) return 0;
     else if (r == 1 || r == 16 || r == 512) {
          return 1;
     }
     else if (r == 32) {
          if (dotinline(d1, d2, rd1) || dotinline(d1, d2, rd2) || dotinline(d1, d2, rd3) || dotinline(d1, d2, rd4)) return 1;
          else return 2;
     }
     else return 2;
}

int main(void) {
     int t;
     square s;
     dot d1, d2;
     scanf("%d", &t);
     for(int i = 0; i < t; i++) {
          scanf("%lld %lld %lld %lld", &s.xmin, &s.ymin, &s.xmax, &s.ymax);
          scanf("%lld %lld %lld %lld", &d1.x, &d1.y, &d2.x, &d2.y);
          printf("%d\n", insec(s, d1, d2));
     }
     return 0;
}
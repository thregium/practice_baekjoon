#include <stdio.h>
#include <math.h>

/*
문제 : 좌표평면상에 육각형들이 벌집 형태로 무한히 늘어져 있다. 육각형의 한 변의 길이는 N이고, 원점은 한 육각형의 중심이며,
육각형들은 X축에 평행한 형태로 놓여 있다. 이때, 벌들이 (X1, Y1)에서 (X2, Y2)로 이동하려고 한다. 두 지점이 같은 육각형 안에 있다면
그 지점으로 바로 이동하지만, 다른 육각형 안에 있는 경우 우선 (X1, Y1)이 위치한 육각형의 중심으로 이동한 뒤 육각형의 중심들을 지나가다
(X2, Y2)이 위치한 육각형의 중심까지 이동한 다음 (X2, Y2)로 이동하게 된다. 각 값들이 주어지면 이 과정에서 벌들이 이동하는 거리를 구한다.

해결 방법 : 우선 각 지점들이 어떤 육각형에 속해있는지를 확인해야 한다. Y좌표 기준으로는 지그재그로 배치되어 있기 때문에 X좌표를 기준으로 살펴본다.
X좌표에 따라서 X축이 육각형의 중심에 있는 구간(원점과 같은 형태)와 육각형의 변에 있는 구간(원점의 양 옆 지역과 같은 형태), 둘 다 될 수 있는 구간
(육각형들이 맞물리는 지역)으로 나뉠 수 있다. 앞의 두 구간은 영역이 직사각형 형태이므로 비교적 간단히 소속된 육각형을 구할 수 있다.
세 변째 경우에는 \ 형태의 대각선인지 / 형태의 대각선인지에 따라 또 경우를 나눈 다음 해당 대각선을 넘어간 경우 소속된 육각형을 바꿔줘야 한다.

만약 앞에서 얻은 두 육각형이 같은 구역인 경우 두 지점 사이의 직선 거리를 구하면 된다. 다른 구역인 경우 우선, 두 지점에서 각각 그 지점들이 속한
육각형의 중심으로 가는 직선 거리를 구한다. 각 육각형이 속한 구역을 알면 중심을 구하는 것은 간단한 편이므로 쉽게 구할 수 있다.
그 다음으로 육각형들을 이어서 두 육각형 사이의 최단 경로를 구해야 한다. 최단 경로는 우선 열 단위로 목적지 육각형이 속한 열에 그 육각형이 있는 행에
가장 가까운 행까지 움직인 다음 남은 행만큼 움직이면 된다.

주요 알고리즘 : 기하학, 케이스 워크

출처 : GNY 2000 B번
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
#include <stdio.h>
#include <stdlib.h>

/*
문제 : 좌표평면상에 10000 이하의 정수로 세 점의 좌표가 주어진다. 이때 세 점으로 만들 수 있는 삼각형이 어느 삼각형인지 구분한다.
정삼각형/예각이등변삼각형/직각이등변삼각형/둔각이등변삼각형/예각삼각형/직각삼각형/둔각삼각형/삼각형이 아님
의 경우가 있다.

해결 방법 : 먼저 CCW 알고리즘을 이용하여 세 점이 일직선상에 위치해있는지 미리 구한다. 일직선인 경우 삼각형이 아니다.
삼각형이 맞다면 세 변의 길이의 제곱을 정렬한 후 가장 긴 변과 나머지 변의 합을 비교해본다.
가장 긴 변이 더 크다면 둔각삼각형이다. 가장 긴 변이 나머지와 같다면 직각삼각형이고, 더 짧다면 예각삼각형이다.
그 다음으로는 두 변의 길이가 같은지 살펴보며 이등변 여부를 찾으면 된다. 정삼각형은 정수 좌표에서 나올 수 없으므로
생각하지 않아도 된다.(sqrt(3)이 무리수이기 때문에)

주요 알고리즘 : 기하학, 케이스 워크
*/

int sides[3];

int sqr(int a) {
    return a * a;
}

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d %d%d %d%d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (ccw(x1, y1, x2, y2, x3, y3) == 0) {
        printf("X");
        return 0;
    }
    sides[0] = sqr(x1 - x2) + sqr(y1 - y2);
    sides[1] = sqr(x2 - x3) + sqr(y2 - y3);
    sides[2] = sqr(x3 - x1) + sqr(y3 - y1);
    qsort(sides, 3, sizeof(int), cmp1);
    if (sides[2] > sides[0] + sides[1]) {
        if (sides[0] == sides[1] || sides[1] == sides[2]) printf("Dunkak2Triangle");
        else printf("DunkakTriangle");
    }
    else if (sides[2] == sides[0] + sides[1]) {
        if (sides[0] == sides[1] || sides[1] == sides[2]) printf("Jikkak2Triangle");
        else printf("JikkakTriangle");
    }
    else {
        if (sides[0] == sides[2]) printf("JungTriangle");
        else if (sides[0] == sides[1] || sides[1] == sides[2]) printf("Yeahkak2Triangle");
        else printf("YeahkakTriangle");
    }
    return 0;
}
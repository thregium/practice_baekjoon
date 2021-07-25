#include <stdio.h>

/*
문제 : 직육면체의 길이, 너비, 높이, 부피 중 하나가 나오지 않았을 때, 나오지 않은 하나를 포함한 4개의 값을 구한다.

해결 방법 : 나오지 않은 값을 확인하고 계산하면 된다. 부피는 나머지 3개를 곱하면 되고, 나머지는 부피에서 나온 2개를 나누면 된다.

주요 알고리즘 : 수학

출처 : NZPC 2009 B번
*/

int main(void) {
    int l, w, h, v;
    while (1) {
        scanf("%d %d %d %d", &l, &w, &h, &v);
        if (l == 0 && w == 0 && h == 0 && v == 0) break;
        if (v == 0) printf("%d %d %d %d\n", l, w, h, l * w * h);
        else if (h == 0) printf("%d %d %d %d\n", l, w, v / l / w, v);
        else if (w == 0) printf("%d %d %d %d\n", l, v / l / h, h, v);
        else printf("%d %d %d %d\n", v / w / h, w, h, v);
    }
    return 0;
}
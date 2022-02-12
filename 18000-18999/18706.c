#include <stdio.h>
#include <string.h>

/*
문제 : C(C <= 100)가지 커피에 대해 사이즈별 가격이 주어질 때, P(P <= 100)명의 각 사람이 주문한 커피에 대한
최종 금액을 구한다. 배송비는 100$ / P를 버림한 값이고, 1$을 올리거나 내려서 5의 배수가 되는 경우
5의 배수로 맞추어 둔다.

해결 방법 : 각 커피의 이름과 사이즈별 가격을 저장한 다음, 주문에 따라 해당하는 커피를 찾고,
사이즈에 맞는 커피의 가격에 배송비를 더한 값을 구한다. 그런 다음 5의 배수로 맞출 수 있으면 맞춘 후
금액을 출력하면 된다.

주요 알고리즘 : 구현, 브루트 포스, 문자열

출처 : Arab 2018 C번
*/

char cof[128][32], per[32], csz[32], cfn[32];
int price[128][4];

int main(void) {
    int t, c, p, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &c, &p);
        for (int i = 0; i < c; i++) {
            scanf("%s", cof[i]);
            for (int j = 0; j < 3; j++) {
                scanf("%d", &price[i][j]);
            }
        }
        for (int i = 0; i < p; i++) {
            scanf("%s %s %s", per, csz, cfn);
            r = 100 / p;
            for (int j = 0; j < c; j++) {
                if (!strcmp(cfn, cof[j])) {
                    if (!strcmp(csz, "small")) r += price[j][0];
                    else if (!strcmp(csz, "medium")) r += price[j][1];
                    else if (!strcmp(csz, "large")) r += price[j][2];
                    else return 1;
                    break;
                }
            }
            if (r % 5 == 1) r--;
            else if (r % 5 == 4) r++;
            printf("%s %d\n", per, r);
        }
    }
    return 0;
}
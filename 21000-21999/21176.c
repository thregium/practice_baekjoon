#include <stdio.h>

/*
문제 : R(R <= 100000)가지 레시피와 K(K <= 100000)가지 재료가 있다.(R * K <= 100000)
이때, 각 재료의 남은 수량과 각 레시피의 사용하는 재료 수 및 가격이 주어질 때,
레시피 1가지만으로 얻을 수 있는 최대 매출액을 구한다. 남은 수량, 재료 수, 가격은 모두 10000 이하다.
또한, 모든 레시피에는 1개 이상의 재료를 사용한다.

해결 방법 : 각 레시피마다 재료를 최대 얼마나 사용 가능한 지 확인한다.
그리고 만들 수 있는 최대량을 구하고 이 값과 가격의 곱이 가장 작은 것을 찾으면 된다.
단, 0으로 나누지 않도록 주의한다.

주요 알고리즘 : 그리디 알고리즘

출처 : MidC 2020 O번
*/

int amount[103000];

int main(void) {
    int k, r, best = 0, smlst, usg, price;
    scanf("%d %d", &k, &r);
    for (int i = 0; i < k; i++) {
        scanf("%d", &amount[i]);
    }
    for (int i = 0; i < r; i++) {
        smlst = 10000;
        for (int j = 0; j < k; j++) {
            scanf("%d", &usg);
            if (usg == 0) continue;
            if (amount[j] / usg < smlst) smlst = amount[j] / usg;
        }
        scanf("%d", &price);
        if (smlst * price > best) best = smlst * price;
    }
    printf("%d", best);
    return 0;
}
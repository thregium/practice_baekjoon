#include <stdio.h>

/*
문제 : M(M <= 20)마리의 숫소와 F(F <= 20)마리의 암소에 대해 각각의 DNA 일부가 25자씩 주어진다. 만약 어떠한 소의 DNA가
모든 염기에 대해 부모 소 가운데 한 마리의 염기와 같다면 그 소는 부모의 자식일 가능성이 있다고 한다면,
모든 부모의 쌍에 대해 부모의 자식일 가능성이 있는 소가 몇 마리인지 구한다.
물론 부모 소 자체는 자식 소가 될 수 없다.

해결 방법 : 각 부모 소의 쌍마다 모든 소들에 대해 자식 소가 될 수 있는지 확인한다.
자식 소가 될 수 있는 조건은 부모 소 자신이 아니며 모든 DNA의 염기가 부모 소의 해당 염기 중 하나일 때이다.

주요 알고리즘 : 구현, 문자열

출처 : USACO 2010J B1번
*/

char bull[32][32], cow[32][32];

int main(void) {
    int m, f, c, t;
    scanf("%d %d", &m, &f);
    for (int i = 0; i < m; i++) {
        scanf("%s", bull[i]);
    }
    for (int i = 0; i < f; i++) {
        scanf("%s", cow[i]);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < f; j++) {
            c = 0;
            for (int k = 0; k < m; k++) {
                //각 수컷에 대해
                if (k == i) continue;
                t = 1;
                for (int l = 0; bull[k][l]; l++) {
                    if (bull[k][l] != bull[i][l] && bull[k][l] != cow[j][l]) {
                        t = 0;
                        break;
                    }
                }
                c += t;
            }
            for (int k = 0; k < f; k++) {
                //각 암컷에 대해
                if (k == j) continue;
                t = 1;
                for (int l = 0; cow[k][l]; l++) {
                    if (cow[k][l] != bull[i][l] && cow[k][l] != cow[j][l]) {
                        t = 0;
                        break;
                    }
                }
                c += t;
            }
            printf("%d ", c);
        }
        printf("\n");
    }
    return 0;
}
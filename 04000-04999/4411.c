#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)명의 사람들이 여행 경비로 사용한 돈(<= 10^6) 센트 가 주어질 때,
모든 사람의 돈 차이를 1센트 이내로 만들 기 위해 옮겨야 하는 돈의 최솟값을 구한다.

해결 방법 : 우선 나머지를 버림한 후 최대한 돈을 옮긴다. 그 다음 돈이 평균 이상인 사람들에 대해
최대한 나머지 돈을 옮기고, 나머지는 다시 옮기면 된다. 전체 옮긴 돈의 절반이 답이 된다.

주요 알고리즘 : 수학, 그리디 알고리즘

출처 : Waterloo 19990131 A번
*/

int mon[1024];

int main(void) {
    int n, dol, cen, sum, ave, rem;
    //freopen("E:\\PS\\Contest\\waterloo\\19990131\\A.3.dat", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d.%d", &dol, &cen);
            mon[i] = dol * 100 + cen;
            sum += mon[i];
        }
        //if (sum % n) return 1;
        ave = sum / n;
        rem = sum % n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += abs(mon[i] - ave);
        }
        for (int i = 0; i < n; i++) {
            if (rem > 0 && mon[i] > ave) {
                sum--;
                rem--;
            }
        }
        sum += rem;
        if (sum & 1) return 2;
        sum >>= 1;
        printf("$%d.%02d\n", sum / 100, sum % 100);
    }
    return 0;
}
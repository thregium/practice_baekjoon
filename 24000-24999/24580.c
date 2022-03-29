#include <stdio.h>

/*
문제 : H * W(H * W <= 64) 크기의 직사각형 모양인 땅이 있다. 각 땅에 쓰인 수는 0, 1, 2 중 하나이다.
이때, 이 땅을 두 개의 연결 요소로 분할하고 나온 두 연결 요소에 쓰인 수의 곱의 차가 최소가 되도록
만들려고 한다. 그때의 곱의 차를 구한다.

해결 방법 : 0이 2개 이상 있는 경우 양쪽에 0을 1개씩 분배하는 것이 항상 가능하기 때문에 답은 0이 된다.

0이 한 개도 없다면 모든 수는 1 또는 2일 것이다. 2의 개수를 최대한 균등하게 분배하는 것이 가능하므로
최대한 균등하게 분배한다면 2의 개수가 짝수인 경우 답은 0이고, 홀수인 경우에는 2^(2의 개수 / 2)이다.

0이 1개만 있는 경우에는 1이 1개도 없다면 답은 2가 된다(2와 나머지). 1이 있는 경우에는 1과 나머지 부분으로
나누면 답이 1이 된다. 단, H나 W의 값이 1이고 양쪽 끝 중 하나가 1이 아니라면 1이 중간에 있더라도
1과 나머지 부분으로 나눌 수 없기 때문에 답은 2가 된다.

주요 알고리즘 : 수학, 케이스 워크

출처 : MidAtl 2021 D번 // NCNA 2021 E번
*/

int x[64][64];

int main(void) {
    int h, w, zero = 0, one = 0, two = 0;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &x[i][j]);
            if (x[i][j] == 0) zero++;
            else if (x[i][j] == 1) one++;
            else if (x[i][j] == 2) two++;
            else return 1;
        }
    }

    if (zero == 0) {
        if (two & 1) printf("%lld", 1LL << (two >> 1));
        else printf("0");
    }
    else if (zero == 1) {
        if (one > 0) {
            if (h == 1) {
                if (x[0][0] != 1 && x[0][w - 1] != 1) printf("2");
                else printf("1");
            }
            else if (w == 1) {
                if (x[0][0] != 1 && x[h - 1][0] != 1) printf("2");
                else printf("1");
            }
            else printf("1");
        }
        else printf("2");
    }
    else printf("0");
    return 0;
}
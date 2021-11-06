#include <stdio.h>

/*
문제 : 자연수로 된 구간 [S, F](S, F <= 2 * 10^9)에서 이진수로 표현했을 때 1의 개수가 0의 개수보다 많지 않은 수의 개수를 구한다.

해결 방법 : X보다 작은 수에 대해 1의 개수가 0의 개수보다 많지 않은 수는 (자릿수가 X의 자릿수보다 적은 수 가운데 그러한 수) + 
(X의 수와 같은 수에서 그러한 수이다.) 전자는 조합을 통해 C(자릿수, 1의 개수)를 계산해 구할 수 있고,
후자는 이진수로 2번째 1부터 1을 볼 때 마다 그 수를 0으로 하고 나머지 수들을 배치했을 때
조건을 만족하는 수의 개수를 조합을 통해 세서 구할 수 있다.
위 값을 구했으면 누적 합을 이용해 f + 1의 함숫값에서 s의 함숫값을 빼면 답이 된다.

주요 알고리즘 : 수학, 조합론

출처 : USACO 2006N S3번
*/

int comb[32][32], tmp[32];

int getround(int x) {
    //X 미만에서 조건을 만족하는 수의 개수
    int ones = 1, len = 0, t = 0, r = 0;
    for (int y = x; y; y >>= 1, len++) tmp[len] = (y & 1);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        t = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = t;
    } //X를 이진수 형태로 만들어둔다.
    for (int i = 1; i < len - 1; i++) {
        for (int j = 0; j * 2 < i; j++) r += comb[i][j]; //X보다 자릿수가 작은 수들 가운데 조건을 만족하는 수의 개수를 구한다.
    }
    
    for (int i = 1; i < len; i++) {
        if (tmp[i]) {
            //두 번째 이후 자리가 1인 경우
            for (int j = 0; (ones + j) * 2 <= len; j++) {
                r += comb[len - i - 1][j]; //해당 자리를 0으로 하고 조건을 만족하는 수의 개수를 구한다.
            }
            ones++;
        }
    }
    
    return r; //위에서 구한 수의 합을 반환한다.
}

int main(void) {
    int s, f;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if (i == 0) comb[i][j] = !j;
            else if (j == 0) comb[i][j] = 1;
            else comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1]; //32 이하의 수에 대해 조합을 구한다.
        }
    }
    scanf("%d %d", &s, &f);
    /*
    for (int i = s; i <= f; i++) {
        //printf("%d : %d\n", i, getround(i));
        if (getround(i) > getround(i - 1)) {
            printf("round number: %d -> ", i - 1);
            for (int j = i - 1; j; j >>= 1) printf("%d", j & 1);
            printf("\n");
        }
    }
    */
    printf("%d", getround(f + 1) - getround(s)); //누적 합을 이용해 위의 함숫값으로 답을 구한다.
    return 0;
}
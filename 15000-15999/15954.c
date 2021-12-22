#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 500)개의 인형이 있다. 각 인형의 선호도(<= 10^6, 음이 아닌 정수)가 주어질 때, 연속한 K(1 <= K <= N)개 이상의
인형 중 선호도의 표준편차가 가장 작은 것을 뽑았을 때의 표준편차를 구한다.

해결 방법 : 브루트 포스로 모든 경우를 확인해 보면 된다. 이때, 실수 오차가 크기 때문에 long double을 써야 함에 유의한다.

주요 알고리즘 : 수학, 브루트 포스

출처 : 카카오코페 2018예 B번
*/

int fav[512];

int main(void) {
    int n, k;
    long long sum;
    long double best = 9E+40, ave, sum2;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &fav[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + k - 1; j < n; j++) {
            sum = 0;
            for (int ii = i; ii <= j; ii++) {
                sum += fav[ii];
            }
            ave = (long double)sum / (j - i + 1);
            sum2 = 0;
            for (int ii = i; ii <= j; ii++) {
                sum2 += (fav[ii] - ave) * (fav[ii] - ave);
            }
            sum2 /= (j - i + 1);
            if (sum2 < best) {
                best = sum2;
            }
        }
    }
    printf("%.9Lf", sqrtl(best));
    return 0;
}
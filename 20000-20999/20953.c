#include <stdio.h>

/*
문제 : 자연수 A와 B(A, B <= 777)가 주어질 때, 문제에 주어진 코드의 실행 결과를 구한다. (코드 생략)

해결 방법 : 항상 A와 B를 더해서 쓰므로 A와 B의 합만 보면 된다. 그 다음, 0부터 j까지의 합은 j로 바꿀 수 있다.
또한, 가장 바깥에 있는 i 루프도 A와 B의 합을 곱하여 더하는 것으로 바꾸면 O((A+B)^2)에 전처리가 가능하고,
각 A + B에 대한 답을 배열에 저장해두면 주어진 범위의 A와 B에 대해 답을 구해낼 수 있다.

주요 알고리즘 : 수학

출처 : 강원대 1회 A번
*/

int mem[2048];

int main(void) {
    int t, a, b;
    for (int s = 2; s <= 777 * 2; s++) {
        for (int j = 0; j < s; j++) {
            mem[s] += j * s;
        }
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", mem[a + b]);
    }
    return 0;
}

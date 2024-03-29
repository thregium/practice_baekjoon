#include <stdio.h>

/*
문제 : 두 정수 A, A'가 주어질 때(-2^31 <= A, A' < 2^31), A를 정수의 곱으로 만든 후 해당하는 정수들의 합으로
A'를 만들 수 있는지 구한다.

해결 방법 : 만약 A가 0이라면 어떠한 정수를 곱해도 0이기 때문에 적절히 정수를 곱하면 A'를 항상 만들 수 있다.
A가 양수인 경우에는 1을 곱하면 항상 값이 같고 -1을 2번 곱해도 항상 값이 같다는 점을 이용해 A'를 만들 수 있다.
음수인 경우에도 매우 비슷하지만 -1을 홀수번 곱한다는 점만이 다를 뿐이다.
따라서 A가 어떠한 정수인 경우에도 A'를 만들 수 있다.

주요 알고리즘 : 수학
*/

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        printf("yes\n");
    }
    return 0;
}
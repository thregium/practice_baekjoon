#include <stdio.h>

/*
문제 : N(N <= 30)개의 자연수로 이루어진 배열에서 문제에 주어진 코드의 출력이 주어지면,
그 출력을 만드는 입력을 출력한다.

해결 방법 : 주어진 코드를 분석해 보면 각 배열의 원소를 출력한 후 그 원소의 번호만큼 뒤의 원소를
보는 것을 반복하는 코드임을 알 수 있다. 단, 이 과정에서 한 번 본 원소가 나오면 다음 원소를 봐야 한다.
이 과정을 역순으로 옮겨 적으면 출력과 입력을 바꿀 수 있다.

주요 알고리즘 : 애드 혹?

출처 : 정올 2013 초3/중2번
*/

int a[32], b[32];

int main(void) {
    int n, pos = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        while (b[pos] != 0) pos = (pos + 1) % n;
        b[pos] = a[i];
        pos = (pos + a[i]) % n;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}
#include <stdio.h>

/*
문제 : M(M <= 500000)개의 쿼리에 응답한다. 시작시 수열은 빈 상태다.
1. 수열에 수 X를 추가한다.
2. 수열에서 수 X 한 개를 제거한다. 제거한 수는 수열에 있었음이 보장된다.
3. 수열의 모든 수를 더한 값을 구한다.
4. 수열의 모든 수를 XOR한 값을 구한다.

해결 방법 : 수열의 각 수가 무엇인지는 별로 중요하지 않으므로 모든 수의 합과 XOR 값을 저장해놓고 추가, 삭제시마다 업데이트해준다.
수가 추가되는 경우에는 합에 X를 더하고 XOR에 X를 XOR해주면 되고, 제거되는 경우에는 합에서 X를 빼고 XOR에 X를 XOR해주면 된다.

주요 알고리즘 : 수학, 누적 합
*/

int main(void) {
    int m, o, x;
    long long xor = 0, sum = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &o);
        switch (o) {
        case 1:
            scanf("%d", &x);
            xor ^= x;
            sum += x;
            break;
        case 2:
            scanf("%d", &x);
            xor ^= x;
            sum -= x;
            break;
        case 3:
            printf("%lld\n", sum);
            break;
        case 4:
            printf("%lld\n", xor);
            break;
        }
    }
    return 0;
}
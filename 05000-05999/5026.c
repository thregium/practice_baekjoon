#include <stdio.h>

/*
문제 : 주어진 수식이 a + b 형태인지 P=NP인지 확인하고, P=NP라면 skipped, a + b라면 그 수식의 답을 출력한다.

해결 방법 : 수식을 문자열 형태로 입력받은 다음, P=NP라면 skipped를 출력하면 되고,
a + b라면 sscanf를 통해 a, b의 값을 알아내서 a + b를 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : NCPC 2010 F번
*/

char prob[16];

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", prob);
        if (prob[0] == 'P') printf("skipped\n");
        else {
            sscanf(prob, "%d+%d", &a, &b);
            printf("%d\n", a + b);
        }
    }
    return 0;
}
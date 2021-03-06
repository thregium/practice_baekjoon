#include <stdio.h>

/*
문제 : 10^6자리 이하 수가 주어질 때, 이 수의 모든 자릿수를 몇 번 더해야 한 자리 수가 되는지 확인하고,
한 자리 수가 되면 3으로 나누어떨어지는지 구한다.

해결 방법 : 먼저, 주어진 수가 한 자리 수인지 구한다. 한 자리 수라면 미리 0을 출력하고 결과를 확인해 프로그램을 종료하고,
아니라면 문자열의 각 자리 수를 전부 더한다. 이제 이 더한 값이 한 자리 수가 될 때 까지 모든 자리 수를 더하는 과정을 반복하다가
한 자리 수가 되면 그때까지 연산 횟수와 그 수가 3의 배수인지 확인한 결과를 출력하면 된다.

주요 알고리즘 : 수학, 문자열
*/

char s[1048576];

int main(void) {
    int sum = 0, len = 0, cnt = 1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        sum += s[i] - '0';
        len = i + 1;
    }
    if (len == 1) {
        printf("0\n"); //이미 한 자리 수이므로 더할 필요가 없다.
        if (sum % 3 == 0) printf("YES");
        else printf("NO");
        return 0;
    }
    while (sum >= 10) {
        sum = (sum / 1000000 + sum / 100000 % 10 + sum / 10000 % 10 + sum / 1000 % 10 + sum / 100 % 10 + sum / 10 % 10 + sum % 10);
        cnt++; //각 자리 수를 더하고 합을 한 횟수 카운트를 1 늘린다.
    }
    printf("%d\n", cnt);
    if (sum % 3 == 0) printf("YES");
    else printf("NO");
    return 0;
}
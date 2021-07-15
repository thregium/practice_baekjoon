#include <stdio.h>
#include <string.h>

/*
문제 : 3 * 10^6자 이하의 0 ~ 9로 이루어진 수가 주어진다. 이 수를 B진법으로 나타내었을 때, 1이나 B가 아니면서
B의 약수가 되는 X와 B의 쌍을 구한다.

해결 방법 : 먼저, 한 자리 수인 경우에는 직접 처리해준다. 그 다음으로 2자리 이상의 수인 경우에는
각 자릿수의 합을 이용한다. 자릿수의 합을 S라 한다면 S + 1진법 수는 항상 S로 나눌 수 있음을 통해 S + 1과 S를 출력하면 된다.

주요 알고리즘 : 수학, 정수론, 구성적

출처 : NWRRC 2019Q G번
*/

char s[3145728];

int main(void) {
    int sum = 0;
    scanf("%s", s);
    int len = strlen(s);
    if (len == 1) {
        if (s[0] == '4' || s[0] == '6' || s[0] == '8') printf("9 2");
        else if (s[0] == '9') printf("103000 3");
        else printf("-1");
    }
    else {
        if ((s[len - 1] - '0') & 1) {
            for (int i = 0; i < len; i++) sum += s[i] - '0';
            printf("%d %d", sum + 1, sum);
        }
        else printf("10 2");
    }
    return 0;
}
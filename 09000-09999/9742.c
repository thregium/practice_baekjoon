#include <stdio.h>
#include <string.h>

/*
문제 : 길이 10 이하의 사전순으로 된 순열이 주어지고, 10! 이하의 자연수가 주어질 때, 해당하는 번째의 순열이 있는지 구하고
있다면 그러한 순열을 출력한다.

해결 방법 : 먼저 순열의 길이를 확인한다. 만약 길이를 L이라 했을 때 주어진 자연수가 L!보다 큰 경우 그러한 순열을 만들 수 없다.
그 이하인 경우 순열을 만들 수 있다. 첫 글자부터 확인했을 때, 해당 번째에 출력할 문자는 N / (L - i)!를 L - i로 나눈 나머지번째
문자이다. 단, 이러한 번째에서 앞에 사용한 문자가 들어가서는 안 된다.

주요 알고리즘 : 수학, 조합론

출처 : Phili 2013 J번
*/

char perm[16], chk[16];
int fact[16];

int main(void) {
    int n, l;
    fact[0] = 1;
    for (int i = 1; i <= 10; i++) fact[i] = fact[i - 1] * i;
    while (scanf("%s %d", perm, &n) != EOF) {
        l = strlen(perm);
        for (int i = 0; i <= l; i++) chk[i] = 0;
        printf("%s %d = ", perm, n);
        n--;
        if (n >= fact[l]) {
            printf("No permutation\n");
            continue;
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (chk[j]) continue; //이미 사용한 문자는 넘어간다.
                if (n >= fact[l - i - 1]) n -= fact[l - i - 1]; //해당 문자로 시작하지 않는 경우\
                해당 문자로 시작하는 순열의 개수만큼을 넘긴다.
                else {
                    printf("%c", perm[j]); //해당 문자로 시작하는 경우 해당 문자를 체크하고 해당 문자를 출력한 다음\
                    다음 문자로 넘어간다.
                    chk[j] = 1;
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
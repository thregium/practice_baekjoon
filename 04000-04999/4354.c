#include <stdio.h>

/*
문제 : 길이 10^6 이하의 알파벳 소문자로 이루어진 문자열이 주어질 때, 이 문자열의 최대 반복 횟수를 구한다.

해결 방법 : 길이의 약수가 되는 단위를 지금까지 중 최소 길이까지 확인해 나가는 것을 반복하며 같은 지 확인해 나간다.
이를 반복하여 최소 길이에서의 반복 횟수를 구하면 답이 된다.

주요 알고리즘 : 수학, 정수론, 문자열

출처 : Waterloo 20020601 D번
*/

char s[1048576];

int main(void) {
    int j, m, n;
    //freopen("E:\\PS\\Contest\\waterloo\\20020601\\data\\D.0.dat", "r", stdin);
    while (1) {
        fgets(s, 1030000, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (!strcmp(s, ".")) break;
        n = strlen(s);
        m = n;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                for (j = 0; j < m - m / i && s[j] == s[j + m / i]; j++);
                if (j == m - m / i) m /= i;
            }
        }
        printf("%d\n", strlen(s) / m);
    }
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^6)개의 2 이상 5 * 10^6 이하의 자연수가 주어질 때, 주어지는 각 자연수들을 소인수분해한 결과를 출력한다.

해결 방법 : 에라토스테네스의 체를 이용한다. 5 * 10^6 이하의 모든 수마다 소인수분해한 결과를 미리 저장해둔 다음,
수가 입력될 때 마다 해당하는 결과를 출력한다. 입출력 시간을 줄이기 위해 파싱을 일부 해야 한다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스, 파싱

출처 : 서강대 2018M C번
*/

int sieve[5242880][24];
char buff[16777216], buff2[1024], buff3[1024];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int n, x, kk;
    char* c;
    for (int i = 2; i <= 5000000; i++) {
        if (sieve[i][0]) continue;
        for (int j = i; j <= 5000000; j += i) {
            for (int k = j; k % i == 0; k /= i) sieve[j][++sieve[j][0]] = i;
        }
    }
    fgets(buff, 128, stdin);
    n = strtoll(buff, NULL, 10);
    fgets(buff, 16777215, stdin);
    for (int i = 0; i < n; i++) {
        if (i == 0) c = strtok(buff, " ");
        else c = strtok(NULL, " ");
        if (c == NULL) return 1;
        x = strtoll(c, NULL, 10);
        strcpy(buff2, "");
        for (int j = 1; j <= sieve[x][0]; j++) {
            kk = 0;
            for (int k = sieve[x][j]; k; k /= 10, kk++) buff3[kk] = k % 10 + '0';
            buff3[kk] = '\0';
            for (int s = 0, e = strlen(buff3) - 1; s < e; s++, e--) swap(&buff3[s], &buff3[e]);
            buff3[kk] = ' ';
            buff3[kk + 1] = '\0';
            strcat(buff2, buff3);
        }
        printf("%s\n", buff2);
    }
    return 0;
}
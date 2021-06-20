#include <stdio.h>
#include <string.h>

/*
문제 : 2000자 이하의 문자열이 주어질 때, 해당 문자열을 최소 개수의 회문으로 나누었을 때의 회문 개수를 구한다.

해결 방법 : 문자열의 모든 문자에 대해 회문의 중심을 잡은 다음 해당 문자를 중심으로 하는 회문들을 전부 구한다.
해당 문자부터 시작해 주변을 탐색해 나가며 양 끝이 서로 다른 문자가 되기 전까지의 모든 문자열을 회문으로 기록해두면 된다.
이를 문자가 홀수개인 경우와 짝수개인 경우로 나누어 진행한다.

모든 회문에 대한 검사가 끝나면 문자열의 첫 문자부터 차례로 읽어나가며 해당 문자까지는 최소 몇 개의 회문이 필요한지를 저장한다.
첫 문자의 경우 반드시 1개이며, 이후 문자의 경우 이전 문자 + 1개에서 시작해 만약 보고 있는 문자로 끝나는 회문이 존재하는 경우
(해당 회문의 이전 문자 + 1)개 가운데 가장 작은 값이 된다. 특히 첫 문자부터 해당 문자까지가 전부 회문이라면 필요한 회문은 1개가 된다.
이를 문자열의 끝까지 반복하여 마지막 문자에서 나온 값이 답이 된다.

주요 알고리즘 : DP

출처 : CHCI 2001RS 4번
*/

char s[2560];
int pals[2560][2560], mem[2560];

int main(void) {
    int n;
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        pals[i][i] = 1;
        for (int j = i, k = i; j >= 0 && k < n; j--, k++) {
            if (s[j] != s[k]) break;
            pals[j][k] = 1;
        }
        if (s[i] != s[i + 1]) continue;
        for (int j = i, k = i + 1; j >= 0 && k < n; j--, k++) {
            if (s[j] != s[k]) break;
            pals[j][k] = 1;
        }
    }
    mem[0] = 1;
    for (int i = 1; i < n; i++) {
        mem[i] = mem[i - 1] + 1;
        for (int j = 1; j < i; j++) {
            if (pals[j][i]) {
                if (mem[j - 1] + 1 < mem[i]) mem[i] = mem[j - 1] + 1;
            }
        }
        if (pals[0][i]) mem[i] = 1;
    }
    printf("%d", mem[n - 1]);
    return 0;
}
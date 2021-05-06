#include <stdio.h>
#include <string.h>

/*
문제 : 25자리 이내의 수 N이 주어진다. 제곱해서 이 수를 만들 수 있는 수가 있는지 확인하고 있다면 하나를 출력한다.
단, 여기서 제곱은 모든 과정에서 올림을 하지 않는다. 예를 들어 765 * 765 = (92500 + 2600 + 505) = 94605가 된다.

해결 방법 : 먼저 N의 자릿수를 본다. 자릿수가 짝수인 경우에는 제곱근을 만들 수 없다.
N이 홀수인 경우에는 제곱근의 자릿수를 알 수 있는데, (N + 1) / 2과 같다.
제곱수를 만드는 방법을 살펴보면 맨 앞자리부터 해당 자리수까지 곱해봤을 때 X번째 자릿수가 N의 X번째 자릿수와 같게 나오는지 보면 된다.
그것이 가능해지는 수는 자릿수마다 2개씩 존재하므로 최대 2^13가지 경우의 수를 확인해보면 되고,
이는 충분히 시간 내에 풀 수 있는 양이다.

주요 알고리즘 : 수학, 백트래킹

출처 : PacNW 2019 L번/Y번 // SEUSA 2019D1 A번 // SEUSA 2019D2 B번
*/

char n[32], root[16];
int ans = 0;

void track(int x, int y) {
    if (x == y) {
        //실제로 제곱해봐서 N과 같은지 확인한다.
        int tmp[32] = { 0, };
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < y; j++) {
                tmp[i + j] = (tmp[i + j] + root[i] * root[j]) % 10;
            }
        }
        for (int i = 0; i < x * 2 - 1; i++) {
            if (tmp[i] != n[i]) return;
        }
        ans = 1;
        return;
    }
    int sum = 0;
    for (int i = 1; i < y; i++) {
        sum += root[i] * root[y - i];
    }
    for (int i = 0; i < 10; i++) {
        root[y] = i;
        if ((sum + (1 + !!y) * i * root[0]) % 10 != n[y]) continue; //Y번째 숫자를 N과 같게 만들 수 있는지 확인해본다.
        track(x, y + 1);
        if (ans) return;
    }
}

int main(void) {
    scanf("%s", n);
    int len = strlen(n);
    if (!(len & 1)) {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < len; i++) n[i] -= '0';
    track((len >> 1) + 1, 0);
    if (!ans) {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < (len >> 1) + 1; i++) {
        printf("%c", root[i] + '0');
    }
    return 0;
}
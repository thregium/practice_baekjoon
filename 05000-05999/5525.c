#include <stdio.h>

/*
문제 : 길이 M(M <= 10^6)인 문자열에서 (I 뒤에 OI가 n회 붙은 An(n * 2 - 1 <= M))이 등장하는 횟수를 구한다.

해결 방법 : IOI가 반복되는 동안 OI가 몇 회 나왔는지 센다. 반복이 끝나면 센 값을 바탕으로 An이 해당 반복에서 몇 번 나올 수 있는지 알아본다.
만약 반복이 n보다 작다면 한 번도 나올 수 없고, n 이상이라면 (반복 횟수) - n + 1회 나올 수 있다.
이를 반복하여 문자열 끝까지 나오는 An의 횟수를 센 다음 마지막으로 반복이 끝났다고 가정하고 다시 횟수를 세 준 다음 지금까지의 값들을 모두 더해주면 된다.

주요 알고리즘 : 문자열, 수학

출처 : JOI 2009 1번 / 2013 P4번 / 2014 P4번
*/

char s[1048576];

int main(void) {
    int n, m, cnt = 0, counting = 0;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 2; i < m; i++) {
        if (counting == 0 && s[i] == 'I' && s[i - 1] == 'O' && s[i - 2] == 'I') {
            counting = 1;
            i++;
        }
        else if (counting && s[i] == 'I' && s[i - 1] == 'O') {
            counting++;
            i++;
        }
        else if (counting) {
            if (counting >= n) cnt += counting - n + 1;
            counting = 0;
        }
    }
    if (counting >= n) cnt += counting - n + 1;
    printf("%d", cnt);
    return 0;
}
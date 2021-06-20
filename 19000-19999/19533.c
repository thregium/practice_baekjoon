#include <stdio.h>

/*
문제 : 길이 문자열 가운데 길이가 a(a <= 10^9) * 10^b(b <= 10^6)인 것을 찾는다. 단, a * 10^b가 20보다 큰 경우 앞 17자만 출력한다.
길이 문자열은 -과 수가 번갈아가며 등장하며, 등장하는 모든 수의 마지막 자릿수의 위치는 그 수 번째인 문자열이다.

해결 방법 : 먼저, 20자 미만인 경우의 문자열들은 직접 구해준다. 20자 이상의 문자열들에 대해 살펴보면
a * 10^b가 같은 자리 수인 경우 문자열의 앞 부분은 (자릿수 + 1)번마다 반복됨을 알 수 있다.
이를 이용해 10^v - v부터 10^v - 1까지의 수의 길이 문자열을 이전의 값을 이용해 구하면
10^(v - 1) - v에서 10^(v - 1) - 1까지의 길이 문자열에서 9 * 10^(v - 1) - 1칸만큼 왼쪽으로 옮긴 것임을 알 수 있다.
이는 9 * 10^(v - 1) - 1 % v의 값들을 미리 계산해놓고 한번씩 연속으로 적용해주면 구할 수 있다.
모든 v에 대해 10^(2^i) % v의 값들을 저장해둔 다음 v - 1이 있는 비트에 대해 해당 값들을 곱해줘서 구하면 된다.
10^v는 10^v - v의 값과 같다. 따라서 각 길이 문자열들은 연속해서 나타날 것이므로
각 v당 3 가지 길이 문자열의 시작 위치들만 저장해둔다.
각 v에 대한 영역의 저장이 끝나면 수들을 입력받은 다음 자릿수를 확인하고 나머지를 구한 다음(위에서 했던 방식대로)
해당 자릿수와 나머지에 맞는 영역을 구하면 된다.

주요 알고리즘 : 수학, 정수론, 분할제곱

출처 : UCPC 2020예 B번
*/

/*mod10: 10^(2^j) % i의 값, start: area[i]에서 area[i + 1]이 되기 위해 움직여야 하는 칸 수, 10^i % i, area: 10^i - i부터 계산하여
각 길이 문자열이 되는 영역의 가장 앞 부분
*/
int mod10[1048576][24], start[1048576][2], area[1048576][3];
char* strs[3] = { "1-3-5-7-10-13-16-", "-2-4-6-8-11-14-17", "1-3-5-7-9-12-15-1" }; //20자 초과하는 경우에 대한 문자열
char* strslong[3] = { "1-3-5-7-9-12-15-18-21", "1-3-5-7-10-13-16-19-22", "-2-4-6-8-11-14-17-20" }; //20자 미만에 대한 문자열

int getarea(int base, int md) {
    //만들어진 영역 정보를 바탕으로 자릿수와 나머지 값에 해당하는 영역을 찾는다.
    md = (md - start[base][1]) % (base + 1);
    if (md < 0) md += (base + 1);
    if (area[base][0] < area[base][1] && area[base][0] < area[base][2]) {
        if (md < area[base][0]) return 2;
        else if (md < area[base][1]) return 0;
        else if (md < area[base][2]) return 1;
        else return 2;
    }
    else if (area[base][1] < area[base][0] && area[base][1] < area[base][2]) {
        if (md < area[base][1]) return 0;
        else if (md < area[base][2]) return 1;
        else if (md < area[base][0]) return 2;
        else return 0;
    }
    else {
        if (md < area[base][2]) return 1;
        else if (md < area[base][0]) return 2;
        else if (md < area[base][1]) return 0;
        else return 1;
    }
}

int getdigits(int n) {
    //int n이 몇 자리 수인지 구한다.
    if (n < 10) return 1;
    else if (n < 100) return 2;
    else if (n < 1000) return 3;
    else if (n < 10000) return 4;
    else if (n < 100000) return 5;
    else if (n < 1000000) return 6;
    else if (n < 10000000) return 7;
    else if (n < 100000000) return 8;
    else if (n < 1000000000) return 9;
    else return 10;
}

int main(void) {
    int md, t, a, b, digits; //md: 문자열, digits: a * 10^b의 자릿수 + 1
    for (int i = 3; i <= 1024000; i++) {
        md = 10;
        if (md >= i) md %= i;
        mod10[i][0] = md;
        for (int j = 1; j <= 20; j++) {
            mod10[i][j] = ((long long)mod10[i][j - 1] * mod10[i][j - 1]) % i; //10의 (2^j)제곱을 i로 나눈 값들을 구한다.
        }
    }
    for (int i = 2; i <= 1012000; i++) {
        md = 9;
        for (int tmp = i - 1, j = 0; tmp; j++) {
            if ((tmp >> j) & 1) {
                tmp -= (1 << j);
                md = ((long long)md * mod10[i + 1][j]) % (i + 1);
            }
        }
        start[i][0] = (md + i) % (i + 1);
        md = 1;
        for (int tmp = i - 1, j = 0; tmp; j++) {
            if ((tmp >> j) & 1) {
                tmp -= (1 << j);
                md = ((long long)md * mod10[i][j]) % i;
            }
        }
        start[i - 1][1] = md;
    }
    area[2][0] = 0;
    area[2][1] = 1;
    area[2][2] = 2;
    for (int i = 3; i <= 1012000; i++) {
        for (int j = 0; j < 3; j++) {
            area[i][j] = (area[i - 1][j] - start[i][0]) % (i + 1);
            if (area[i][j] < 0) area[i][j] += (i + 1);
        }
    }

    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        if ((a <= 20 && b == 0) || (a <= 2 && b == 1)) {
            digits = a * (b ? 10 : 1);
            if (digits < 10) {
                if (digits & 1) {
                    for (int i = 0; i < digits; i++) {
                        printf("%c", strslong[0][i]);
                    }
                    printf("\n");
                }
                else {
                    for (int i = 0; i < digits; i++) {
                        printf("%c", strslong[2][i]);
                    }
                    printf("\n");
                }
            }
            else {
                for (int i = 0; i < digits; i++) {
                    printf("%c", strslong[digits % 3][i]);
                }
                printf("\n");
            }
            continue;
        }

        digits = b + getdigits(a) + 1;
        md = a % digits;
        for (int tmp = b, j = 0; tmp; j++) {
            if ((tmp >> j) & 1) {
                tmp -= (1 << j);
                md = ((long long)md * mod10[digits][j]) % digits;
            }
        }
        printf("%s...\n", strs[getarea(digits - 1, md)]);

    }

    return 0;
}
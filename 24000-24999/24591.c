#include <stdio.h>
#include <string.h>

/*
문제 : 길이 26 이하의 서로 다른 소문자로 이루어진 문자열 v와 10^6 이하의 v에 있는 문자들로 이루어진
문자열 s가 주어진다. 그리고 N(N <= 10^6)개의 v에 있는 문자들로 이루어진 문자열 q_i가 주어질 때,
각 q_i에 대해 이 문자열이 s의 최단 비부분수열인 지 구한다. 모든 q_i 길이의 합은 10^6 이하다.

해결 방법 : 1885번의 방식대로 최단 비부분수열의 길이를 구한다.
그와 함께 s의 각 글자에 대한 누적 합도 구해준다. 그 다음 N개의 문자열을 입력받으면서
문자열의 길이를 확인한다. 길이가 최단 비부분수열과 다르다면 이 문자열은 최단 비부분수열이 아니다.
길이가 같다면 비부분수열인지 확인한다. 앞에서 구한 누적 합을 이용해 다음 문자의 자리를
이분 탐색으로 찾아나가며 모든 문자를 차례로 찾을 수 있는 지 확인하면 된다.
비부분수열이라면 이 문자열은 최단 비부분수열이고, 아니라면 최단 비부분수열이 아니다.

주요 알고리즘 : 문자열, 그리디 알고리즘, 이분 탐색, 누적 합

출처 : PacNW 2021 B/O번 // SCUSA 2021D1 G번 // NENA 2021 L번
*/

char v[32], chk[32], s[1048576], q[1048576];
int psum[26][1048576];

int main(void) {
    int n, ans = 1, rem, slen, qlen, pos, lo, hi, mid;
    scanf("%s%s", v, s + 1);
    rem = strlen(v);
    slen = strlen(s + 1);
    for (int i = 1; s[i]; i++) {
        if (chk[s[i] - 'a'] == 0) {
            chk[s[i] - 'a'] = 1;
            rem--;
            if (rem == 0) {
                for (int i = 0; v[i]; i++) chk[v[i] - 'a'] = 0;
                rem = strlen(v);
                ans++;
            }
        }
        for (int j = 0; j < 26; j++) psum[j][i] = psum[j][i - 1];
        psum[s[i] - 'a'][i]++;
    }
    for (int i = 0; i < 26; i++) psum[i][slen + 1] = 1012345678;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", q);
        qlen = strlen(q);
        if (qlen != ans) {
            printf("0\n");
            continue;
        }
        pos = 0;
        for (int j = 0; q[j] && pos <= slen; j++) {
            lo = pos + 1, hi = slen + 1;
            while (lo < hi) {
                mid = (lo + hi) >> 1;
                if (psum[q[j] - 'a'][mid] > psum[q[j] - 'a'][pos]) hi = mid;
                else lo = mid + 1;
            }
            pos = lo;
        }
        printf("%d\n", pos > slen);
    }
    return 0;
}
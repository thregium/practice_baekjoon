#include <stdio.h>

/*
문제 : 길이 N(N <= 100000)의 대문자로 이루어진 문자열에서 연속한 K(K <= N)개의 문자를 같게 만들기 위해
바꿔야 하는 문자 개수의 최솟값을 구한다.

해결 방법 : 각 문자에 대해 왼쪽에서부터 개수의 누적 합을 구한다. 그 다음, 각 문자에 대해 누적 합을
옮겨 가며 그 문자 개수의 K에 대한 차이를 계산해 나간다. 이때, 나올 수 있는 가장 작은 차이가 답이 된다.

주요 알고리즘 : 문자열, 누적 합

출처 : INC 2020 F번
*/

char s[103000];
int psum[26][103000];

int main(void) {
    int n, k, r = 103000;
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        psum[s[i] - 'A'][i] = 1;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) psum[i][j] += psum[i][j - 1];
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j <= n - k; j++) {
            if (k - (psum[i][j + k] - psum[i][j]) < r) r = k - (psum[i][j + k] - psum[i][j]);
        }
    }
    printf("%d", r);
    return 0;
}
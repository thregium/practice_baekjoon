#include <stdio.h>

/*
문제 : 2자리 이하의 자연수 2개가 주어질 때, 이 범위 내에 있는 수들을 문자열 순으로 정렬한 결과를 출력한다.

해결 방법 : 개수가 적은 편이므로 일일히 찾아가며 풀었다.

주요 알고리즘 : 문자열, 전처리
*/

int res[] = { 8, 88, 85, 84, 89, 81, 87, 86, 83, 82,
80, 5, 58, 55, 54, 59, 51, 57, 56, 53,
52, 50, 4, 48, 45, 44, 49, 41, 47, 46,
43, 42, 40, 9, 98, 95, 94, 99, 91, 97,
96, 93, 92, 90, 1, 18, 15, 14, 19, 11,
17, 16, 13, 12, 10, 7, 78, 75, 74, 79,
71, 77, 76, 73, 72, 70, 6, 68, 65, 64,
69, 61, 67, 66, 63, 62, 60, 3, 38, 35,
34, 39, 31, 37, 36, 33, 32, 30, 2, 28,
25, 24, 29, 21, 27, 26, 23, 22, 20 };

int main(void) {
    int m, n, cnt = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < 99; i++) {
        if (res[i] > n || res[i] < m) continue;
        else printf("%d ", res[i]);
        cnt++;
        if (cnt % 10 == 0) printf("\n");
    }
    return 0;
}
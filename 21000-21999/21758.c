#include <stdio.h>

/*
문제 : N(N <= 100000) 길이의 일직선상의 지역에 놓인 꿀의 양(<= 10000, 자연수)이 각각 주어진다.
벌통과 벌 2마리를 각각 다른 칸에 둘 때, 각 벌은 벌통을 향해 날아가며 벌이 출발한 지역이 아니면 벌통까지
꿀을 지역에 놓인 만큼 딴다고 할 때, 딸 수 있는 꿀의 최댓값을 구한다.

해결 방법 : 벌통이 가운데 있는 경우에는 벌들을 양쪽 끝에 놓고, 그 가운데 중 가장 꿀이 많은 곳에
벌통을 놓는 것이 좋다. 벌통이 끝쪽에 있다면 벌통을 끝에 두고 벌 하나는 반대쪽 끝, 나머지 하나는
꿀을 가장 많이 딸 수 있는 출발점에 두면 된다. 꿀을 따는 양은 누적 합을 이용해 구한다.

주요 알고리즘 : 그리디 알고리즘, 케이스 워크, 누적 합

출처 : 정올 2021_1 중1번
*/

int a[103000];

int main(void) {
    int n, res = 0, best = 0, sum = 0, psum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i > 0 && i < n - 1 && a[i] > best) best = a[i];
        sum += a[i];
    }
    res = sum + best - a[0] - a[n - 1];
    psum = a[n - 1];
    for (int i = n - 2; i > 0; i--) {
        if (sum + psum - a[0] - a[i] > res) res = sum + psum - a[0] - a[i];
        psum += a[i];
    }
    psum = a[0];
    for (int i = 1; i < n - 1; i++) {
        if (sum + psum - a[n - 1] - a[i] > res) res = sum + psum - a[n - 1] - a[i];
        psum += a[i];
    }
    printf("%d", res);
    return 0;
}
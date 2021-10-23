#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)개의 약속 시각과 상대의 도착 시각이 주어진다. 약속 시각을 조절하여 전체 대기 시간을 줄이고자 할 때,
전체 대기 시간이 최소가 되는 정수 약속 시각의 오프셋 개수를 구한다.

해결 방법 : 약속 시각과 도착 시각의 차이를 담은 배열을 만든다. 그 다음, 그 배열을 정렬해 둔다.
만약 N이 홀수인 경우 전체 대기 시간이 최소가 되는 약속 시각은 전체 배열의 중앙값인 경우로 반드시 하나만 존재한다.
N이 짝수인 경우에는 가운데 두 값 사이의 임의의 정수면 되고, 이러한 경우는 두 값의 차 + 1로 계산 가능해진다.

주요 알고리즘 : 그리디 알고리즘, 정렬
*/

int t[10240];

int cmp1(const void* a, const void* b) {
  int ai = *((int*)a);
  int bi = *((int*)b);
  return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main()
{
  int n, s, a, r = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &s, &a);
    t[i] = s - a;
  }
  qsort(t, n, sizeof(int), cmp1);
  if(n & 1) printf("1");
  else printf("%d", t[n >> 1] - t[(n >> 1) - 1] + 1);
  return 0;
}
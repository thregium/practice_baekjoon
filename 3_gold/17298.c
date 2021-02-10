#include <stdio.h>

/*
문제 : 수열의 원소 A[i] 보다 오른쪽에 있으면서 A[i]보다 큰 수 가운데 가장 왼쪽에 있는 수(오큰수)를 원소별로 출력한다.

해결 방법 : 스택을 이용해 풀 수 있다. 값들을 스택에 집어넣다가 현재 집어넣는 값보다 작은 값이 스택의 맨 위에 있는 경우 그 값에 대한 오큰수는 현재 집어넣는 값이다.
오큰수를 확인한 다음에는 스택에서 확인한 수를 제거하고 다시 맨 위와 집어넣는 값을 스택의 값이 더 작지 않을 때 까지 반복한다.

주요 알고리즘 : 자료구조, 스택
*/

int a[1048576], r[1048576];
int stack[1048576][2];
int top = 0;

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &a[i]);
          while (top && stack[top - 1][0] < a[i]) {
               r[stack[top - 1][1]] = a[i];
               top--;
          }
          stack[top][0] = a[i];
          stack[top][1] = i;
          top++;
     }
     for (int i = 0; i < n; i++) {
          printf("%d ", r[i] ? r[i] : r[i] - 1);
     }
     return 0;
}
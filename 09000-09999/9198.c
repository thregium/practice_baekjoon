#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 길이 10000 이하의 []와 숫자로 이루어진 문자열이 주어진다. 숫자는 가장 안쪽 [] 안에만 존재하며,
각 [] 안에는 홀수 개의 [] 또는 숫자들이 주어진다. 숫자들을 연결하면 9999 이하의 홀수 자연수가 된다.
이때, 각 단계마다 [] 안의 인원들이 투표를 진행하여 과반 득표를 통해 다음 단계의 사람을 뽑는다.
각 단계마다 아래 단계의 []들이 투표를 진행할 때, 투표에서 승리하기 위해 득표해야 할 1단계 투표자의
투표 수를 구한다.

해결 방법 : 각 단계마다 투표에 승리하기 위해서는 하위 단계 중 과반수의 찬성을 얻어햐 한다.
그 중 1단계 투표자 수가 가장 적은 경우는 가장 작은 선거구 ceil(N / 2)개에서 이기는 것이고,
이는 정렬을 통해 해결할 수 있다. 또한, 1단계의 투표자 수는 strtoll() 함수를 이용한 뒤 절반 + 1을
하여 구한다. 각 단계 별로 하위 단계의 투표자 수를 재귀적으로 확인하며 답을 구해나가면 된다.

주요 알고리즘 : 문자열, 파싱, 분할 정복, 정렬

출처 : JDC 2013 C번
*/

char data[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int vote(int s, int e) {
    if (data[s + 1] != '[') return (strtoll(&data[s + 1], NULL, 10) + 1) >> 1;
    int stage[4096];
    int voter = 0, cnt = 0, ss = -1, res = 0;
    for (int i = s + 1; i < e; i++) {
        if (cnt == 0 && data[i] == '[') ss = i;
        else if (cnt == 1 && data[i] == ']') stage[voter++] = vote(ss, i);
        if (data[i] == '[') cnt++;
        else if (data[i] == ']') cnt--;
    }
    qsort(stage, voter, sizeof(int), cmp1);
    for (int i = 0; i <= (voter >> 1); i++) res += stage[i];
    return res;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", data);
        printf("%d\n", vote(0, strlen(data) - 1));
    }
    return 0;
}
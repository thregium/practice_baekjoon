#include <stdio.h>
#include <string.h>

/*
문제 : 집합 표기법으로 나타낸 두 자연수(또는 0)가 주어질 때, 두 수의 합을 집합 표기법으로 나타낸다.
두 수의 합은 최대 15이다.
집합 표기법은 0을 {}로 나타내고 1 이상의 수는 해당 수 미만의 모든 수를 더한 집합으로 나타내는 것이다.
예를 들어 1은 {{}}로 나타내고, 2는 {{},{{}}}로 나타낸다.

해결 방법 : 15 이하의 집합 표기법으로 나타낸 수들을 미리 전부 저장해둔다.
이는 문자열 연산을 통해 DP와 비슷한 방식으로 할 수 있다. 그 다음, 각 수들의 길이도 미리 저장해둔다.
이후로 수들을 입력받은 다음, 두 수의 길이를 구하고 해당 길이와 같은 두 수를 확인한다.
모든 수의 길이가 다르기 때문에 이 방법을 사용 가능하다. 두 수를 확인하면 두 수의 합에 해당하는 집합 표기법 수를 출력하면 된다.

주요 알고리즘 : 문자열

출처 : Rocky 2007 I번
*/

char nums[16][103000], a[103000], b[103000];
int len[16];

int main(void) {
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2007\\addition\\cases\\test1\\addition.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2007\\addition\\cases\\test1\\addition_t.out", "w", stdout);
    strcpy(nums[0], "{}");
    for (int i = 1; i <= 15; i++) {
        nums[i][0] = '{';
        for (int j = 0; j < i; j++) {
            strcat(nums[i], nums[j]);
            if (j < i - 1) strcat(nums[i], ",");
        }
        strcat(nums[i], "}");
    }
    for (int i = 0; i <= 15; i++) len[i] = strlen(nums[i]);
    int n, an, bn, al, bl;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s", a, b);
        an = -1, bn = -1;
        al = strlen(a), bl = strlen(b);
        for (int j = 0; j <= 15; j++) {
            if (al == len[j]) an = j;
            if (bl == len[j]) bn = j;
        }
        if (an < 0 || bn < 0) return 1;
        printf("%s\n", nums[an + bn]);
    }
    return 0;
}
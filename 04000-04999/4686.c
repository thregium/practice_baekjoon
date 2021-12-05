#include <stdio.h>
#include <stdlib.h>

/*
문제 : 20개 이하의 연산자로 이루어진 수식을 하나씩 계산하는 과정을 출력한다. 각 연산은 덧셈, 뺄셈, 곱셈, 나눗셈이고,
나눗셈 시 항상 정수 범위에 있도록 주어진다. 수식의 수에서 음수가 들어올 수 있다.

해결 방법 : 먼저 수식의 수와 연산자들을 파싱한 다음, 앞에서부터 곱셈과 나눗셈을 계산해 나간다.
그 후 다시 덧셈과 뺄셈을 계산하면 된다.

주요 알고리즘 : 수학, 구현, 파싱

출처 : MidC 1996 E번
*/

char op[32], s[16];
int num[32], level[32];

void print(int cnt) {
	for (int i = 0; i < cnt; i++) {
		printf("%d ", num[i]);
		printf("%c ", op[i]);
	}
	printf("%d ", num[cnt]);
	printf("= %s\n", s);
}

int main(void) {
	int cnt, cur;
	char equal;

	//freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM6\\ALGEBRA.IN", "r", stdin);
	//freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM6\\ALGEBRA_T.OUT", "w", stdout);

	while (1) {
		cnt = 0;
		while (1) {
			if (scanf("%d ", &num[cnt]) == EOF) return 0;
			scanf("%c ", &op[cnt]);
			cnt++;
			if (op[cnt - 1] == '=') break;
		}
		cnt--;
		scanf("%s", s);
		print(cnt);

		cur = 0;
		for (int i = 0; i < cnt; i++) {
			if (op[i] == '*' || op[i] == '/') level[i] = cur++;
		}
		for (int i = 0; i < cnt; i++) {
			if (op[i] == '+' || op[i] == '-') level[i] = cur++;
		}

		for (int i = 0; i < cnt; i++) {
			for (cur = 0; level[cur] != i; cur++);
			switch (op[cur]) {
			case '+': num[cur] += num[cur + 1]; break;
			case '-': num[cur] -= num[cur + 1]; break;
			case '*': num[cur] *= num[cur + 1]; break;
			case '/': num[cur] /= num[cur + 1]; break;
			}
			for (int i = cur + 1; i < cnt; i++) {
				num[i] = num[i + 1];
				op[i - 1] = op[i];
				level[i - 1] = level[i];
			}
			print(cnt - i - 1);
		}
		printf("\n");
	}
}

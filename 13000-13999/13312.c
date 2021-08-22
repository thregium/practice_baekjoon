#include<stdio.h>
#include<math.h>
#include<cassert>
#include<stdlib.h>
const int LIM = 1000000000;

/*
문제 : N(N <= 100000)개 이하의 int형 수를 사용해 전체 합 / 100의 아크 코사인 값과 각 수 / 100의 합의 아크 코사인 값이
서로 0.001 이상 차이가 나도록 하는 수들을 구한다. 단, 최종 결과는 +100과 -100 사이여야 한다.

해결 방법 : 실수 오차를 가능한 크게 만들어야 하기 때문에 매번 큰 수를 더해주는 것이 좋다.
또한, 더할 때와 뺄 때의 수가 다르도록 하는 것이 실수 오차가 더 커지게 하는 방법이다.
간단한 방법으로는 33333번 2^31 - 1을 더하고, 66666번 2^30 - 1을 빼고, 마지막으로 33333을 빼는 방법이 있다.

주요 알고리즘 : 수학, 구성적

출처 : 꼬마컵 2016 B번
*/

typedef long long ll;

float _abs(float x) { return x < 0 ? -x : x; }
int is_equal(double a, double b) { return _abs(a - b) < 1e-3; }

int main()
{
	int N = 100000, a;
	ll tot = 0;
	double x = 0;
	//assert(scanf("%d", &N) == 1);
	//assert(2 <= N && N <= 100000);
	printf("%d\n", N);
	for (int i = 1; i <= N; i++) {
		//assert(scanf("%d", &a) == 1);
		if (i <= N / 3) a = 2147483647;
		else if (i < N) a = -1073741823;
		else a = -33333;
		printf("%d\n", a);
		tot += a;
		x += a / 100.0;
	}
	assert(-100 <= tot && tot <= 100);
	//printf("%.9f %.9f", acos(x), acos(tot / 100.0));
	assert(!is_equal(acos(x), acos(tot / 100.0)));
	return 0;
}

#include <stdio.h>
#include <math.h>

/*
문제 : v2 = RC d/dt (v1 – v2) 이고 v1 = Vs cos ω t, v2 = Vr cos ( ωt + θ )일 때
고정된 R, C, Vs에 대해 각 ω마다 Vr의 값을 구한다.

해결 방법 : ??

16silver  23시간 전
좀 안 좋은 문제네요... 일단 지금 미지수가 θ랑 Vr 이렇게 두 개인데, 저 삼각함수 식을 넣어서 미분을 해보면
Vr cos (wt+θ) = RCw(Vr sin(wt+θ) - Vs sin(wt))
가 됩니다. 이제 삼각함수의 덧셈정리
cos(wt+θ) = cosθ cos(wt) - sinθ sin(wt), sin(wt+θ) = sinθ cos(wt) + cosθ sin(wt)
를 넣어주면 sin(wt)의 계수가 같다는 거로부터 식 하나, cos(wt)의 계수가 같다는 거로부터 식 하나 해서 총 두 개의 식이 나옵니다. cos(wt)의 계수가 같다는 식에서
Vr cosθ = RCw Vr sinθ가 나오는데, 이로부터 cosθ와 sinθ의 비율이 나왔으므로 제곱해서 1이라는 사실과 연결하면
cosθ = RCw / sqrt(1+(RCw)^2), sinθ = 1/sqrt(1+(RCw)^2)
이 나옵니다. 이제 이걸 sin(wt)의 계수가 같다는 식에 넣으면 Vr을 구할 수 있습니다...

byeongkeunahn  23시간 전
다른 방법으로 풀려면 정상상태를 가정하니까 phasor를 써도 됩니다.
q = q0 * exp(iwt)
의 trial solution을 넣고 풀면
Vs * exp(iwt) - q/C - (dq/dt)R = 0
에서
Vs - q0/C - iwq0R = 0,
따라서
q0 = Vs / (1/C + iwR)
이 나옵니다. 전류진폭은
iwq0
이니까 저항 R를 곱해 iwq0R의 복소수의 크기를 취하면 됩니다. (급하게 써서 부호가 틀릴지도 모르니 잘 살펴보세요...ㅎㅎ)
일반적으로 교류전원의 전압진폭이 Vs이고 R, L, C가 직렬 연결된 회로의 경우 유도 리액턴스가 XL = wL, 용량 리액턴스가 XC = 1/wC로, 전류진폭은 Vs를 등가저항(임피던스) Z = sqrt( R^2 + (XL - XC)^2 )로 나눈 값으로 주어집니다. (편집됨) 

대충 이렇다고 한다.

주요 알고리즘 : 수학, 미적분학

출처 : GNY 2001 D번
*/

int main(void) {
    int n;
    double vs, r, c, om;
    scanf("%lf %lf %lf %d", &vs, &r, &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &om);
        printf("%.3f\n", r * c * vs / sqrt(1 + pow(1 / (om * r * c), 2)));
    }
    return 0;
}
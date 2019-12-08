#include <iostream>
#include <cstdio>


using namespace std;

int D[1000000];

/*주어진 연산은 세 가지
    1.X가 3으로 나누어 떨어지면, 3으로 나눈다
    2.X가 2로 나누어 떨어지면, 2로 나눈다
    3.1을 뺀다.

    첫번째 경우는 최소 연산횟수 N->N/3
    ->1로 만드는 것인데 N -> N/3은 1번이고
    N/3에서 1로 만드는 것은 최소 연산횟수가 저장된
    D[N/3]을 더해주는 것이다

    두번째 경우는 최소 연산횟수 N->N/2
    ->1로 만드는 것인데 N -> N/2은 1번이고
    N/2에서 1로 만드는 것은 최소 연산횟수가 저장된
    D[N/2]을 더해주는 것이다

    세번째 경우는 최소 연산횟수 N->N-1 -> 1
    인데 1 + D[N-1]과 같다

    따라서 최종 솔루션은 D[N] = min(D[N/3]+
    D[N/2] + D[N-1]) + 1이다
     */


int solution(int n){
   /*예외는 n이 1일때 0번  */
   if(n == 1) return 0;
   if(D[n] > 0) return D[n];
   /*0보다 크다는 것은 값이 있다는 것이기 때문에
   최소 연산횟수 반환 */
   D[n] = solution(n-1) + 1;
   /* n-1부터 최소 연산횟수 재귀호출 끝까지 가서
   D[2]부터 채워지기 시작함 */
   if(n%2 == 0)
   {
       int temp = solution(n/2) +1;
       /* 최소 연산횟수 계산 */
       if(D[n] > temp ) D[n] = temp;
       /* 최소 연산횟수 수정 */
   }
   if(n%3 == 0)
   {
       int temp = solution(n/3) +1;
        /* 최소 연산횟수 계산 */
       if(D[n] > temp) D[n] = temp;
       /* 최소 연산횟수 수정 */
   }
   return D[n];

}

int main()
{
    int N;
    /*1보다 크고 1000000보다 작은 정수 N  */

    scanf("%d",&N);
    printf("%d",solution(N));

    return 0;
}

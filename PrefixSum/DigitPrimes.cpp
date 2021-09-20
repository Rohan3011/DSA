#include <stdio.h>
typedef long long ll ;

const int N = 1000001 ;
int isPrime[N + 1] , digitPrime[N + 1] ;


int digitSum(ll n) ;
void sieve();

int main() {
	sieve() ;
	int n ;
	scanf("%d" , &n) ;
	int digit = 0 ;
	for (long long i = 0 ; i <= N ; i++) {
		if (isPrime[i] && isPrime[digitSum(i)])
			digit++;
		digitPrime[i] = digit ;
	}

	while (n--) {
		int t1 , t2 ;
		scanf("%d %d" , &t1 , &t2) ;
		int ans = digitPrime[t2] - digitPrime[t1 - 1] ;
		printf("%d\n", ans );
	}

}

int digitSum(ll n) {
	int sum = 0 ;
	while (n > 0) {
		sum += n % 10 ;
		n /= 10 ;
	}
	return sum ;
}

void sieve() {
	for (int i = 0 ; i <= N ; i++)
		isPrime[i] = 1 ;
	isPrime[0] = isPrime[1] = 0 ;
	for (long long i = 2 ; i * i <= N ; i++) {
		if (isPrime[i]) {
			for (long long j = i * i ; j <= N ; j += i)
				isPrime[j] = 0 ;
		}
	}
}

#include<bits/stdc++.h>
using namespace std ;


void primeFactorization(int limit , vector<int> & ppf) {
// To maximize the rounds, we have to maximize (n/x) i.e minimize
// the x. In other words , prime factorization of n
	vector<int> lpf(limit , 0) ; // Largest Prime Factor
	vector<int> cpf(limit , 0) ; //  Count of Prime Factors

	for (int i = 2 ; i * i < limit ; i++) {
		if (lpf[i] == 0) {
			for (int j = i * i ; j < limit ; j += i)
				lpf[j] = i ;
		}
	}

	for (int i = 2 ; i < limit ; i++) {
		int p = (lpf[i] > 0 ? lpf[i] : 1) ;
		cpf[i] = cpf[i / p] + 1 ;
		ppf[i] += cpf[i] + ppf[i - 1] ;
	}
}





int main() {
	const int limit = 5e6 + 1 ;
	vector<int> ppf (limit , 0) ; // Prefixsum of count of Prime Factors
	primeFactorization(limit , ppf) ;
	int t ;
	scanf("%d\n" , &t) ;
	while (t--) {
		int a , b ;
		scanf("%d%d" , &a , &b) ;
		printf("%d\n" , ppf[a] - ppf[b]) ;
	}
}
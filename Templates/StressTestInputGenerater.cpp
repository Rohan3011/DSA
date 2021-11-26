#include <bits/stdc++.h>
using namespace std ;

// Random number in range [a , b]
template<typename T >
T random(T a , T b) {
	return a + rand() % (b - a + 1) ;
}

int main () {
	srand(time(0)) ;

}
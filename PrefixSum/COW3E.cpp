#include<iostream>
using namespace std ;
typedef long long ll ;

ll arr[1001][1001];
ll diff[1001][1001];

void createDiffArr(int n , int m) ;
void prefixSumArr(int n , int m) ;

int main() {
    ios::sync_with_stdio(0) ; cin.tie(NULL) ;
    int n , m , u , q ;
    cin >> n >> m >> u >> q ;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            ll x ;
            cin >> x ;
            arr[i][j] = x ;
        }
    }
    createDiffArr(n , m) ;

    while (u--) {
        int k , r1 , c1 , r2 , c2 ;
        cin >> k >> r1 >> c1 >> r2 >> c2 ;

        diff[r1][c1] += k ;
        if (c2 + 1 < m) diff[r1][c2 + 1] -= k ;
        if (r2 + 1 < n) diff[r2 + 1][c1] -= k ;
        if (r2 + 1 < n && c2 + 1 < m )diff[r2 + 1][c2 + 1] += k ;
    }
    prefixSumArr(n , m) ;
    prefixSumArr(n , m) ;
    while (q--) {
        int r1 , c1 , r2 , c2 ;
        cin >> r1 >> c1 >> r2 >> c2 ;
        ll ans = diff[r2][c2] ;
        if (r1 - 1 >= 0 ) ans -= diff[r1 - 1][c2] ;
        if (c1 - 1 >= 0) ans -= diff[r2][c1 - 1] ;
        if (r1 - 1 >= 0 && c1 - 1 >= 0 ) ans += diff[r1 - 1][c1 - 1] ;
        cout << ans << "\n" ;
    }
}

void createDiffArr(int n , int m) {
    diff[0][0] = arr[0][0] ;
    for (int i = 1 ; i < n ; i++)
        diff[i][0] = arr[i][0] - arr[i - 1][0] ;

    for (int j = 1 ; j < m ; j++)
        diff[0][j] = arr[0][j] - arr[0][j - 1] ;

    for (int i = 1 ; i < n ; i++) {
        for (int j = 1; j < m ; j++)
            diff[i][j] = arr[i][j] - arr[i - 1][j] - arr[i][j - 1] + arr[i - 1][j - 1] ;
    }
}

void prefixSumArr(int n , int m) {
    for (int i = 1 ; i < n ; i++)
        diff[i][0] += diff[i - 1][0] ;
    for (int j = 1 ; j < m ; j++)
        diff[0][j] += diff[0][j - 1] ;

    for (int i = 1 ; i < n ; i++ ) {
        for (int j = 1 ; j < m ; j++ )
            diff[i][j] += (diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1]) ;
    }
}


#include "iostream"
using namespace std ;

int main() {
    ios::sync_with_stdio(0) ; cin.tie(0) ;
    int t ;
    cin >> t ;
    while (t--) {
        int n , k ;
        cin >> n >> k ;
        int arr[n] ;
        for (auto &i : arr) cin >> i ;
        // //  circular array
        // int bag[2 * n];
        // for (int i = 0 ; i < n ; i++)
        //     bag[i] = arr[i] ;
        // for (int i = 0 ; i < n ; i++) {
        //     bag[i + n] = arr[i] ;
        // }
        // sliding Window
        long long sum = 0 ;
        for (int i = 0 ; i < k ; i++)
            sum += arr[i] ;
        long long ans = sum ;
        for (int i = 1 ; i < n ; i++) {
            sum -= arr[i - 1] ;
            sum += arr[(i + k - 1) % n] ;
            ans = max(ans , sum) ;
        }
        cout << ans << "\n" ;
    }
}
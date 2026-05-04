#include <stdio.h>
int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;  
    int left = 1, right = n, ans = 0;
    while (left <= right) {
        long mid = left + (right - left) / 2;  
        long sq = mid * mid;
        if (sq == n) {
            return (int)mid;  
        } else if (sq < n) {
            ans = (int)mid;   
            left = mid + 1;   
        } else {
            right = mid - 1;  
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));
    return 0;
}
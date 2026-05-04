/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15
*/
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[m][n];
    int i, j, sum = 0;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < m && i < n; i++) {
        sum += a[i][i];
    }

    printf("%d", sum);

    return 0;
}

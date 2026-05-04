/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix
*/
#include <stdio.h>

int main() {
    int n, i, j;
    int matrix[100][100];
    int flag = 1;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    flag = 0;
                    break;
                }
            } else {
                if(matrix[i][j] != 0) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0)
            break;
    }

    if(flag == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}

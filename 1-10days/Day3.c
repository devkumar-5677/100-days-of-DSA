/* Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
*/
#include<stdio.h>
#define N 100

int main()
{
    int arr[N],i,element,loc=-1,n,comparisons=0;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    
    printf("enter elements in this array => \n");
    for (i=0;i<n;i++)
    {
scanf("%d", &arr[i]);
    }

    printf("enter element to search");
    scanf("%d", &element);

    for(i=0;i<N;i++)
    {
        comparisons++;
        if(arr[i]==element)
        {
        loc=i;
        printf("Found at index %d \n", loc);
        break;
        }
    }
    if(loc==-1)
    {
        printf("elment not present");
    }
    
    printf("Comparisons = %d\n", comparisons);

}
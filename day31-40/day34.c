/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
            continue;
        }

        else {
            int op2 = pop();
            int op1 = pop();
            int result;

            switch (exp[i]) {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;

                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("%d\n", result);

    return 0;
}
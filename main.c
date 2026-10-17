
#include <stdio.h>
#include "infix_postfix.h"

int main(void)
{
    char infix[100], postfix[100];

    printf("Enter infix expression: ");

    if (scanf("%99s", infix) != 1)
        return 1;

    if (infix_to_postfix(infix, postfix))
        printf("Postfix expression: %s\n", postfix);
    else
        printf("Invalid character or mismatched parentheses\n");

    return 0;
}

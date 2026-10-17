
#include <stdio.h>
#include <ctype.h>
#include "infix_postfix.h"

int precedence(char op)
{
    if (op == '^')
        return 4;
    if (op == '*' || op == '/')
        return 3;
    if (op == '+' || op == '-')
        return 2;

    return 0;
}

int infix_to_postfix(char infix[], char postfix[])
{
    char stack[100];
    char current;
    int top = -1, pos = 0, i = 0;
    int p1, p2;

    while (infix[pos] != '\0')
    {
        current = infix[pos];

        if (isalnum((unsigned char)current))
        {
            postfix[i] = current;
            i++;
        }
        else if (current == '(')
        {
            stack[++top] = current;
        }
        else if (current == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[i] = stack[top];
                i++;
                top--;
            }

            if (top < 0)
                return 0;

            top--;  /* Remove '(' */
        }
        else if (precedence(current) != 0)
        {
            p2 = precedence(current);

            while (top >= 0 && stack[top] != '(')
            {
                p1 = precedence(stack[top]);

                if (p1 > p2 ||
                    (p1 == p2 && current != '^'))
                {
                    postfix[i] = stack[top];
                    i++;
                    top--;
                }
                else
                {
                    break;
                }
            }

            stack[++top] = current;
        }
        else
        {
            return 0;
        }

        pos++;
    }

    while (top >= 0)
    {
        if (stack[top] == '(')
            return 0;

        postfix[i] = stack[top];
        i++;
        top--;
    }

    postfix[i] = '\0';

    return 1;
}

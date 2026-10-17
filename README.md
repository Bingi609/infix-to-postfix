# Infix to Postfix Converter in C

## Description
This project converts an infix expression into a postfix expression using a stack implemented with an array in C.

**Example**

- Infix: `A+B*C`
- Postfix: `ABC*+`

## Features
- Supports `+`, `-`, `*`, `/`, and `^` operators.
- Handles parentheses.
- Follows operator precedence and associativity.
- Uses an array-based stack.
- Written in C using separate source and header files.

## Operator Precedence

| Operator | Precedence | Associativity |
|---|---:|---|
| `^` | 4 | Right to left |
| `*`, `/` | 3 | Left to right |
| `+`, `-` | 2 | Left to right |

## Algorithm
1. Read the infix expression from left to right.
2. Add operands directly to the postfix expression.
3. Push opening parentheses onto the stack.
4. When a closing parenthesis is found, pop operators until the opening parenthesis is reached, then discard it.
5. For operators, compare precedence and associativity to decide whether to pop existing operators.
6. Push the current operator onto the stack.
7. After scanning the expression, pop the remaining operators.
8. Terminate the postfix string with `\0`.

## Project Structure
```text
infix-to-postfix/
├── main.c
├── infix_postfix.c
├── infix_postfix.h
└── README.md
```

## Compilation
Compile with Gcc

## Execution

On Linux or macOS:

```bash
./infix
```

On Windows, depending on your compiler:

```bash
infix.exe
```

## Sample Test Cases

| Infix | Expected Postfix |
|---|---|
| `A+B*C` | `ABC*+` |
| `A*(B+C)` | `ABC+*` |
| `A^B^C` | `ABC^^` |
| `A+B-C` | `AB+C-` |
| `A/B*C` | `AB/C*` |

## Limitations
- Supports single-character operands.
- Does not support unary operators or implicit multiplication.
- Input validation depends on the implementation.

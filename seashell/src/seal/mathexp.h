#ifndef __SEAL_MATHEXP_H
#define __SEAL_MATHEXP_H

#define EXP_MAX_SIZE 100
#define IS_DIGIT(x) (x >= '0' && x <= '9')

typedef enum {
    NUMBER,
    OPERATOR,
} TokenType;

typedef struct T {
    TokenType type;
    double value;
    char op;
} Token;

typedef struct S {
    Token *list[EXP_MAX_SIZE];
    int top;
} Stack;

typedef struct Q {
    Token *arr[EXP_MAX_SIZE];
    int back;
    int front;
} Queue;

static Token *peek(Stack *stack);
static Token *pop(Stack *stack);
static void push(Stack *stack, Token *token);
static void enqueue(Queue *queue, Token *token);
static Token *dequeue(Queue *queue);
static int precedence(char op);
static int is_right_associative(char op);
static double calculate(double num1, double num2, char op);

static void infix_to_postfix(Stack *stack, Queue *queue);
static void evaluate_postfix(Stack *stack, Queue *queue);
static void clear(Stack *stack, Queue *queue);

int evaluate_math_expression(const char *expression);

#endif /* __SEAL_MATHEXP	_H */

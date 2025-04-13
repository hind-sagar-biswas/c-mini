// A program to evaluate a mathematical expression
// Using: Shunting-yard algorithm by Edsger W. Dijkstra

#include <linux/limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./mathexp.h"
#include "./../constants.h"

static char expression[MAX_ARGS];

int evaluate_math_expression(const char *exp) {
    Stack stack;
    stack.top = -1;

    Queue queue;
    queue.back = -1;
    queue.front = -1;

    strcpy(expression, exp);

    size_t len = strlen(expression);

    infix_to_postfix(&stack, &queue);
    evaluate_postfix(&stack, &queue);

    int result = peek(&stack)->value;

    clear(&stack, &queue);
    return result;
}


static void infix_to_postfix(Stack *stack, Queue *queue) {
    for (int i = 0; expression[i] != '\0'; i++) {
	if (expression[i] == ' ') continue;

        Token *token = malloc(sizeof(Token));

        if (IS_DIGIT(expression[i]) || expression[i] == '.') {
	    char *endptr;
	    token->type = NUMBER;
	    token->value = strtod(&expression[i], &endptr);
	    i = endptr - expression - 1; // Update the index
	    enqueue(queue, token);
	    continue;
	} else {
            token->type = OPERATOR;
            token->op = expression[i];
        }

        if (token->op == '(') {
            push(stack, token);
        } else if (token->op == ')') {
            while (stack->top != -1 && peek(stack)->op != '(') enqueue(queue, pop(stack));
            pop(stack); // Remove '(' from the stack
        } else {
            while (stack->top != -1 && precedence(peek(stack)->op) >= precedence(token->op)) {
                enqueue(queue, pop(stack));
            }
            push(stack, token);
        }
    }

    while (stack->top != -1) enqueue(queue, pop(stack));
}

static void evaluate_postfix(Stack *stack, Queue *queue) {
    while (queue->front != queue->back) {
	Token *token = dequeue(queue);
	if (stack->top == -1 || token->type == NUMBER) {
	    push(stack, token);
	    continue;
	}
	
	if (token->type == OPERATOR) {
	    Token *num2 = pop(stack);
	    Token *num1 = pop(stack);

	    num2->value = calculate(num1->value, num2->value, token->op);
	    num2->type = NUMBER;

	    push(stack, num2);
	}
    }
}

static double calculate(double num1, double num2, char op) {
    if (op == '+') return num1 + num2;
    if (op == '-') return num1 - num2;
    if (op == '*') return num1 * num2;
    if (op == '/') return num1 / num2;
    if (op == '^') return pow(num1, num2);
    return 0;
}

static void push(Stack *stack, Token *token) {
    stack->list[++stack->top] = token;
}

static Token *pop(Stack *stack) {
    if (stack->top == -1) return NULL;
    return stack->list[stack->top--];
}

static Token *peek(Stack *stack) {
    if (stack->top == -1) return NULL;
    return stack->list[stack->top];
}

static void enqueue(Queue *queue, Token *token) {
    queue->arr[++queue->back] = token;
}

static Token *dequeue(Queue *queue) {
    if (queue->front == queue->back) return NULL;
    return queue->arr[++queue->front];
}

static int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

static int is_right_associative(char op) {
    return op == '^';
}

static void clear(Stack *stack, Queue *queue) {
	while (stack->top != -1) free(pop(stack));
	while (queue->front != queue->back) free(dequeue(queue));
}

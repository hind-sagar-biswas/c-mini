// 2302016_150.c
// A program to evaluate a mathematical expression
// Using: Shunting-yard algorithm by Edsger W. Dijkstra


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
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
    Token *list[MAX_SIZE];
    int top;
} Stack;

typedef struct Q {
    Token *arr[MAX_SIZE];
    int back;
    int front;
} Queue;

char expression[1025];

Token *peek(Stack *stack);
Token *pop(Stack *stack);
void push(Stack *stack, Token *token);
void enqueue(Queue *queue, Token *token);
Token *dequeue(Queue *queue);
int precedence(char op);
int is_right_associative(char op);
double calculate(double num1, double num2, char op);

void infix_to_postfix(Stack *stack, Queue *queue);
void evaluate_postfix(Stack *stack, Queue *queue);
void clear(Stack *stack, Queue *queue);

int main() {
    Stack stack;
    stack.top = -1;

    Queue queue;
    queue.back = -1;
    queue.front = -1;

    printf("Enter a mathematical expression...\n>> ");
    fgets(expression, sizeof(expression), stdin);
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
	expression[len - 1] = '\0';
    }

    infix_to_postfix(&stack, &queue);
    evaluate_postfix(&stack, &queue);

    printf("\nResult: %lf\n", peek(&stack)->value);

    clear(&stack, &queue);
    return 0;
}


void infix_to_postfix(Stack *stack, Queue *queue) {
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

void evaluate_postfix(Stack *stack, Queue *queue) {
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

double calculate(double num1, double num2, char op) {
    if (op == '+') return num1 + num2;
    if (op == '-') return num1 - num2;
    if (op == '*') return num1 * num2;
    if (op == '/') return num1 / num2;
    if (op == '^') return pow(num1, num2);
    return 0;
}

void push(Stack *stack, Token *token) {
    stack->list[++stack->top] = token;
}

Token *pop(Stack *stack) {
    if (stack->top == -1) return NULL;
    return stack->list[stack->top--];
}

Token *peek(Stack *stack) {
    if (stack->top == -1) return NULL;
    return stack->list[stack->top];
}

void enqueue(Queue *queue, Token *token) {
    queue->arr[++queue->back] = token;
}

Token *dequeue(Queue *queue) {
    if (queue->front == queue->back) return NULL;
    return queue->arr[++queue->front];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int is_right_associative(char op) {
    return op == '^';
}

void clear(Stack *stack, Queue *queue) {
	while (stack->top != -1) free(pop(stack));
	while (queue->front != queue->back) free(dequeue(queue));
}

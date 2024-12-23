#include <stdio.h>
#include <stdlib.h>

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
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

char expression[1025];

void infix_to_postfix(Stack *stack, Queue *queue);
void evaluate_postfix(Stack *stack, Queue *queue);

int main() {
    Stack stack;
    stack.top = -1;

    Queue queue;
    queue.back = -1;
    queue.front = -1;

    printf("Enter a mathematical expression...\n>> ");
    scanf("%s", expression);

    infix_to_postfix(&stack, &queue);
    evaluate_postfix(&stack, &queue);

    printf("\nResult: %lf\n", peek(&stack)->value);

    return 0;
}

void infix_to_postfix(Stack *stack, Queue *queue) {
     for (int i = 0; expression[i] != '\0'; i++) {
	Token *token = malloc(sizeof(Token));

	if (IS_DIGIT(expression[i]) || expression[i] == '.') {
	    double num = 0;
	    int decimal_place = 0;
	    while (IS_DIGIT(expression[i]) || expression[i] == '.') {
		if (expression[i] == '.') decimal_place = 1;
		else {
		    num = num * 10 + (expression[i] - '0');
		    if (decimal_place) decimal_place *= 10;
		}
		i++;
	    }
	    if (decimal_place) num /= decimal_place;
	    token->type = NUMBER;
	    token->value = num;
	    continue;
	} else {
	    token->type = OPERATOR;
	    token->op = expression[i];
	}

	if (token->type == NUMBER) {
	    enqueue(queue, token);
	    continue;
	}

	if (stack->top == -1) {
	    push(stack, token);
	    continue;
	}

	if (token->op != ')') {
	    while (stack->top != -1 && peek(stack)->op != '(') enqueue(queue, pop(stack));
	    pop(stack);
	    continue;
	}

	if (token->op == '(' && precedence(peek(stack)->op) > precedence(token->op)) enqueue(queue, pop(stack));
	push(stack, token);
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
	
	
    }
}

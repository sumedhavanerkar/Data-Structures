#include <stdio.h> 
#include <string.h> 
#define MAX 100000 
char stack[MAX]; 
int top = -1; 
void push(char c) { 
stack[++top] = c; 
} 
char pop() { 
if (top == -1) return '\0'; 
return stack[top--]; 
} 
int isMatching(char open, char close) { 
return (open == '(' && close == ')') || 
(open == '{' && close == '}') || 
(open == '[' && close == ']'); 
} 
int isBalanced(char *s) { 
    for (int i = 0; s[i]; i++) { 
        char c = s[i]; 
 
        if (c == '(' || c == '{' || c == '[') 
            push(c); 
        else { 
            if (top == -1) return 0; 
            char open = pop(); 
            if (!isMatching(open, c)) return 0; 
        } 
    } 
    return top == -1; 
} 
 
int main() { 
    char s[] = "{[()]}"; 
 
    if (isBalanced(s)) 
        printf("Balanced"); 
    else 
        printf("Not Balanced"); 
 
    printf("\nName: Sumedha Jayesh Vanerkar | PRN: 25070521245 | Section: E | Semester: 2nd | Year: 1st\n"); 
 
    return 0; 
}
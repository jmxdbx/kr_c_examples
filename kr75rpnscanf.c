/* K&R C, Exercise 7-5. */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100       /* max size of operand or operator */
#define MAXVAL 100      /* maximum depth of val stack */

void push(double);
double pop(void);

static int sp = 0;          /* next free stack position */
static double val[MAXVAL];  /* value stack */

int main()
{
    char *c;
    char s[MAXOP], buf[MAXOP];
    double a = 0, op2;
    char e = '\0';

    while (scanf("%s%c", s, &e) == 2) {
        if (sscanf(s, " %lf", &a) == 1) /* number */
            push(a);
        else if (sscanf(s, "%s", buf)) {
            for (c = buf ; *c; c++) {
                switch (*c) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                default:
                    printf("error: unknown command\n");
                    break;
                }
            }
            if (e == '\n')
                printf("\t%.8g\n", pop());
        }
    }
    return 0;
}

/* push: push f onto value stack*/
void push(double f)
{
   if (sp < MAXVAL)
       val[sp++] = f;
   else
       printf("error: stack full\n");
}

/* pop: pop and return top value from stack*/
double pop(void)
{
   if (sp > 0)
       return val[--sp];
   else {
       printf("error: stack empty\n");
       return 0.0;
   }
}

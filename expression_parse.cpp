#include<iostream>
#include<cstring>
using namespace std;
int isOperator(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c=='/' || c=='%')
    {
        return 2;
    }
    else if (c == '+' || c=='-')
    {
        return 1;
    }
    else if (c == '(' || c==')')
    {
        return -1;
    }
    else
    {
        return 0;
    }  
}
int InfixToPostfix(char* infix ,char* postfix)
{   
    char stack[10];
    int top = -1;
    int j=0;
    for (int i = 0; i < strlen(infix); i++)
    {   
        if (infix[i]=='(')
        {
            stack[++top]='(';
            continue;
        }
        if (infix[i] ==')')
        {
            while (stack[top]!='(')
            {
                postfix[j++]=stack[top--];
            }
            continue;
        }
        if (isOperator(infix[i]) == 0)
        {
            postfix[j++] = infix[i];
        }
        else{
            while (top != -1 && isOperator(infix[i])<=isOperator(stack[top]))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }        
    }
    while (top>=0)
    {   
        if (stack[top]!='(')
        {
            postfix[j++]= stack[top--];
        }
        else
        {
            top--;
        }
    }
    postfix[j++]='\0';    
}
int main()
{
    char infix[20],postfix[20];
    strcpy(infix,"a*b/c-d^2+e");
    strcpy(postfix,"");
    InfixToPostfix(infix,postfix);
    cout<<"Infix Expression : "<<infix<<endl;
    cout<<"Postfix Expression : "<<postfix<<endl;
    return 0;
}
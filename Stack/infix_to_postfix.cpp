#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

struct Node{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x){
    struct Node *t;
    t=new Node;
    if(t==NULL) cout<<"\nStack is Full."<<endl;
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

char pop(){
    struct Node *t;
    char x;
    if(top==NULL) cout<<"\nStack is Empty."<<endl;
    else{
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}

int pre(char x){
    if(x=='+'||x=='-') return 1;
    else if(x=='*'||x=='/') return 2;
    else return 0;
}

int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/') return 0;
    return 1;
}

char* InToPost(char *infix){
    char *postfix;
    int len=strlen(infix);
    int i=0,j=0;
    postfix=new char[len+2];
    while(infix[i]!=0){
        if(isOperand(infix[i])) postfix[j++]=infix[i++];
        else{
            if(pre(infix[i])>pre(top->data)) push(infix[i++]);
            else postfix[j++]=pop();
        }
    }
    while(top!=NULL) postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}

// MORE SPECIFIC METHOD:
int isOperand2(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}

char* InToPost2(char* infix){
    char* postfix = new char [strlen(infix) + 1];
    stack<char>stk;
    int i=0,j=0;
    while (infix[i] != '\0'){
        if (isOperand2(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top())){
                stk.push(infix[i++]);
            } else if (outPrecedence(infix[i]) == inPrecedence(stk.top())){
                stk.pop();
            }
            else {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }
    while (! stk.empty() && stk.top() != ')'){
        postfix[j++] = stk.top();
        stk.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int Eval(char *postfix){
    int i,x1,x2,r=0;
    stack<int> s;
    for(i=0; postfix[i]!=0;i++){
        if(isOperand2(postfix[i])) s.push(postfix[i]-'0');
        else{
            x2=s.top();
            s.pop();
            x1=s.top();
            s.pop();
            switch(postfix[i]){
                case '+':r=x1+x2; break;
                case '-':r=x1-x2; break;
                case '*':r=x1*x2; break;
                case '/':r=x1/x2; break;
            }
            s.push(r);
        }
    }
    return s.top();
}

int main(){
    char infix[]="a+b*c-d/e";
    char infix2[] = "((a+b)*c)-d^e^f";
    char infix3[] = "8+5*3-9/3";
    push('#'); //Program may give error if the stack is empty from the beginning
    cout<<"\n"<<InToPost(infix)<<endl;
    cout<<"\n"<<InToPost2(infix2)<<endl;
    cout<<"\n"<<Eval(InToPost2(infix3))<<endl;
    return 0;
}
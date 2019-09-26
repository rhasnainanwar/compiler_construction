#include<bits/stdc++.h> 
using namespace std; 

struct node 
{ 
    char value; 
    node *left, *right; 
};

bool isop(char c) 
{
    if (c == '+' || c == '-' || 
            c == '*' || c == '/' || 
            c == '^') 
        return true; 
    return false; 
}
  
// Utility function to do inorder traversal 
void inorder(node *t) 
{ 
    if(t) 
    {
        inorder(t->left); 
        printf("%c ", t->value); 
        inorder(t->right);
    }
} 

void find_terminals(node *t) 
{
    if(!t)
        return;
    if(!t->left && !t->right)
        printf("%c\n", t->value);
    find_terminals(t->left);
    find_terminals(t->right);
}

// A utility function to create a new node 
node* newNode(int v) 
{ 
    node *temp = new node; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 
  
// Returns root of constructed tree for given 
// postfix expression 
node* constructTree(char postfix[]) 
{ 
    stack<node *> st;
    node *t, *t1, *t2; 
  
    // Traverse through every character of 
    // input expression 
    for (int i=0; i<strlen(postfix); i++) 
    { 
        // If operand, simply push into stack 
        if (!isop(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else // operator 
        { 
            t = newNode(postfix[i]); 
  
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop(); 
  
            //  make them children 
            t->right = t1; 
            t->left = t2; 
  
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
  
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
  
    return t; 
}

void tree() 
{ 
    char postfix[] = "ab+ef*g*-"; 
    node* r = constructTree(postfix);

    printf("\nInfix expression is:\n"); 
    inorder(r);

    printf("\nTerminals are:\n");
    find_terminals(r);


    printf("\n");
}
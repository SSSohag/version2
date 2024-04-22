
//Creat a tree and print it in inorder
#include <stdio.h>

struct Node  //creat struct
{
    int value;
    struct Node * left, * right;
};

// the function print to preorder
// it is a recursive function
void explore (struct Node * root)
{
    if (root == NULL) { return; }
    else
    {
        printf (" %d ", root->value);
        explore (root->left); //function call recursiely
        explore (root->right); //function call recursiely
    }
}

int main() {

    int i=0, last = 0, current = 0;
    struct Node *root, *pleft, *pright, *list[2000];
    int n = 0;

    //creating the root.
    printf ("root value ? ");
    scanf ("%d", &n);
    root = (struct Node *) malloc (sizeof (struct Node)); //located a node
    root->value = n;
    root->left = NULL;
    root->right = NULL;
    list[0] = root;
    current = 0;
    last = 0;

    while (1)
    {
        if (current > last) { break; }

        if (list[current]->value == -99) { current++; continue; } //-99 is a terning value that's represents a blank child

        pleft = (struct Node *) malloc (sizeof (struct Node));
        pright = (struct Node *) malloc (sizeof (struct Node));

        printf ("left of %d? ", list[current]->value); //enter a left node after root
        scanf ("%d", &n);
        pleft->value = n;  pleft->left = NULL; pleft->right = NULL;

        printf ("right of %d? ", list[current]->value); // enter a right node after root
        scanf ("%d", &n);
        pright->value = n;   pright->left = NULL; pright->right = NULL;

        if (pleft->value == -99) { list[current]->left = NULL; }
        else { list[current]->left = pleft; }
        if (pright->value == -99) { list[current]->right = NULL; }
        else { list[current]->right = pright; }

        list[last+1] = pleft;
        list[last+2] = pright;
        last = last + 2;
        current++;
    }

    explore (root); // function call for print tree

    return 0;
}



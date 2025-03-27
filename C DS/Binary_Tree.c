
#include <stdio.h>
#include <stdlib.h>

//The node for the Binary Search Tree (BST)
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

//Creates a node for the BST
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//Inserts a new value into the BST
Node* insertBST(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    
    if (value < root->data)
        root->left = insertBST(root->left, value);

    else if (value > root->data)
        root->right = insertBST(root->right, value);
    
    return root;
}

//Searches for a value in the BST
int searchBST(Node* root, int key) {
    if (root == NULL)
        return 0;
    
    if (root->data == key)
        return 1;

    else if (key < root->data)
        return searchBST(root->left, key);
    
    else
        return searchBST(root->right, key);
}

//Finds the min value of the BST (used for deletion)
Node* findMin(Node* node) {
    while (node && node->left != NULL)
        node = node->left;

    return node;
}

//Removes a node from the BST
Node* deleteBST(Node* root, int key) {
    if (root == NULL)
        return NULL;
    
    if (key < root->data)
        root->left = deleteBST(root->left, key);

    else if (key > root->data)
        root->right = deleteBST(root->right, key);

    else {
        //Node to be deleted found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        //Node with two children: get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

//In-order traversal of the BST (to print the elements in sorted order)
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//Main function to test the BST implementation
int main() {
    Node* root = NULL;
    
    //Inserting values into the BST
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);
    
    printf("In-order da BST: ");
    inorder(root);
    printf("\n");
    
    //Searching for a value in the BST
    int key = 40;
    if (searchBST(root, key))
        printf("Valor %d encontrado na BST.\n", key);
    else
        printf("Valor %d não encontrado na BST.\n", key);
    
    //Removing a value from the BST
    root = deleteBST(root, 20);
    printf("In-order após remover 20: ");
    inorder(root);
    printf("\n");
    
    return 0;
}

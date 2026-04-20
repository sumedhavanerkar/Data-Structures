 #include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node *left, *right; 
}; 
 
struct Node* newNode(int data) { 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
 
struct Node* insert(struct Node* root, int data) { 
    if (root == NULL) return newNode(data);  
    if (data < root->data) 
        root->left = insert(root->left, data); 
    else 
        root->right = insert(root->right, data); 
    return root; 
} 
 
void printInRange(struct Node* root, int low, int high) { 
    if (root == NULL) return; 
 
    if (root->data > low) 
        printInRange(root->left, low, high); 
 
    if (root->data >= low && root->data <= high) 
        printf("%d ", root->data); 
 
    if (root->data < high) 
        printInRange(root->right, low, high); 
} 
 
int main() { 
    struct Node* root = NULL; 
    root = insert(root, 10); 
    insert(root, 5); 
    insert(root, 15); 
    insert(root, 3); 
    insert(root, 7); 
 
    int low = 5, high = 12; 
    printInRange(root, low, high); 
 
    printf("\nName: Sumedha Jayesh Vanerkar | PRN: 25070521245 | Section: E | Semester: 2nd | Year: 1st\n"); 
 
    return 0; 
} 
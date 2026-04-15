#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Folder Node
typedef struct Node {
    char name[50];
    struct Node *firstChild;
    struct Node *nextSibling;
} Node;

// Function to create a new folder
Node* createFolder(char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// Function to add a sub-folder (Child)
void addSubFolder(Node* parent, char name[]) {
    Node* newSub = createFolder(name);
    if (parent->firstChild == NULL) {
        parent->firstChild = newSub;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = newSub;
    }
    printf("Folder '%s' added inside '%s'.\n", name, parent->name);
}

// Function to display the structure (DFS)
void displaySystem(Node* root, int depth) {
    if (root == NULL) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("|-- %s\n", root->name);
    displaySystem(root->firstChild, depth + 1);
    displaySystem(root->nextSibling, depth);
}

int main() {
    Node* root = createFolder("C:/Documents");
    int choice;
    char folderName[50];

    while (1) {
        printf("\n--- File Explorer Menu ---\n");
        printf("1. Add Sub-folder to Root\n2. View Directory Structure\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter folder name: ");
                scanf("%s", folderName);
                addSubFolder(root, folderName);
                break;
            case 2:
                printf("\nDirectory Layout:\n");
                displaySystem(root, 0);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

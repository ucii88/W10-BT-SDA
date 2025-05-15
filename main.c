#include "BinSTree.h"

int main() {
    BinTree morseTree = Nil;
    int choice;
    char input[100], result[500];
     
    // Menu utama
    do {
        printf("\n===== PROGRAM Binary TREE =====\n");
        printf("1. Insert node\n");
        printf("2. Print Tree\n");
        printf("3. Traversal PreOrder\n");
        printf("4. Traversal InOrder\n");
        printf("5. Traversal PostOrder\n");
        printf("6. Traversal LevelOrder\n");
        printf("7. Search Node Tree\n");
        printf("8. Jumlah Daun/Leaf\n");
        printf("9. Mencari Kedalaman Node Tree\n");
        printf("10. Membandingkan 2 Node Tree\n");
        printf("11. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar(); // Ambil  newline
        
        switch (choice) {
            case 1: 

            case 2:
                // Print Tree
                printf("\n== Print Tree ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    PrintTree(morseTree, 0);
                }
                break;
                
            case 3:
                // Traversal PreOrder
                printf("\n== PreOrder Traversal ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    PreOrder(morseTree);
                    printf("\n");
                }
                break;
                
            case 4:
                // Traversal InOrder
                printf("\n== InOrder Traversal ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    InOrder(morseTree);
                    printf("\n");
                }
                break;
                
            case 5:
                // Traversal PostOrder
                printf("\n== PostOrder Traversal ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    PostOrder(morseTree);
                    printf("\n");
                }
                break;
                
            case 6:
                // Implementasi level order traversal (BFS)
                printf("\n== LevelOrder Traversal ==\n");
                if (IsEmpty(morseTree)) {
                    printf("Tree kosong!\n");
                } else {
                    // Implementasi sederhana BFS dengan array sebagai queue
                    BinTree queue[100];
                    int front = 0, rear = 0;
                    
                    queue[rear++] = morseTree;
                    
                    while (front < rear) {
                        BinTree current = queue[front++];
                        printf("%s ", Info(current));
                        
                        if (Left(current) != Nil) {
                            queue[rear++] = Left(current);
                        }
                        
                        if (Right(current) != Nil) {
                            queue[rear++] = Right(current);
                        }
                    }
                    printf("\n");
                }
                break;

            }

        }


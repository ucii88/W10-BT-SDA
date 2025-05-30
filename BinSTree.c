#include <stdio.h>
#include "BinSTree.h"

infotype GetAkar(BinTree P) {
    return Info(P);
}

BinTree GetLeft(BinTree P) {
    return Left(P);
}

BinTree GetRight(BinTree P) {
    return Right(P);
}

address1 AlokasiList(infotype X) {
    address1 P = (address1) malloc(sizeof(ElmtList));  // Alokasi untuk linked list
    if (P != NULL) {
        P->info = X;   // Set informasi
        P->next = NULL; // Pointer next diatur ke NULL
    }
    return P;
}

address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(Node));  // Alokasi untuk tree
    if (P != NULL) {
        P->info = strdup(X);  // Alokasi string untuk info
        P->left = NULL;
        P->right = NULL;
    }
    return P;
}

BinTree Tree(infotype Akar, BinTree L, BinTree R) {
    BinTree P = Alokasi(Akar);
    if (P != Nil) {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P) {
    *P = Alokasi(Akar);
    if (*P != Nil) {
        Left(*P) = L;
        Right(*P) = R;
    }
}

void BuildTree(BinTree *P) {
    char X[100];
    printf("Masukkan nilai node (9999 untuk node kosong): ");
    scanf("%s", X);

    if (strcmp(X, "9999") == 0) {
        *P = Nil;
    } else {
        *P = Alokasi(X);
        if (*P != Nil) {
            printf("Isi subtree kiri dari node %s:\n", X);
            BuildTree(&Left(*P));
            printf("Isi subtree kanan dari node %s:\n", X);
            BuildTree(&Right(*P));
        }
    }
}


boolean IsUnerLeft(BinTree P) {
    return !IsEmpty(P) && Left(P) != Nil && Right(P) == Nil;
}

boolean IsUnerRight(BinTree P) {
    return !IsEmpty(P) && Left(P) == Nil && Right(P) != Nil;
}

boolean IsBiner(BinTree P) {
    return !IsEmpty(P) && Left(P) != Nil && Right(P) != Nil;
}

boolean IsEmpty(BinTree P) {
    return P == Nil;
}

void PreOrder(BinTree P) {
    if (!IsEmpty(P)) {
        printf("%s ", Info(P));
        PreOrder(Left(P));
        PreOrder(Right(P));
    }
}

void InOrder(BinTree P) {
    if (!IsEmpty(P)) {
        InOrder(Left(P));
        printf("%s ", Info(P));
        InOrder(Right(P));
    }
}

void PostOrder(BinTree P) {
    if (!IsEmpty(P)) {
        PostOrder(Left(P));
        PostOrder(Right(P));
        printf("%s ", Info(P));
    }
}

void PrintNodeLevel(BinTree P, int level) {
    if (IsEmpty(P)) return;

    if (level == 1) {
        printf("Info node           : %s\n", Info(P));
        if (!IsEmpty(Left(P)))
            printf("Info node left son  : %s\n", Info(Left(P)));
        else
            printf("Info node left son  : Tidak ada\n");

        if (!IsEmpty(Right(P)))
            printf("Info node right son : %s\n", Info(Right(P)));
        else
            printf("Info node right son : Tidak ada\n");

        printf("\n");
    } else {
        PrintNodeLevel(Left(P), level - 1);
        PrintNodeLevel(Right(P), level - 1);
    }
}

void PrintTree(BinTree P, int h) {
    int d = Depth(P);
    for (int i = 1; i <= d; i++) {
        printf("Level %d:\n", i);
        PrintNodeLevel(P, i);
    }
}

boolean Search(BinTree P, infotype X) {
    if (IsEmpty(P)) {
        return false;
    }
    if (strcmp(Info(P), X) == 0) {
        return true;
    }
    return Search(Left(P), X) || Search(Right(P), X);
}

int nbElmt(BinTree P) {
    if (IsEmpty(P)) {
        return 0;
    } else {
        return 1 + nbElmt(Left(P)) + nbElmt(Right(P));
    }
}

int nbDaun(BinTree P) {
    if (IsEmpty(P)) {
        return 0;
    } else if (Left(P) == Nil && Right(P) == Nil) {
        return 1;
    } else {
        return nbDaun(Left(P)) + nbDaun(Right(P));
    }
}

boolean IsSkewLeft(BinTree P) {
    if (IsEmpty(P)) {
        return true;
    } else if (Right(P) != Nil) {
        return false;
    } else {
        return IsSkewLeft(Left(P));
    }
}

boolean IsSkewRight(BinTree P) {
    if (IsEmpty(P)) {
        return true;
    } else if (Left(P) != Nil) {
        return false;
    } else {
        return IsSkewRight(Right(P));
    }
}

int Level(BinTree P, infotype X) {
    if (IsEmpty(P)) {
        return 0; // tidak ditemukan
    }

    if (strcmp(Info(P), X) == 0) {
        return 1; // ditemukan di level 1
    }

    int leftLevel = Level(Left(P), X);
    if (leftLevel > 0) {
        return leftLevel + 1;
    }

    int rightLevel = Level(Right(P), X);
    if (rightLevel > 0) {
        return rightLevel + 1;
    }

    return 0; // tidak ditemukan di manapun
}

int Depth(BinTree P) {
    if (IsEmpty(P)) {
        return 0;
    } else {
        return 1 + Max(Depth(Left(P)), Depth(Right(P)));
    }
}

 int Max(int a, int b) {
    return (a > b) ? a : b;
}
  
void AddDaunTerkiri (BinTree *P, infotype X) {
    if (IsEmpty(*P)) {
        *P = Alokasi(X);
    } else {
        AddDaunTerkiri(&Left(*P), X);
    }
}
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri) {
    if (!IsEmpty(*P)) {
        if (Info(*P) == X && Left(*P) == Nil && Right(*P) == Nil) {
            if (Kiri) {
                Left(*P) = Alokasi(Y);
            } else {
                Right(*P) = Alokasi(Y);
            }
        } else {
            AddDaun(&Left(*P), X, Y, Kiri);
            AddDaun(&Right(*P), X, Y, Kiri);
        }
    }
}

void DelDaunTerkiri (BinTree *P, infotype *X) {
    if (Left(*P) == Nil && Right(*P) == Nil) {
        *X = Info(*P);
        DeAlokasi(*P);
        *P = Nil;
    } else if (Left(*P) != Nil) {
        DelDaunTerkiri(&Left(*P), X);
    } else {
        DelDaunTerkiri(&Right(*P), X);
    }
}

void DelDaun (BinTree *P, infotype X) {
    if (!IsEmpty(*P)) {
        if (Left(*P) == Nil && Right(*P) == Nil && Info(*P) == X) {
            DeAlokasi(*P);
            *P = Nil;
        } else {
            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}

void InsertLast(ElmtList **L, infotype X) {
    address1 P = AlokasiList(X);  
    if (P != NULL) {
        if (*L == NULL) {
            *L = P;  
        } else {
            address1 Last = *L;
            while (Last->next != NULL) {  
                Last = Last->next;
            }
            Last->next = P; 
        }
    }
}

ListOfNode MakeListDaun (BinTree P) {
    ListOfNode L = Nil;
    if (!IsEmpty(P)) {
        if (Left(P) == Nil && Right(P) == Nil) {
            InsertLast(&L, Info(P));
        } else {
            ListOfNode LL = MakeListDaun(Left(P));
            ListOfNode LR = MakeListDaun(Right(P));
            if (LL != Nil) {
                L = LL;
                address1 Last = LL;
                while (Next(Last) != Nil) {
                    Last = Next(Last);
                }
                Next(Last) = LR;
            } else {
                L = LR;
            }
        }
    }
    return L;
}

ListOfNode MakeListPreOrder (BinTree P) {
    ListOfNode L = Nil;
    if (!IsEmpty(P)) {
        InsertLast(&L, Info(P));
        ListOfNode LL = MakeListPreOrder(Left(P));
        ListOfNode LR = MakeListPreOrder(Right(P));
        if (L != Nil) {
            address1 Last = L;
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = LL;
            if (LL != Nil) {
                Last = LL;
                while (Next(Last) != Nil) {
                    Last = Next(Last);
                }
                Next(Last) = LR;
            } else {
                Next(Last) = LR;
            }
        }
    }
    return L;
}

void MakeListLevelHelper(BinTree P, int CurrLevel, int TargetLevel, ListOfNode *L) {
    if (!IsEmpty(P)) {
        if (CurrLevel == TargetLevel) {
            InsertLast(L, Info(P));
        } else if (CurrLevel < TargetLevel) {
            MakeListLevelHelper(Left(P), CurrLevel + 1, TargetLevel, L);
            MakeListLevelHelper(Right(P), CurrLevel + 1, TargetLevel, L);
        }
    }
}

ListOfNode MakeListLevel (BinTree P, int N) {
    ListOfNode L = Nil;
    MakeListLevelHelper(P, 1, N, &L);
    return L;
}

boolean BSearch (BinTree P, infotype X) {
    if (IsEmpty(P)) {
        return false;
    } else if (Info(P) == X) {
        return true;
    } else if (X < Info(P)) {
        return BSearch(Left(P), X);
    } else {
        return BSearch(Right(P), X);
    }
}

address BinSearch (BinTree P, infotype X) {
    if (IsEmpty(P)) {
        return Nil;
    } else if (Info(P) == X) {
        return P;
    } else if (X < Info(P)) {
        return BinSearch(Left(P), X);
    } else {
        return BinSearch(Right(P), X);
    }
}

void InsSearch (BinTree *P, infotype X) {
    if (IsEmpty(*P)) {
        *P = Alokasi(X);
    } else if (X < Info(*P)) {
        InsSearch(&Left(*P), X);
    } else if (X > Info(*P)) {
        InsSearch(&Right(*P), X);
    }
}

void DestroyTree(BinTree *P) {
    if (!IsEmpty(*P)) {
        DestroyTree(&Left(*P));
        DestroyTree(&Right(*P));
        DeAlokasi(*P);
        *P = Nil;
 }
}

void DelNode (BinTree *P) {
    if (Right(*P) != Nil) {
        DelNode(&Right(*P));
    } else {
        BinTree Q = *P;
        *P = Left(*P);
        DeAlokasi(Q);
    }
}

void DeAlokasi (address P) {
    if (P != Nil) {
        free(P->info); 
        free(P);
    }
}

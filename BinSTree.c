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
/***** Search *****/
boolean Search (BinTree P, infotype X);

/***** Fungsi Lain *****/
int nbElmt (BinTree P);
int nbDaun (BinTree P);
boolean IsSkewLeft (BinTree P);
boolean IsSkewRight (BinTree P);
int Level (BinTree P, infotype X);
int Depth (BinTree P);
int Max (infotype Data1, infotype Data2);
  
/***** Operasi Lain *****/
void AddDaunTerkiri (BinTree *P, infotype X);
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri);
void DelDaunTerkiri (BinTree *T, infotype *X);
void DelDaun (BinTree *T, infotype X);

/***** Manipulasi LIST OF NODE *****/
ListOfNode MakeListDaun (BinTree P);
ListOfNode MakeListPreOrder (BinTree P);
ListOfNode MakeListLevel (BinTree P, int N);

/***** Operasi untuk Binary Search Tree *****/
boolean BSearch (BinTree P, infotype X);
address BinSearch (BinTree P, infotype X);
void InsSearch (BinTree *P, infotype X);

void DestroyTree (BinTree *P);
void DelBTree (BinTree *P, infotype X);
void DelNode (BinTree *P);
void DeAlokasi (address P);

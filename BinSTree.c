#include <stdio.h>
#include "BinSTree.h"

/* Konstruktor */
address Alokasi (infotype X);
BinTree Tree (infotype Akar, BinTree L, BinTree R);
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P);
void BuildTree (BinTree *P);

/**** Predikat Penting *****/
boolean IsUnerLeft (BinTree P);
boolean IsUnerRight (BinTree P);
boolean IsBiner (BinTree P);
boolean IsEmpty (BinTree P);

/***** Traversal *****/
void PreOrder (BinTree P);
void InOrder (BinTree P);
void PostOrder (BinTree P);
void PrintTree (BinTree P, int h);

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

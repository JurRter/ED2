#include<stdio.h>
#include "BinTree.h"

int char2Int(char c){
  return c-'0';
}

TNo* ReadBinTree(char *treeStr, int *current){
  TNo* root = NULL; 
  if(treeStr[(*current)++]=='(' && treeStr[*current]!=')'){
    //Vamos ler a chave do no
    int key = 0;
    while(treeStr[*current]!=')' && treeStr[*current]!='(')
      key=10*key + char2Int(treeStr[(*current)++]);
    root = createNFill(key);
    //Vamos checar se não é uma folha
    if(treeStr[*current]=='('){ // Significa que há subarvores a serem lidas
      root->left = ReadBinTree(treeStr, current);
      root->right = ReadBinTree(treeStr, current);
    }
  }
  (*current)++;//para escapar do ')' da subarvore atual
  return root; 
}

int main(){
  char buffer[4096];
  //Índice global
  int current=0;
  fgets(buffer, 4096, stdin);
  BinTree *btree = BinTree_create();
  btree->root = ReadBinTree(buffer, &current);
  printf("PREORDER: ");
  BinTree_preorder(btree->root);
  putchar('\n');
  printf("INORDER: ");
  BinTree_inorder(btree->root);
  putchar('\n');
  return 0;
}
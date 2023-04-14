#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct noArv{
    int info;
    int h;
    struct noArv* esq;
    struct noArv* dir;
};
typedef struct noArv NoArv;

NoArv* cria_vazia(void){
    return NULL;
}
NoArv* arv_cria(int c,NoArv* sae,NoArv* sad){
    NoArv* p = (NoArv*)malloc(sizeof(NoArv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}
int vazia(NoArv* a){
    return a == NULL;
}
int folhas(NoArv* a){
    if(vazia(a))
        return 0;
    else if(a->esq == NULL && a->dir == NULL)
        return 1;
    else
        return nos(a->esq) + nos(a->dir);
}

int main(){
    NoArv* a1 = arv_cria(4,cria_vazia(),cria_vazia());
    NoArv* a2 = arv_cria(2,cria_vazia(),a1);
    NoArv* a3 = arv_cria(3,cria_vazia(),cria_vazia());
    NoArv* a4 = arv_cria(1,a2,a3);
    int qtdfolhas = folhas(a4);
    cout<<qtdfolhas;
}

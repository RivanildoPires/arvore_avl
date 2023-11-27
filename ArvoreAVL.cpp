#include <iostream>

using namespace std;


struct NoArvore{
    int key;
    int altura;
    NoArvore* esquerda;
    NoArvore* direita;
};

int altura(NoArvore *raiz) {
    if (raiz == NULL){
        return 0;}
    return raiz->altura;
}

int fatorDeBalanceamento(NoArvore *raiz) {
    if (raiz == NULL){
        return 0;
    }else{
        return altura(raiz->esquerda) - altura(raiz->direita);
    }
    
}

void atualizarAltura(NoArvore* raiz) {
    if (raiz != NULL){
        raiz->altura = max(altura(raiz->esquerda), altura(raiz->direita)) + 1;
        }
}

NoArvore* rotacaoEsquerda(NoArvore* x){
    NoArvore *y, *f;

    y = x -> direita;
    f = y -> esquerda;

    y -> esquerda = x;
    x -> direita = f;

    atualizarAltura(x);
    atualizarAltura(y);

    return y;
}
NoArvore* rotacaoDireita(NoArvore* y){
    NoArvore *x, *f;

    x = y -> direita;
    f = x -> esquerda;

    x -> esquerda = y;
    y -> direita = f;

    atualizarAltura(y);
    atualizarAltura(x);

    return x;

}
/*NoArvore* balancear(NoArvore *&raiz){

    int fb = fatorDeBalanceamento(raiz);

    if(fb < -1 && fatorDeBalanceamento(raiz->direita) <= 0){
        raiz = rotacaoEsquerda(raiz);
        return rotacaoEsquerda(raiz);
    }
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerda) >= 0){
        raiz = rotacaoDireita(raiz);
        return rotacaoDireita(raiz);
    }
    else if(fb > 1 && fatorDeBalanceamento(raiz -> esquerda) < 0){
        raiz -> esquerda = rotecaoEsquerdaDireita(raiz ->esquerda);
        return rotacaoDireita(raiz);
    }
    else if(fb < -1 && fatorDeBalanceamento(raiz -> direita) > 0){
        raiz -> direita = rotecaoDireitaEsquerda(raiz -> direita);
        return rotacaoEsquerda(raiz);
    }
    return raiz;
}*/

NoArvore* insercao(NoArvore *&raiz, int key){

    if(raiz == NULL){

        NoArvore* novoNo = new NoArvore;
        novoNo -> key = key;
        novoNo -> esquerda = NULL;
        novoNo -> direita = NULL;

        raiz = novoNo;
        return novoNo;
    }

        else{
        if(key > raiz -> key){
            raiz -> direita = insercao(raiz->direita,key);
        }
        else if(key < raiz -> key){
            raiz -> esquerda = insercao(raiz->esquerda,key);
        }
        else{
        return raiz;
        }
    atualizarAltura(raiz);

    int balancearo = fatorDeBalanceamento(raiz);

    if (balancearo > 1 && key < raiz->esquerda->key)
        return rotacaoDireita(raiz);

    if (balancearo < -1 && key > raiz->direita->key)
        return rotacaoEsquerda(raiz);

    if (balancearo > 1 && key > raiz->esquerda->key) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    if (balancearo < -1 && key < raiz->direita->key) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
    }
}

void listar(NoArvore* raiz){
    if(raiz != NULL){
        
        listar(raiz->esquerda);
        cout << raiz -> key  << " ";
        listar(raiz->direita);
    }
}

int main(){
    
    NoArvore* raiz = NULL;
    
    raiz = insercao (raiz,25);
    raiz = insercao (raiz,20);
    raiz = insercao (raiz,30);
    raiz = insercao (raiz,40);
    raiz = insercao (raiz,50);
    raiz = insercao (raiz,10);
    

    cout << "Arvore AVL em ordem: ";
    listar(raiz);


    return 0;
}


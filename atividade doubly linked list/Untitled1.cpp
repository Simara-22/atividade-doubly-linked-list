#include <iostream>
using namespace std;

struct No {
    int valor;
    No* ant;
    No* prox;
};

class Lista {
    No* inicio;
    No* fim;
    int tamanho;

public:
    Lista() {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }

    void inserirInicio(int valor) {
        No* novo = new No{valor, NULL, inicio};

        if (inicio != NULL)
            inicio->ant = novo;
        else
            fim = novo;

        inicio = novo;
        tamanho++;
    }

    void inserirFim(int valor) {
        No* novo = new No{valor, fim, NULL};

        if (fim != NULL)
            fim->prox = novo;
        else
            inicio = novo;

        fim = novo;
        tamanho++;
    }

    void inserirPosicao(int valor, int pos) {
        if (pos == 0) {
            inserirInicio(valor);
            return;
        }

        if (pos >= tamanho) {
            inserirFim(valor);
            return;
        }

        No* atual = inicio;

        for (int i = 0; i < pos; i++)
            atual = atual->prox;

        No* novo = new No{valor, atual->ant, atual};

        atual->ant->prox = novo;
        atual->ant = novo;
        tamanho++;
    }

    void removerInicio() {
        if (inicio == NULL) return;

        No* aux = inicio;
        inicio = inicio->prox;

        if (inicio != NULL)
            inicio->ant = NULL;
        else
            fim = NULL;

        delete aux;
        tamanho--;
    }

    void removerFim() {
        if (fim == NULL) return;

        No* aux = fim;
        fim = fim->ant;

        if (fim != NULL)
            fim->prox = NULL;
        else
            inicio = NULL;

        delete aux;
        tamanho--;
    }

    void removerPosicao(int pos) {
        if (pos < 0 || pos >= tamanho) return;

        if (pos == 0) {
            removerInicio();
            return;
        }

        if (pos == tamanho - 1) {
            removerFim();
            return;
        }

        No* atual = inicio;

        for (int i = 0; i < pos; i++)
            atual = atual->prox;

        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;

        delete atual;
        tamanho--;
    }

    int getTamanho() {
        return tamanho;
    }

    void imprimir() {
        No* atual = inicio;

        while (atual != NULL) {
            cout << atual->valor << " ";
            atual = atual->prox;
        }

        cout << endl;
    }

    void buscar(int valor) {
        No* atual = inicio;
        int pos = 0;

        while (atual != NULL) {
            if (atual->valor == valor) {
                cout << "Encontrado na posicao " << pos << endl;
                return;
            }

            atual = atual->prox;
            pos++;
        }

        cout << "Nao encontrado" << endl;
    }
};

int main() {
    Lista lista;

    lista.inserirInicio(10);
    lista.inserirFim(30);
    lista.inserirPosicao(20, 1);

    lista.imprimir();

    cout << "Tamanho: " << lista.getTamanho() << endl;

    lista.buscar(20);

    lista.removerInicio();
    lista.removerFim();
    lista.removerPosicao(0);

    lista.imprimir();

    return 0;
}
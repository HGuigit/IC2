#include <stdio.h>
#include <stdlib.h>

struct lista {
    int valor;
    struct lista *next;
};

typedef struct lista elemento;

void inserir_no_fim(elemento **h, int num);
int acha_maior(elemento **h);
void inverte_ate_o_maior(elemento **h);
void inverte_lista_toda(elemento **h);
void printar_lista(elemento *lista);
int acha_menor(elemento **h);
int exclui_retorna_ultimo(elemento **h);
elemento *criar_lista(void);

int main() {
    elemento *head;
    elemento *head_aux;
    int tam;
    int cont = 0;
    int num;
    int aux;
    head = criar_lista();
    head_aux = criar_lista();
    scanf("%d", &tam);
    do {
        scanf("%d", &num);
        inserir_no_fim(&head, num);

        cont++;
    } while (cont != tam);

    do {
        if ((head)->next != NULL) {
            inverte_ate_o_maior(&head);

            inverte_lista_toda(&head);
        }
        aux = exclui_retorna_ultimo(&head);

        inserir_no_fim(&head_aux, aux);

    } while ((head) != NULL);

    printar_lista(head_aux);
}

void inserir_no_fim(elemento **h, int num) {
    elemento *p;
    elemento *procura;
    procura = (*h);
    int flag = 0;
    p = (elemento *)malloc(sizeof(elemento));
    p->next = NULL;
    p->valor = num;

    if ((*h) == NULL) {
        (*h) = p;
    } else {
        do {
            if (procura->next == NULL) {
                procura->next = p;
                flag++;
            } else {
                procura = procura->next;
            }

        } while (flag != 1);
    }
}
int acha_menor(elemento **h) {
    int menor;
    elemento *search;
    search = (*h);
    menor = search->valor;

    do {
        if (search->valor < menor) {
            menor = search->valor;
        }

        search = search->next;

    } while (search != NULL);

    return menor;
}

int acha_maior(elemento **h) {
    int maior;
    elemento *search;
    search = (*h);
    maior = search->valor;

    do {
        if (search->valor > maior) {
            maior = search->valor;
        }

        search = search->next;

    } while (search != NULL);

    return maior;
}

void inverte_ate_o_maior(elemento **h) {
    elemento *ant;
    elemento *atual;
    elemento *prox;
    ant = NULL;
    atual = (*h);
    prox = (*h)->next;
    int maior = acha_maior(h);

    if (atual != NULL && prox != NULL) {
        do {
            if (atual != (*h)) {
                atual->next = ant;
            }
            if (atual->valor != maior) {
                ant = atual;
                atual = prox;
                prox = prox->next;
            }

            if (atual->valor == maior) {
                atual->next = ant;
                (*h)->next = prox;
                (*h) = atual;
            }
        } while (atual->valor != maior);
    } else if (prox == NULL) {
        (*h) = prox;
        prox->next = atual;
        atual->next = ant;
    }
}

void inverte_lista_toda(elemento **h) {
    elemento *ant;
    elemento *atual;
    elemento *prox;
    ant = NULL;
    atual = (*h);
    prox = (*h)->next;
    if (atual != NULL && prox != NULL) {
        do {
            atual->next = ant;
            if (prox != NULL) {
                ant = atual;
                atual = prox;
                prox = prox->next;
            }

            if (prox == NULL) {
                (*h) = atual;
                atual->next = ant;
            }

        } while (prox != NULL);
    } else if (prox == NULL) {
        (*h) = prox;
        prox->next = atual;
        atual->next = ant;
    }
}

void printar_lista(elemento *lista) {
    elemento *procura = lista;

    while (procura != NULL) {
        printf("%d ", procura->valor);
        procura = procura->next;
    }
}

elemento *criar_lista(void) {
    elemento *cabeca;
    cabeca = NULL;
    return cabeca;
}

int exclui_retorna_ultimo(elemento **h) {
    elemento *ant;
    elemento *atual;
    ant = NULL;
    atual = (*h);
    int num;
    if (atual->next == NULL) {
        num = atual->valor;
        (*h) = NULL;
        free(atual);
    } else {
        do {
            ant = atual;
            atual = atual->next;
            if (atual->next == NULL) {
                num = atual->valor;
                free(atual);
                ant->next = NULL;
            }

        } while (atual->next != NULL);
    }
    return num;
}
#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int a;
    struct nodo *next;
} nodo;

void add(nodo *t, int el)
{
    while (t->next!=NULL) {
        t = t->next;
    }
    nodo *p = malloc(sizeof(nodo));
    p->a = el;
    p->next = NULL;
    t->next = p;
}

void add2(nodo *t, int el)
{
    if (t->next==NULL) {
        nodo *p = malloc(sizeof(nodo));
        p->a = el;
        p->next =NULL;
        t->next = p;
        return;
    }
    add2(t->next, el);
}

void print (nodo *t)
{
    while (t!=NULL){
        printf("%d\n",t->a);
        t = t->next;
    }
}

void acquisisci (nodo *t)

{
	int a, b=0;
	FILE *stream = fopen("data.txt", "r");
	while (fscanf(stream, "%d", &a)==1) {
		add(t, a);
	}
	fclose(stream);
}

void scambia(nodo *t, nodo *min)
{
	int tmp, i;
	tmp = t->a;
	t->a=min->a;
	(min->next)->a = tmp;
}

void primo(nodo *t, nodo *testa, nodo *min)
{
	if (min==NULL) {
		min = malloc(sizeof(nodo));
		min->a = t->a;
		min->next = NULL;
	}
	if (t->a < min->a) {
		min->a = t->a;
		min->next = t;
	}
	if (t->next==NULL) {
		scambia(testa, min);
		if ((testa->next)->next!=NULL) 
			primo(testa->next, testa->next, NULL);
		return;
	}
	primo(t->next, testa, min);
}

void write(nodo * t)
{
    FILE *stream = fopen ("data.txt", "w");
    fprintf(stream, "\n");
    while (t!=NULL) {
        fprintf(stream, "%d", t->a);
        t = t->next;
    }

}


int main()
{
    nodo *t = malloc(sizeof(nodo));
    nodo *t2 = malloc(sizeof(nodo));
    nodo *min = NULL;
    t->next = t2;
    t->a = 452;
    t2->a = 3;
    t2->next = NULL;
    acquisisci(t);
    add2(t, 4);
    print(t);
    printf("\n");
    primo(t, t, min);
    print(t);
    write(t);
    return 0;
}

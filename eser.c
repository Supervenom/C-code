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
	int a;
	FILE *stream = fopen("data.txt", "r");
	while (fscanf(stream, "%d", &a)==1) {
		add2(t, a);
	}
	fclose(stream);
}

void scambia(nodo *t, nodo *min)
{
	int tmp;
	tmp = t->a;
	t->a=min->a;
	(min->next)->a = tmp;
}

void primo(nodo *t, nodo *testa, nodo *min)
{
	if (min==NULL) {
		min = malloc(sizeof(nodo));
		min->a = t->a;
		min->next = t;
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

void primo_iter(nodo *t, nodo *testa, nodo *min)
{
	while (t!=NULL) {
		if (min==NULL) {
			min = malloc(sizeof(nodo));
			min->a = t->a;
			min->next = t;
		}
		if (t->a < min->a) {
			min->a = t->a;
			min->next = t;
		}
		if (t->next==NULL) {
			scambia(testa, min);
			if ((testa->next)->next!=NULL) 
				primo_iter(testa->next, testa->next, NULL);
			return;
		}
		t = t->next;
	}

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
    print(t);
    printf("\n");
    primo(t, t, min);
    print(t);
    //write(t);
    return 0;
}

/* data.txt
54 765 761 38 4683 45 856 47 12 7 
86 19 586 7685 8273 8327 2324 4544 123 741 963*/

#include <stdio.h>


int mossa_ovvia(int x[3][3], int giocatore, int i, int j);
int gioca (int x[3][3], int giocatore);
int gioca_p (int x[3][3], int giocatore);
int mossa (int x[3][3], int giocatore, int i, int j);
int mossa_p (int x[3][3], int giocatore, int i, int j);


int vincente(int x[3][3]){
	int i;
	int j;
	int a;
	for (i=0;i<3;i++){
		a=0;
		for(j=0; j<2; j++) {
			if (x[i][j] == x[i][j+1]) a=a+1;
			if (a==2 && x[i][j]==1) return 1;
			if (a==2 && x[i][j]==2) return 2; 
		}
	}
	
	for (j=0;j<3;j++){
		a=0;
		for(i=0; i<2; i++) {
			if (x[i][j] == x[i+1][j]) a=a+1; 
			if (a==2 && x[i][j]==1) return 1;
			if (a==2 && x[i][j]==2) return 2;
		}	
	}
	
	a=0;
	for (j=0;j<2;j++)
	{
		if( x[j][j]==x[j+1][j+1]) a=a+1;
		if (a==2 && x[j][j]==1) return 1;
		if (a==2 && x[j][j]==2) return 2;
	}	
	a=0;
	for (j=0;j<2;j++){
		if (x[j][2-j]== x[j+1][1-j]) a=a+1;
		if (a==2 && x[j][j]==1) return 1;
		if (a==2 && x[j][j]==2) return 2;
	}
	
	return 0;
}

int pari (int x[3][3])
{
	int k,h;
	
	for (k=0; k<3; k++) {
		for (h=0;h<3;h++){
			if (x[k][h]==0) return 0;
		}
	}
	if (vincente(x)==0) return 1;
	return 0;
}

void stampa (int x[3][3])
{
    int i, j;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%d  ", x[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int gioca (int x[3][3], int giocatore) 
{
	int i, j;
	
	for (i=0; i<3; i++)
		for (j=0; j<3; j++) {
				if (x[i][j]==0 && mossa_ovvia(x, giocatore, i, j)!=0) {
					x[i][j] = giocatore;
					return giocatore;
				}
		}
	
	for (i=0; i<3; i++)
		for (j=0; j<3; j++) {
				if (x[i][j]==0 && mossa(x, giocatore, i, j)!=0) {
					x[i][j] = giocatore;
					return giocatore;
				}
		}
		
	/*for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
				if (x[i][j]==0 && mossa_p(x, giocatore, i, j)!=0) {
					x[i][j] = giocatore;
					//stampa(x);
					//printf("ok1\n");
					return 3;
				}
		}
	}	*/
	gioca_p(x, giocatore);	
	//if(!gioca_p(x, giocatore)) mossa_random(x, giocatore);
		
}

int gioca_p (int x[3][3], int giocatore) 
{
	int i, j;
	
	for (i=0; i<3; i++)
		for (j=0; j<3; j++) {
				if (x[i][j]==0 && mossa_ovvia(x, giocatore, i, j)!=0) {
					x[i][j] = giocatore;
					return giocatore;
				}
		}
	
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
				if (x[i][j]==0 && mossa_p(x, giocatore, i, j)!=0) {
					x[i][j] = giocatore;
					//stampa(x);
					//printf("ok1\n");
					return 3;
				}
		}
	}
}

int mossa_ovvia(int x[3][3], int giocatore, int i, int j)

{
	int x_copia[3][3], k, l;
	for (k=0; k<3; k++) {
		for (l=0; l<3; l++) {
			x_copia[k][l] = x[k][l];
		}
	}
	x_copia[i][j] = giocatore;
	if (vincente(x_copia) != 0) {
		//printf("Giocatore %d\n", giocatore);
		return giocatore;
	}
	x_copia[i][j] = 3-giocatore;
	if (vincente(x_copia) != 0) {
		//printf("Giocatore %d\n", giocatore);
		return giocatore;
	}
	return 0;
}

int mossa (int x[3][3], int giocatore, int i, int j)
{
	int x_copia[3][3], k, l;
	for (k=0; k<3; k++) {
		for (l=0; l<3; l++) {
			x_copia[k][l] = x[k][l];
		}
	}
	x_copia[i][j] = giocatore;
	if (vincente(x_copia) == giocatore) {
		//printf("Giocatore %d\n", giocatore);
		return giocatore;
	}
	if (gioca(x_copia, 3-giocatore) == 3-giocatore) return 0;
	//printf("ok2\n");
	return 1;
}

int mossa_p (int x[3][3], int giocatore, int i, int j)
{
	int x_copia[3][3], k, l;
	for (k=0; k<3; k++) {
		for (l=0; l<3; l++) {
			x_copia[k][l] = x[k][l];
		}
	}
	x_copia[i][j] = giocatore;
	//printf("Giocatore %d\n", giocatore);
	//stampa(x_copia);
	if (vincente(x_copia) == giocatore) {
		//printf("Giocatore %d\n", giocatore);
		return giocatore;
	}
	if (pari(x_copia)) {
		//printf("Pari %d  %d\n", i, j);
		return 3;
	}
	if (gioca_p(x_copia, 3-giocatore) == 3-giocatore) return 0;
	//printf("ok2_p\n");
	return 1;
}
	
int mossa_random (int x[3][3], int giocatore) 
{
	int i, j;
	
	for (i=0; i<3; i++) {
		for (j=0;j<3;j++){
			if (x[i][j]==0) { 
				x[i][j]=giocatore;
				printf("Giocatore %d, %d / %d  (mossa random)\n", giocatore, i+1, j+1);
				stampa(x);
				return 0;
			}
		}
	}
}


int gioca_umano (int x[3][3], int giocatore)
{
	int i;
	scanf("%d", &i);
	x[i/10][i%10]= giocatore;
}



int main () {
	
	int x[3][3]={{0,0,0},
                 {0,0,0},
                 {0,0,0}
                };
	int i=0, j, giocatore=1;
	stampa(x);
	while (vincente(x)==0 && pari(x)==0) {
		//if (i==1) break;
		if (giocatore%2==0) gioca(x, giocatore);
		else gioca_umano(x, giocatore);
		giocatore = 3-giocatore;
        printf("Mossa\n");
		stampa(x);
        i++;
    }
        
	if (vincente(x)) printf("Vince %d\n", vincente(x));
	if (pari(x)) printf("Avete pareggiato\n");
    return 0;
} 

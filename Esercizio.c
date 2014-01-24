#include <stdio.h>

int stampa_vettore(int vettore[],int n)
{
	 int i;
	 for(i=0;i<n;i++)
 		 printf("%d\t",vettore[i]);
	 printf("\n");
}

int maggiore( int a, int b)
{
	 if (a>b) return a;
	 else return b;
}

int fatt (int n)
{
	 if (n==0) return 1;
 	return (n *fatt(n-1));
}

int divisore_unico(int a, int b)
{
 	int i, contatore=0;
 	for (i=2; i<((maggiore(a, b)/2)+1); i++) {
  		if (a%i==0 && b%i==0) contatore ++;
 	}
 	if (contatore!=1) return 0;
 	return 1;
}

int controlla_vettore(int vett[], int n)
{
 	int i, j;
 	for (i=0; i<n-1; i++) {
 		 if (!divisore_unico(vett[i], vett[i+1])) return i+1;
 	}
 	return i+1;
}

void scambia(int v[], int a, int b)
{
	int tmp;
	tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;
}

/*int permutazioni(int vett[],int vett_max[], int n, int max, int k, int fat) {
 int i;
 int hold=0;
 if (fat==0) return stampa_vettore(vett_max,max);
 if (controlla_vettore(vett, n)>max) {
  max = controlla_vettore(vett, n);
  for (i=0; i<n; i++) {
   vett_max[i]=vett[i];
  }
 }
 hold = vett[k];
 vett[k] = vett[k+1];
 vett[k+1]= hold;
 stampa_vettore(vett, n);
 //printf("%d\n", fat);
 return permutazioni(vett, vett_max, n, max, (k==n-2) ? 0 : k+1, fat-1); 
}*/

void enumera(int i, int v[], int n, int v_max[], int *max, long int *fat)
{
	int k;
	if (i==n) {
		//printf("Max prima: %d\t", *max);
		//printf("Test: %d\t", controlla_vettore(v, 4));
		//stampa_vettore(v, n);
		if (controlla_vettore(v, n)>*max) {
  			
			*max = controlla_vettore(v, n);
  			for (i=0; i<n; i++) {
   				v_max[i]=v[i];
  			}
 		}
 		//stampa_vettore(v_max, max);
		(*fat)--;
 		if (*fat==0) stampa_vettore(v_max,*max);
 		//printf("Max dopo: %d\n", *max);
	}
	for (k=i; k<n; k++) {
		scambia (v, k, i);
		enumera(i+1, v, n, v_max, max, fat);
		scambia (v, k, i);
	}
}

int main()
{
 	int vett[]={ 21, 10, 17, 51, 14, 3, 5, 8 ,4};
 	//int vett[]={ 10, 2, 17, 51};
 	//int test[]={21, 14, 10, 5};
 	int vett_max[]={0, 0, 0, 0, 0, 0, 0, 0, 0};
 	//int vett_max[]={0, 0, 0, 0};
 	int n = 9;
	int max = 0;
	int *max_ptr = &max;
 	long int fat = fatt(n);
 	long int *fat_ptr = &fat;
 	enumera(0, vett, n, vett_max, max_ptr, fat_ptr);
 	
 	//printf("Test: %d\n", controlla_vettore(test, 4));
 	return 0;
}

/*procedure perm(i:integer);
 var k: integer;
 begin
 if i=n then scrivivettore(v,n)
 else
 for k:= i to n do begin
 scambia(v[k],v[i]);
 perm(i+1);
 scambia(v[k],v[i])
 end
 end;*/
 
#include <stdio.h>
 

void scambia(int v[], int a, int b)
{
	int tmp;
	tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;
}

void enumera(int i, int v[], n, int v_max[], int max)
{
	int k;
	if (i==LEN) stampa_vettore(v);
	for (k=i; k<LEN; k++) {
		scambia (v, k, i);
		enumera(i+1, v);
		scambia (v, k, i);
	}
}

int main()
{
	 int vett[]={21, 10, 14, 5};
	 enumera(0, vett);
}








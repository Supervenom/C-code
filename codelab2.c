#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cercaParola(char* parola, char *frase)

{
    int lenf = strlen(frase);
    int lenp = strlen(parola);
    int verit=1;
    int i=0, j=0, contatore=0,a=0;
	if (lenf<lenp) return 0;//potrebbe dare problemi
	do{for (i=0, j=a; i<lenf; i++,j++) {
		if (verit==1 && frase[i]!=parola[j] && frase[i]!=' ') {
    		verit = 0;
    	}
		if (frase[i]==' ') {
			if (verit==1&&(parola[j]=='\0'||parola[j]==',')) contatore++;
			j=a-1;
			verit=1;
		}
    }
    if (verit==1) contatore++;
    for(j=a,i=0;j<lenp;j++)
	{if(parola[j]==','){
	   a=j+1;
	   i=1;
	   j=lenp;
        }
    }
    }while(i);
    return contatore;
}


int main ()
{
    char frase[] = "ciao a al tutti e alla proprio al tutti";
    char parola[] = "e,tutti,al";//virgole da controllare
    printf("%d\n", cercaParola(parola,frase));
    return 0;
}

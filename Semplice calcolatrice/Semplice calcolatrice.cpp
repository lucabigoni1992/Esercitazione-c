#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int op; /* operazione richiesta */ int a, b, c; /* numeri inseriti ( a e b ) e risultato operazione ( c ) */ int err; /* condizione di errore */
	/* STAMPA LE POSSIBILI OPERAZIONI SVOLTE DALLA CALCOLATRICE */ 
	printf("Semplice calcolatrice\n\n");
	printf("Inserisci 1 per la somma\n"); 
	printf("Inserisci 2 per la sottrazione\n");
	printf("Inserisci 3 per la moltiplicazione\n"); 
	printf("Inserisci 4 per la divisione\n");
	/* LEGGI QUALE OPERAZIONE DEVE ESSERE SVOLTA */ 
	printf("La tua scelta:"); 
	scanf("%d", &op);
	/* LEGGI I NUMERI INSERITI */
	printf("Immetti il primo operando: "); 
	scanf("%d", &a);

	printf("Immetti il secondo operando: ");
	scanf("%d", &b);
	/* LA CONDIZIONE DI ERRORE VIENE INIZIALIZZATA */
	err = 0;
	/* ESEGUI L'OPERAZIONE RICHIESTA */ switch (op)
	{
	case 1:
		c = a + b;
		break;
	case 2:
		c = a - b;
		break;
	case 3:
		c = a * b;
		break;
	case 4:
		if (b == 0)
		{
			printf("Impossibiledividere per zero!\n");
			err = 1;
		}
		else
		{
			c = a / b;
		} break;
	default:
		printf("Operazioneerrata\n"); err = 1;
	}
	/* SE NON SI E' VERIFICATA NESSUNA CONDIZIONE DI ERRORE,
STAMPA IL RISULTATO */ if (err == 0)
printf("Ilrisultato vale: %d\n", c);

return(0);
}

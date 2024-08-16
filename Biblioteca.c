#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CLS system("cls")
#define CB fflush(stdin)
#define COR system("color f4")
#define QUEBRA_LINHA printf ("\n")
#define LINHA printf("\n\t\t---------------------------------------------");
#define MSG(x) printf("\n\t\t\t%s", (x))
#define MSGS(x, y) printf("\n\t\t\t%s%s", (x), (y))
#define MSGC(x, y) printf("\n\t\t\t%s%c", (x), (y))
#define MSGI(x, y) printf("\n\t\t\t%s%i", (x), (y))
#define MSGF(x, y) printf("\n\t\t\t%sR$ %.2f", (x), (y))
#define PAUSA system("pause")

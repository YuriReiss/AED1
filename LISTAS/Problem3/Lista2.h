#include "Elemento.h"
typedef struct lista Lista;
Lista * lista_cria ();
Lista * lista_copia (Lista * p);
void lista_libera (Lista * p);
int lista_insere_inicio (Lista * p, Elemento * e);
int lista_insere_final (Lista * p, Elemento * e);
int lista_insere_posicao (Lista * p, Elemento * e, int posicao);
int lista_remove_inicio (Lista * p);
int lista_remove_final  (Lista * p);
int lista_remove_posicao (Lista * p, int posicao);
Elemento * lista_obtem_elemento  (Lista * p, int posicao); /* retorna elemento em uma posicao */
int lista_se_presente  (Lista * p, char * nome); /* retorna posicao do elemento, ou zero se ausente */
int lista_obtem_tamanho  (Lista * p);
char * lista_imprime  (Lista * p);
void lista_ordena (Lista * p);

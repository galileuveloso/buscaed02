#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct {
	int hora;
	int min;
	int seg;
} t_time;

typedef struct {
	char * valor;
	t_time * time;
} t_timetable;

t_time * init_time() {
	t_time * time;
	
	time = (t_time*)malloc(sizeof(t_time));
	
	return time;
}

t_timetable * init_timetable() {
	t_timetable * tt;
	
	tt = (t_timetable*)malloc(sizeof(t_timetable) * 86400);
	
	tt->time = (t_time*)malloc(sizeof(t_time) * 86400);
	
	return tt;
}

int time_cmp(t_time h1, t_time h2) {
	if(h1.hora > 24 || h1.min > 60 || h1.seg > 60 || h2.hora > 24 || h2.min > 60 || h2.seg > 60)
		return NULL;
	
	if(h1.hora > h2.hora) return 1;
	if(h1.hora < h2.hora) return -1;
	if(h1.min > h2.min) return 1;
	if(h1.min < h2.min) return -1;
	if(h1.seg > h2.seg) return 1;
	if(h1.seg < h2.seg) return -2;
	return 0;
}

char * toString(t_time * time) {
	char hora[2];
	char min[2];
	char seg[2];
	
	char key[8];
	
	sprintf(hora, "%d", time->hora);
	sprintf(min, "%d", time->min);
	sprintf(seg, "%d", time->seg);
	
	key[0] = hora[0];
	key[1] = hora[1];
	key[2] = ':';
	key[3] = min[0];
	key[4] = min[1];
	key[5] = ':';
	key[6] = seg[0];
	key[7] = seg[1];
	
	return key;
}

t_time toTime(int hora, int minuto, int segundo){
	t_time time;
	time.hora = hora;
	time.min = minuto;
	time.seg = segundo;	
	return time;	
}

void put(t_time key, char * val, t_timetable * horarios[]) {
	
	int posicao = key.hora * key.min * key.seg;

	if(val == NULL || val == ""){
		horarios[posicao] == NULL;
	} else {
		t_time * timeInsert = init_time();
		timeInsert->hora = key.hora;
		timeInsert->min = key.min;
		timeInsert->seg = key.seg;
	
		horarios[posicao]->time = timeInsert;
		horarios[posicao]->valor = val;
	}
}

char * get(t_time key, t_timetable * horarios[]) {
	int posicao = key.hora * key.min * key.seg;
	
	return horarios[posicao]->valor;
}

void deletar(t_time key, t_timetable * horarios[]) {
	int posicao = key.hora * key.min * key.seg;
	horarios[posicao] = NULL;
}

bool contains(t_time key, t_timetable * horarios[]) {
	int posicao = key.hora * key.min * key.seg;
	
	if(horarios[posicao]->valor != NULL)
		return true;
	
	return false;
}

bool is_empty(t_timetable * horarios[]) {
	for(int i = 0; i<86400; i++){
		if (horarios[i] != NULL)
			return false;
	}
	
	return true;
}

int size(t_timetable * horarios[]) {
	int size = 0;
	for(int i = 0; i<86400; i++){
		if(horarios[i] != NULL){
			size++;
		}
	}
	return size;
}

t_time * min(t_timetable * horarios[]) {
	for(int i = 0; i<86400; i++){
		if(horarios[i] != NULL){
			return horarios[i]->time;
		}
	}
	return NULL;
}

t_time * max(t_timetable * horarios[]) {

	for(int i = 86400; i>= 0; i--){
		if(horarios[i] != NULL){
			return horarios[i]->time;
		}
	}
	return NULL;
}

t_time * floor(t_time key, t_timetable * horarios[]) {
	int posicao = key.hora * key.min * key.seg;
		
	for(int i = posicao; i <= 0; i--){
		if(horarios[i] != NULL){
			return horarios[i]->time;
		}
	}
	return NULL;
}

t_time * ceiling(t_time key, t_timetable * horarios[]) {
	int posicao = key.hora * key.min * key.seg;
		
	for(int i = posicao; i<86400; i++){
		if(horarios[i] != NULL){
			return horarios[i]->time;
		}
	}
	return NULL;
}

int rank(t_time key, t_timetable * horarios[]) {
	int posicao = key.hora * key.min * key.seg;
	int size = 0;
	
	for(int i = posicao; i>=0; i--){
		if(horarios[i] != NULL){
			size++;
		}
	}
	return size;
}

t_time select(int k) {
	
}

void delete_min(t_timetable * horarios[]) {
	t_time * minimo = min(horarios);
	int posicao = minimo->hora * minimo->min * minimo->seg;
	
	horarios[posicao] = NULL;
}

void delete_max(t_timetable * horarios[]) {
	t_time * maximo = max(horarios);
	int posicao = maximo->hora * maximo->min * maximo->seg;
	
	horarios[posicao] = NULL;
}

int size_range(t_time lo, t_time hi) {
	
}

t_time * keys(t_time lo, t_time hi) {
	
}

int main(int argc, char** argv) {
	
	t_timetable * horarios[86400];

	int op;
	int hora = 0;
	int min = 0;
	int seg = 0;
	char value[25];
	
	do {
		printf("1 - Put\n");	
		printf("2 - Get\n");	
		printf("3 - Delete\n");	
		printf("4 - Contains\n");
		printf("5 - Is Empty\n");	
		printf("6 - Size\n");	
		printf("7 - Min\n");	
		printf("8 - Max\n");
		printf("9 - Floor\n");	
		printf("10 - Ceiling\n");
		printf("11 - Rank\n");	
		printf("12 - Select\n");	
		printf("13 - Delete min\n");
		printf("14 - Delete max\n");	
		printf("15 - Size range\n");	
		printf("16 - Keys\n");	
		printf("0 - Sair\n");	
		
		scanf("%d", &op);
		
		switch (op){
			case 1: 
				printf("hora: ");
				scanf("%d", &hora);
				
				printf("minuto: ");
				scanf("%d", &min);
				
				printf("segundo: ");
				scanf("%d", &seg);
				
				printf("valor: ");
				scanf("%s", value);
				put(toTime(hora, min, seg), value, horarios);
				break;
			case 2: 
				printf("hora: ");
				scanf("%d", &hora);
				
				printf("minuto: ");
				scanf("%d", &min);
				
				printf("segundo: ");
				scanf("%d", &seg);
				
				get(toTime(hora, min, seg), horarios);
				break;
			case 3: 
				printf("hora: ");
				scanf("%d", &hora);
				
				printf("minuto: ");
				scanf("%d", &min);
				
				printf("segundo: ");
				scanf("%d", &seg);
				
				deletar(toTime(hora, min, seg), horarios);
				break;
			case 4: 
				printf("hora: ");
				scanf("%d", &hora);
				
				printf("minuto: ");
				scanf("%d", &min);
				
				printf("segundo: ");
				scanf("%d", &seg);
				
				contains(toTime(hora, min, seg), horarios);
				break;
			case 5: 
				printf("%s", is_empty(horarios));
				break;
			case 6: 
				printf("%d", size(horarios));
				break;
			case 7: 
				//t_time * min = min(horarios);
				//printf("%s", toString(min));
				break;
			case 8: 
				//printf("%s",toString(max(horarios)));
				break;
			case 9: 
				printf("hora: ");
				scanf("%d", &hora);
				
				printf("minuto: ");
				scanf("%d", &min);
				
				printf("segundo: ");
				scanf("%d", &seg);;
				printf("%s", toString(floor(toTime(hora, min, seg), horarios)));
				break;
			case 10: 
				printf("hora: ");
				scanf("%d", &hora);
				
				printf("minuto: ");
				scanf("%d", &min);
				
				printf("segundo: ");
				scanf("%d", &seg);
				printf("%s", toString(ceiling(toTime(hora, min, seg), horarios)));
				break;
			case 11:
				printf("hora: ");
				//scanf("%s", key);
				//printf("%d", rank((toTime(key))));
				break;
			case 12: 
				//TODO
				break;
			case 13: 
				delete_min(horarios);
				break;
			case 14: 
				delete_max(horarios);
				break;
				//TODO
			case 15: 
				//TODO
				break;
			default:
				break;
		}
	} while (op != 0);
	
	return 0;
}

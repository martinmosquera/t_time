#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct t_time{
    int H;
    int M;
    int S;
}time_k;

typedef struct t_timetable{
    char name[15];
    time_k key;
    struct t_timetable* next;
    struct t_timetable* ant;
}nodo;

typedef struct head{
    struct t_timetable* inicio;
    int count;
    struct t_timetable* max;
}Head;


typedef time_k* Time;
typedef Head* Table;
typedef nodo Nodo;

Table init_table();

void clear_table(Table table);

void put(Table table,Time key, char val[]);

char* get(Table table,Time key);

void borrar(Table table,Time key);

int contains(Table table,Time key);

int is_empty(Table table);

int size(Table table);

time_k min(Table table);

time_k max(Table table);

time_k floor(Table table,Time key);

time_k ceiling(Table table,Time key);

int rank(Table table,Time key);

time_k select(Table table,int k);

void delete_min(Table table);

void delete_max(Table table);

int size_range(Table table,time_k lo, time_k hi);

time_k* keys(Table table,time_k lo, time_k hi);

void print_table(Table table);

void print_menu();

void limpar_buffer();
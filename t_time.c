#include "t_time.h"


Table init_table(){

    Table table = (Table) malloc(sizeof(struct head));
    if(table == NULL) return NULL;
    table->inicio = NULL;
    table->count = 0;
    return table;
};

void clear_table(Table table){
    if(table == NULL) return;
    if(table->count == 0){
        free(table);
        printf("\n\tTabela liberada com sucesso!\n");
        return;
    }
    Nodo* aux;
    Nodo* ant;
    aux = table->inicio;
    while(aux->next != NULL){
        ant = aux;
        aux = aux->next;
        free(ant);
        table->count--;
    }
    free(table);
    printf("\n\tTabela liberada com sucesso!\n");
};

void put(Table table,Time key, char val[]){
    if(table == NULL) return;
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    if(nodo == NULL) return;

    (nodo->key.H) = key->H;
    (nodo->key.M) = key->M;
    (nodo->key.S) = key->S;
    strcpy(nodo->name,val);
    
    if (table->count == 0){
        table->inicio = nodo;
        table->count++;
        table->max = nodo;
        nodo->next = NULL;
        nodo->ant = NULL;
        return;
    }
        Nodo* aux;
        Nodo* ant;
        aux = table->inicio;
        int timeNew = (key->H*3600)+(key->M*60)+key->S;
        int timeExist = (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
        if(timeNew < timeExist){
            table->inicio = nodo;
            table->count++;
            aux->ant = nodo;
            nodo->next = aux;
        return;
        }      
        while((timeNew > timeExist) && (aux != NULL)){
            ant = aux;
            aux = aux->next;
            if(aux != NULL)
            timeExist = (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
        }
        if(aux == NULL){
            ant->next = nodo;
            nodo->ant = ant;
            nodo->next = NULL;
            table->count++;
            table->max = nodo;
            return;
        }
        nodo->next = aux;
        aux->ant = nodo;
        nodo->ant = ant;
        ant->next = nodo;
        table->count++;
    return;
};

char* get(Table table,Time key){
    if(table == NULL) return NULL;
    Nodo* aux = table->inicio;
    int timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    int timeNew = (key->H*3600)+(key->M*60)+key->S;
    while((timeOld != timeNew) && aux != NULL){
        aux = aux->next;
        timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    }
    if(aux == NULL){
        printf("O valor %d:%d:%d nao foi encontrado",key->H,key->M,key->S);
        return NULL;
    }
    return aux->name;
};

void borrar(Table table,Time key){
    if(table == NULL) return;
    Nodo* aux = table->inicio;
    Nodo* ant;
    int timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    int timemax = (table->max->key.H*3600)+(table->max->key.M*60)+(table->max->key.S);
    int timeNew = (key->H*3600)+(key->M*60)+key->S;
    if(timeNew < timeOld || timeNew > timemax){
        printf("\n\tO valor %d:%d:%d nao foi encontrado na tabela\n",key->H,key->M,key->S);
        return;
    }
    while((timeOld < timeNew) && aux != NULL){
        ant = aux;
        aux = aux->next;
        if(aux != NULL)
        timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    }
    if(aux == NULL){
        printf("O valor %d:%d:%d nao foi encontrado",key->H,key->M,key->S);
    }else{
        ant->next = aux->next;
        aux->next->ant = ant;
        free(aux);
        if(ant->next == NULL) table->max = ant;
        table->count--;
        printf("\n \tRegistro %d:%d:%d eliminado com sucesso!\n",key->H,key->M,key->S);
    }

};

int contains(Table table,Time key){
    if(table == NULL) return 0;

    Nodo* min = table->inicio;
    Nodo* max = table->inicio;
    int timemin =  (min->key.H*3600)+(min->key.M*60)+min->key.S;
    int timemax =  (max->key.H*3600)+(max->key.M*60)+max->key.S;
    int timeNew = (key->H*3600)+(key->M*60)+key->S;
    if(timeNew < timemin || timeNew > timemax) return -1;
    while((timemin != timeNew) && min != NULL){
        min = min->next;
        timemin =  (min->key.H*3600)+(min->key.M*60)+min->key.S;
    }
    if(min == NULL){
        printf("\n\tO valor %d:%d:%d nao foi encontrado\n",key->H,key->M,key->S);
        return -1;
    }
    return 1;

}

int is_empty(Table table){
    if(table == NULL) return 0;
    if(table->count == 0) return 1;
    else return -1;
}

int size(Table table){
    if(table == NULL) return 0;
    return table->count;
}

time_k min(Table table){
    return table->inicio->key;
}

time_k max(Table table){
    return table->max->key;
}

time_k floor(Table table,Time key){

    Nodo* aux = table->inicio;
    Nodo* ant;   
    int timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    int timeNew = (key->H*3600)+(key->M*60)+key->S;
    while((timeOld < timeNew) && aux != NULL){
        ant = aux;
        aux = aux->next;
        if(aux != NULL)
        timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    }
    if(aux == NULL){
        printf("\n\tO valor %d:%d:%d nao foi encontrado\n",key->H,key->M,key->S);
        time_k timeout;
        timeout.H = -1;
        return timeout;
        }
    else return ant->key;

}

time_k ceiling(Table table,Time key){

    Nodo* aux = table->inicio;
    Nodo* ant;   
    int timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    int timeNew = (key->H*3600)+(key->M*60)+key->S;
    while((timeOld < timeNew) && aux != NULL){
        ant = aux;
        aux = aux->next;
        if(aux != NULL)
        timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    }
    if(aux == NULL){
        printf("\n\tNao tem valores maiores de %d:%d:%d\n",key->H,key->M,key->S);
        time_k timeout;
        timeout.H = -1;
        return timeout;
    }else return aux->key;
}

int rank(Table table,Time key){
    if(table->count == 0) return 0;
     Nodo* aux = table->inicio;
    Nodo* ant;   
    int count = 0;
    int timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    int timeNew = (key->H*3600)+(key->M*60)+key->S;
    while((timeOld < timeNew) && aux != NULL){
        ant = aux;
        aux = aux->next;
        if(aux != NULL)
        timeOld =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
        count++;
    }
    return count;
}

time_k select(Table table,int k){

    if(table->count < k){
        printf("\n\tO dado sae fora da dimensao da tabela %d dados | Solicitado indice: %d\n",table->count,k);
        time_k timeout;
        timeout.H = -1;
        return timeout;
    }
    Nodo* aux = table->inicio; 
    int count = 0;
    while((count < k) && aux != NULL){
        aux = aux->next;
        count++;
    }
    return aux->key;
}

void delete_min(Table table){
    if(table ==  NULL) return;
    table->inicio = table->inicio->next;
    table->inicio->ant = NULL;
    table->count--;
}

void delete_max(Table table){
    if(table ==  NULL) return;
    table->max = table->max->ant;
    table->max->next = NULL;
    table->count--;
}

int size_range(Table table,time_k lo, time_k hi){
    
    Nodo* aux = table->inicio;
    Nodo* ant;
    int timemin = (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
    int timemax =  (table->max->key.H*3600)+(table->max->key.M*60)+table->max->key.S;
    int timelo = (lo.H*3600)+(lo.M*60)+lo.S;
    int timehi = (hi.H*3600)+(hi.M*60)+hi.S;
    if(timelo > timemax || timehi < timemin){
        printf("\n\tNao tem dados no rango informado\n");
        return -1;
    }
    int count = 0;
     while(timemin < timehi && timelo < timemax && aux != NULL){
        ant = aux;
        aux = aux->next;
        if(aux != NULL)
        timemin =  (aux->key.H*3600)+(aux->key.M*60)+aux->key.S;
        count++;
    }
    return count;
}

void print_table(Table table){
    if(table == NULL) return;
    Nodo* aux;
    aux = table->inicio;
    limpiar_pantalla();
    printf("\n=================================================\n");
    printf("|\t KEYS \t\t|\t VALUES\t\t|\n");
    while(aux != NULL){
        printf("|\t %d:%d:%d\t\t|\t%s\t\t|\n",aux->key.H,aux->key.M,aux->key.S,aux->name);
        aux = aux->next;
    }
    return;
}

void print_menu(){

    printf("=================================================\n");
    printf("|\t \t Implementacao de Busca\t\t|\n");
    printf("=================================================\n");
    printf("\t 1) Adicionar (Put)\n");
    printf("\t 2) Trazer (Get)\n");
    printf("\t 3) Apagar (Delete)\n");
    printf("\t 4) Existe uma chave (Y/N)\n");
    printf("\t 5) Esta vazio? (Empty?)\n");
    printf("\t 6) Tamanho (Size)\n");
    printf("\t 7) Trazer o Minimo (min)\n");
    printf("\t 8) Trazer o Maximo (min)\n");
    printf("\t 9) Maior chave armazenada menor ou igual a key (floor)\n");
    printf("\t 10) Menor chave armazenada maior ou igual a key (ceiling)\n");
    printf("\t 11) Numero de chaves armazenadas menores do que key (Rank)\n");
    printf("\t 12) Chave de rank igual a k (Search)\n");
    printf("\t 13) remove a menor chave (Delete Min)\n");
    printf("\t 14) remove a maior chave (Delete Max)\n");
    printf("\t 15) Numero de chaves armazenadas entre [lo..hi]\n");
    printf("\t 16) Chaves armazenadas entre [lo..hi]\n");
    printf("\t 17) Imprimir Tabela (print)\n");
    printf("\t 18) Sair - Exit\n");

    printf("Digite o numero correspondente a opcao desejada: ");
    

    
}

void limpar_buffer(void){
    char c;
    while(((c = getchar()) != '\n') && (c != EOF));
};

void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
};

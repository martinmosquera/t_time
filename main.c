#include "t_time.c"

int main()
{

    Table table;
    table = init_table();
    int resp;
    int size;
    char val[15];
    Time key;
    while (resp != 18)
    {

        print_menu();
        scanf("%d", &resp);
        limpiar_pantalla();

        switch (resp)
        {
        case 1:

            printf("====== INSERSAO DE DADOS ===========");
            printf("\n \t Digita o valor do time - Hora (00 - 23): ");
            scanf("%d", &key->H);
            printf("\n \t - Minutos (00 - 59): ");
            scanf("%d", &(key->M));
            printf("\n \t - Segundos (00 - 59): ");
            scanf("%d", &(key->S));
            printf("\n \t Digita o valor correspondente a key :");
            scanf("%s", &val);
            put(table, key, val);

            break;

        case 2:

            printf("\n \t======= PESQUISA DE VALOR =========\n");
            char *nome;
            printf("\n \t Digita o valor da key - Hora (00 - 23): ");
            scanf("%d", &(key->H));
            printf("\n \t - Minutos (00 - 59): ");
            scanf("%d", &(key->M));
            printf("\n \t - Segundos (00 - 59): ");
            scanf("%d", &(key->S));
            nome = get(table, key);
            printf("Valor encontrado: %s \n", nome);

            break;

        case 3:

            printf("\n \t======= APAGAR REGISTRO =========\n");
            printf("\n \t Digita o valor da key - Hora (00 - 23): ");
            scanf("%d", &(key->H));
            printf("\n \t - Minutos (00 - 59): ");
            scanf("%d", &(key->M));
            printf("\n \t - Segundos (00 - 59): ");
            scanf("%d", &(key->S));
            borrar(table, key);

            break;

        case 4:

            printf("\n \t======= PESQUISAR KEY =========\n");
            int boolean;
            printf("\n \t Digita o valor da key - Hora (00 - 23): ");
            scanf("%d", &(key->H));
            printf("\n \t - Minutos (00 - 59): ");
            scanf("%d", &(key->M));
            printf("\n \t - Segundos (00 - 59): ");
            scanf("%d", &(key->S));
            boolean = contains(table, key);
            if (boolean == 1)
                printf("\n\t KEY Achada na Tabela \n");
            else
                printf("\n\t A KEY nao foi achada na Tabela \n");

            break;

        case 5:

            printf("\n \t======= A TABELA ESTA VAZIA? =========\n");
            size = is_empty(table);
            if (size == 1)
                printf("\n\tA table esta vazia, simm\n");
            else
                printf("\n\tA table nao esta vazia ela tem %d dados \n", table->count);

            break;

        case 6:
            printf("\n \t======= TAMANHO DA TABELA =========\n");
            size = is_empty(table);
            printf("\n\t O tamanho de tabela e de %d dados \n", table->count);
            break;

        case 7:
            printf("\n \t======= MINIMO =========\n");
            time_k mini;
            mini = min(table);
            printf("\n\t A key com menor valor e : %d:%d:%d \n", mini.H, mini.M, mini.S);
            break;

        case 8:
            printf("\n \t======= MAXIMO =========\n");
            time_k maxi;
            maxi = max(table);
            printf("\n\t A key com maior valor e : %d:%d:%d \n", maxi.H, maxi.M, maxi.S);
            break;

        case 9:

            printf("\n \t======= FLOOR =========\n");
            printf("\n \t Digita o valor da key - Hora (00 - 23): ");
            scanf("%d", &(key->H));
            printf("\n \t - Minutos (00 - 59): ");
            scanf("%d", &(key->M));
            printf("\n \t - Segundos (00 - 59): ");
            scanf("%d", &(key->S));
            time_k flo;
            flo = floor(table, key);
            if(flo.H > -1)
            printf("\n\t A key com maior valor e : %d:%d:%d \n", flo.H, flo.M, flo.S);
            break;

        case 10:

            printf("\n \t======= CEILING =========\n");
            printf("\n \t Digita o valor da key - Hora (00 - 23): ");
            scanf("%d", &(key->H));
            printf("\n \t - Minutos (00 - 59): ");
            scanf("%d", &(key->M));
            printf("\n \t - Segundos (00 - 59): ");
            scanf("%d", &(key->S));
            time_k cei;
            cei = ceiling(table, key);
            if(cei.H > -1)
            printf("\n\t A key com maior valor e : %d:%d:%d \n", cei.H, cei.M, cei.S);
            break;

        case 11:

            printf("\n \t======= RANK - QUANTIDADE DE KEYS MENORES =========\n");
            printf("\n \t Digita o valor da key - Hora (00 - 23): ");
            scanf("%d", &(key->H));
            printf("\n \t - Minutos (00 - 59): ");
            scanf("%d", &(key->M));
            printf("\n \t - Segundos (00 - 59): ");
            scanf("%d", &(key->S));
            int qtd;
            qtd = rank(table, key);
            printf("\n\t O numero de keys menores que %d:%d:%d sao %d \n", key->H, key->M, key->S,qtd);
            break;

        case 12:

            printf("\n \t======= SELECT =========\n");
            int ind;
            printf("\n \t Digita o valor da indice: ");
            scanf("%d", &ind);
            time_k sel;
            sel = select(table, ind);
            if(sel.H > -1)
            printf("\n\t O numero de key no indice %d e -> %d:%d:%d\n",ind, sel.H, sel.M, sel.S);

            break;

        case 13:

            printf("\n \t======= DELETE MIN =========\n");
            delete_min(table);

            break;

        case 14:

            printf("\n \t======= DELETE MAX =========\n");
            delete_max(table);

            break;

        case 15:

            printf("\n \t======= QUANTIDADE DE DADOS NO RANGO =========\n");
            time_k lo;
            time_k hi;
            printf("\n \t Digita o valor da key inferior - Hora (00 - 23): ");
            scanf("%d", &(lo.H));
            printf("\n \t - Minutos (00 - 59): ");
            scanf("%d", &(lo.M));
            printf("\n \t - Segundos (00 - 59): ");
            scanf("%d", &(lo.S));
            printf("\n \t Digita o valor da key Superior - Hora (00 - 23): ");
            scanf("%d", &(hi.H));
            printf("\n \t - Minutos (00 - 59): ");
            scanf("%d", &(hi.M));
            printf("\n \t - Segundos (00 - 59): ");
            scanf("%d", &(hi.S));
            int tam;
            tam = size_range(table,lo,hi);
            if(tam > -1)
                printf("\n\tO Numero de registros no rango e de %d \n",tam);

            break;

        case 17:
            print_table(table);
            break;

        default:
            printf("saindo...");
            break;
        }
    }
    clear_table(table);
}
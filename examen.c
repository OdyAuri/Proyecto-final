// Proyecto final 
// Loaeza García Odethe Aurora

#include <stdio.h>
#define MAX 100
#define TOTAL 10
#define MIN 0

int main() 
{
    int vo[MAX][3];
    int vc[TOTAL] = {0}; 
    int po[MAX] = {0};
    int num = 0;
    
    int v1 = MIN, v2 = 0, v3 = 0; 
    
    // Almacenar votos
    printf("¡COMIENZA EL CONCURSO! \n\n");
    printf("Introduce tus 3 votos separados por espacios\n");
    
    while (!(v1 == -1) && num < MAX) 
    {
        printf("Eres el oyente %d \n", num);
        scanf("%d %d %d", &v1, &v2, &v3);
        // que solo lea 3
        char extra = ' ';
        while (extra != '\n') 
        {
            scanf("%c", &extra);
        }
        
        if (v1 == -1) 
        {
            // holi profe, aqui no puede estar vacio jeje :P
        }
        else 
        {
            if (v1 >= MIN && v1 < TOTAL && v2 >= MIN && v2 < TOTAL && v3 >= MIN && v3 < TOTAL) 
            {
                vo[num][0] = v1;
                vo[num][1] = v2;
                vo[num][2] = v3;
                vc[v1] += 3;
                vc[v2] += 2;
                vc[v3] += 1;
            
                num++;
            }
            else 
            {
                printf("ERROR \n ¡Las canciones solo van del 0 al 9 y son 3! \n Vuelve a intentar\n");
            }
        }
    }
    
    // Top 2
    int id_max1 = -1, max1 = -1;
    int id_max2 = -1, max2 = -1;
    
    printf("\nResultados de las votaciones\n");
    
    for (int i = 0; i < TOTAL; i++) 
    {
        printf("Cancion %d %d votos\n", i, vc[i]);
        
        if (vc[i] > max1) 
        {
            max2 = max1;
            id_max2 = id_max1;
            max1 = vc[i];
            id_max1 = i;
        } 
        else if (vc[i] > max2) 
        {
            max2 = vc[i];
            id_max2 = i;
        }
    }
    
    printf("\n1a cancion\n %d\n\n", id_max1);
    printf("2a cancion\n %d\n\n", id_max2);
    
    // Repartir puntos
    int ganador = -1;
    int maxp = -1;
    
    for (int i = 0; i < num; i++) 
    {
        int bienprimera = 0; 
        int biensegunda = 0;
        
        for (int j = 0; j < 3; j++) 
        {
            if (vo[i][j] == id_max1) 
              bienprimera = 1;
            if (vo[i][j] == id_max2) 
              biensegunda = 1;
        }
        
        if (bienprimera == 1) 
          po[i] += 30;
        if (biensegunda == 1)
          po[i] += 20;
        if (bienprimera == 1 && biensegunda == 1) 
          po[i] += 10; 
        
        printf("El oyente %d obtuvo %d puntos\n", i, po[i]);
        
        if (po[i] > maxp) 
        {
            maxp = po[i];
            ganador = i;
        }
    }
    
    if (num > 0) 
    {
        printf("\n¡El ganador es el Oyente %d con %d puntos! :D\n", ganador, maxp);
    } 
    else 
    {
        printf("\nNo hubo participantes :(\n");
         printf("\n Nadie gana buu");
    }

    return 0;
}

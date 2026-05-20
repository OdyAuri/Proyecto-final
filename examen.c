// Proyecto final 
// Loaeza García Odethe Aurora

#include <stdio.h>
#define MAX 100
#define TOTAL 10
#define MIN 0

int main() 
{
    // Usamos los define para darle tamaño a los arreglos
    int vo[MAX][3];
    int vc[TOTAL] = {0}; 
    int po[MAX] = {0};
    int num = 0;
    int v1 = MIN, v2 = 0, v3 = 0; 
    
    // Almacenar votos
    printf("Introduce los 3 votos separados por espacios\n");
    while (v1 >= MIN && num < MAX) 
    {
        printf("Oyente %d: \n", num);
        scanf("%d %d %d", &v1, &v2, &v3);
        
        if (v1 >= MIN) 
        {
            vo[num][0] = v1;
            vo[num][1] = v2;
            vo[num][2] = v3;
            vc[v1] += 3;
            vc[v2] += 2;
            vc[v3] += 1;
        
            num++;
        }
    }
    
    // Top 2
    int id_max1 = -1, max1 = -1;
    int id_max2 = -1, max2 = -1;
    
    printf("Resultados de las votaciones\n");
    
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
        else 
          if (vc[i] > max2) 
          {
            max2 = vc[i];
            id_max2 = i;
          }
    }
    
    printf("1a cancion\n %d\n\n", id_max1);
    printf("2a cancion\n %d\n\n", id_max2);
    
    //Repartir puntos
    int gana = -1;
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
        
        if (po[i] > max) 
        {
            maxp = po[i];
            gana = i;
        }
    }
    
    if (num > 0) 
    {
        printf("\nEl ganador es el Oyente %d con %d puntos.\n", ganador_id, max_puntos);
    } 
    else 
    {
        printf("\nNo hubo participantes.\n");
    }

    return 0;
}

// Proyecto final 
// Loaeza García Odethe Aurora

#include <stdio.h>
#define MAX 100
#define TOTAL 10
#define MIN 0

void Bienvenida() 
{
    printf("¡COMIENZA EL CONCURSO! \n\n");
    printf("Introduce tus 3 votos separados por espacios\n");
}

int VotoValido(int v1, int v2, int v3) 
{
    return (v1 >= MIN && v1 < TOTAL && v2 >= MIN && v2 < TOTAL && v3 >= MIN && v3 < TOTAL);
}

int CalcularPuntos(int v1, int v2, int v3, int id1, int id2) 
{
    int puntos = 0;
    int bienprimera = (v1 == id1 || v2 == id1 || v3 == id1);
    int biensegunda = (v1 == id2 || v2 == id2 || v3 == id2);
    
    if (bienprimera) puntos += 30;
    if (biensegunda) puntos += 20;
    if (bienprimera && biensegunda) puntos += 10;
    
    return puntos;
}

int main() 
{
    int vo[MAX][3];
    int vc[TOTAL] = {0}; 
    int po[MAX] = {0};
    int num = 0;
    int v1 = MIN, v2 = 0, v3 = 0; 
    
    Bienvenida();
    
    while (!(v1 == -1) && num < MAX) 
    {
        printf("Eres el oyente %d \n", num);
        scanf("%d %d %d", &v1, &v2, &v3);
        
        char extra = ' ';
        while (extra != '\n') scanf("%c", &extra);
        
        if (v1 != -1) 
        {
            if (VotoValido(v1, v2, v3)) 
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
    
    int id_max1 = -1, max1 = -1;
    int id_max2 = -1, max2 = -1;
    
    printf("\nResultados de las votaciones\n");
    for (int i = 0; i < TOTAL; i++) 
    {
        printf("Cancion %d %d votos\n", i, vc[i]);
        if (vc[i] > max1) 
        {
            max2 = max1; id_max2 = id_max1;
            max1 = vc[i]; id_max1 = i;
        } 
        else if (vc[i] > max2) 
        {
            max2 = vc[i]; id_max2 = i;
        }
    }
    
    printf("\n1a cancion: %d\n", id_max1);
    printf("2a cancion: %d\n\n", id_max2);
    
    int ganador = -1, maxp = -1;
    for (int i = 0; i < num; i++) 
    {
        po[i] = CalcularPuntos(vo[i][0], vo[i][1], vo[i][2], id_max1, id_max2);
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
        printf("\nNo hubo participantes :( Nadie gana buu\n");
    }
    return 0;
}

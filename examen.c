// Proyecto final 
// Loaeza García Odethe Aurora

#include <stdio.h>
#define MAX 100
#define TOPE 10
#define MIN 0

int vo[MAX][3];
int vc[TOPE] = {0}; 
int po[MAX] = {0};
int num = 0;

int id_max1 = -1, max1 = -1;
int id_max2 = -1, max2 = -1;

void Leer() 
{
    int v1 = MIN, v2 = 0, v3 = 0; 
    
    printf("¡COMIENZA EL CONCURSO! \n\n");
    printf("Los oyentes ingresaran los números asignados a cada canción por la que votan \n\n");
    
    while (!(v1 == -1) && num < MAX) 
    {
        printf("\n\nCANCIONES\n0. Locked Out of Heaven de Bruno Mars \n");
        printf("1. the 1 de Taylor Swift \n2. Levels de Avicii \n");
        printf("3. Shut up and Dance de WALK THE MOON \n4. Tormenta (feat. Bad Bunny) de Gorillaz\n");
        printf("5. Pierre de Ryn Weaver \n6. Are you bored yet? (feat. Clairo) de Wallows\n");
        printf("7. drop dead de Olivia Rodrigo \n8. Hot N cold de Katy Perry\n");
        printf("9. This Love de Maroon 5\n\n");
        printf("Eres el oyente %d ¡RECUERDALO!\n", num);
        printf("Introduce los números de las 3 canciones por las que votas separados por espacios\n");

        scanf("%d %d %d", &v1, &v2, &v3);
        
        char extra = ' ';
        while (extra != '\n') scanf("%c", &extra);
        
        if (v1 != -1) 
        {
            if ((v1 >= MIN && v1 < TOPE) && 
                (v2 >= MIN && v2 < TOPE) && 
                (v3 >= MIN && v3 < TOPE)) 
            {
                vo[num][0] = v1; vo[num][1] = v2; vo[num][2] = v3;
                vc[v1] += 3; vc[v2] += 2; vc[v3] += 1;
                num++;
            } 
            else printf("ERROR \n ¡Las canciones solo van del 0 al 9 y son 3! \n Vuelve a intentar\n\n");
        }
    }
}

void Top() 
{
    for (int i = 0; i < TOPE; i++) 
    {
        if (vc[i] > max1) 
        { 
            max2 = max1; id_max2 = id_max1; 
            max1 = vc[i]; id_max1 = i; 
        }
        else if (vc[i] > max2) max2 = vc[i]; id_max2 = i; 
    }
    printf("\nResultados de las votaciones\n");
    printf("1a cancion: %d\n", id_max1);
    printf("2a cancion: %d\n\n", id_max2);
}

void Repartir() 
{
    int ganador = -1, maxp = -1;
    for (int i = 0; i < num; i++) 
    {
        int puntos = 0;
        int bienprimera = (vo[i][0] == id_max1 || vo[i][1] == id_max1 || vo[i][2] == id_max1);
        int biensegunda = (vo[i][0] == id_max2 || vo[i][1] == id_max2 || vo[i][2] == id_max2);
        
        if (bienprimera) puntos += 30;
        if (biensegunda) puntos += 20;
        if (bienprimera && biensegunda) puntos += 10;
        
        po[i] = puntos;
        
        printf("El oyente %d obtuvo %d puntos\n", i, po[i]);
        if (po[i] > maxp) maxp = po[i]; ganador = i; 
    }
    
    if (num > 0) printf("\n¡El ganador es el oyente %d con %d puntos! \n\n ¡Felicidades oyente %d! :D\n", ganador, maxp, ganador);
    else printf("\nNo hubo participantes :,( Nadie gana buu\n");
}

int main() 
{
    Leer();
    Top();
    Repartir();
    
    return 0;
}

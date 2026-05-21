// Proyecto final 
// Loaeza García Odethe Aurora

#include <stdio.h>
#define MAX 100
#define TOPE 10
#define MIN 0

int Valido;
int PuntosCalc;

void Bienvenida() 
{
    printf("¡COMIENZA EL CONCURSO! \n\n");
    printf("Los oyentes ingresaran los números asignados a cada canción por la que votan \n\n");
}

void VotoValido(int v1, int v2, int v3) 
{
    if (v1 >= MIN && v1 < TOPE && v2 >= MIN && v2 < TOPE && v3 >= MIN && v3 < TOPE)
        Valido = 1; //sí
    else
        Valido = 0; //no
}

void CalcularPuntos(int v1, int v2, int v3, int id1, int id2) 
{
    PuntosCalc = 0;
    int bienprimera = (v1 == id1 || v2 == id1 || v3 == id1);
    int biensegunda = (v1 == id2 || v2 == id2 || v3 == id2);
    
    if (bienprimera) PuntosCalc += 30;
    if (biensegunda) PuntosCalc += 20;
    if (bienprimera && biensegunda) PuntosCalc += 10;
}

int main() 
{
    int vo[MAX][3];
    int vc[TOPE] = {0}; 
    int po[MAX] = {0};
    int num = 0;
    int v1 = MIN, v2 = 0, v3 = 0; 
    
    Bienvenida();
    
    while (!(v1 == -1) && num < MAX) 
    {
        printf("Eres el oyente %d ¡RECUERDALO!\n", num);
        printf("CANCIONES\n0. Locked Out of Heaven de Bruno Mars \n");
        printf("1. the 1 de Taylor Swift \n2. Levels de Avicii \n");
        printf("3. Shut up and Dance  de WALK THE MOON \n4. Tormenta (feat. Bad Bunny) de Gorillaz\n");
        printf("5. Pierre de Ryn Weaver \n6. Are you bored yet? (feat. Clairo) de Wallows\n");
        printf("7. drop dead de Olivia Rodrigo \n8. Hot N cold de Katty Parry\n");
        printf("9. This Love de Marron 5\n\n");
        printf("Introduce los números de las 3 canciones por las que votas separados por espacios\n");


        scanf("%d %d %d", &v1, &v2, &v3);
        char extra = ' ';
        while (extra != '\n') scanf("%c", &extra);
        
        if (v1 != -1) 
        {
            VotoValido(v1, v2, v3);
            
            if (Valido) 
            {
                vo[num][0] = v1; 
                vo[num][1] = v2; 
                vo[num][2] = v3;
                vc[v1] += 3; 
                vc[v2] += 2; 
                vc[v3] += 1;
                num++;
            } 
            else printf("ERROR \n ¡Las canciones solo van del 0 al 9 y son 3! \n Vuelve a intentar\n\n");
        }
    }
    
    int id_max1 = -1, max1 = -1;
    int id_max2 = -1, max2 = -1;
    
    for (int i = 0; i < TOPE; i++) 
    {
        if (vc[i] > max1) 
        { 
        max2 = max1; 
        id_max2 = id_max1; 
        max1 = vc[i];
        id_max1 = i; 
        }
        else 
        {
            if (vc[i] > max2) 
            { 
            max2 = vc[i]; 
            id_max2 = i; 
            }
        }
    }
    
    int ganador = -1, maxp = -1;
    for (int i = 0; i < num; i++) 
    {
        CalcularPuntos(vo[i][0], vo[i][1], vo[i][2], id_max1, id_max2);
        po[i] = PuntosCalc;
        
        printf("El oyente %d obtuvo %d puntos\n", i, po[i]);
        if (po[i] > maxp) 
        { 
        maxp = po[i]; 
        ganador = i; 
        }
    }
    
    if (num > 0) printf("\n¡El ganador es el oyente %d con %d puntos! \n\n ¡Felicidades oyente %d! :D\n", ganador, maxp, ganador);
    else printf("\nNo hubo participantes :,( Nadie gana buu\n");
    
    return 0;
}

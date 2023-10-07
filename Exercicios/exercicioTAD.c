#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	float cord_x;
	float cord_y;
}Ponto;

typedef struct{
    float raio;
    Ponto *ponto;
}Circulo;

Ponto* criar(float x, float y){
    Ponto *P = (Ponto*) malloc(sizeof(Ponto));

    if(P!=NULL){
        P->cord_x = x;
        P->cord_y = y;
    }

    return P;
}

void destruir(Ponto *P){
    free(P);
}

void acessar(Ponto *P, float *x, float *y){
    *x = P->cord_x;
    *y = P->cord_y;
}

void atribuir(Ponto *P, float x, float y){
    P->cord_x = x;
    P->cord_y = y;
}

float dist(Ponto *P1, Ponto *P2){
    float dx = P2->cord_x - P1->cord_x;
    float dy = P2->cord_y - P1->cord_y;

    return sqrt((dx*dx)+(dy*dy));
}

Circulo* criar_c(Ponto *P, float r){
    Circulo *c = (Circulo*) malloc(sizeof(Circulo));
    if(c!=NULL){
        c->ponto = P;
        c->raio = r;
    }

    return c;
}

void destruir_c(Circulo *c){
    free(c);
}

float area_c(Circulo *c){
    float r = c->raio;
    float a = r*r*(3.14);

    return a;
}

int interior_c(Ponto *p, Circulo *c){
    Ponto *pc = c->ponto;
    float ajuda = dist(p,pc);
    float r = c->raio;

    if(ajuda>r){
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
	Ponto *p1, *p2;
	float d, x1, x2, y1, y2;
	Circulo *c1, *c2;
	float r1, r2;
	int n;

	printf("Digite as cordenadas do primeiro ponto\n");
	scanf("%f%f", &x1, &y1);
	printf("Digite as cordenadas do segundo ponto\n");
	scanf("%f%f", &x2, &y2);

	p1 = criar(x1,y1);
	p2 = criar(x2,y2);
	d = dist(p1,p2);
	printf("A distancia é %.2f\n", d);

	printf("Digite o raio do primeiro circulo\n");
	scanf("%f", &r1);
	printf("Digite o raio do primeiro circulo\n");
	scanf("%f", &r2);

	c1 = criar_c(p1,r1);
	c2 = criar_c(p2,r2);

	printf("A area do circulo 1 eh: %.2f\n", area_c(c1));
	printf("A area do circulo 2 eh: %.2f\n", area_c(c2));

	if(interior_c(p2,c1)==1){
        printf("O ponto 2 pertence ao 1o circulo\n");
	}
	else{
        printf("O ponto 2 nao pertence ao 1o circulo\n");
	}

	destruir(p1);
	destruir(p2);
	destruir_c(c1);
	destruir_c(c2);


	return 0;
}

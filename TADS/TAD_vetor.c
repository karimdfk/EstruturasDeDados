#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

struct vetor {
	float *elem;
	int total;
	int max;
};

typedef struct vetor Vetor;

Vetor *criar(int n, bool *deuCerto)
{
	Vetor *v;
	v = (Vetor *) malloc(sizeof(Vetor));
	if (v == NULL) *deuCerto = false;
	else {
		// precisamos do else pois, se não deu certo, não podemos alocar o array
		v->elem = (float *) malloc(n * sizeof(float));
		if (v->elem == NULL) *deuCerto = false;
		else {
			*deuCerto = true;
			v->total = 0;
			v->max = n;
		}
	}

	return v;
}

void destruir(Vetor *v)
{
	free(v->elem);
	free(v);
}

bool cheio(Vetor *v)
{
	if (v->total == v->max)
		return true;
	else
		return false;
}

void inserir(Vetor *v, float X, bool *deuCerto)
{
	if (cheio(v) == false) {
		*deuCerto = true;
		v->elem[v->total] = X;
		v->total = v->total + 1;
	} else {
		*deuCerto = false;
	}
}

bool vazio(Vetor *v)
{
	if (v->total == 0)
		return true;
	else
		return false;
}

void mostrar(Vetor *v, int index, float *X, bool *deuCerto)
{
	if (vazio(v) == false) {
		if (index >= 0 && index < v->max) {
			*deuCerto = true;
			*X = v->elem[index];
		} else *deuCerto = false;
	} else *deuCerto = false;
}

int main()
{
	bool deuCerto;
	Vetor *v;
	int i, n;
	float valor;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);

	v = criar(n, &deuCerto);
	if (deuCerto == false) {
		printf("Erro ao criar vetor\n");
		exit(1);
	}

	i = 1;
	while (cheio(v) == false) {
		inserir(v, sqrt(i), &deuCerto);
		i = i+1;
	};

	i = 0;
	do {
		mostrar(v, i, &valor, &deuCerto);
		printf("%f ", valor);
		i = i+1;
	} while (deuCerto == true);
	printf("\n");

	destruir(v);

	return 0;
}

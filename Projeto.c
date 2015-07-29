#include <stdio.h>
#include <string.h>
#include <locale.h>

// Equipe: Lucas Figueiredo Pereira, Matheus Costa.//
// Faltaram algumas proteçoes de quebra ://

FILE* stream;

// Estrutura//
typedef struct
 {
 int matricula;
 char nome[100];
 char situacao[4][50];
 int nascimento;
 float nota[4][3];
 float media[4];
 char materia[4][100];
}cadastro;
cadastro aluno;

//protótipo da funçao//
void cadastro_aluno(void);
//protótipo da funçao//
void buscar_aluno(void);

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//abertura do arquivo//
if (stream = fopen("cadastro_aluno.txt","a+"))
	printf("Arquivo aberto com sucesso.\n\n");
	
	else{
	stream = fopen("cadastro_aluno.txt","w+");
	printf("Arquivo criado com sucesso.\n");		
}
system("color 0A");
fclose(stream);
int opcao;
do
{
// MENU //
printf("(1) - Cadastro de Aluno.\n");
printf("(2) - Busca de Aluno.\n");
printf("(3) - Sair do Programa.\n");
scanf("%d",&opcao);
system("cls");

switch(opcao){
	case 1: cadastro_aluno();break;
	case 2: buscar_aluno();break;
	case 3: system("PAUSE");break;
}
}while(opcao != 3);
}
// Cadastro de alunos //
void cadastro_aluno(void)
{
    int	n = 0;
    int m;
    int i;
    int info;
    
    // Faltou proteçoes de letra//
    stream = fopen("cadastro_aluno.txt","a");
    printf("Quantos alunos você deseja cadastrar:\n");
    scanf("%d",&info);
    system("cls");
    
    // Faltou proteçoes de numero//
    cadastro:
    for(i = 0;i < info;i++){
	puts("Informe o número da matrícula que deseja adicionar: ");
	scanf("%d",&aluno.matricula);
	fprintf(stream,"matricula: %d\n",aluno.matricula);
	system("cls");
	puts("Informe o nome do Aluno: ");
	scanf("%s",aluno.nome);
	fprintf(stream,"nome: %s\n",aluno.nome);
	system("cls");	
	puts("Informe a data de nascimento do Aluno (DD/MM/AA): ");
	scanf("%d", &aluno.nascimento);
	fprintf(stream,"data de nascimento: %d\n",aluno.nascimento);
	system("cls");
	
	// Faltou proteçoes de numero//
	materia:
	for(m = 0;m < 4;m++){
	puts("Informe o nome da matéria que deseja cadastrar:");
	scanf("%s",&aluno.materia[m]);
	fprintf(stream,"materia: %s\n",aluno.materia[m]);
	
	// Faltou proteçoes de letra//
	for(n=0;n < 3;n++){
	notas:
	printf("Informe a %d nota da matéria:\n",n+1);
	scanf("%f",&aluno.nota[m][n]);
	
	// Faltou proteçoes de letra/
	if(aluno.nota[m][n] >= 0 && aluno.nota[m][n] <= 10)
	fprintf(stream,"nota: %.3f\n",aluno.nota[m][n]);
	else{
	puts("Nota inválida!!, Só permitida notas de 0 a 10.");
	goto notas;
	}
	}
	// Media //
	aluno.media[m] = ((aluno.nota[m][0] + aluno.nota[m][1] + aluno.nota[m][2]) / 3);
	fprintf(stream,"media: %.3f\n",aluno.media[m]);
	if(aluno.media[m] >= 7.00){
    strcpy(aluno.situacao[m],"Aprovado");
	fprintf(stream,"situacao: %s\n",aluno.situacao[m]);
	}
	else{
	strcpy(aluno.situacao[m],"Reprovado");
	fprintf(stream,"situacao: %s\n",aluno.situacao[m]);
	}
	}
	}
	fclose(stream);
return;
}
// Busca de alunos //
void buscar_aluno(void)
{
	int busca;
	int achou = 0 ;
	int i;
	int j;
	// Faltou proteçoes de letra//
    stream = fopen("cadastro_aluno.txt","r");
    puts("Informe o número da matrícula:");
    scanf("%d",&busca);
    system("cls");
    
	while(!feof(stream) && (achou == 0))
	{
	fscanf(stream,"matricula: %d\n",&aluno.matricula);
	fscanf(stream,"nome: %s\n",&aluno.nome);
	fscanf(stream,"data de nascimento: %d\n",&aluno.nascimento);
	for (i=0; i<4; i++)
	{
		fscanf(stream,"materia: %s\n",&aluno.materia[i]);
		for (j=0; j<3; j++)
			fscanf(stream, "nota: %f\n", &aluno.nota[i][j]);
		fscanf(stream, "media: %f\n", &aluno.media[i]);
		fscanf(stream,"situacao: %s\n",&aluno.situacao[i]);
	}
	
	if(busca == aluno.matricula)
	{
		printf("matricula: %d\nnome: %s\nnascimento: %d\n\n",aluno.matricula,aluno.nome,aluno.nascimento);
		for (i=0; i<4; i++)
		{
			printf("materia: %s\n", aluno.materia[i]);
			for (j=0; j<3; j++)
			{
				printf("nota: %.3f\n", aluno.nota[i][j]);
			}
			printf("media: %.3f\nsituacao: %s\n\n", aluno.media[i], aluno.situacao[i]);
		}
		achou = 1;
	}
	}
	if (achou == 0)
		puts("matricula não cadastrada");
    fclose(stream);
return;
}
































#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 

void SelectionSort(int list[], int list2[], int n);	//Sort���
void SWAP(int* a, int* b);							//SWAP���
int whichBracket(char c);							//�P�_����جA��
int judgeBracket(char c);							//�P�_���A���k��or���O�A��
typedef struct Stack					//Stack
{
	int top;
	int array[256];
}Stack;

int main()
{
	int c = 0;							//��e���r��
	int arrayindex = 0;					//��e�}�Cindex
	int BracketError = 0;				//�p�G�t�異�� = 1
	int Match = 0;						//�A��Match�ƶq
	int Matcharray1[256] = { '\0' };	//match���A��index
	int Matcharray2[256] = { '\0' };	//match�k�A��index
	FILE* inFILE;						//input.txt
	FILE* outFILE;						//output.txt
	Stack CharStack;					//�r��Stack
	Stack IndexStack;					//IndexStack
	CharStack.top = -1;
	IndexStack.top = -1;
	
	fopen_s(&inFILE, "Input.txt", "r");		//�}��Input.txt
	fopen_s(&outFILE, "Output.txt", "w+");	//�}��Output.txt

	if (inFILE == NULL)						//�ɮ׶}�ҬO�_���`
	{
		printf("fail to open file");
		return -1;
	}

	while (c != EOF)
	{
		c = fgetc(inFILE);
		if (c == '\n' || c == EOF)								//��ƴ���
		{
			if (BracketError == 1|| CharStack.top != -1)								//�A���t�異��
			{													//��X���ɮ�
				fprintf(outFILE, "-1\n");
				fprintf(outFILE, "%d\n",IndexStack.array[0]);
			}
			else
			{													//��ưt�令�\
				SelectionSort(Matcharray1,Matcharray2, Match);	//�ƧǸ��
				fprintf(outFILE, "1\n");						//��X���ɮ�
				for (int i = 0; i < Match; i++)fprintf(outFILE, "%d,%d;", Matcharray1[i], Matcharray2[i]);
				fprintf(outFILE,"\n");
			}
			BracketError = 0;									//initialize
			arrayindex = 0;
			CharStack.top = -1;
			IndexStack.top = -1;
			Match = 0;
		}
		else
		{
			switch (judgeBracket(c))										//�P�_���A���k��
			{
			case 1:	CharStack.array[++(CharStack.top)] = c;										//�O���A��:pushchar & pushindex
					IndexStack.array[++(IndexStack.top)] = arrayindex;
					break;										
			case 2:	if (whichBracket(c) == whichBracket(CharStack.array[CharStack.top--]))	//�O�k�A��:pop & detect�O�_���T
					{
				Matcharray1[Match] = (IndexStack.array[IndexStack.top--]);
						Matcharray2[Match++] = arrayindex;
					}
					else BracketError = 1;
					break;
			default:break;
			}
			arrayindex++;
		}
	}
	fclose(inFILE);		//����Input.txt
	fclose(outFILE);	//����Output.txt
	return 0;
}


int judgeBracket(char c)
{
	if (c == '(' || c == '[' || c == '{') return 1;
	else if (c == ')' || c == ']' || c == '}') return 2;
	else return 0;
}

int whichBracket(char c)	
{
	if (c == '(' || c == ')') return 0;
	if (c == '[' || c == ']') return 1;
	if (c == '{' || c == '}') return 2;
}

void SelectionSort(int list[],int list2[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) if (list[j] < list[min]) min = j;
		SWAP(&list[i], &list[min]);
		SWAP(&list2[i], &list2[min]);
	}
}

void SWAP(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
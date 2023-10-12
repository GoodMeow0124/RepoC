#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 

void SelectionSort(int list[], int list2[], int n);	//Sort資料
void SWAP(int* a, int* b);							//SWAP資料
int whichBracket(char c);							//判斷為何種括號
int judgeBracket(char c);							//判斷左括號右刮號or不是括號
typedef struct Stack					//Stack
{
	int top;
	int array[256];
}Stack;

int main()
{
	int c = 0;							//當前文件字元
	int arrayindex = 0;					//當前陣列index
	int BracketError = 0;				//如果配對失敗 = 1
	int Match = 0;						//括號Match數量
	int Matcharray1[256] = { '\0' };	//match左括號index
	int Matcharray2[256] = { '\0' };	//match右括號index
	FILE* inFILE;						//input.txt
	FILE* outFILE;						//output.txt
	Stack CharStack;					//字元Stack
	Stack IndexStack;					//IndexStack
	CharStack.top = -1;
	IndexStack.top = -1;
	
	fopen_s(&inFILE, "Input.txt", "r");		//開啟Input.txt
	fopen_s(&outFILE, "Output.txt", "w+");	//開啟Output.txt

	if (inFILE == NULL)						//檔案開啟是否正常
	{
		printf("fail to open file");
		return -1;
	}

	while (c != EOF)
	{
		c = fgetc(inFILE);
		if (c == '\n' || c == EOF)								//資料換行
		{
			if (BracketError == 1|| CharStack.top != -1)								//括號配對失敗
			{													//輸出至檔案
				fprintf(outFILE, "-1\n");
				fprintf(outFILE, "%d\n",IndexStack.array[0]);
			}
			else
			{													//資料配對成功
				SelectionSort(Matcharray1,Matcharray2, Match);	//排序資料
				fprintf(outFILE, "1\n");						//輸出至檔案
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
			switch (judgeBracket(c))										//判斷左括號右刮號
			{
			case 1:	CharStack.array[++(CharStack.top)] = c;										//是左括號:pushchar & pushindex
					IndexStack.array[++(IndexStack.top)] = arrayindex;
					break;										
			case 2:	if (whichBracket(c) == whichBracket(CharStack.array[CharStack.top--]))	//是右括號:pop & detect是否正確
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
	fclose(inFILE);		//關閉Input.txt
	fclose(outFILE);	//關閉Output.txt
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
#include<stdio.h>
#pragma warning(disable : 4996)

int main()
{
	FILE *fp = nullptr;
	if ((fp = fopen("txt1.txt", "rt")) == NULL)
	{
		printf("\ncannot open!");
	}

	char ch;
	bool isspace = 1; 
	int record = 1;   //临时记录长度
	int length[11];
	
	for (int i = 0; i < 11; ++i)   //记录长度1-10+的单词的个数
		length[i] = 0;

	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == ' ' || ch == '\n' || ch == '\t')
		{
			if (isspace == 0)
			{
				isspace = 1;
				if (record > 10)
					++length[10];
				else
					++length[record - 1];
			}
		}
		else if (isspace == 1)
		{
			isspace = 0;
			record = 1;
		}
		else
			++record;

		ch = fgetc(fp);
	}
	//显示直方图
	for (int i = 0; i < 11; ++i)
	{
		if (i == 10)
			printf("10+");
		else if (i == 9)
			printf("010");
		else
		{
			printf("00");
			putchar('0' + i + 1);
		}

		printf(" | ");
		for (int j = 0; j < length[i]; ++j)
			printf("* ");
		putchar('\n');
	}

	printf("\n垂直直方图\n");
	
	int max = 0;
	for (int i = 0; i < 11; ++i)   //找最大频数
		if (max < length[i])
			max = length[i];

	for (int i = max; i >0; --i)
	{
		//做每一行的直方图
		putchar(' ');
		for (int j = 0; j < 41; ++j)
		{
			if (j % 4 == 0)
			{
				if (length[j / 4] >= i )
					putchar('*');
				else
					putchar(' ');
			}
			else
				putchar(' ');
		}
		putchar('\n');
	}
	printf("001 002 003 004 005 006 007 008 009 010 10+\n");
	return 0;
}

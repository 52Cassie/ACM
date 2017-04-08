#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define MAXN 50000

char v[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
int s[26] = { 4, 2, 5, 6, 1, 4, 5, 6, 7, 2, 3, 4, 8, 9, 3, 1, 2, 6, 8, 9, 2, 6, 3, 2, 5, 7 };

struct Words
{
	char word[30];
	int value;
	int length;
}words[MAXN];
int biao[MAXN] = { 0 };


int re(char c)
{
	int i;
	i = c - 'a';
	return s[i];
}

int main()
{
	int n, m;
	int i, j, max = -1;
	memset(words, 0, sizeof(words));

	scanf("%d%d", &n, &m);
		for (i = 0; i<n; i++)
		{
			scanf("%s", words[i].word);
			words[i].length = strlen(words[i].word);
			for (j = 0; j<words[i].length; j++)
			{
				words[i].value += re(words[i].word[j]);
			}
		}

		while (m--)
		{
			max = -1;
			for (i = 0; i<n; i++)
			{
				if (max <= words[i].value&&!biao[i])
				{
					if (max<words[i].value)
					{
						max = words[i].value;
						j = i;
					}
					else
					{
						if (words[j].length<words[i].length)
						{
							max = words[i].value;
							j = i;
						}
						if (words[j].length = words[i].length)
						{
							for (int k = 0; k<words[j].length; k++)
							{
								if (words[j].word[k]>words[i].word[k])
								{
									max = words[i].value;
									j = i;
									break;
								}
								if (words[j].word[k] < words[i].word[k])
								{
									break;
								}
							}
						}
					}
				}
			biao[j] = 1;
			printf("%s %d\n", words[j].word, words[j].value);
		}
	}
	return 0;

}
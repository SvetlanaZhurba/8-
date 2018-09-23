#include<stdio.h>
// определение символических констант
#define YES		1
#define NO		0
#define MAXLINE 1000

void process_line(char buffer[]);

int main(void)
{
	char line[MAXLINE];
	gets(line);
	process_line(line);
	puts(line);
	getchar();
	return 0;
}

void process_line(char buffer[])
{
	char *buf_ptr; // указатель на текущий символ буфера
	char *end; // указатель на конец слова
	char *begin; // указатель на начало слова
	char *dst; // указатель, хранящий в себе начало слова при удалении
	char c; // текущий символ
	char prev_c; // предыдущий символ
	int flag; // признак слова
	int found; // признак того, что буквы не повторились
	int repeat; // признак того, что буквы повторились

	flag = NO;
	found = NO;
	prev_c = ' ';
	repeat = NO;

	buf_ptr = buffer;
	begin = buffer;
	end = buffer;

	do 
	{
		c = *buf_ptr;

		if (c == ' ' || c =='_' || c == ',' || c == '.' || c == '\n' || c == '\0')
		{
			if (flag)
			{
				// найден первый разделить после слова
				end = buf_ptr;
				if ( !found && !repeat )
				{
					// в слове не встретились одинаковые буквы
					// слово нужно удалить
					dst = begin;
					// удаление слова (перенос оставшейся части
					// строки)
					while ( (*dst++ = *end++) != '\0' );
					buf_ptr = begin; // начать обработку строки с
									 // перенесённого фрагмента
				}
				else
					if (repeat)
						repeat = NO;
			}
			flag = NO;
		}
		else
		{
			if (!flag)   
				begin = buf_ptr;

			if (prev_c == c) 
				repeat = YES;
			else
				found = NO;
			
			flag = YES;	
		}
		prev_c = c;
		buf_ptr++;
	}
	while (!c);
}
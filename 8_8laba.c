#include<stdio.h>
// ����������� ������������� ��������
#define YES		1
#define NO		0
#define MAXLINE 1000

void process_line(char buffer[]);

void main(void)
{
	char line[MAXLINE];
	gets(line);
	process_line(line);
	puts(line);
	return 0;
}

void process_line(char buffer[])
{
	char *buf_ptr; // ��������� �� ������� ������ ������
	char *end; // ��������� �� ����� �����
	char *begin; // ��������� �� ������ �����
	char c; // ������� ������
	char prev_c; // ���������� ������
	int flag; // ������� �����
	int found; // ������� ����, ��� ����� �� �����������
	int repeat; // ������� ����, ��� ����� �����������

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

		if (c == ' ' || c =='_' || c == ',' || c == '\n' || c == '\0')
		{
			if (flag == YES)
			{
				// ������ ������ ��������� ����� �����
				end = buf_ptr - 1;
				if ((found == NO) && (repeat == NO))
				{
					// � ����� �� ����������� ���������� �����
					// ����� ����� �������
					char *src = end + 1;
					char *dst = begin;
					// �������� ����� (������� ���������� �����
					// ������)
					while ((*dst++ = *src++) != '\0');
					buf_ptr = begin; // ������ ��������� ������ �
									 // ������������ ���������
				}
				else
					if (repeat == YES)
						repeat = NO;
			}
			flag = NO;
		}
		else
		{
			if (flag == NO)   
				begin = buf_ptr;
			

			if (prev_c == c) 
			{
				
					repeat = YES;
				
			}
			else
				found = NO;
			
	
			flag = YES;
			
		}
		prev_c = c;
		buf_ptr++;
		
	}
	while (c != '\0');

}
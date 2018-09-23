#include<stdio.h>
// ����������� ������������� ��������
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
	char *buf_ptr; // ��������� �� ������� ������ ������
	char *end; // ��������� �� ����� �����
	char *begin; // ��������� �� ������ �����
	char *dst; // ���������, �������� � ���� ������ ����� ��� ��������
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

		if (c == ' ' || c =='_' || c == ',' || c == '.' || c == '\n' || c == '\0')
		{
			if (flag)
			{
				// ������ ������ ��������� ����� �����
				end = buf_ptr;
				if ( !found && !repeat )
				{
					// � ����� �� ����������� ���������� �����
					// ����� ����� �������
					dst = begin;
					// �������� ����� (������� ���������� �����
					// ������)
					while ( (*dst++ = *end++) != '\0' );
					buf_ptr = begin; // ������ ��������� ������ �
									 // ������������ ���������
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
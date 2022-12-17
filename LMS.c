#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void list();
void admin();
void controls();
void append();
void search();
void pass();
int p=2003;
int main()
{
	int i;
	printf("\nWelcome to the Library Management System.");
	printf("\nPress 1 to view the list of books.");
	printf("\nPress 2 to enter admin account.");
	printf("\nPress 3 to search for a book or author.");
	printf("\nEnter 4 to exit.");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			list();
			break;
		case 2:
			admin();
			break;
		case 3:
			search();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Enter valid number.");
			main();
			break;
	}
	return 0;
	
}
void list()
{
	FILE *li;
	char ch;
	int f;
	li=fopen("list.c","r");
	if(li==NULL)
	{
		printf("File not found");
	}
	while(ch !=EOF)
	{
		ch=fgetc(li);
		printf("%c",ch);
	}
	fclose(li);
	printf("\n\n\nEnter 1 to go to main menu and 0 to exit.");
	scanf("%d",&f);
	switch(f)
	{
		case 1:
			main();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Invalid selection.");
			break;
	}
}
void admin()
{
	int a,c,n,v,z;
	printf("\nEnter password");
	scanf("%d",&z);
	while(1)
	{
		if (z==p)
		{
			printf("Enter 1 to add books.");
			printf("\nEnter 2 to change password.");
			printf("\nEnter 3 to return to main menu");
			printf("\nEnter 4 to exit.\n");
			scanf("%d",&a);
			switch(a)
			{
				case 1:
					append();
					break;
				case 2:
				    pass();
				    break;
				case 4:
					exit(0);
					break;
				case 3:
					main();
					break;
				default:
					printf("Invalid choice");
					main();
					break;
			} 
		break;
		}
		else
		{
			printf("Password is incorrect.");
			printf("\nEnter 1 to re-enter password.");
			printf("\nEnter 2 to return to main menu.");
			printf("\nEnter 3 to exit.");
			scanf("%d",&v);
			switch(v)
			{
				case 1:
					admin();
					break;
				case 2:
					main();
					break;
				case 3:
					exit(0);
					break;
				default:
					printf("Invalid choice.");
					main();
					break;
			}
			break;
		}
	}
	
}
void append()
{
	FILE *li;
	char str[80],auth[80];
	char temp1,temp2;
	li=fopen("list.c","a");
	if(li==NULL)
	{
		printf("File not found");
	}
	printf("Enter name of new book:");
	scanf("%c",&temp1);
	scanf("%[^\n]", str);
	fprintf(li,"\n%s",str);
	printf("\nEnter author of new book:");
	scanf("%c",&temp2);
	scanf("%[^\n]", auth);
	fprintf(li,"\n%s",auth);
	fclose(li);
	main();
	
}
void pass()
{
	int y;
	printf("Enter new password");
	scanf("%d",&y);
	p=y;
	printf("\nThe new pin is %d",p);
	printf("\nLogin again.");
	admin();	
}
void search()
{
	char wrd[80],buffer[256];
	int m,line=0,i,n,j,q,x=0,b,r;
	printf("Enter the book or author you want to search");
	scanf("%d",&q);
	scanf("%s",wrd);
	m=strlen(wrd);
	FILE* li;
	li = fopen("list.c", "r");
	while (fgets(buffer, 256, li) != NULL) 
	{
		i = 0;
		n = strlen(buffer);
		while (i < n)
		{
			j = 0;
			while (i < n && j < m && buffer[i] == wrd[j]) 
			{
				++i, ++j;
			}
			if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
			{
				printf("\nSearch matched:");
				printf("Line: %d ", line+1);
				printf("Column: %d\n", i - m);
				printf("\nEnter 1 to search another book or author.");
				printf("\nEnter 2 to return to main menu.");
				printf("\nEnter 3 to exit.");
				scanf("%d",&r);
				switch(r)
				{
				case 1:
					search();
					break;
				case 2:
					main();
					break;
				case 3:
					exit(0);
					break;
				default:
					printf("Invalid choice.");
					main();
					break;
				}
				x=1;
			}
			while (i < n && buffer[i] != ' ')
			{
				++i;
			}
			++i;
		}
		++line;
	}
	if(x==0)
	{
		printf("Search unsuccessful");
		printf("\nEnter 1 to search again");
		printf("\nEnter 2 to return to main menu.");
		printf("\nEnter 3 to exit,");
		scanf("%d",&b);
		switch(b)
		{
				case 1:
					search();
					break;
				case 2:
					main();
					break;
				case 3:
					exit(0);
					break;
				default:
					printf("Invalid choice.");
					main();
					break;
		}
	}
	fclose(li);
}

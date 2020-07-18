#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact
{
	char name[20];
	unsigned long long mobile_no;
	char sex[10];
	char email[40];
	char address[20];

}s;


void add();
void display();
void search();
void update();
void delete();

int main()
{
			 
	char user[10],id[10];
	char user1[]="heroes",id1[]="qwerty123";
	
	again :
	system("clear");
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\t******************************************************\n\t\t\t\t\t\t\t***********************************");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t  ENTER THE USER NAME AND PASSWORD\n\t\t\t\t\t\t--______________________________________________--");
	printf("\n\n\n\t\t\t\t\t\t\t  USER NAME:-");
	scanf("%s",user);
       // sleep(2);
	printf("\n\t\t\t\t\t\t\t  PASSWORD:-");
	scanf("%s",id);

	if((strcmp(user,user1)==0) && (strcmp(id,id1)==0))
	{
		system("clear");//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t********* WELCOME ********\n\n\n\t\t\t\t\t\t\t YOU ENTER RIGHT PASSWORD\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t\t** PHONEBOOK APPLICATION **\n\t\t\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("\t\t\t\t\t\t\t\t y/n\n");
		char ch;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		getchar();
		scanf("%c",&ch);
		system("clear");
		
		if(ch == 'y')
		{
			int x,m1;
			do
			{
			system("clear");
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\t\t\t\t\t\tMENU\n\n\t\t\t\t\t\t\t1 - CONTACT LIST \n\t\t\t\t\t\t\t2 - ADD NEW CONTACT\n");
			printf("\t\t\t\t\t\t\t3 - SEARCH ANY CONTACT\n\t\t\t\t\t\t\t4 - UPDATION IN CONTACT LIST\n\t\t\t\t\t\t\t");
			printf("5 - DELETE ANY CONTACT\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			scanf("%d",&x);
			switch(x) 
			{
				case 1: display();
					break;

				case 2: add();
					break;

				case 3: search();
					break;

				case 4: update();
					break;

				case 5: delete();
					break;

				default : printf("\n\t\tYOU ENTER WRONG OPTION\n\n");

			}
			printf("\n\n\n\n\n\t\tPRESS\n\t\t1 - Go to MENU\n\t\t2 - Exit\n\n");
			scanf("%d",&m1);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			}while(m1 == 1);  
		}
	}
	else
	{
		char m1; int temp;
		printf("\n\n\n\t\t\t\t\t\tYOU ENTER INVALID USER_NAME OR PASSWORD\n");
		printf("\n\n\t\t\t\t\t\t   If you want retry press y/n ");
		getchar();	
		scanf("%c",&m1);
		printf("\n\n\n\n\n\n\n\n");
		if(m1 == 'y')
		 goto again;
		
			
		printf("\n\n\n\n\n\n\n\n");
	}

	printf("\n\n\n\n\n\n\n");
	return 0;
}


void add()
{
	FILE *fp;
	fp = fopen("mohsin.txt","a");	
		
	system("clear");
	printf("\n\n\n\n\t\t\tENTER THE CONTACT\n\n");

	printf("\t\tenter the name : ");
	scanf("%s",s.name);
	printf("\n\t\tenter mobile no. :");
	scanf("%llu",&s.mobile_no);
	printf("\n\t\tenter sex : ");
	scanf("%s",s.sex);
	printf("\n\t\tEnter email id : ");
	scanf("%s",s.email);
	printf("\n\t\tenter Address : ");
	scanf("%s",s.address);

	fwrite(&s, sizeof(s), 1, fp);
	
	
	fclose(fp);
}



void display()
{
	FILE *fp1;
	fp1 = fopen("mohsin.txt","r");
	system("clear");
	if(fp1 == NULL)
		printf("\t\tNO CONTACT\n");
	else
	{	
		while(fread(&s, sizeof(s), 1, fp1))
			printf("\n\t\tNAME = %s\n\t\tMOBILE NO. = %llu\n\t\tSEX = %s\n\t\tEMAIL ID = %s\n\t\tADDRESS = %s\n\n",s.name,s.mobile_no,s.sex,s.email,s.address);
	}
	
	fclose(fp1);
}




void search()
{
	char search[20];
	int k=1,t=0;
	system("clear");
	FILE *fp2;

	printf("\n\n\n\n\n\n\t\t\t\t\tENTER THE NAME WHICH YOU WANT TO SERCH\n\n\n\t\t\t\t\t\t  NAME :-");
	scanf("%s",search);
	
	fp2 = fopen("mohsin.txt","r");
	while(fread(&s, sizeof(s), 1, fp2))
	{
		k = strcmp(search,s.name);
		if(k == 0)
		{
			t = 1;
			printf("\n\t\tNAME = %s\n\t\tMOBILE NO. = %llu\n\t\tSEX = %s\n\t\tEMAIL ID = %s\n\t\tADDRESS = %s\n\n",s.name,s.mobile_no,s.sex,s.email,s.address);
		
		}
	}
	if(t == 0)
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t        CONTACT NOT FOUND\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

	fclose(fp2);		
}

void update()
{
	system("clear");
	struct contact s1;
	char search[20];
	int k=1,t=0;
	FILE *fp5,*fp6;

	printf("\n\n\n\n\n\n\t\t\t\t\tENTER THE NAME WHICH YOU WANT TO EDIT\n\n\n\t\t\t\t\t\t  NAME :-");
	scanf("%s",search);
	
	fp5 = fopen("mohsin.txt","r");
	fp6 = fopen("temp.txt","w");

	while(fread(&s, sizeof(s), 1, fp5))
	{
		k = strcmp(search,s.name);
		if(k == 0)
		{
			t=1;
			printf("\n\t\t\t\t\tPREVIOUS DATA\n");
			printf("\n\t\tNAME = %s\n\t\tMOBILE NO. = %llu\n\t\tSEX = %s\n\t\tEMAIL ID = %s\n\t\tADDRESS = %s\n\n",s.name,s.mobile_no,s.sex,s.email,s.address);
			printf("\n\n\n\n\t\t\t\t\tEDIT YOUR DATA\n\n");
			
			printf("\t\tenter the name : ");
			scanf("%s",s1.name);
			printf("\n\t\tenter mobile no. :");
			scanf("%llu",&s1.mobile_no);
			printf("\n\t\tenter sex : ");
			scanf("%s",s1.sex);
			printf("\n\t\tEnter email id : ");
			scanf("%s",s1.email);
			printf("\n\t\tenter Address : ");
			scanf("%s",s1.address);

			fwrite(&s1, sizeof(s1), 1, fp6);
			continue;	
		}
		fwrite(&s, sizeof(s), 1, fp6);
	}

	if(t == 0)
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t        CONTACT NOT FOUND\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	if(t == 1)
	{
	remove("mohsin.txt");
	fclose(fp5);
	fclose(fp6);

	fp5 = fopen("mohsin.txt","w");
	fp6 = fopen("temp.txt","r");

	while(fread(&s, sizeof(s), 1, fp6))
		fwrite(&s,sizeof(s),1,fp5);

			printf("\n\n\n\n\n\n\n\n\t\t\t\t\t        EDIT SUCCESSFULLY\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	fclose(fp5);
	fclose(fp6);
		
}

void delete()
{
	system("clear");
	FILE *fp3,*fp4;
	char search[20];
	int k=1,t=0;

	fp3 = fopen("mohsin.txt","r");
	fp4 = fopen("temp.txt","w");

	printf("\n\n\n\n\n\n\t\t\t\t\tENTER THE NAME WHICH YOU WANT TO DELETE\n\n\n\t\t\t\t\t\t  NAME :-");
	scanf("%s",search);
	
	while(fread(&s, sizeof(s), 1, fp3))
	{
		k = strcmp(search,s.name);
		if(k == 0)
		{
			t=1;
			continue;
		}
		fwrite(&s, sizeof(s), 1, fp4);
	}
	if(t == 0)
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t        CONTACT NOT FOUND\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	if(t == 1)
	{
	remove("mohsin.txt");
	fclose(fp3);
	fclose(fp4);

	fp3 = fopen("mohsin.txt","w");
	fp4 = fopen("temp.txt","r");

	while(fread(&s, sizeof(s), 1, fp4))
		fwrite(&s,sizeof(s),1,fp3);

		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t        DELETE SUCCESSFULLY\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	fclose(fp3);
	fclose(fp4);
}












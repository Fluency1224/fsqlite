#include  <stdio.h>
#include  <stdlib.h>
#include  <sqlite3.h>

sqlite3   *db;  

int func(void *para, int f_num, char **f_value, char **f_name)
{
	int  i;
	
	printf("*****************************\n");
	for (i=0; i<f_num; i++)
	{
		printf("%s :  %s\n",  f_name[i], f_value[i]);
		sleep(1);
	}
	return  0;	
}

void show()
{      
	char  *errmsg,**resultp;
	int  nrow,  ncolumn, i, j, index;	
	
	if  (sqlite3_get_table(db, "select  *  from  huaqing",  &resultp,  &nrow, &ncolumn,  &errmsg) !=  SQLITE_OK)
	{
		printf("error :  %s\n",  errmsg);
		exit(-1);
	}
	index = ncolumn;
	for  (i=0;  i<nrow;  i++)
	{
		 for  (j=0;  j<ncolumn;  j++)
		 {
			printf("%s  :  %s\n",  resultp[j], resultp[index++]);  
		 }
	}
	getchar();	
}

void insert(void )
{
		  
	char  *errmsg;	
	char sqlmsg[1024];
	char name[32];
	char sex[4];
	int age;
	
	printf("input your name#");
	scanf("%s",name);
	printf("input your sex#");
	scanf("%s",sex);
	printf("input your age#");
	scanf("%d",&age);
		
	sprintf(sqlmsg,"INSERT INTO huaqing (sname,ssex,sage,sdept,spwd) VALUES('%s','%s',%d,'math','123456')",
		name,sex,age);
	
	if  (sqlite3_exec(db, sqlmsg,  NULL,  NULL, &errmsg) !=  SQLITE_OK)
	{
		printf("error :  %s\n",  errmsg);
		exit(-1);
	}else{
		printf("insert is done!\n");		
	}
}
int menu()
{	
	int sel;
	
	while(1)
	{
		system("clear");
		printf("       1. insert record\n");
		printf("       2. delete record\n");	
		printf("       3. update record\n");		
		printf("       4. show record\n");	
		printf("       5. quit\n");	
		printf("input your selection#");
		scanf("%d",&sel);
		
		if(sel<0||sel>5)
		{
			printf("invalid choice,input your selection again\n");
			continue;
		}
		return sel;
	}	
}

int   main(int argc,   char  *argv[])
{
	  
	char  *errmsg,**resultp;
	int id;
	int  nrow,  ncolumn, i, j, index;	
	char sqlmsg[1024];
	int sel;
	
	if  (sqlite3_open("my.db",  &db)  !=  SQLITE_OK)
	{
		printf("error : %s\n", sqlite3_errmsg(db));
		exit(-1);  
	}

	if  (sqlite3_exec(db, "CREATE TABLE  IF NOT EXISTS huaqing(sno integer primary key,sname text not null,ssex text default 'man',sage integer default 19,sdept text default 'cs', spwd text default '123456')",  NULL,  NULL, &errmsg) !=  SQLITE_OK)
	{
		printf("error :  %s\n",  errmsg);
		exit(-1);
	}
	
	while(1)
	{
		sel = menu();
		switch(sel)
		{
			case 1:
				insert();
				break;
			case 2:
				
				break;
			case 3:
				break;
			case 4:
				show();
				break;
			case 5:	
				return;
			default:
				return;
			
		}			
	}



	sqlite3_close(db);
	return 0;
}

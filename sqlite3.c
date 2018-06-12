#include  <stdio.h>
#include  <stdlib.h>
#include  <sqlite3.h>


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

int   main(int argc,   char  *argv[])
{
	sqlite3   *db;        
	char  *errmsg;
	
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

	if  (sqlite3_exec(db, "INSERT INTO huaqing VALUES(95004,'liyong','m',25,'math','123456')",  NULL,  NULL, &errmsg) !=  SQLITE_OK)
	{
		printf("error :  %s\n",  errmsg);
		exit(-1);
	}	

	if  (sqlite3_exec(db, "select * from huaqing",  func,  NULL, &errmsg) !=  SQLITE_OK)
	{
		printf("error :  %s\n",  errmsg);
		exit(-1);
	}	
	
	
	sqlite3_close(db);

	return 0;
}

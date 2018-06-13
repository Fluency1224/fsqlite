/*************************************************************************
    > File Name: sqlite_api.c
    > Author: fluency
    > Mail: 1005068694@qq.com
    > Created Time: Wed 13 Jun 2018 11:22:16 AM CST
 ************************************************************************/
#include  "sqlite_api.h"

sqlite3 *Open_Db( char *db_name)
{
    sqlite3 *db;          
	char *errmsg;
	if( sqlite3_open( db_name, &db) != SQLITE_OK)
	{
		printf( "error: %s\n", sqlite3_errmsg(db));
		exit(-1); 
	}
    return db;
}

int Close_Db( sqlite3 *db)
{
	sqlite3_close( db);
    return EXECSUCCESS;
}

int Create_Table( sqlite3 *db, char *table_name)
{
    char *errmsg;
    char sq_cmd[CMDLEN];
    sprintf( sq_cmd, "CREATE TABLE IF NOT EXISTS %s(sno integer primary key,sname text not null,ssex text default 'man',sage integer default 19,sdept text default 'cs', spwd text default '123456')", table_name);
    if( sqlite3_exec(db, sq_cmd, NULL,  NULL, &errmsg) !=  SQLITE_OK)
	{
		printf( "error: %s\n", errmsg);
		return EXECFAIL;
	}
    return EXECSUCCESS;
}

int Drop_Table( sqlite3 *db, char *table_name)
{
    char *errmsg;
    char sq_cmd[CMDLEN];
    sprintf( sq_cmd, "DROP TABLE %s", table_name);
    if( sqlite3_exec(db, sq_cmd, NULL,  NULL, &errmsg) !=  SQLITE_OK)
	{
		printf( "error: %s\n", errmsg);
		return EXECFAIL;
	}
    return EXECSUCCESS;
}

int Insert_Table( sqlite3 *db, char *table_name)
{
    char *errmsg;
    char sq_cmd[CMDLEN];
    char name[32];
	char sex[4];
	int age;
	
	printf("input your name#");
	scanf("%s",name);
	printf("input your sex#");
	scanf("%s",sex);
	printf("input your age#");
	scanf("%d",&age);
		
	sprintf(sq_cmd,"INSERT INTO %s(sname,ssex,sage,sdept,spwd) VALUES('%s','%s',%d,'math','123456')", table_name, name, sex, age);
    if( sqlite3_exec(db, sq_cmd,  NULL,  NULL, &errmsg) !=  SQLITE_OK)
	{
		printf("error: %s\n", errmsg);
		return EXECFAIL;
	}	
    return EXECSUCCESS;
}

int Show_Table( sqlite3 *db, char *table_name)
{      
	char  *errmsg,**resultp;
	int  nrow,  ncolumn, i, j, index;	
	char sq_cmd[CMDLEN];

    sprintf( sq_cmd, "select * from %s", table_name);
	if( sqlite3_get_table( db, sq_cmd, &resultp, &nrow, &ncolumn, &errmsg) != SQLITE_OK)
	{
		printf("error: %s\n", errmsg);
		return EXECFAIL;
	}
	index = ncolumn;
	for( i = 0; i<nrow; i++)
	{
		 for  ( j = 0; j < ncolumn; j++)
		 {
			printf("%s: %s\n", resultp[j], resultp[index++]);  
		 }
	}
	return EXECSUCCESS;
}

int Select_Callback( void *para, int f_num, char **f_value, char **f_name)
{
	int  i;
	for( i = 0; i < f_num; i++)
	{
	    printf("%s: %s\n", f_name[i], f_value[i]);
	}
	return EXECSUCCESS;	
}

int Select_Table( sqlite3 *db, char *table_name)
{
    char *errmsg;
    char sq_cmd[CMDLEN];
    sprintf( sq_cmd, "select * from %s", table_name);
    if( sqlite3_exec( db, sq_cmd, Select_Callback, NULL, &errmsg) != SQLITE_OK)
	{
		printf("error: %s\n", errmsg);
		return EXECFAIL;
	}
    return EXECSUCCESS;	
}

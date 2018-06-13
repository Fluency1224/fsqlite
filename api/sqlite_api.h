/*************************************************************************
    > File Name: sqlite_api.h
    > Author: fluency
    > Mail: 1005068694@qq.com
    > Created Time: Wed 13 Jun 2018 11:22:25 AM CST
 ************************************************************************/
#ifndef SQLITE_API_H
#define SQLITE_API_H 

#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <sqlite3.h>

#define CMDLEN 11024
#define EXECSUCCESS 0 
#define EXECFAIL -1 

sqlite3 *Open_Db( char *db_name);
int Close_Db( sqlite3 *db);
int Create_Table( sqlite3 *db, char *table_name);
int Drop_Table( sqlite3 *db, char *table_name);
int Insert_Table( sqlite3 *db, char *table_name);
int Show_Table( sqlite3 *db, char *table_name);
int Select_Table( sqlite3 *db, char *table_name);

#endif

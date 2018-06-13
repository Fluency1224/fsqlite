/*************************************************************************
    > File Name: test_sqlite.c
    > Author: fluency
    > Mail: 1005068694@qq.com
    > Created Time: Wed 13 Jun 2018 02:58:39 PM CST
 ************************************************************************/
#include "sqlite_api.h"

#define MYDATABSAE "test.db"
#define MYTABLE "TestTable"

int main(int argc, char *argv[])
{
    sqlite3 *db;
    /* open mydatabase database */
    db = Open_Db(MYDATABSAE);

    /* create table */
    Create_Table( db, MYTABLE);

    /* insert data to table */
    Insert_Table( db, MYTABLE);

    /* show table data by sqlite3_get_table */
    Show_Table( db, MYTABLE);

    /* show table data by Callback */
    Select_Table( db, MYTABLE);

    /* delete table */
    Drop_Table( db, MYTABLE);

    /* close mydatabase database */
    Close_Db( db);

    return 0;
}



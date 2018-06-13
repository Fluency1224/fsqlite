# Fsqlite_API
嵌入式数据库软件sqlite3 C语言API接口
.

├── api

│   ├── sqlite            可执行文件

│   ├── sqlite_api.c      API函数

│   ├── sqlite_api.h      API头文件

│   ├── test.db           数据库

│   └── test_sqlite.c     测试源码

└── README.md
 
1 directory, 6 files

# 编译
gcc sqlite_api.c test_sqlite.c -o sqlite -lsqlite3

# 环境配置
Ubuntu1604自带sqlite3 

安装sqlite3.h头文件和库文件

sudo apt-get install libsqlite3-dev
# sqlite3移植

在嵌入式设备上使用sqlite3 我的博客详解链接如下：

https://blog.csdn.net/qq_37474534/article/details/80366033

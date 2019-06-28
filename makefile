# C flags:
CFLAGS_OPTIMIZATION = -g
#CFLAGS_OPTIMIZATION = -O3
CFLAGS_VERSION = -std=c11
CFLAGS_WARNINGS = -Wall -Wextra -Wno-unused-parameter
CFLAGS_DEFINES = -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -D_POSIX_SOURCE=1 -D_DEFAULT_SOURCE=1 -D_GNU_SOURCE=1
CFLAGS = $(CFLAGS_OPTIMIZATION) $(CFLAGS_VERSION) $(CFLAGS_WARNINGS) $(CFLAGS_DEFINES)

CC = gcc
RM = rm -f

INCLUDE = /usr/include/postgresql
LIB = pq

all: clean pqconnect pqselect pqcolumn_headers pqconnect pqlist_tables pqprepared_statement pqselect pqtransaction

pqcolumn_headers:
	$(CC) -o pqcolumn_headers pqcolumn_headers.c -I$(INCLUDE) -l$(LIB) $(CFLAGS)

pqconnect:
	$(CC) -o pqconnect pqconnect.c -I$(INCLUDE) -l$(LIB) $(CFLAGS)

pqlist_tables:
	$(CC) -o pqlist_tables pqlist_tables.c -I$(INCLUDE) -l$(LIB) $(CFLAGS)

pqprepared_statement:
	$(CC) -o pqprepared_statement pqprepared_statement.c -I$(INCLUDE) -l$(LIB) $(CFLAGS)

pqselect:
	$(CC) -o pqselect pqselect.c -I$(INCLUDE) -l$(LIB) $(CFLAGS)

pqtransaction:
	$(CC) -o pqtransaction pqtransaction.c -I$(INCLUDE) -l$(LIB) $(CFLAGS)

pqconnect:
	$(CC) -o pqconnect pqconnect.c -I$(INCLUDE) -l$(LIB) $(CFLAGS)

pqselect:
	$(CC) -o pqselect pqselect.c -I$(INCLUDE) -l$(LIB) $(CFLAGS)

clean:
	-$(RM) pqconnect pqselect pqcolumn_headers pqconnect pqlist_tables pqprepared_statement pqselect pqtransaction core *.o

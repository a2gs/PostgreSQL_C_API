/*
 * Code from: http://zetcode.com/db/postgresqlc/
 * with little modifications...
 */

#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void do_exit(PGconn *conn)
{
	PQfinish(conn);
	exit(1);
}

int main(int argc, char *argv[])
{
	PGconn *conn = PQconnectdb("hostaddr=192.168.2.130 port=5432 dbname=webdevdb user=webdev password=webdev");

	if(PQstatus(conn) == CONNECTION_BAD){
		fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
		do_exit(conn);
	}

	PGresult *res = PQexec(conn, "SELECT VERSION()");

	if(PQresultStatus(res) != PGRES_TUPLES_OK){
		printf("No data retrieved\n");
		PQclear(res);
		do_exit(conn);
	}

	printf("%s\n", PQgetvalue(res, 0, 0));

	PQclear(res);
	PQfinish(conn);

	return 0;
}

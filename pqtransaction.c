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

	PGresult *res = PQexec(conn, "BEGIN");

	if(PQresultStatus(res) != PGRES_COMMAND_OK){
		printf("BEGIN command failed\n");
		PQclear(res);
		do_exit(conn);
	}

	PQclear(res);

	res = PQexec(conn, "UPDATE Cars SET Price=23700 WHERE Id=8");

	if(PQresultStatus(res) != PGRES_COMMAND_OK){
		printf("UPDATE command failed\n");
		PQclear(res);
		do_exit(conn);
	}

	res = PQexec(conn, "INSERT INTO Cars VALUES(9,'Mazda',27770)");

	if(PQresultStatus(res) != PGRES_COMMAND_OK){
		printf("INSERT command failed\n");
		PQclear(res);
		do_exit(conn);
	}

	res = PQexec(conn, "COMMIT");

	if(PQresultStatus(res) != PGRES_COMMAND_OK){
		printf("COMMIT command failed\n");
		PQclear(res);
		do_exit(conn);
	}       

	PQclear(res);
	PQfinish(conn);

	return 0;
}

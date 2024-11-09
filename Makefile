all: client server
clean: 
	rm -f client server
client: client.c client-helper.c
	gcc -o client client.c client-helper.c
server: server.c server-helper.c
	gcc -o server server.c server-helper.c

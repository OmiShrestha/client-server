# A Client-Server Dev Environment and a Client-Server Sample App

This project may be used to set up a development for client-service applications using Linux Operating System and the project shows a simple client-server application using sockets in the C programming language. The server listens to TCP connections at a socket and then serves either requests for local text files or accepts a message from the client. The server may only terminate when the user enters CTRL + C. 

## Start an Ubuntu machine as server and Ubuntu machines as clients. 

### To start a Ubuntu machine to run the server

Start a Terminal/PowerShell and enter:
```
docker compose run --rm --name server server
```

### To start Ubuntu machines to run the client 

Start another Terminal/PowerShell and enter:
```
docker compose run --rm --name client1 client
```

Each client requires to use a different container name, i.e., change client1 to client2, client3, etc. 

### Compile the server and the client programs

The sample application is in _client-server_ directory. You may compile the programs on either the Ubuntu server machine or an Ubuntu client machine. 

```
cd client-server
gcc -o server server.c server-helper.c
gcc -o client client.c client-helper.c
```

### Start the application server

In the _client-server_ directory on the Ubuntu server machine, enter:

```
./server server 41000
```

You may use any non-privileged port for the applciation server to listen to.

### Start an application client

In the _client-server_ directory on an Ubunto client machine, enter
```
./client server 41000 server-helper.h
```

_server_: container name of the Ubuntu server. The name is defined in compose.yaml.

_41000_: port the application server listens to. 

_server-helper.h_: a file in the current directory. It can be any file in the directory

## Running the Remote Server at AWS

### Download AWS VPN Client and Configuration. 

Click the following link to download, install, configure the app. 

https://scranton.edu/apps/aws

Click the _Applications_ tab and then press _CSAWS Student VPN Portal_. Download the VPN client app for your OS and download the configuration file. 

After installing the VPN client app, you need to create a Profile and find and use the configuration file you just downloaded. 

### Connect to the AWS VPN

Run the AWS VPN client and connect to the VPN 

### Test your connect by ogging into the remote machine (a FreeBSD machine)

In a Terminal/PowerShell, enter the following. Replace the names with your real name. 
```
ssh yourfirstname-yourlastname@172.30.129.135
exit
```
### Secure-copying files to the remote machine

This step is to copy all the C code file for the app server to the remote FreeBSD machine.

In a Terminal/PowerShell, enter the following. Replace the names with your real name. 

```
scp client-server/server* yourfirstname-yourlastname@172.30.129.135:/usr/home/yourfirstname-yourlastname/.
```
### Compiling and starting the app server on the remote FreeBSD machine

In a Terminal/PowerShell, enter the following. Replace the names with your real name.

```
ssh yourfirstname-yourlastname@172.30.129.135
```
After logged into the FreeBSD machine, enter the following to compile and run the app server:
```
cd client-server
gcc -o server server.c server-helper.c
./server 172.30.129.135 41000
```

### Run the app client on a local Ubuntu 

Start another Terminal/PowerShell on your local machine, enter:

```
docker compose run --rm --name remoteclient1 remoteclient
```

In the Ubuntu machine, enter the following to start the client:
```
cd client-server
gcc -o client client.c client-helper.c
./client 172.30.129.135 41000 server-helper.h
```

You can test the sample app by enter 1, 2, 0 to request the server to return server-helper.h file and send a "Hello World" message to the server. Option 0 is to stop the client. 

### exit from the remote machine

Kill the app server by pressing CTRL + c, and then enter the following to exit the FreeBSD machine. 

```
exit
```

### Disconnect the VPN

Your VPN connection incurs cost ($$$$) to the University. so please DISCONNECT the VPN once it is no longer needed. 

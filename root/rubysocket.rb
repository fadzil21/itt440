require 'socket'

server = TCPServer.open(1029)
loop {
	client = server.accept
	client.puts(Time.now.ctime)
	client.puts "Closing Connection"
	client.close
	}

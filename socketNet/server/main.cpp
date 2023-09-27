#include <iostream> 
#include "boost/asio.hpp"
#include "netwrk/tcp_server.h"

using boost::asio::ip::tcp; 

int main(int argc, char *argv[])
{
      
     netwrk::TCPServer server{netwrk::IPV::V4, 1337};
     
     server.Run();

     return 0;
}
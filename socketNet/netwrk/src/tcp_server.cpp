#include <iostream>
#include "netwrk/tcp_connection.h"
#include "netwrk/tcp_server.h"

namespace netwrk
{
     using boost::asio::ip::tcp; 

     TCPServer::TCPServer(IPV ipv, int port) : _ipVersion(ipv), _port(port), 
          _acceptor(_ioc, boost::asio::ip::tcp::endpoint(ipv == IPV::V4 ? tcp::v4() : tcp::v6(), _port))
     {
          //async           
     }

     int TCPServer::Run()
     {
          try
          {
               startAccept();
              _ioc.run();
               
          }
          catch(const std::exception& e)
          {
               std::cerr << e.what() << '\n';
               return -1; 
          }
          return 0;
     }
     void TCPServer::startAccept()
     {
          //Create a connection 
          auto connection = TCPConnection::Create(_ioc);
          
          _connections.push_back(connection);
          
          //asynchronously accept connection     
          _acceptor.async_accept(connection->Socket(), [connection, this](const boost::system::error_code &error)
          {
               if(!error)
               {
                    connection->Start(); 
               }
               else 
               {
                    std::cout << "ACCEPTANCE NEVER STARTED!";
               }

               startAccept();
          });

     }
}
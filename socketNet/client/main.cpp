#include <iostream>
#include <boost/asio.hpp>
#include <array>
// #include "netwrk/tcp_connection.h"

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
     try
     {
          boost::asio::io_context ioContext ; 
          tcp::resolver resolver{ioContext}; 
          tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "1337");
          tcp::socket socket {ioContext};

          boost::asio::connect(socket, endpoints);

          while(true)
          {
               std::array<char, 128> buf {}; 
               boost::system::error_code error; 

               size_t len = socket.read_some(boost::asio::buffer(buf), error);

               if(error == boost::asio::error::eof)
               {
                    //Clean connection cutoff 
                    break;
               }
               else if(error)
               {
                    throw boost::system::system_error(error);
               }

               std::cout.write(buf.data(), len);

          }

     }
     catch( std::exception& e)
     {
          std::cerr << e.what() << '\n';
     }
     

     return 0;
}
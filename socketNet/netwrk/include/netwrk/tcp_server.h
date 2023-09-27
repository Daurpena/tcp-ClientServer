#pragma once 

#include <string> 
#include <boost/asio.hpp>
#include "netwrk/tcp_connection.h"
#include <functional>



namespace netwrk{
     enum class IPV {
          V4,
          V6
     };

     class TCPServer{ 
          public: 
               TCPServer(IPV ip, int port) ;
               
               int Run();
               
               template<typename T>
               void WriteToConnection(int connectionIndex, const T& message); 

               template<typename T> 
               using ListenCallback = std::function<void(int, const T&)>;

               template <typename T> 
               void RegisterListenCallback(int connectionIndex, ListenCallback<T> callback);


          private:
               void startAccept();
               IPV _ipVersion; 
               int _port; 

               boost::asio::io_context _ioc;
               boost::asio::ip::tcp::acceptor _acceptor;

               std::vector<TCPConnection::pointer> _connections {};
     };

}


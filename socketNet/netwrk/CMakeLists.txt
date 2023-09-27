cmake_minimum_required(VERSION 3.19)
project(netwrk)



set(CMAKE_CXX_STANDARD 20)

set(BOOST_INCLUDEDIR "/usr/local/include/boost_1_83_0")
set(BOOST_ROOT "/usr/local/include/boost_1_83_0")

file(GLOB SOURCES src/* src/*/* src/*/*/*)
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} 
          PUBLIC
               $<INSTALL_INTERFACE:include>
               $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
               ${BOOST_INCLUDEDIR}
          PRIVATE
)

target_link_libraries(${PROJECT_NAME}
          PUBLIC
              ${Boost_LIBRARIES}               
          PRIVATE
)


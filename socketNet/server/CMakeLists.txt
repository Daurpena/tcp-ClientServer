cmake_minimum_required(VERSION 3.19)
project(server)

set(CMAKE_CXX_STANDARD 20)


# set(BOOST_INCLUDEDIR "/usr/local/include/boost_1_83_0")
# set(BOOST_ROOT "/usr/local/include/boost_1_83_0")

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME}
          PUBLIC
               netwrk
               # ${BOOST_INCLUDEDIR}
)    

target_link_libraries(${PROJECT_NAME}
          PUBLIC
               netwrk
          PRIVATE
               # ${Boost_LIBRARIES}

)

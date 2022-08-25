cmake_minimum_required(VERSION 3.22)
project(ex4_noamt)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4_noamt
        Activation.cpp
        Activation.h
        Dense.cpp
        Dense.h
#        main.cpp
        test.cpp
        Matrix.cpp
        Matrix.h
        MlpNetwork.cpp
        MlpNetwork.h
        test_activation.cpp
        test_matrix.cpp
        test_matrix.h
        test_activation.h
#        test_activation.o
        test_dense.cpp
        test_dense.h
#        test_dense.o
#        test_matrix.o
        )

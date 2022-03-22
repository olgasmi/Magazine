cmake_minimum_required(VERSION 3.17)
project(SmistekOlga-etap3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(SmistekOlga-etap3
        commodity.cpp
        commodity.h
        dry.cpp
        dry.h
        extra_vector.cpp
        extra_vector.h
        helper.h
        liquid.cpp
        liquid.h
        magazine.cpp
        magazine.h
        magazine_conv.cpp
        magazine_conv.h
        main.cpp
        myVector.h
        pallet_jack.cpp
        pallet_jack.h
        product.cpp
        product.h)

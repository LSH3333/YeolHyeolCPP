cmake_minimum_required(VERSION 3.21)
project(OOP09)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP09 main.cpp String.cpp String.h Account.cpp Account.h AccountArray.cpp AccountArray.h
        AccountHandler.cpp AccountHandler.h BankingCommon.h BankingSystemMain.cpp HighCreditAccount.h NormalAccount.h)

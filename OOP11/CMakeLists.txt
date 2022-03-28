cmake_minimum_required(VERSION 3.21)
project(OOP11)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP11 String.cpp String.h Account.cpp Account.h
        AccountHandler.cpp AccountHandler.h BankingCommon.h BankingSystemMain.cpp HighCreditAccount.h NormalAccount.h BoundCheckArray.h)

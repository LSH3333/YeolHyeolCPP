cmake_minimum_required(VERSION 3.21)
project(OOP07)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP07 BankingSystemMain.cpp Account.h Account.cpp BankingCommon.h NormalAccount.h HighCreditAccount.h AccountHandler.cpp AccountHandler.h)

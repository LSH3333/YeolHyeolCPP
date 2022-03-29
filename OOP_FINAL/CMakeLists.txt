cmake_minimum_required(VERSION 3.21)
project(OOP_FINAL)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_FINAL BankingCommon.h Account.cpp Account.h String.cpp String.h ExceptionClass.h BoundCheckArray.h NormalAccount.h HighCreditAccount.h AccountHandler.cpp AccountHandler.h BankingSystemMain.cpp)

add_executable(SeaBattle_MAIN main.cpp src/Game.cpp src/RandomBot.cpp src/SmartBot.cpp src/Board.cpp)

add_executable(TEST_Board test_Board.cpp src/Board.cpp)

add_executable(TEST_Human test_human_class.cpp include/HumanPlayer.h src/Board.cpp)

add_executable(TEST_RandomBot test_RandomBot_class.cpp src/RandomBot.cpp src/Board.cpp)

add_executable(TEST_SmartBot test_SmartBot.cpp src/SmartBot.cpp src/Board.cpp)
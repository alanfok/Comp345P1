cmake_minimum_required(VERSION 3.9)
project(Comp345P1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Comp345P1 main.cpp Die.cpp Die.h Maps.cpp Maps.h Maploader.cpp Maploader.h Player.cpp Player.h Tokens.cpp Tokens.h Interraction.cpp Interraction.h ListofPlayer.cpp ListofPlayer.h NodeRegion.cpp NodeRegion.h Veiwer.cpp Veiwer.h PlayerType.h AggressivePlayer.cpp AggressivePlayer.h DefensivePlayer.cpp DefensivePlayer.h ModeratePlayer.cpp ModeratePlayer.h RandomPlayer.cpp RandomPlayer.h Observer.h Subject.h PhaseObserver.cpp PhaseObserver.h Subject.cpp StatisticsObserver.cpp StatisticsObserver.h ObserverDecorator.h DominationObserverDecorator.cpp DominationObserverDecorator.h VictoryCoinsObserverDecorator.cpp VictoryCoinsObserverDecorator.h HandsObserverDecorator.cpp HandsObserverDecorator.h)
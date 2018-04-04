cmake_minimum_required(VERSION 3.9)
project(Comp345P1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Comp345P1 main.cpp Die.cpp Die.h Maps.cpp Maps.h Maploader.cpp Maploader.h Player.cpp Player.h Tokens.cpp Tokens.h Interraction.cpp Interraction.h ListofPlayer.cpp ListofPlayer.h NodeRegion.cpp NodeRegion.h Veiwer.cpp Veiwer.h Strategy.cpp Strategy.h Observer.cpp Observer.h PhaseObserver.cpp PhaseObserver.h gameStatsObserver.cpp gameStatsObserver.h DominationObserverDecorator.cpp DominationObserverDecorator.h HandsObserverDecorator.cpp HandsObserverDecorator.h VictoryCoinsObserverDecorator.cpp VictoryCoinsObserverDecorator.h)
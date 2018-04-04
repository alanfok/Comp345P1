//
// Created by fok poon kai on 2018-02-03.
//

#include "Die.h"

  int Die::throwsOne() {
      srand( time( NULL ) );
      dice1 = (rand()+365)%4 ;
  }



//
// Created by fok poon kai on 2018-04-07.
//

#include "Subject.h"

void Subject::attach(Observer *ob) {
observer.push_back(ob);
}

void Subject::detach(Observer *ob) {
    observer.clear();
    observer.shrink_to_fit();
}

void Subject::notify(ListofPlayer *pl) {
    for (int i = 0; i <observer.size() ; ++i) {
        observer[i]->update(pl);
    }
}
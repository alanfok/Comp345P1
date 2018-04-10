//
// Created by fok poon kai on 2018-04-07.
//

#include "Subject.h"

void Subject::attach(Observer *ob) {
observer.push_back(ob);
}

void Subject::detach() {
    observer.clear();
    observer.shrink_to_fit();
}

void Subject::notify(ListofPlayer *pl) {
    for (int i = 0; i <observer.size() ; ++i) {
        observer[i]->update(pl);
    }
}
void Subject::attachStatic(Observer *obs) {
    staticObserver.push_back(obs);
}


void Subject::notifyStatic(vector<ListofPlayer> *lp_vPtr, int numberOfRegion) {
    for (int i = 0; i <staticObserver.size() ; ++i) {
//        cout<<"StaticTest"<<endl;
        staticObserver[i]->update(lp_vPtr,numberOfRegion);
    }
}

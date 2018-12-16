//
// Created by michael on 16/12/18.
//

#include "People.h"

int person = 0;

People::People() {
    person++
}

People::id() {
    return person;
}

People::toString() {
    return "#" + person;
}


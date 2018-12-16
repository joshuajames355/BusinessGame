//
// Created by michael on 16/12/18.
//

#include "People.h"
#include <string>

int person = 0;

People::People() {
    person++
}

people::id() {
    return person;
}

people::toString() {
    return ("#%d", person);
}
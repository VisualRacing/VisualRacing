//
// Created by stark on 21-Oct-17.
//

#include "DataInterface.h"

DataInterface::DataInterface() {
    this->buffer = new VRData();
}

DataInterface::~DataInterface() {
    delete this->buffer;
}

//
// Created by stark on 21-Oct-17.
//

#include "DataInterface.h"

DataInterface::DataInterface(std::string processName) {
    this->processName = processName;
    this->buffer = new VRData();
}

DataInterface::~DataInterface() {
    delete this->buffer;
}

std::string DataInterface::getProcessName(){
    return this->processName;
}
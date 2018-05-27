#ifndef VRDATAINTERFACEFACTORY_H
#define VRDATAINTERFACEFACTORY_H

#include "vrdatainterface.h"
#include "vrdatainterfaceac.h"
#include "vrdatainterfacer3e.h"

class VRDataInterfaceFactory
{
public:
    enum Simulation { AC, R3E };

    static QSharedPointer<VRDataInterface> createInterface(Simulation s);
};

#endif // VRDATAINTERFACEFACTORY_H

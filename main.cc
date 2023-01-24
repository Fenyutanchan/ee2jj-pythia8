#include "Pythia8/Pythia.h"
#ifndef HEPMC2
    #include "Pythia8Plugins/HepMC3.h"
#else
    #include "Pythia8Plugins/HepMC2.h"
#endif

using namespace Pythia8;

int main() {

    Pythia8::Pythia8ToHepMC topHepMC("eeqqbar.hepmc");

    // Generator. Process selection. LHC initialization. Histogram.
    Pythia pythia;
    pythia.readFile("input.config");
    double mZ = pythia.particleData.m0(23);
    pythia.settings.parm("Beams:eCM", mZ);
    pythia.init();

    int num_of_event    =   pythia.settings.mode("Main:numberOfEvents");
    // Begin event loop. Generate event. Skip if error.
    for (
        int iEvent = 0;
        iEvent < num_of_event;
        ++iEvent
    ) {
        if (!pythia.next()) continue;
        topHepMC.writeNextEvent( pythia );
    }
    return 0;
}
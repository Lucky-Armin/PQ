#include "trajOutput.hpp"

using namespace std;
using namespace frameTools;

void TrajOutput::write(Frame &frame)
{
    const auto &molecules = frame.getMolecules();
    const auto &box = frame.getBox();

    _fp << molecules.size() << " " << box << endl;
    _fp << endl;

    for (const auto &molecule : molecules)
    {
        const auto &com = molecule.getCenterOfMass();

        _fp << "COM " << com[0] << " " << com[1] << " " << com[2] << endl;
    }
}
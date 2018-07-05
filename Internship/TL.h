//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __INTERNSHIP_TL_H_
#define __INTERNSHIP_TL_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class TL : public cSimpleModule
{
    cMessage *start;
    cMessage *lock;
    cMessage *reply;
    cMessage *allred;
    simtime_t IaTime;
    int timelocked = 0;
    int id;



  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif

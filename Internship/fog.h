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

#ifndef __INTERNSHIP_FOG_H_
#define __INTERNSHIP_FOG_H_

#include <omnetpp.h>
#include <queue>

using namespace omnetpp;
using namespace std;
/**
 * TODO - Generated class
 */
class Fog : public cSimpleModule
{
public:
    cMessage *fromdevice;
    cMessage *reply;
    cMessage *copy;
    cMessage *msg;
    cMessage *lock;
    cMessage *m120;
    int max ; int chosen; int counter ; int counter2;  int cur ; int curTL;
    std::queue<int> queuerandom;
    std::queue<int> queuerandom2;
    std::queue<int> trafficLights;
    std::array<int,4> cn1;
    std::array<int,4> cn2;
    std::array<int,4> locktime1;
    std::array<int,4> locktime2;
    int cnn;
    int current;
    std::queue<int> a;
    std::queue<int> b;



protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void arrange(queue<int> a,queue<int>b);
    //   virtual void lockF(array<int,4> cn, int cnn);
};

#endif

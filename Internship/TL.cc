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

#include "TL.h"
Define_Module(TL);

void TL::initialize()
{
    start= new cMessage("start");
    id=0;
    IaTime = par("InterArrival").doubleValue();
    EV<<"InterArrival time :" << IaTime  << endl;
    scheduleAt(simTime()+IaTime,start);
    reply= new cMessage("reply");
    lock= new cMessage("lock");



}

void TL::handleMessage(cMessage *msg)
{
    if (msg==start){

       msg= new cMessage("HI");
       id = this -> getIndex();

       if(id >=0 && id<4){
           cModule *target = getParentModule()->getSubmodule("fog");
           sendDirect(msg,0.1,0, target, "radioIn");
       }
       else{
           cModule *target = getParentModule()->getSubmodule("fog1");
           sendDirect(msg,0.1,0, target, "radioIn");
       }

       IaTime = par("InterArrival").doubleValue();
       EV<<"InterArrival time :" << IaTime  << endl;
       scheduleAt(simTime()+IaTime,start);

    }
    if(strcmp(msg->getName(), reply->getName())==0)
    {
        bubble("green");


    }

    }


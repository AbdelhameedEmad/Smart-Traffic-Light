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

#include "fog.h"
using namespace std;
Define_Module(Fog);

void Fog::initialize()
{

    counter = 0;
    counter2 = 0;
    cur = 0 ;


    curTL =0;
    fromdevice = new cMessage("HI");
    reply = new cMessage("reply");
    lock = new cMessage("lock");
    for(int i = 0; i<4 ; i++){
        cn1.at(i) = 0;
        locktime1.at(i)=0;
        locktime2.at(i)=0;
    }

}

void Fog::handleMessage(cMessage *msg)
{
    if (strcmp(msg->getName(), fromdevice->getName()) == 0) {

        if (strcmp(this->getName(), "fog")==0)
        {
            counter++;
            while(!queuerandom.empty())
            {
                queuerandom.pop();
            }
            while(!trafficLights.empty())
            {
                trafficLights.pop();
            }


            if(cn1.at(0) <0)
            {
                queuerandom.push(0);

            }
            else
            {
                int rand1 = rand()%100;
                queuerandom.push(rand1);
            }



            if(cn1.at(1) <0)
            {
                queuerandom.push(0);
            }
            else
            {
                int rand2 = rand()%100;
                queuerandom.push(rand2);
            }


            if(cn1.at(2)<0)
            {
                queuerandom.push(0);
            }
            else {
                int rand3 = rand()%100;
                queuerandom.push(rand3);
            }


            if(cn1.at(3) <0)
            {
                queuerandom.push(0);
            }
            else{
                int rand4 = rand()%100;
                queuerandom.push(rand4);

            }


            if(counter==4)
            {


                trafficLights.push(0);
                trafficLights.push(1);
                trafficLights.push(2);
                trafficLights.push(3);

                arrange(queuerandom,trafficLights);
                EV<<"at zerooooooo"<<cn1.at(2)<<endl;
                EV<<"CHOSENnn"<<chosen<<endl;
                cModule *target = getParentModule()->getSubmodule("tl",chosen);
                sendDirect(reply->dup(),0.1,0, target, "radioIn");


                for(int i = 0 ; i<cn1.size();i++)
                {
                    if (i == chosen || cn1.at(i)<0)
                    {

                        cn1.at(i)++;
                        locktime1.at(i) =0;
                    }

                    else
                    {
                        locktime1.at(i)+=20;
                        cn1.at(i)=0;
                    }
                }

                for(int i = 0 ; i<cn1.size();i++)
                {
                    if (cn1.at(i)==2)
                    {

                        EV<<"max TL"<<i<<endl;
                        cModule *target = getParentModule()->getSubmodule("tl",i);
                        sendDirect(lock->dup(),0.5,0, target, "radioIn");
                        cn1.at(i) =-5;

                    }
                    else   if (locktime1.at(i) == 120)
                                      {
                                          for (int j = 0 ; j <cn1.size();j++ )
                                          {
                                              if (j!=i)
                                              {
                                                  cn1.at(j) = -2;
                                              }
                                          }
                                      }
                }
                EV<<"maxxxxxxxxxxxTL"<<max<<endl;
                counter=0;


            }


        }
        else{
            counter2++;
            int rand1 = rand()%100; queuerandom2.push(rand1); trafficLights.push(4);
            int rand2 = rand()%100; queuerandom2.push(rand2); trafficLights.push(5);
            int rand3 = rand()%100; queuerandom2.push(rand3); trafficLights.push(6);
            int rand4 = rand()%100; queuerandom2.push(rand4); trafficLights.push(7);
            if(counter2==4)
            {

                arrange(queuerandom2,trafficLights);

                EV<<"CHOSENnn"<<chosen<<endl;
                cModule *target = getParentModule()->getSubmodule("tl",chosen);

                sendDirect(reply->dup(),0.1,0, target, "radioIn");

                for(int i = 0 ; i<cn2.size();i++)
                {
                    if (i == chosen || cn1.at(i)<0)
                    {
                        cn2.at(i)++;
                        locktime2.at(i) =0;

                    }

                    else
                    {
                        cn2.at(i)=0;
                        locktime2.at(i)+=20;
                    }
                }

                for(int i = 0 ; i<cn2.size();i++)
                {
                    if (cn2.at(i)==2)
                    {

                        EV<<"max TL"<<i<<endl;
                        cModule *target = getParentModule()->getSubmodule("tl",i+4);
                        sendDirect(lock->dup(),0.5,0, target, "radioIn");
                        cn2.at(i) =-5;
                    }
                    else   if (locktime2.at(i) == 120 ) //the priority to be put here
                    {
                        for (int j = 0 ; j <cn2.size();j++ )
                        {
                            if (j!=i )
                            {
                                cn2.at(j) = -2;
                            }
                       }
                    }




                }



                counter2=0;

            }

        }


    }
}




void Fog::arrange(queue<int> a,queue<int> b)
{
    max =0 ;chosen =0 ;


    while(!(a.size()==0)){
        cur = a.front();
        curTL = b.front();
        if(cur>max){
            max = cur;
            chosen= curTL;
        }

        a.pop();
        b.pop();

    }


    EV<<"CHOSEN"<<chosen<<endl;
    EV<<"max"<<max<<endl;
    EV<<"queuesize:"<<queuerandom.size()<<endl;

}

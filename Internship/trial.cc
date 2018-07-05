/*
 * trial.cc
 *
 *  Created on: Jun 24, 2018
 *      Author: user
 */

#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

class trial{
   std::queue<int> queuerandom;
   std::queue<int> trafficLights;
   int max = 0; int chosen =0;

public:

trial()
{
    for(int i=0;i<queuerandom.size();i++)
    {
        if(!queuerandom.size()==0){
       int cur = queuerandom.front();
       int curTL = trafficLights.front();
        if(cur>max){
            max = cur;
            chosen= curTL;
        }
        queuerandom.pop();
        trafficLights.pop();

    }

    }
   // EV<<":"<<max;

}

};

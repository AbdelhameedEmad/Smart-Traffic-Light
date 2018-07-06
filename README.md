# Smart-Traffic-Light
An Omnet++ Simulation for a Smart Traffic Light network consisting of:

- Fog: Which represents the Edge computing part in the network as the fog implements a specific algorithm to choose the next Traffic light to be green.

- Traffic Light: Which sends the fog a message containing the number of cars waiting in it's lane and it is Red as default and turns green when it receives a message from the fog to open and it opens for 20 sec. and then sends new readings to the fog.

# Algorithm:

The algorithm is designed for crossroads which has 4 Traffic lights, the fog gets the number of cars at each traffic light by video processing of the video sent from the traffic light camera to it, each traffic light opens for 20 sec. when it recieves a message from the fog and it can open 2 sucessive times but, then it will be locked for 60 sec. so that no starvation happens in the other 3 lanes.

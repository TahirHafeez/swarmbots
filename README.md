# swarmbots: a diy arduino swarm

#
#
#

## Notes and documentation journal of build process
### April 22, 2017: Arduino Robot Library as a model
[Arduino Robot Library](https://www.arduino.cc/en/Reference/RobotLibrary) and
(https://github.com/arduino-libraries/Robot_Control) has some interesting features, and since it incorporates several libraries into itself as a memory-saving strategy, it might be worth looking at its architecture and functions.  

The Swarm Bots could be programmed for certain "modes" following the example sketches of the Robot Library.  For instance: 
#### Line Following - draw a racing track and get robot to run on it
#### Disco Bot - turn robot into an 8-bit jukebox and dance to the beat
#### Compass - plan a treasure hunt with digital compass
#### ...
#### Runaway Robot - play tag with robot using a distance sensor
#### Remote control - reuse that old tv-remote to command the bot on distance
#### Rescue - train robot to look for hidden pearls in a maze
#### ...
> "This library enables easy access to the functionality of the Arduino Robot. It relies on a number of 3rd party libraries 
> including Fat16, EasyTransfer, Squawk, and IRRemote. It also relies on a number of Arduino libraries like TFT, SPI, and Wire. 
> Their functionality has been replicated inside the robot's library to optimize the code's size.”


### April 10, 2017: Update and first pcbs
At this point I think the bots will send constant lights/signal from each side, and I have been using [the navigation light systems of boats and planes as a model](https://en.wikipedia.org/wiki/Navigation_light)

### April 4, 2017: Rethinking motion and form of robots
[This video](https://vimeo.com/173159398) has several fascinating designs that challenge the “default” methods of rendering motion for bots, and even present new modes of structuring the frames and chassis.

### April 4, 2017: Communication and Data Needs of this Swarm's Emergent Behavior 
We are starting with [hardware tutorials from sparkfun](https://learn.sparkfun.com/tutorials/ir-control-kit-hookup-guide) and are going to lean heavily on [Ken Shirriff's excellent and easily hacked IRRemote library]
(http://www.righto.com/2009/08/multi-protocol-infrared-remote-library.html)

As the first prototypes are built from paper and cardboard the goal will be to better understand the data needs of the bots; for instance: what does a single bot need to know?  And, what does the swarm of bots need to do?  Do we need to decide what the swarm is going to do, not in the sense of performing a programmed action but at least in a general sense of knowing what range of possibilities exist for the swarm, in order to decide what each bot needs to know?  Or, could the bots be programmed without knowing the swarm’s range of possibilities, and then functionality would be added? 

A second-level question that may be answered differently depending on the design we arrive at:  Does the swarm of bots as a whole, in doing one or another thing, achieve its own “understanding”?   

#### Emergent Behavior links: 
https://en.wikipedia.org/wiki/Emergence

[MIT Project on Emergent Behavior --old page via Internet Archive](https://tinyurl.com/contents-emergence)
https://github.com/sklise/conways-game-of-life


### March 24, 2017: Swarm Project Plan and Brainstorm
We want the project to use minimal hardware and keep expenses low, so probably using a simple vibro motor for locomotion is better than servos or other dc motors.

The main problem to address is location:
How does the swarm know where it is? 
How does an individual “ant” know where it is? 

These we might address with a centralized larger computer, a “beacon” that emits some form of sound or light signal, or perhaps (we didn’t discuss this one) we build a table or “play field” or “terrarium” for the bots that has directional signs/signals built in.  

#### Minimum viable product: 
(1) swarm knows its own members and moves together 
(2) swarm responds to stimuli and acts on its own

#include "Particle.h"


void Particle::update()
{
    
    velocity = velocity + acceleration;
    
    velocity = velocity * drag;
    
    position = position + velocity;
    
    maxAge--;
    
    age++;
    
}


#pragma once
#include "Vec.hpp"
#include "Entity.hpp"
#include "Frame.hpp"

static graph::Draw drawing;

class Particle : public Entity{
public:
    double q = 1;
    
    using Entity::Entity;
    void set_q( double q);
    virtual void draw();
};

class Electron : public Particle{
    using Particle::Particle;
    void draw() override;
};

class Positron : public Particle{
    using Particle::Particle;
    
    void draw() override;
};
from time import sleep
from nbformat import read
import numpy as np
import pandas as pd
from physics_particle import *
from physics_calc import *

class App:
    def __init__(self) -> None:
        self.particles = []
        
        df = pd.read_csv('particles.csv')
        for i in df.index:
            self.particles.append(Particle(particle_used=df['particle_used'][i], position=np.array([df['x'][i], df['y'][i]])))

        while True:
            self.run()

    def run(self):
        for i, particle in enumerate(self.particles):
            vector = self.set_field_in_point(i, particle.position)
            particle.update_status(vector)
            particle.update_position()

    def create_particle(self,
        particle_used : True, # must be True, 'proton' or 'electron'
        position : np.ndarray = np.array([0, 0]),
        charge : float =  __elementar_charge__,
        mass : float = __proton_mass__
    ):
        self.particles.append(Particle(particle_used, position, charge, mass))

    def set_field_in_point(self, particle_index:int, point:np.ndarray) -> np.ndarray:
        vector = np.array([0, 0])
        particles = self.particles[:]
        particles.remove(self.particles[particle_index])
        for particle in particles:
            vector = vector + eletric_field_by_particle_in_point(point, particle)

        return vector

    

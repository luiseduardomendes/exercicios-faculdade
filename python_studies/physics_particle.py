import numpy as np

frame_rate = 24
__elementar_charge__ = 1.60217663 * 10**(-19)
__proton_mass__ = 1.67262192 * 10**(-27)
__electron_mass__ = 9.1093837 * 10**(-31)
__vacuum_permittivity__ = 8.854 * 10 **(-12)

class Particle:
    def __init__(
        self,
        particle_used : True, # must be True, 'proton' or 'electron'
        position : np.ndarray = np.array([0, 0]),
        charge : float =  __elementar_charge__,
        mass : float = __proton_mass__
    ):
        
        self.position = position
        self.charge = charge
        self.mass = mass
        self.acceleration = np.array([0, 0])
        self.velocity = np.array([0, 0])

        if not particle_used:
            if particle_used == 'electron':
                self.mass = __electron_mass__
            elif particle_used == 'proton':
                self.mass = __proton_mass__
    
    def update_acceleration(self, vector_force:float) -> None:
        self.acceleration = vector_force/self.mass

    def update_velocity(self):
        self.velocity = self.velocity + (self.acceleration * (1/frame_rate))

    def update_position(self):
        self.position = self.position + (self.velocity * (1/frame_rate))

    def update_status(self, force_vector:float):
        self.update_acceleration(force_vector)
        self.update_velocity()


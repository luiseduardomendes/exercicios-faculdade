import math
from physics_particle import __vacuum_permittivity__

def distance_between(p1, p2):
    return math.sqrt((p1[0]**2 - p2[0]**2) + (p1[0]**2 - p2[0]**2))

def eletric_field_by_particle_in_point(point, particle):
    return 1/(4*math.pi*__vacuum_permittivity__) * (particle.charge/distance_between(particle.position, point) ** 2)
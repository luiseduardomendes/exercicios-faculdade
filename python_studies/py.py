filePath = 'points.csv'

with open(filePath) as f:
    data = f.readlines()
    f.close

lines = [d.split(',')[-3:] for d in data]
for line in lines:
    line[2] = line[2].split('\n')[0]

values = {
    'xAxis': [],
    'yAxis': [],
    'zAxis': []
}

for line in lines:
    for i, key in enumerate(values.keys()):
        values[key].append(line[i])

def plot3dScatter(x: list, y: list, z: list):
    import matplotlib.pyplot as plt
    from mpl_toolkits.mplot3d import Axes3D
    
    fig = plt.figure()
    
    ax = fig.add_subplot(111, projection='3d')
    
    ax.scatter(x, y, z)

    fig.show()


plot3dScatter(values['xAxis'], values['yAxis'], values['zAxis'])

import matplotlib.pyplot as plt

positionLinear = [25.55, 24.3, 23.2, 21.95, 20.8, 19.55, 18.35, 17.05, 15.85, 14.55, 13.35]
positionAngular = [171.0, 164.5, 157.5, 151.0, 144.0, 137.5, 130.0, 123.5, 116.5, 109.5, 102.5]
timeCurrent = [1.869, 1.902, 1.935, 1.969, 2.002, 2.035, 2.069, 2.102, 2.135, 2.169, 2.202]
velocityLinear = []
velocityAngular = []
c = []

numQuadros = 11
velocityAngular.append(0)
velocityLinear.append(0)
for i in range(1, numQuadros - 1):
    velocityLinear.append((positionLinear[i-1] - positionLinear[i+1]) / (timeCurrent[i-1] - timeCurrent[i+1]))
    velocityAngular.append((positionAngular[i-1] - positionAngular[i+1]) / (timeCurrent[i-1] - timeCurrent[i+1]))
velocityAngular.append(0)
velocityLinear.append(0)

c.append(0)
for i in range(1, numQuadros-1):
    c.append(velocityLinear[i] / velocityAngular[i])
c.append(0)

fig_1 = plt.figure(1, figsize=(6.4, 4.8))

chart_1 = fig_1.add_subplot(222)
chart_2 = fig_1.add_subplot(223)
chart_3 = fig_1.add_subplot(221)
chart_4 = fig_1.add_subplot(224)

chart_1.scatter(timeCurrent, positionLinear)
#chart_1.plot(timeCurrent, positionLinear)
chart_2.scatter(timeCurrent, positionAngular)
#chart_2.plot(timeCurrent, positionAngular)
chart_3.scatter(timeCurrent, velocityLinear)
chart_4.scatter(timeCurrent, velocityAngular)
#chart_5.scatter(timeCurrent, c)

plt.show()


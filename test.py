from ctypes import *
from math import *
import matplotlib.pyplot as plt
import numpy as np

f = lambda x: -5 * cos(10 * x) * sin(3 * x) / pow(x, 1/2)

lib_dll = cdll.LoadLibrary("Ship\\bin\\genetic.dll")
func = lib_dll['genetic']
func.restype = c_double

print('Local min: {}'.format(func(c_char_p(b'min'))))
print('Local max: {}'.format(func(c_char_p(b'max'))))


# 100 linearly spaced numbers
x = np.linspace(.001,10,100)

# the function, which is y = x^2 here
y = list()
for n in x:
    y.append(f(n))

# setting the axes at the centre
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')

# plot the function
plt.plot(x,y, 'r')

# show the plot
plt.show()
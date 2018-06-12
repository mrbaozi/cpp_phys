#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

x, y = np.loadtxt('./a17-spline-res.dat', unpack=True)
plt.plot(x, y)
plt.show()

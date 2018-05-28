#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt


def main():
    x0, y0 = np.loadtxt('./a16-interpol.dat', unpack=True)
    x1, y1 = np.loadtxt('./a16-results.dat', unpack=True)

    plt.scatter(x0, y0, c='k', marker='x')
    plt.plot(x1, y1, 'r--')
    plt.tight_layout()
    plt.show()


if __name__ == '__main__':
    main()

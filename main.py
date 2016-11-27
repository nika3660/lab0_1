# -*- coding: UTF-8 -*-


def extract_data(data1):
    infile = open(data1, 'r')
    infile.readline()
    numbers = [float(line.split()[1]) for line in infile]
    # формирование списка каждого второго числа каждой строки
    infile.close()
    return numbers


time1 = extract_data('data1.txt')


def extract_data(data2):
    infile = open(data2, 'r')
    infile.readline()
    numbers = [float(line.split()[1]) for line in infile]
# //формирование списка каждого второго числа каждой строки
    infile.close()
    return numbers


time2 = extract_data('data2.txt')


def extract_data(data3):
    infile = open(data3, 'r')
    infile.readline()
    numbers = [float(line.split()[1]) for line in infile]
# //формирование списка каждого второго числа каждой строки
    infile.close()
    return numbers


time3 = extract_data('data3.txt')

import matplotlib.pyplot as plt
import numpy as np
count1 = range(len(time1))
count2 = range(len(time2))
count3 = range(len(time3))
plt.subplot(221)
plt.plot(count1, time1, '-o')
plt.title("Нерекурсивный")
plt.xlabel("число")
plt.xlabel("время")


plt.subplot(222)
plt.plot(count2, time2, '-o')
plt.title("рекурсивный")
plt.xlabel("число")
plt.xlabel("время")


plt.subplot(223)
plt.plot(count3, time3, '-o')
plt.title("Нерекурсивный с библиотекой")
plt.xlabel("число")
plt.xlabel("время")


plt.subplot(224)
plt.plot(count1, time1, '-o', count2, time2, '-o', count3, time3, '-o')
plt.title("Общий")
plt.xlabel("число")
plt.xlabel("время")
plt.show()















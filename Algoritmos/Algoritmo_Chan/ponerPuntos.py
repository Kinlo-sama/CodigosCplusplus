import numpy as np
import matplotlib.pyplot as plt

puntos = np.random.randint(-40,40, size = (60,2))

with open("Puntos.txt","w") as archivo:
    for punto in puntos:
        archivo.write(str(punto[0]) + ' ' + str(punto[1]) + '\n')


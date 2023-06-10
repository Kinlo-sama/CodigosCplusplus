import matplotlib.pyplot as plt

archivoP = open("Puntos.txt","r")
archivoV = open("Vertices.txt","r")

x = []
y = []
for line in archivoP:
    x.append(float((line.split())[0]))
    y.append(float((line.split())[1]))
archivoP.close()

x_ = []
y_ = []
for line in archivoV:
    x_.append(float((line.split())[0]))
    y_.append(float((line.split())[1]))
archivoV.close()

plt.plot(x_,y_)
plt.scatter(x, y)
plt.figure(figsize=(10, 10))
plt.show() 


#BY KINLO_SAMA :3
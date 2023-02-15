import matplotlib as mpl
from stl import mesh
from mpl_toolkits import mplot3d
from matplotlib import pyplot

mpl.use('qt5agg')

# Create a new plot
fig = pyplot.figure()
#axes = mplot3d.Axes3D(figure)
ax = fig.add_subplot(projection='3d')
#ax.set_position([0, 0, 0.95, 1])

# Load the STL files and add the vectors to the plot
cadmesh = mesh.Mesh.from_file('model/acHousing.stl')

ax.add_collection3d(mplot3d.art3d.Poly3DCollection(cadmesh.vectors))

# Auto scale to the mesh size
scale = cadmesh.points.flatten()
ax.auto_scale_xyz(scale, scale, scale)

# Show the plot to the screen
pyplot.show()

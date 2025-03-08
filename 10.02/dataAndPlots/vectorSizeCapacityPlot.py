import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path

file_path = Path(__file__).parent / "vectorSizeCapacity.txt"

data = np.loadtxt(file_path)

indexes = [i for i in range(data.shape[0])]

plt.scatter(data[:, 0], data[:, 1])
plt.ylabel("Capacity")
plt.xlabel("Size")
plt.title("Capacity and size for std::vector")
plt.grid()
plt.savefig('vectorSizeCapacityDefaultStart.png')
plt.show()

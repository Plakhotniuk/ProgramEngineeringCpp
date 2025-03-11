import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path


def count_column_duplicates(data: pd.Series):
    name_duplicates = data.value_counts()
    non_unique_counts = name_duplicates[name_duplicates > 1]
    return non_unique_counts.size


def plot_one_duplicates_count(data: pd.Series):

    points_num = range(1000, data.size, 50000)

    duplicates = [count_column_duplicates(data.head(i)) for i in points_num]

    plt.plot(points_num, duplicates, label=data.name)


def plot_duplicates_count(data: pd.DataFrame):

    for name in data.columns:
        plot_one_duplicates_count(data[name])
    
    plt.ylabel("collision count")
    plt.xlabel("str count")
    plt.legend()
    plt.title("Collisions of different hash functions.")
    plt.grid()
    plt.savefig('Collisions.png')
    plt.show()


if __name__ == "__main__":
    file_path = Path(__file__).parent / "Hashes.csv"

    data = pd.read_csv(file_path)

    plot_duplicates_count(data)

import csv
import numpy as np
import matplotlib.pyplot as plt

Heapsort = []
Timsort = []
Introsort = []

sorting_algorythm = ["heapsort", "timsort", "introsort"]
filename_start = [1000, 2000, 5000, 10000, 50000, 100000, 500000, 1000000]
filename_end = [0.000, 0.250, 0.500, 0.750, 0.950, 0.990, 0.997, 1.000]

for sort in sorting_algorythm:
    for i in filename_end:
        sort_mean = []

        for j in filename_start:
            sum = 0
            filename = f"results/{sort}_{j}_{i:.3f}.csv"

            with open(filename) as csvfile:
                spamreader = csv.reader(csvfile, delimiter=';', quotechar='|')

                for row in spamreader:
                        sum+=float(row[0])

            sort_mean.append(sum / 100)

        if sort == "heapsort":
            Heapsort.append(sort_mean)
        elif sort == "timsort":
            Timsort.append(sort_mean)
        elif sort == "introsort":
            Introsort.append(sort_mean)


plot_percentage = [0, 25, 50, 75, 95, 99, 99.7, 100]

# heapsort
plt.figure(figsize=(8, 5))
for i, values in zip(plot_percentage, Heapsort):
    filtered_sizes = [x for x, y in zip(filename_start, values) if y is not None]
    filtered_times = [y for y in values if y is not None]
    plt.plot(filtered_sizes, filtered_times, marker='o', linestyle='-', label=f"% of sorted elements = {i}%")

plt.xlabel("Size of the table [N]")
plt.ylabel("Average execution time [ms]")
plt.title("Heapsort")
plt.xscale("log")
#plt.yscale("log")
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.savefig("heapsort.pdf")
plt.show()

# timsort
plt.figure(figsize=(8, 5))
for i, values in zip(plot_percentage, Timsort):
    filtered_sizes = [x for x, y in zip(filename_start, values) if y is not None]
    filtered_times = [y for y in values if y is not None]
    plt.plot(filtered_sizes, filtered_times, marker='o', linestyle='-', label=f"% of sorted elements = {i}%")

plt.xlabel("Size of the table [N]")
plt.ylabel("Average execution time [ms]")
plt.title("Timsort")
plt.xscale("log")
#plt.yscale("log")
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.savefig("timsort.pdf")
plt.show()

# introsort
plt.figure(figsize=(8, 5))
for i, values in zip(plot_percentage, Introsort):
    filtered_sizes = [x for x, y in zip(filename_start, values) if y is not None]
    filtered_times = [y for y in values if y is not None]
    plt.plot(filtered_sizes, filtered_times, marker='o', linestyle='-', label=f"% of sorted elements = {i}%")

plt.xlabel("Size of the table [N]")
plt.ylabel("Average execution time [ms]")
plt.title("Introsort")
plt.xscale("log")
#plt.yscale("log")
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.savefig("introsort.pdf")
plt.show()

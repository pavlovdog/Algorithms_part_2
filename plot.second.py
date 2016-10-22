import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("profiler.second.csv")
tests = zip(list(df["time"]), list(df["edges"]))

profiling = {}

for test in tests:
	if test[1] not in profiling.keys():
		profiling[test[1]] = [test[0]]
	else:
		profiling[test[1]].append(test[0])

times = []
edges = []

for edge in profiling:
	edges.append(edge)
	times.append(sum(profiling[edge]) / len(profiling[edge]))

plt.scatter(edges, times)
plt.show()
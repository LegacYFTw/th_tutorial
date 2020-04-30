import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()
T = int(input())
while T:
    a, b = map(str, input().split())
    G.add_edge(a, b)
    T -= 1
nx.draw(G, with_labels=True, font_weight='bold')
plt.savefig("graph.png")

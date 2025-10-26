import pandas as pd
import matplotlib.pyplot as plt
import os

# Helper function to read CSV safely
def read_csv_safe(path):
    if os.path.exists(path):
        return pd.read_csv(path)
    else:
        print(f"⚠️ File not found: {path}")
        return None

# File paths
dijkstra_path = "../data/dijkstra_output.csv"
bfs_path = "../data/bfs_output.csv"
dfs_path = "../data/dfs_output.csv"

# Load data
dijkstra_data = read_csv_safe(dijkstra_path)
bfs_data = read_csv_safe(bfs_path)
dfs_data = read_csv_safe(dfs_path)

# Plot 1: Dijkstra vs BFS (distance comparison)
if dijkstra_data is not None and bfs_data is not None:
    plt.figure(figsize=(7, 4))
    plt.plot(dijkstra_data["Node"], dijkstra_data["Distance"], marker="o", label="Dijkstra (Weighted)")
    plt.plot(bfs_data["Node"], bfs_data["Distance"], marker="s", label="BFS (Unweighted)")
    plt.title("Shortest Path Comparison (Dijkstra vs BFS)")
    plt.xlabel("Node")
    plt.ylabel("Distance from Source")
    plt.legend()
    plt.grid(alpha=0.6)
    plt.tight_layout()
    plt.savefig("../data/comparison_dijkstra_bfs.png")
    plt.show()

# Plot 2: DFS traversal order
if dfs_data is not None:
    plt.figure(figsize=(6, 3))
    plt.bar(range(len(dfs_data["Visit_Order"])), dfs_data["Visit_Order"], color="orange")
    plt.title("DFS Traversal Order")
    plt.xlabel("Step")
    plt.ylabel("Visited Node")
    plt.tight_layout()
    plt.savefig("../data/dfs_order.png")
    plt.show()

print("✅ Comparison plots saved in data/ folder!")

# === Dynamic Routing Visualization ===
print("\n=== Dynamic Traffic Routing Visualization ===")

dyn_path = "../data/dynamic_routing.csv"

try:
    dyn_data = pd.read_csv(dyn_path)

    plt.figure(figsize=(7, 4))
    for node in dyn_data["Node"].unique():
        node_data = dyn_data[dyn_data["Node"] == node]
        plt.plot(node_data["Round"], node_data["Distance"], marker="o", label=f"Node {node}")

    plt.title("Dynamic Routing: Distance Changes Over Time")
    plt.xlabel("Traffic Update Round")
    plt.ylabel("Distance from Source (Node 0)")
    plt.legend()
    plt.grid(alpha=0.6)
    plt.tight_layout()
    plt.savefig("../data/dynamic_routing_plot.png")
    plt.show()

    print("✅ Dynamic routing plot saved to data/dynamic_routing_plot.png")

except Exception as e:
    print("⚠️ Could not plot dynamic routing:", e)

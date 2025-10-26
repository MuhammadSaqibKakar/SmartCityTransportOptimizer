import pandas as pd
import matplotlib.pyplot as plt
import os

# --- Step 1: Read BFS CSV file ---
csv_path = '../data/bfs_output.csv'

if not os.path.exists(csv_path):
    print(f"❌ File not found: {csv_path}")
    print("Run your C++ bfs.exe first to generate bfs_output.csv")
    exit()

bfs = pd.read_csv(csv_path)

# --- Step 2: Display basic data info ---
print("\n✅ BFS Output loaded successfully!\n")
print("Sample Data:")
print(bfs.head())
print("\nColumns found:", bfs.columns.tolist())

# --- Step 3: Basic data check ---
if 'Node' not in bfs.columns or 'Distance' not in bfs.columns:
    print("\n❌ Expected columns 'Node' and 'Distance' not found in the CSV.")
    print("Please ensure bfs_output.csv has columns: Node, Distance")
    exit()

# --- Step 4: Plot Node vs Distance ---
plt.figure(figsize=(8, 5))
plt.plot(bfs['Node'], bfs['Distance'], marker='o', color='b', label='BFS Distance')
plt.title('BFS: Node vs Distance')
plt.xlabel('Node')
plt.ylabel('Distance from Source')
plt.legend()
plt.grid(True)

# --- Step 5: Save and show plot ---
output_path = '../data/bfs_node_distance.png'
plt.savefig(output_path)
plt.show()

print(f"\n📊 Plot saved successfully as: {output_path}")

# 🚦 Smart City Transportation Optimizer
*A Complex Engineering Problem Project for Design and Analysis of Algorithms (DAA)*

## 📘 Overview
With rapid urbanization, traffic congestion and inefficient transportation are critical challenges.  
This project implements a **Smart City Traffic Optimizer** using multiple algorithmic paradigms —  
combining **Graph Algorithms**, **Greedy Methods**, **Dynamic Programming**, and **Approximation Algorithms**.

---

## ⚙️ Project Architecture
SmartCityTransportOptimizer/
├─ cpp/ → Core algorithm implementations (C++)
│ ├─ src/ → Source code files
│ └─ build/ → Compiled binaries & executables
├─ data/ → Input/Output CSVs + generated graphs
├─ python/ → Analysis & visualization (matplotlib, pandas)
│ └─ venv/ → Python virtual environment
├─ docs/ → Reports, notes, proofs
└─ README.md


---

## 🧠 Algorithms Implemented
### 1. **Graph Representation & Pathfinding**
- BFS / DFS  
- Dijkstra’s Algorithm  
- A* Algorithm  

### 2. **Dynamic Traffic Routing**
- Dynamic Edge Weight Updates  
- Divide & Conquer / Dynamic Programming for Re-routing  

### 3. **Vehicle Scheduling & Resource Allocation**
- Greedy vs Dynamic Programming Comparison  

### 4. **NP-Complete Problem Integration**
- Traveling Salesman Problem (TSP)  
- Exact (Branch & Bound) and Approximation (Nearest Neighbor / Christofides)

---

## 📊 Example Output (BFS)
C++ BFS implementation generates:
data/bfs_output.csv
Python visualization:
data/bfs_node_distance.png
![BFS Graph Example](data/bfs_node_distance.png)

---

## 🔬 Complexity & Analysis
Each algorithm’s performance is evaluated both **theoretically (asymptotic analysis)** and **empirically (runtime & scaling plots)**.  
Time vs Space trade-offs and correctness proofs are discussed in the report.

---

## 🛠️ Technologies Used
- **C++** → Core algorithms, efficiency testing  
- **Python (pandas, matplotlib)** → Analysis & visualization  
- **Git + GitHub** → Version control and collaboration  

---

## 📈 Results
- BFS, Dijkstra, and A* tested on graphs with varying node counts  
- Comparative plots show empirical runtime growth  
- Greedy vs DP vehicle scheduling trade-offs analyzed  

---

## 👨‍💻 Contributors
**Muhammad Saqib Kakar**  
BS Software Engineering, BUITEMS Quetta  
Project Supervisors: *Engr. Arsalan Ul Haq & Engr. Farhan Aftab*

---

## 🧾 License
This project is part of BUITEMS coursework and is for academic and learning purposes only.


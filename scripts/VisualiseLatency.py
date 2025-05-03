import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load CSV
df = pd.read_csv("benchmark/latency_report.csv")

# Plot latency histogram
plt.figure(figsize=(10, 5))
sns.histplot(data=df, x="latency_ns", bins=100, kde=True)
plt.title("Order Processing Latency Distribution")
plt.xlabel("Latency (ns)")
plt.ylabel("Frequency")
plt.grid(True)
plt.tight_layout()
plt.show()

# Compare naive vs optimized
plt.figure(figsize=(10, 5))
sns.boxplot(data=df, x="type", y="latency_ns")
plt.title("Latency by Engine Type (Naive vs Optimized)")
plt.ylabel("Latency (ns)")
plt.grid(True)
plt.tight_layout()
plt.show()

# TPS (rolling throughput)
df["rolling_avg_ns"] = df["latency_ns"].rolling(window=1000).mean()
df["tps"] = 1e9 / df["rolling_avg_ns"]

plt.figure(figsize=(10, 5))
plt.plot(df["tps"], label="Rolling TPS")
plt.title("Rolling Throughput (TPS over 1000 orders)")
plt.xlabel("Order Index")
plt.ylabel("TPS")
plt.grid(True)
plt.tight_layout()
plt.legend()
plt.show()

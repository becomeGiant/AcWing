SPFA算法是对BellmanFord算法的优化
优化思路：
BellmanFord算法的松弛公式：dist[b]=min(dist[b],dist[a]+w)，如果dist[a]没有变小，dist[b]也不可能变小

queue
while queue没空
  取队头
  更新队头的所有出边
  

### Chapter4 RAFT

每个node维护一个election timeout（每次150ms-300ms随机）。作为follower，如果到了timeout则转为candidate

转完后参加vote：

1. term+1
2. 投给自己，并行发RequestVote RPC给所有的其他server
3. 收server结果，如果获得超过半数的投票，则成为leader
4. 如果没选出leader则进入election timeout，当选了则立刻发送一条AppendEntries消息给其他所有的服务器，没当选则等待leader的heartbeat

在3前如果收到了其他candidate的RequestVote则重制timeout



term

拒绝过期的term


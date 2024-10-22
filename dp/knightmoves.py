from re import I
import math, sys

#idhere
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

mod = int(1e9 + 7)
def bfs_max_knight_moves(K):
    # Tạo một hàng đợi cho BFS và một tập hợp để lưu trữ các ô đã thăm
    queue = [(1, 1, 0)]  # (row, col, moves)
    moves = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]
    
    count = 1  # bắt đầu từ ô (1, 1) khi K = 0
    
    while queue:
        r, c, current_moves = queue.pop(0)
        
        if current_moves < K:
            for dr, dc in moves:
                nr, nc = r + dr, c + dc
                if 1 <= nr <= 8 and 1 <= nc <= 8:
                    queue.append((nr, nc, current_moves + 1))
                    count += 1
    
    return count

def dp_knight_moves(K):
    # Khởi tạo mảng DP cho bàn cờ 8x8 và K bước
    dp = [[[0] * (K + 1) for _ in range(9)] for _ in range(9)]
    dp[1][1][0] = 1  # Trạng thái ban đầu tại (1, 1)

    # Các nước đi của quân Mã trên bàn cờ
    moves = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]

    # Tính toán DP cho từng bước
    for k in range(K):
        for i in range(1, 9):
            for j in range(1, 9):
                if dp[i][j][k] > 0:
                    for dr, dc in moves:
                        ni, nj = i + dr, j + dc
                        if 1 <= ni <= 8 and 1 <= nj <= 8:
                            dp[ni][nj][k + 1] += dp[i][j][k]

    # Tính tổng số nước đi riêng biệt cho bước K
    result = sum(dp[i][j][K] for i in range(1, 9) for j in range(1, 9))
    return result

def dp_knight_moves_sum(K):
    # Tính tổng nước đi từ 0 đến 63
    max_steps = 63
    dp_sums = [0] * (max_steps + 1)
    
    for i in range(max_steps + 1):
        dp_sums[i] = dp_knight_moves(i)

    # Tính tổng nước đi từ 0 đến K_small
    K_small = K % max_steps
    total_sum = sum(dp_sums[:K_small + 1])

    # Tính số lần lặp lại chu kỳ
    repeat_count = K // max_steps
    
    # Tổng nước đi cho tất cả chu kỳ lặp lại và phần dư
    total_sum += repeat_count * sum(dp_sums)

    return total_sum

# Sử dụng hàm với các giá trị K khác nhau
K = int(input())
result = 0
result = result % mod + dp_knight_moves_sum(K) % mod
print(result)


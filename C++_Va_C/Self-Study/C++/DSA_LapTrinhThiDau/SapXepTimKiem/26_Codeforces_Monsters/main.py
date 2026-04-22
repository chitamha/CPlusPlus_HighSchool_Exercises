import sys

def solve():
    # Đọc input nhanh
    input = sys.stdin.read
    data = input().split()
    
    if not data:
        return
        
    t = int(data[0]) # Số lượng test cases
    idx = 1
    
    out = []
    
    for _ in range(t):
        n = int(data[idx])
        k = int(data[idx+1])
        idx += 2
        
        arr = []
        for i in range(n):
            health = int(data[idx + i])
            
            # Tính lượng máu dư ở đòn quyết định
            rem = health % k
            if rem == 0:
                rem = k
            
            # Lưu vào mảng dưới dạng Tuple: (-máu dư, chỉ số gốc)
            # Dùng số âm cho máu dư để khi sort tăng dần mặc định của Python, 
            # máu dư lớn nhất (số âm nhỏ nhất) sẽ được đẩy lên đầu.
            # Chỉ số (i + 1) vẫn giữ số dương để ưu tiên từ nhỏ đến lớn.
            arr.append((-rem, i + 1))
            
        idx += n
        
        # Sắp xếp theo luật mặc định của Tuple trong Python
        arr.sort()
        
        # Trích xuất kết quả
        result = [str(x[1]) for x in arr]
        out.append(" ".join(result))
        
    # In tất cả output cùng lúc để tối ưu I/O
    sys.stdout.write("\n".join(out) + "\n")

if __name__ == "__main__":
    solve()
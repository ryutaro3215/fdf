import random

def print_random_numbers(width, height, include_color=False):
    for _ in range(height):
        for j in range(width):
            num = random.randint(0, 0)  # 0から30の範囲で乱数を生成
            if include_color:
                # ランダムな色コードを生成（"0x"接頭辞を付けて16進数形式で）
                color = "0x{:06x}".format(random.randint(0, 0xFFFFFF))
                print(f"{num},{color}", end=" " if j < width - 1 else "")
            else:
                print(f"{num}", end=" " if j < width - 1 else "")
        print()

def main():
    width = 50
    height = 50
    include_color = True  # Trueにすると色コードを含む、Falseにすると含まない
    print_random_numbers(width, height, include_color)

if __name__ == "__main__":
    main()

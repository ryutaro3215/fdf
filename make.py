import random

def print_random_numbers(width, height):
    INT_MAX = 2**31 - 1
    INT_MIN = -2**31

    for _ in range(height):
        for j in range(width):
            # INT_MIN から INT_MAX の範囲で乱数を生成
            num = random.randint(INT_MIN, INT_MAX)
            print(f"{num}", end=" " if j < width - 1 else "")
        print()

def main():
    width = int(input("幅を入力してください: "))
    height = int(input("高さを入力してください: "))

    print_random_numbers(width, height)

if __name__ == "__main__":
    main()

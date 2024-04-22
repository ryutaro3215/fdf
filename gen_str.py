from PIL import Image, ImageDraw, ImageFont

def generate_text_pattern(character, font_path, font_size, matrix_width, matrix_height):
    # 文字を描画するための画像を作成
    image = Image.new('1', (matrix_width, matrix_height), 1)  # 1-bit image, '1' は白背景
    draw = ImageDraw.Draw(image)
    font = ImageFont.truetype(font_path, font_size)

    # 文字を画像中央に配置
    text_width, text_height = draw.textsize(character, font=font)
    text_top_left = ((matrix_width - text_width) // 2, (matrix_height - text_height) // 2)
    draw.text(text_top_left, character, font=font, fill=0)  # 0 は黒色

    # 画像からパターンを抽出
    pattern = set()
    for y in range(matrix_height):
        for x in range(matrix_width):
            if image.getpixel((x, y)) == 0:  # 黒ピクセルを検出
                pattern.add((y, x))
    return pattern

def print_pattern_numbers(width, height, pattern, high_value, low_value):
    for y in range(height):
        for x in range(width):
            num = high_value if (y, x) in pattern else low_value
            print(f"{num} ", end="")
        print()

def main():
    width = 100  # マトリックスの幅
    height = 40  # マトリックスの高さ
    character = 'A'  # 表示したい文字
    font_path = 'arial.ttf'  # 使用するフォントのパス
    font_size = 32  # フォントサイズ

    high_value = 9  # 形状を目立たせる高い値
    low_value = 1  # 背景の低い値

    pattern = generate_text_pattern(character, font_path, font_size, width, height)
    print_pattern_numbers(width, height, pattern, high_value, low_value)

if __name__ == "__main__":
    main()

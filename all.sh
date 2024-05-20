#!/bin/bash

# Указываем путь до корневой директории, где будем начинать поиск
ROOT_DIR="./"

# Указываем файл, в который будем записывать результаты
OUTPUT_FILE="./out.txt"

# Рекурсивно обходим все .c, .cpp и .h файлы в указанной директории и ее поддиректориях
find "$ROOT_DIR" -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" \) | while IFS= read -r file; do
    # Выводим путь к файлу в файл результатов
    echo "// $file" >> "$OUTPUT_FILE"
    echo "" >> "$OUTPUT_FILE"
    # Выводим содержимое файла в файл результатов
    cat "$file" >> "$OUTPUT_FILE"
    echo "" >> "$OUTPUT_FILE"
done

echo "Готово! Результаты записаны в файл: $OUTPUT_FILE"
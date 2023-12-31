if [ $# -eq 0 ]; then
  echo "Необходимо указать путь до файла лога"
  exit 1
fi

# Проверяем, существует ли указанный файл
if [ ! -f "$1" ]; then
  echo "Указанный файл не существует"
  exit 1
fi

# Подсчет общего количества записей в файле
total_records=$(wc -l < "$1")

# Подсчет количества уникальных файлов
unique_files=$(grep -oE '[[:alnum:]]{32}' "$1" | sort -u | wc -l)

# Подсчет количества изменений, приведших к изменению hash файла
hash_changes=$(grep -c 'changed hash' "$1" | awk '{sum+=$1} END {print sum}')

# Вывод результатов
echo "Подсчет общего количества записей в файле: $total_records"
echo "Подсчет количества уникальных файлов: $unique_files"
echo "Подсчет количества изменений, приведших к изменению hash файла: $hash_changes"



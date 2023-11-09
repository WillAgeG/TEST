if [ $# -ne 3 ]; then
    echo "Используйте 3 аргумента в виде: $0 <Название файла> <Исходная строка> <Новая строка>"
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "Файл не найден: $1"
    exit 1
fi

sed -i "s/$2/$3/g" "$1"
echo "Изменение выполнено для файла $1"


file=$1
logfile="files.log"

timestamp=$(stat -c "%y" $file)
sizefile=$(stat -c %s $file)
sha256=$(sha256sum $file)

echo "$file - $sizefile - $timestamp - $sha256 - sha256" >> $logfile


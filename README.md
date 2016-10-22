# Второе домашнее задание
## Потехин Сергей, 156 группа

### Структура репозитория
+ profiler - самописная утилита для тестирования производительности
+ samples - наборы данных для запуска программ
+ profiler.first.csv (profiler.second.csv) - таблица с результатати тестирования для первого (второго) пункта
+ source.first.cpp (source.second.cpp) - исходники для первого (второго) пункта
+ x.first (x.second) - исполняемые файлы для первого (второго) пункта

### Профайлинг
Профайлер написан на Python 2.7, для корректной работы необходимо установить несколько библиотек.
```
sudo pip install pandas termcolor
./profiler --help
usage: profiler [-h] [--first FIRST] [--second SECOND]
                [--nodes NODES [NODES ...]] [--edges EDGES [EDGES ...]]
                [--raws RAWS [RAWS ...]] [--lenght LENGHT [LENGHT ...]]

Profiler for HW, part 2. Profiler works good right out of the box, so just
type "./profiler --first True -- second True"

optional arguments:
  -h, --help            		show this help message and exit
  --first FIRST         		Profile first problem; default = False
  --second SECOND       		Profile second problem; default = False
  --nodes NODES [NODES ...]		Nodes range for the first problem; default = 10 15
  --edges EDGES [EDGES ...]		Edges range for the first problem; default = 20 25
  --raws RAWS [RAWS ...]		Number of raws range for the second problem; default = 100 110
  --lenght LENGHT [LENGHT ...]	Raw's lenght for the second problem; default = 10 15
```
В принципе все неплохо работает на дефолтных настройках, достаточно запустить
```
./profiler --first True --second True
```
Но при желании можно изменить параметры, в --help все достаточно подробно описано. Отчеты в репозитории созданы командой (работает долго, 1600 и 2000 тестов соответственно)
```
./profiler --first True --second True --nodes 10 30 --edges 20 100 --raws 100 300 --lenght 10 20
```

### Первый пункт

#### Код

#### Ассимптотика

#### Доказательство корректности

#### Профайлинг

### Второй пункт

#### Код

#### Ассимптотика

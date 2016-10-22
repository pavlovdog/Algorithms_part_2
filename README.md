# Второе домашнее задание
## Потехин Сергей, 156 группа

### Структура репозитория
+ profiler - самописная утилита для тестирования производительности
+ samples - наборы данных для запуска программ
+ profiler.first.csv (profiler.second.csv) - таблица с результатами тестирования для первого (второго) пункта
+ source.first.cpp (source.second.cpp) - исходники для первого (второго) пункта
+ x.first (x.second) - исполняемые файлы для первого (второго) пункта
+ plot.first.py (plot.second.py) - скрипт для отрисовки данных из profiler.first.csv (profiler.second.csv)

### Первый пункт

#### Код
Используем vector used_nodes для хранения уже посещенных вершин и vector answer для хранения ребер финального паросочетания. После ввода, будем просто идти по списку ребер и если вершин из этого ребра нет в used, то добавим ребро в answer, а вершины ребра в used. Ответом будет answer.

#### Ассимптотика
Будем считать, что вершин у нас x, а ребер - y. Тогда:

1. Считать x и y <b>O(1)</b>
2. m раз считать ребро и добавить его в vector <b>O(m)</b>
3. Инициализируем вектор использованных вершин <b>O(n)<b/>
4. Идем по списку ребер <b>O(m)</b>
5. Проверяем начало и конец ребра на наличие в used_nodes <b>O(1)</b>
6. Добавляем ребро в answer, а вершины в used <b>O(1)</b>

Итог: <b>O(m + n)</b>

#### Доказательство
Пусть есть паросочетание, найденное нашим алгоритмом (А), и оптимальное паросочетание (Б) - сравним их. Возьмем какое-то ребро из А - оно может либо совпадать с каким-то ребром из Б (неинтересно), либо пересекаться с пересекаться к какими-то ребрами из Б.

1. Ребро может пересечься с одним ребром из Б (a.б)
2. Ребро может пересечься с двумя ребрами из Б (б.а.б)

Заметим, что ребро из А не может пересекаться с тремя и более ребрами из Б, тк тогда в Б присутствуют пересекающиеся ребра, что противоречит определению паросочетания. Следовательно, каждому ребру из А, можно поставить в соответствие максимум два ребра из Б, следовательно - Б больше чем А максимум в два раза.

#### График зависимости времени работы (Y) от числа ребер (Х)
Для графика использовался набор данных, полученных в результате тестирования командой (работает несколько минут, ~5000 тестов)
```bash
$ ./profiler --first True --nodes 100 100 --edges 10 5000
```

Видно, что за исключением несольких аномальных точек, время работы зависит линейно от числа ребер. График также подтверждает ассимптотику.

![first](https://github.com/pavlovdog/Algorithms_part_2/blob/master/first.plot.png "First plot")

### Второй пункт

#### Код

#### Ассимптотика

#### График времени работы

### Профайлинг
Профайлер написан на Python 2.7, для корректной работы необходимо установить несколько библиотек.
```bash
$ sudo pip install pandas termcolor
$ ./profiler --help
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
```bash
$ ./profiler --first True --second True
```
Но при желании можно изменить параметры, в --help все достаточно подробно описано. Отчеты в репозитории созданы командой (работает долго, 1600 и 2000 тестов соответственно)
```bash
$ ./profiler --first True --second True --nodes 10 30 --edges 20 100 --raws 100 300 --lenght 10 20
```

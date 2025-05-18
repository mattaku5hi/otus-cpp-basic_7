# OTUS-CPP-Basics 07 homework Project

## 1. Stack
Statistics utility.
Developed by means of C++17 / UNIX / GCC / GTest.

## 2. Description
В задании требуется реализовать тестирование созданных разработанных ранее контейнеров динамического размера – последовательного и
спискового типа.
1. Последовательный контейнер
Отличительная черта такого контейнера – расположение элементов друг за другом подряд
(как и у обычного массива в стиле Си).
2. Контейнер спискового типа – не предоставляет гарантий расположения элементов друг за
другом в памяти. Связь между элементами осуществляется через указатели (указатель на
предыдущий элемент и/или указатель на следующий элемент).
Пользовательский код (вызывается из функции main) должен содержать следующий набор
действий с обоими контейнерами:
1. создание объекта контейнера для хранения объектов типа int
2. добавление в контейнер десяти элементов (0, 1 … 9)
3. вывод содержимого контейнера на экран
ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
4. вывод размера контейнера на экран
ожидаемый результат: 10
5. удаление третьего (по счёту), пятого и седьмого элементов
6. вывод содержимого контейнера на экран
ожидаемый результат: 0, 1, 3, 5, 7, 8, 9
7. добавление элемента 10 в начало контейнера
8. вывод содержимого контейнера на экран
ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9
9. добавление элемента 20 в середину контейнера
10. вывод содержимого контейнера на экран
ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9
11. добавление элемента 30 в конец контейнера
12. вывод содержимого контейнера на экран
ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30
Требования к минимальному интерфейсу:
- метод/ы (может быть несколько) добавления элементов в конец контейнера ( push_back )
- метод/ы вставки элементов в произвольную позицию ( insert )
- метод/ы удаления элементов из контейнера ( erase )
- метод получения текущего размера контейнера ( size )
- метод/ы получения доступа по индексу ( operator[] )

## 3. Preparing
### 3.1 Install the dependencies
Make sure that all the dependencies are already installed on your machine  
```bash
sudo apt update 
sudo apt install -y libgtest-dev
```

## 4. Getting started
### 4.1 Clone the project 
```bash
cd </path/to/workspace>
git clone https://github.com/mattaku5hi/otus-cpp-basic_7/
```
### 4.2 Build the project
To build a project one may simply execute a script:  
to build the release executable and tests for it:
```bash
cd </path/to/workspace>
chmod +x ./tools/container_build_release.sh
./tools/build_release.sh  
```
to build the debug executable:
```bash
cd </path/to/workspace>
chmod +x ./tools/container_build_release.sh
./tools/build_debug.sh  
```

## 5. Usage
The utility is able to accept the GTest compatible options depending on what and how the user wants to test.  
Example launch of all the tests (for both vector and singly linked list):
```bash
./release/container_test 
[==========] Running 19 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 9 tests from LinkedListTest
[ RUN      ] LinkedListTest.Creation
[       OK ] LinkedListTest.Creation (0 ms)
[ RUN      ] LinkedListTest.PushBack
[       OK ] LinkedListTest.PushBack (0 ms)
[ RUN      ] LinkedListTest.Insert
[       OK ] LinkedListTest.Insert (0 ms)
[ RUN      ] LinkedListTest.Erase
[       OK ] LinkedListTest.Erase (0 ms)
[ RUN      ] LinkedListTest.ElementAccess
[       OK ] LinkedListTest.ElementAccess (0 ms)
[ RUN      ] LinkedListTest.Copying
[       OK ] LinkedListTest.Copying (0 ms)
[ RUN      ] LinkedListTest.Moving
[       OK ] LinkedListTest.Moving (0 ms)
[ RUN      ] LinkedListTest.Iterators
[       OK ] LinkedListTest.Iterators (0 ms)
[ RUN      ] LinkedListTest.Clear
[       OK ] LinkedListTest.Clear (0 ms)
[----------] 9 tests from LinkedListTest (0 ms total)

[----------] 10 tests from VectorTest
[ RUN      ] VectorTest.Creation
[       OK ] VectorTest.Creation (0 ms)
[ RUN      ] VectorTest.PushBack
[       OK ] VectorTest.PushBack (0 ms)
[ RUN      ] VectorTest.Insert
[       OK ] VectorTest.Insert (0 ms)
[ RUN      ] VectorTest.Erase
[       OK ] VectorTest.Erase (0 ms)
[ RUN      ] VectorTest.ElementAccess
[       OK ] VectorTest.ElementAccess (0 ms)
[ RUN      ] VectorTest.SizeAndCapacity
[       OK ] VectorTest.SizeAndCapacity (0 ms)
[ RUN      ] VectorTest.Copying
[       OK ] VectorTest.Copying (0 ms)
[ RUN      ] VectorTest.Moving
[       OK ] VectorTest.Moving (0 ms)
[ RUN      ] VectorTest.Iterators
[       OK ] VectorTest.Iterators (0 ms)
[ RUN      ] VectorTest.Clear
[       OK ] VectorTest.Clear (0 ms)
[----------] 10 tests from VectorTest (0 ms total)

[----------] Global test environment tear-down
[==========] 19 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 19 tests.
```
Example launch of all the tests (for both vector and singly linked list) and store report to _container_test_report.xml_ file:
```bash
./release/container_test --gtest_output=xml:./container_test_report.xml
[==========] Running 19 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 9 tests from LinkedListTest
[ RUN      ] LinkedListTest.Creation
[       OK ] LinkedListTest.Creation (0 ms)
[ RUN      ] LinkedListTest.PushBack
[       OK ] LinkedListTest.PushBack (0 ms)
[ RUN      ] LinkedListTest.Insert
[       OK ] LinkedListTest.Insert (0 ms)
[ RUN      ] LinkedListTest.Erase
[       OK ] LinkedListTest.Erase (0 ms)
[ RUN      ] LinkedListTest.ElementAccess
[       OK ] LinkedListTest.ElementAccess (0 ms)
[ RUN      ] LinkedListTest.Copying
[       OK ] LinkedListTest.Copying (0 ms)
[ RUN      ] LinkedListTest.Moving
[       OK ] LinkedListTest.Moving (0 ms)
[ RUN      ] LinkedListTest.Iterators
[       OK ] LinkedListTest.Iterators (0 ms)
[ RUN      ] LinkedListTest.Clear
[       OK ] LinkedListTest.Clear (0 ms)
[----------] 9 tests from LinkedListTest (7 ms total)

[----------] 10 tests from VectorTest
[ RUN      ] VectorTest.Creation
[       OK ] VectorTest.Creation (0 ms)
[ RUN      ] VectorTest.PushBack
[       OK ] VectorTest.PushBack (0 ms)
[ RUN      ] VectorTest.Insert
[       OK ] VectorTest.Insert (0 ms)
[ RUN      ] VectorTest.Erase
[       OK ] VectorTest.Erase (0 ms)
[ RUN      ] VectorTest.ElementAccess
[       OK ] VectorTest.ElementAccess (0 ms)
[ RUN      ] VectorTest.SizeAndCapacity
[       OK ] VectorTest.SizeAndCapacity (0 ms)
[ RUN      ] VectorTest.Copying
[       OK ] VectorTest.Copying (0 ms)
[ RUN      ] VectorTest.Moving
[       OK ] VectorTest.Moving (0 ms)
[ RUN      ] VectorTest.Iterators
[       OK ] VectorTest.Iterators (0 ms)
[ RUN      ] VectorTest.Clear
[       OK ] VectorTest.Clear (0 ms)
[----------] 10 tests from VectorTest (0 ms total)

[----------] Global test environment tear-down
[==========] 19 tests from 2 test suites ran. (7 ms total)
[  PASSED  ] 19 tests.
```
Example launch tests for linked list container only:
```bash
./release/container_test --gtest_filter=LinkedListTest.*
Note: Google Test filter = LinkedListTest.*
[==========] Running 9 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 9 tests from LinkedListTest
[ RUN      ] LinkedListTest.Creation
[       OK ] LinkedListTest.Creation (0 ms)
[ RUN      ] LinkedListTest.PushBack
[       OK ] LinkedListTest.PushBack (0 ms)
[ RUN      ] LinkedListTest.Insert
[       OK ] LinkedListTest.Insert (0 ms)
[ RUN      ] LinkedListTest.Erase
[       OK ] LinkedListTest.Erase (0 ms)
[ RUN      ] LinkedListTest.ElementAccess
[       OK ] LinkedListTest.ElementAccess (0 ms)
[ RUN      ] LinkedListTest.Copying
[       OK ] LinkedListTest.Copying (0 ms)
[ RUN      ] LinkedListTest.Moving
[       OK ] LinkedListTest.Moving (0 ms)
[ RUN      ] LinkedListTest.Iterators
[       OK ] LinkedListTest.Iterators (0 ms)
[ RUN      ] LinkedListTest.Clear
[       OK ] LinkedListTest.Clear (0 ms)
[----------] 9 tests from LinkedListTest (0 ms total)

[----------] Global test environment tear-down
[==========] 9 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 9 tests.
```
Example launch the single test of move semantics (including move ctor) for linked list container only:
```bash
./release/container_test --gtest_filter=LinkedListTest.Moving
Note: Google Test filter = LinkedListTest.Moving
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from LinkedListTest
[ RUN      ] LinkedListTest.Moving
[       OK ] LinkedListTest.Moving (0 ms)
[----------] 1 test from LinkedListTest (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.

```
Example launch tests for linked list container only with the stated repeats:
```bash
./release/container_test --gtest_filter=LinkedListTest.* --gtest_repeat=2
Repeating all tests (iteration 1) . . .

Note: Google Test filter = LinkedListTest.*
[==========] Running 9 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 9 tests from LinkedListTest
[ RUN      ] LinkedListTest.Creation
[       OK ] LinkedListTest.Creation (0 ms)
[ RUN      ] LinkedListTest.PushBack
[       OK ] LinkedListTest.PushBack (0 ms)
[ RUN      ] LinkedListTest.Insert
[       OK ] LinkedListTest.Insert (0 ms)
[ RUN      ] LinkedListTest.Erase
[       OK ] LinkedListTest.Erase (0 ms)
[ RUN      ] LinkedListTest.ElementAccess
[       OK ] LinkedListTest.ElementAccess (0 ms)
[ RUN      ] LinkedListTest.Copying
[       OK ] LinkedListTest.Copying (0 ms)
[ RUN      ] LinkedListTest.Moving
[       OK ] LinkedListTest.Moving (0 ms)
[ RUN      ] LinkedListTest.Iterators
[       OK ] LinkedListTest.Iterators (0 ms)
[ RUN      ] LinkedListTest.Clear
[       OK ] LinkedListTest.Clear (0 ms)
[----------] 9 tests from LinkedListTest (0 ms total)

[==========] 9 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 9 tests.

Repeating all tests (iteration 2) . . .

Note: Google Test filter = LinkedListTest.*
[==========] Running 9 tests from 1 test suite.
[----------] 9 tests from LinkedListTest
[ RUN      ] LinkedListTest.Creation
[       OK ] LinkedListTest.Creation (0 ms)
[ RUN      ] LinkedListTest.PushBack
[       OK ] LinkedListTest.PushBack (0 ms)
[ RUN      ] LinkedListTest.Insert
[       OK ] LinkedListTest.Insert (0 ms)
[ RUN      ] LinkedListTest.Erase
[       OK ] LinkedListTest.Erase (0 ms)
[ RUN      ] LinkedListTest.ElementAccess
[       OK ] LinkedListTest.ElementAccess (0 ms)
[ RUN      ] LinkedListTest.Copying
[       OK ] LinkedListTest.Copying (0 ms)
[ RUN      ] LinkedListTest.Moving
[       OK ] LinkedListTest.Moving (0 ms)
[ RUN      ] LinkedListTest.Iterators
[       OK ] LinkedListTest.Iterators (0 ms)
[ RUN      ] LinkedListTest.Clear
[       OK ] LinkedListTest.Clear (0 ms)
[----------] 9 tests from LinkedListTest (0 ms total)

[----------] Global test environment tear-down
[==========] 9 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 9 tests.
```

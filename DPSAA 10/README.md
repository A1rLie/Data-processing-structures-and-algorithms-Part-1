Для нахождения минимальной длины строки необходимо перебрать всевозможные строки подаваемой подстроки, на очередной переборе используем алгоритм Кнута-Морриса-Пратта, для нахождения первого вхождения этой подстроки в строке. Затем ищем следующее вхождение этой подстроки и находим разницу между индексами, если разница между индексами равна длине текущей подстроки, то возвращаем этот результат. Пример: строка ab, новая строка ababab, переданная строка bab. Начинаем перебор всевозможных подстрок переданной строки, в первом случае это b, используем алгоритм Кнута-Морриса-Пратта и индекс первого вхождения равен 1, еще раз используем алгоритм Кнута-Морриса-Пратта со смещенным первым индексом и второе вхождение равно 3. Сравниваем длину слова с разницей в индексах, результат проверки будет ложным, так доходим до предполагаемой верной строки ab, находим индекс первого ее вхождения, индекс равен 0, индекс второго вхождения равен 2. Разница в индексах равна длине слова и  индекс первого вхождения начинается с 0, возвращаем длину ab.
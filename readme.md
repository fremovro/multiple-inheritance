# Множественное наследование, управление памятью

Разработать консольное приложение позволяющее вводить/выводить/удалять информацию об игровых объектах. Приложение должно удовлетворять следующим требованиям:
1.	Содержать иерархию классов. Тематическая область - «Кухонная утварь»
2.	Объекты хранить в динамической структуре в виде упорядоченного бинарного дерева. В качестве ключа для помещения объекта в дерево использовать уникальный идентификатор. 
3.	Реализовать возможность
3.1.	Ввода данных
●	Тип объекта
●	Уникальный идентификатор
●	Поля, соответствующие конкретному объекту
При попытке добавления объекта с уникальным идентификатором, уже присутствующим в дереве, выдавать соответствующее сообщение и выводить информацию о найденном объекте.
3.2.	Удаления данных (по уникальному идентификатору)
3.3.	Вывода данных
4.	Для вывода данных реализовать метод print() в каждом классе. При этом метод класса должен печатать только внутренние поля класса + вызывать метод print() классов-родителей.
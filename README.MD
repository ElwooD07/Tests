# Программа для прохождения тестов КРОК

Для сборки нужен QT 5.
Программа работает с файлами теста в простом текстовом виде (без фоомул и картинок), примеры в папке Files. Если ваши тесты записаны в файл MS Word, то просто выделите весь текст и скопируйте его в новый текстовый документ, а потом используйте этот документ как файл тестов. Программа может не распознать некоторые вопросы и ответы, об этом она напишет в дебажный поток Qt (эти сообщения будут видны в Qt Creator при отладке). Если такое случится - подправьте тексты тестов.
Реализовано 2 парсинга - для файлов тестов старого образца (2015) и нового (2018). Файлов тестов старого образца не сохранилось.
Основные правила для распознания вопросов и ответов в файлах нового образца:
* вопрос начинается с новой строки, в начале которой стоит цифра и точка, например "42. question bla-bla-bla"
* ответ начинается с новой строки, в начале которой стоит один из латинских символов A B C D E F или кириллических А В С Е, с точкой, например: "B. answer bla-bla-bla"
* правильный ответ должен быть помечен символом звездочки перед текстом ответа, например: "C. * Right answer"

Прошу контрибьютить файлы тестов в папку Files
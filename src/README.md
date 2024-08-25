<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>

<body>
    <h1 class="title">SmartCalc_v2.0</h1>
    <div class="main">
        <h3 class="title_descrtiption" id="title_descrtiption">Описание проекта</h3>
        <p class="text_description">В данном проекте реализована расширенная версия калькулятора SmartCalc_v2.0.
            Разработанное приложение позволяет произвести вычисления с использованием переменной X, а так же выполнить построение графика заданной функции.</p>
        <h3 class="title_operators" id="title_operators">Реализованные операторы и функции</h3>
        <ul class="list_operators">
            <li class="list__operators_item">()</li>
            <li class="list__operators_item">+</li>
            <li class="list__operators_item">-</li>
            <li class="list__operators_item">*</li>
            <li class="list__operators_item">/</li>
            <li class="list__operators_item">^</li>
            <li class="list__operators_item">mod</li>
            <li class="list__operators_item">+a</li>
            <li class="list__operators_item">-a</li>
            <li class="list__operators_item">sin(x)</li>
            <li class="list__operators_item">cos(x)</li>
            <li class="list__operators_item">tan(x)</li>
            <li class="list__operators_item">asin(x)</li>
            <li class="list__operators_item">acos(x)</li>
            <li class="list__operators_item">atan(x)</li>
            <li class="list__operators_item">sqrt(x)</li>
            <li class="list__operators_item">ln(x)</li>
            <li class="list__operators_item">log(x)</li>
        </ul>
        <h3 class="title_bonus">Дополнительно</h3>
        <p class="text_bonus">Дополнительно предусмотрен специальный режим "кредитный калькулятор". <br>
            <b>Вход:</b> общая сумма кредита, срок, процентная ставка, тип (аннуитетный, дифференцированный). <br>
            <b>Выход:</b> ежемесячный платеж, переплата по кредиту, общая выплата.
        </p>
        <h3 class="title_install">Установка</h3>
        <p class="text_install">Для установки програмы необходимо выполнить команды <span class="command">make install</span>. <br>
        На рабочем столе будет создана папка под названием "SmartCalc_v2.0". Исполняемый файл внутри папки будет иметь идентичное название.</p>
        <h3 class="title_uninstall">Удаление</h3>
        <p class="text_uninstall">Для удаления програмы необходимо выполнить команды <span class="command">make uninstall</span>.</p>
        <h3 class="title_archive">Архивирование</h3>
        <p class="text_archive">Для архивирования проекта необходимо выполнить команды <span class="command">make dist</span>. <br>
        В результате выполнения команды на рабочем столе будет создан архив "SmartCalc_v2.0.tar"</p>
    </div>
</body>

</html>

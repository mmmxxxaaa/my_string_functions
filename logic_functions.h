#ifndef LOGIC_FUNCTIONS_H_
#define LOGIC_FUNCTIONS_H_

/*!
    @brief Функция проверяет, является ли нулём значение числа типа float
    @param[in] number Число типа float, которое нужно сравнить с нулём
    @param[out] bool-значение проверки:
                1-число является нулём
                0-число не является нулём
    @return true, если тест прошел и false, если тест не прошёл
*/
bool is_zero(float number);

/**
    @brief Функция проверяет, равны ли переданные ей числа типа float
    @param[in] number_1 Первое число типа float
    @param[in] number_2 Число типа float, с которым сравниваем первое число типа float
    @param[out] bool-значение проверки:
                1-числа равны
                0-числа не равны
    @return true, если тест прошел и false, если тест не прошёл
**/
bool is_equal(float number_1, float number_2);

/**
    @brief Функция проверяет, является ли NaN переданное ей число
    @param[in] number Число типа float, которое нужно проверить на NaN
    @param[out] bool-значение проверки:
                1-число имеет состояние NaN
                0-число имеет стандартное состояние
    @return true, если тест прошел и false, если тест не прошёл
**/
bool is_nan(float number);

/**
    @brief Функция проверяет, является ли INF переданное ей число
    @param[in] number Число типа float, которое нужно проверить на INF
    @param[out] bool-значение проверки:
                1-число имеет состояние INF
                0-число имеет стандартное состояние
    @return true, если тест прошел и false, если тест не прошёл
**/
bool is_inf(float number);

/**
    @brief Функция проверяет, является ли переданное ей число стандартным (то есть не NaN и не INF)
    @param[in] number Число типа float, которое нужно проверить на NaN и INF
    @param[out] bool-значение проверки:
                1-число имеет стандартное состояние
                0-число имеет состояние Nan или INF
    @return true, если тест прошел и false, если тест не прошёл
**/
bool is_finite(float number);

bool is_digit(char ch);

#endif // LOGIC_FUNCTIONS_H_

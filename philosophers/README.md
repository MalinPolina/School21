Задание:

Решите задачу об обедающих философах.

Философов может быть один или больше, и они могут только есть, думать или спать.

Симуляция останавливается со сметрью философа.

Каждый запуск происходит со следющими опциями: number_of_philosophers time_to_die

time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

◦ number_of_philosophers: число философов совпадает с числом вилок

◦ time_to_die: в миллисекундах; если философ не начинает есть в ’time_to_die’
миллисекунд после совего последнего приема пищи или от начала симуляции, он умирает

◦ time_to_eat: в миллисекундах; время, за которое ест философ. В это время ему нужны 2 вилки

◦ time_to_sleep: в миллисекундах; время, которое философ спит

◦ number_of_times_each_philosopher_must_eat: опциональный аргумент, если все философы поели
хотя бы ’number_of_times_each_philosopher_must_eat’ симуляция останавливается.

Любое изменение статуса философа должно выводиться следующим образом (X - номер философа
и timestamp_in_ms - текущее время в миллисекундах):

◦ timestamp_in_ms X has taken a fork

◦ timestamp_in_ms X is eating

◦ timestamp_in_ms X is sleeping

◦ timestamp_in_ms X is thinking

◦ timestamp_in_ms X died

Не может быть задержки более чем 10 мс с момента смерти философа и сообщением о его смерти.

philo:
Используйте threads и mutex. Вилки лежат между философами.

philo_bonus:
Используйте processes и semaphore. Вилки лежат в центре стола.

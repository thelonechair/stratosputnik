// создание переменных и присваивание им значений пинов элементов
int photo = A0; // переменная фоторезисора
int led = 11; // переменная светодиода
int motor = 10; // переменная управляющего транзистора
String motorstate;

void setup()
{
  Serial.begin(9600); // открываем порт для передачи данных
  pinMode(led, OUTPUT); // светодиод в начальный момент времени выключен
  pinMode(photo, OUTPUT); 
  pinMode(motor, OUTPUT); // на управляющий транзистор не подается сигнал
}
void loop()
{
  int transparency = analogRead(photo)/10; // вычисляем прозрачность в соответствии с приведенным графиком: показания фоторезистора/10
  if(digitalRead(motor) != 0) // если состояния мотора не равно 0, то 
  {
    motorstate = "ON"; // строковой переменной присваивается значение "ON"
  }else{
    motorstate = "OFF"; // в противном случае - "OFF"
  }
  String str = "State: " + motorstate + "Transparency: " + transparency + "%"; // выводимая строка равна “State: S, Transparency: T” , где:- S – Состояние перемешивающего устройства (ON/OFF) - T – Текущая прозрачность вещества в % (
  digitalWrite(led, HIGH); //включаем светодиод
  if(transparency <= 40) // если прозрачность меньше или равна 40%, то
  {
    digitalWrite(motor, HIGH); // включение мотора
    Serial.println(str); // вывод строки состояния str
  }else{
    digitalWrite(led, LOW); // в противном случае выключаем светодиод
    Serial.println(str); // выводим строку состояния str
  }
}

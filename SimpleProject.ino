void task1()
{
    // Definición de estados y variable de estado
    enum class Task1States
    {
        INIT,
        WAIT_TIMEOUT
    };
    static Task1States task1State = Task1States::INIT;

    // Definición de variables static (conservan
    // su valor entre llamadas a task1)
    static uint32_t lasTime = 0;
    static uint8_t btn1StateOld = LOW;
    static uint8_t btn2StateOld = LOW;

    // Constantes

    constexpr uint32_t INTERVAL = 1000;
    constexpr uint8_t button1Pin = 12;
    constexpr uint8_t button2Pin = 13;
    constexpr uint8_t ledRed = 25;
    constexpr uint8_t ledGreen = 14;
    constexpr uint8_t ledBlue = 27;
    constexpr uint8_t ledYellow = 26;

    // MÁQUINA de ESTADOS

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        pinMode(button1Pin, INPUT_PULLUP);
        pinMode(button2Pin, INPUT_PULLUP);
        pinMode(ledRed, OUTPUT);
        pinMode(ledGreen, OUTPUT);
        pinMode(ledBlue, OUTPUT);
        pinMode(ledYellow, OUTPUT);
        lasTime = millis();
        task1State = Task1States::WAIT_TIMEOUT;

        break;
    }
    case Task1States::WAIT_TIMEOUT:
    {
        uint8_t btn1State = digitalRead(button1Pin);
        uint8_t btn2State = digitalRead(button2Pin);
        uint32_t currentTime = millis();

    if(btn1State != btn1StateOld || btn2State != btn2StateOld)
    {
        btn1StateOld = btn1State;
        btn2StateOld = btn2State;
        
        printf("btn1: %d,btn2: %d\n", btn1StateOld, btn2StateOld);
        // Evento 1
        if (btn1State == LOW & btn2State == LOW)
            {
            digitalWrite(ledRed, HIGH);
            
            }
            else
            digitalWrite(ledRed, LOW);                                        
        // Evento 2
        if (btn1State == LOW & btn2State == HIGH)
            {digitalWrite(ledGreen, HIGH);
            
            }
            else
            digitalWrite(ledGreen, LOW);
        // Evento 3
        if (btn1State == HIGH & btn2State == LOW)
            {digitalWrite(ledBlue, HIGH);
            
            }
            else
            digitalWrite(ledBlue, LOW);
        // Evento 4
        if (btn1State == HIGH & btn2State == HIGH)
            {digitalWrite(ledYellow, HIGH);
            
            }
            else
            digitalWrite(ledYellow, LOW);
    }


        break;
    }
    default:
    {
        Serial.println("Error");
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}
// FSM_ledBlue States
//-------------------------------------------------------------------------------

void ledBlue_OffStt_Enter();
void ledBlue_OffStt_Update();
void ledBlue_OffStt_Exit();

void ledBlue_OnStt_Enter();
void ledBlue_OnStt_Update();
void ledBlue_OnStt_Exit();

State ledBlue_OFF_STT = State(ledBlue_OffStt_Enter, ledBlue_OffStt_Update, ledBlue_OffStt_Exit);
State ledBlue_ON_STT = State(ledBlue_OnStt_Enter, ledBlue_OnStt_Update, ledBlue_OnStt_Exit);

FSM FSM_ledBlue = FSM(ledBlue_OFF_STT);
char ledBlue_CurrentStt[32];

void ledBlue_OffStt_Enter()
{
	sprintf(ledBlue_CurrentStt, "ledBlue_OFF_STT");
	Serial.println(" Enter ledBlue_OffStt ...");

    lastMillis_led_BLUE=millis();
    digitalWrite(Pin_ledBlue, LOW);

}

void ledBlue_OffStt_Update()
{
    if (millis()-lastMillis_led_BLUE >= timeStateOff_led_BLUE)FSM_ledBlue.transitionTo(ledBlue_ON_STT);
}

void ledBlue_OffStt_Exit()
{
	Serial.println(" Exit ledBlue_OffStt ...");
    count=0;
}

void ledBlue_OnStt_Enter()
{
        sprintf(ledBlue_CurrentStt, "ledBlue_On_STT");
	    Serial.println(" Enter ledBlue_OnStt ...");

        lastMillis_led_BLUE=millis();
        digitalWrite(Pin_ledBlue, HIGH);
}

void ledBlue_OnStt_Update()
{
    if (millis()-lastMillis_led_BLUE >= timeStateOn_led_BLUE) FSM_ledBlue.transitionTo(ledBlue_OFF_STT);
}
void ledBlue_OnStt_Exit()
{
	Serial.println(" Exit ledBlue_OnStt ...");
    count=0;
}
// FSM_ledRed States
//-------------------------------------------------------------------------------

void ledRed_OffStt_Enter();
void ledRed_OffStt_Update();
void ledRed_OffStt_Exit();

void ledRed_OnStt_Enter();
void ledRed_OnStt_Update();
void ledRed_OnStt_Exit();

State ledRed_OFF_STT = State(ledRed_OffStt_Enter, ledRed_OffStt_Update, ledRed_OffStt_Exit);
State ledRed_ON_STT = State(ledRed_OnStt_Enter, ledRed_OnStt_Update, ledRed_OnStt_Exit);

FSM FSM_ledRed = FSM(ledRed_OFF_STT);
char ledRed_CurrentStt[32];

void ledRed_OffStt_Enter()
{
	sprintf(ledRed_CurrentStt, "ledRed_OFF_STT");
	Serial.println(" Enter ledRed_OffStt ...");

    lastMillis_led_RED=millis();
    digitalWrite(Pin_ledRed, LOW);

}

void ledRed_OffStt_Update()
{
    if (millis()- lastMillis_led_RED >= timeStateOff_led_RED ) FSM_ledRed.transitionTo(ledRed_ON_STT);
}

void ledRed_OffStt_Exit()
{
	Serial.println(" Exit ledRed_OffStt ...");
    count=0;
}

void ledRed_OnStt_Enter()
{
    sprintf(ledRed_CurrentStt, "ledRed_On_STT");
	Serial.println(" Enter ledRed_OnStt ...");

    int lastMillis_led_RED=millis();
    digitalWrite(Pin_ledRed, HIGH);
}

void ledRed_OnStt_Update()
{
    if (millis()- lastMillis_led_RED >= timeStateOn_led_RED )FSM_ledRed.transitionTo(ledRed_OFF_STT);
}
void ledRed_OnStt_Exit()
{
	Serial.println(" Exit ledRed_OnStt ...");
    count=0;
}
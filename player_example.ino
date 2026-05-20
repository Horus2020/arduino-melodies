#define BUZZER_PIN 8

#define N_R   0
#define N_C3  131
#define N_CS3 139
#define N_D3  147
#define N_DS3 156
#define N_E3  165
#define N_F3  175
#define N_FS3 185
#define N_G3  196
#define N_GS3 208
#define N_A3  220
#define N_AS3 233
#define N_B3  247
#define N_C4  262
#define N_CS4 277
#define N_D4  294
#define N_DS4 311
#define N_E4  330
#define N_F4  349
#define N_FS4 370
#define N_G4  392
#define N_GS4 415
#define N_A4  440
#define N_AS4 466
#define N_B4  494
#define N_C5  523
#define N_CS5 554
#define N_D5  587
#define N_DS5 622
#define N_E5  659
#define N_F5  698
#define N_FS5 740
#define N_G5  784
#define N_GS5 831
#define N_A5  880
#define N_AS5 932
#define N_B5  988
#define N_C6  1047

struct NoteStep {
  uint16_t freq;
  uint16_t dur; // ORA in ms
};

uint16_t noteToMs(uint16_t dur, uint16_t bpm) {
  return (uint16_t)((float)dur * 120.0f / (float)bpm);
}

void playMelody(const NoteStep* melody, uint16_t bpm) {
    static int i = 0;

    if (melody[i].freq == 0 && melody[i].dur == 0){
      i = 0; // loop
    }

    uint16_t duration = noteToMs(melody[i].dur, bpm);

    if (melody[i].freq > 0)
      tone(BUZZER_PIN, melody[i].freq);
    else
      noTone(BUZZER_PIN);

    delay(duration * 0.9);
    noTone(BUZZER_PIN);
    delay(duration * 0.1);

    i++;
}

// =================================================
//   SUBSTITUTE THE BPM VALUE AND YOUR MELODY HERE
// =================================================

#define MELODY_BPM 120

const NoteStep melody[] = {
    {N_C6,250},{N_AS5,250},{N_G5,250},{N_E5,250},{N_D5,250},{N_C5,250},
    {N_AS4,250},{N_G4,250},{N_F4,250},{N_E4,250},{N_D4,250},{N_C4,250},
    {N_AS3,250},{N_G3,250},{N_F3,250},{N_E3,250},{N_D3,250},{N_C3,250},
    {N_D3,250},{N_E3,250},{N_G3,250},{N_A3,250},{N_C4,250},{N_D4,250},
    {N_E4,250},{N_G4,250},{N_AS4,250},{N_C5,250},{N_D5,250},{N_E5,250},
    {N_G5,250},{N_A5,250},{N_C6,250},{N_AS5,250},{N_G5,250},
    {N_F5,250},{N_DS5,250},{N_C5,250},{N_AS4,250},{N_G4,250},{N_F4,250},
    {N_DS4,250},{N_C4,250},{N_AS3,250},{N_G3,250},{N_F3,250},{N_DS3,250},
    {N_C3,499},{N_DS3,250},{N_F3,250},{N_G3,250},{N_AS3,250},{N_C4,250},
    {N_DS4,250},{N_F4,250},{N_G4,250},{N_AS4,250},{N_C5,250},{N_DS5,250},
    {N_F5,250},{N_G5,250},{N_AS5,249},{N_C6,250},{0,0}
};

// ==============================

void setup() {
}

void loop() {
  playMelody(melody, MELODY_BPM);
}
